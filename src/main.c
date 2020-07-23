/**
 * @file	main.c
 * @brief  	Main file of the e-puck3 programmer firmware
 * 
 * @written by  	Eliot Ferragni
 * @creation date   03.06.2020
 */

#include <stdio.h>
#include <string.h>

#include "ch.h"
#include "hal.h"
#include "chprintf.h"
#include "vl53l1_api.h"
#include "user_shell.h"
#include "usbcfg.h"
#include "dfsdm.h"
#include "ar0144.h"
#include "dcmi_cmd.h"
#include "ir_remote.h"
#include "imu.h"
#include "pressure_sensor.h"
#include "distance_sensor.h"
#include "gdb.h"

static THD_WORKING_AREA(waBlinker,128);
static THD_FUNCTION(Blinker,arg) {
	(void)arg;
	chRegSetThreadName("blinker");
	while(true){
		palClearLine(LINE_FRONT_LED_R);
		chThdSleepMilliseconds(50);
		palClearLine(LINE_RIGHT_LED_R);
		chThdSleepMilliseconds(50);
		palClearLine(LINE_REAR_LED_R);
		chThdSleepMilliseconds(50);
		palClearLine(LINE_LEFT_LED_R);
		chThdSleepMilliseconds(50);
		palClearLine(LINE_FRONT_LED_G);
		chThdSleepMilliseconds(50);
		palClearLine(LINE_RIGHT_LED_G);
		chThdSleepMilliseconds(50);
		palClearLine(LINE_REAR_LED_G);
		chThdSleepMilliseconds(50);
		palClearLine(LINE_LEFT_LED_G);
		chThdSleepMilliseconds(50);
		palClearLine(LINE_FRONT_LED_B);
		chThdSleepMilliseconds(50);
		palClearLine(LINE_RIGHT_LED_B);
		chThdSleepMilliseconds(50);
		palClearLine(LINE_REAR_LED_B);
		chThdSleepMilliseconds(50);
		palClearLine(LINE_LEFT_LED_B);
		chThdSleepMilliseconds(50);
		palSetLine(LINE_FRONT_LED_R);
		chThdSleepMilliseconds(50);
		palSetLine(LINE_RIGHT_LED_R);
		chThdSleepMilliseconds(50);
		palSetLine(LINE_REAR_LED_R);
		chThdSleepMilliseconds(50);
		palSetLine(LINE_LEFT_LED_R);
		chThdSleepMilliseconds(50);
		palSetLine(LINE_FRONT_LED_G);
		chThdSleepMilliseconds(50);
		palSetLine(LINE_RIGHT_LED_G);
		chThdSleepMilliseconds(50);
		palSetLine(LINE_REAR_LED_G);
		chThdSleepMilliseconds(50);
		palSetLine(LINE_LEFT_LED_G);
		chThdSleepMilliseconds(50);
		palSetLine(LINE_FRONT_LED_B);
		chThdSleepMilliseconds(50);
		palSetLine(LINE_RIGHT_LED_B);
		chThdSleepMilliseconds(50);
		palSetLine(LINE_REAR_LED_B);
		chThdSleepMilliseconds(50);
		palSetLine(LINE_LEFT_LED_B);
		chThdSleepMilliseconds(50);
		
		
	}
}

static const SerialConfig ser_cfg_esp32 = {
    .speed = 115200,
    .cr1 = 0,
    .cr2 = 0,
    .cr3 = 0,
};

/*
 * SD card configuration object.
 */
static const SDCConfig sd_card_config = {
    .bus_width = SDC_MODE_4BIT,
};

/*
 * STM32F76xxI maximum RAM setup.
 * 
 * RAM0 - Data, BSS, Heap.
 * RAM3 - Main Stack, Process Stack, NOCACHE, ETH.
 *
 * Notes:
 * By default, everything is placed into ram3 (DTCM)
 * which is the fastest but has only 128k of space.
 * 
 * Then if the data exceed the 64k when compiling, it is neccesarry to
 * put the data that are not time critical into ram0 (SRAM) with the keyword 
 * below before the delcaration:
 * 
 * __attribute__((section(".ram0")))
 *
 * Data thare are used by the DMA should not be placed in ram0, because of the cache.
 */

int main(void) {
	
	/*
	* System initializations.
	* - HAL initialization, this also initializes the configured device drivers
	*   and performs the board-specific initializations.
	* - Kernel initialization, the main() function becomes a thread and the
	*   RTOS is active.
	*/
	halInit();
	chSysInit();

	// DMA can't access correctly cached data
	// Disabled for now
	SCB_DisableDCache();

	// enables the USB HS PHY
	palSetLine(LINE_EN_PHY_HS);

	chThdSleepMilliseconds(100);
	usbSerialStart();

	sdStart(&SD5, &ser_cfg_esp32);
	//spawn_shell();

	chThdCreateStatic(waBlinker, sizeof(waBlinker), NORMALPRIO, Blinker, NULL);

	/* IMU CONFIG */
	imu_start();
	imu_data_t imu_data;
	
	/* PRESSURE CONFIG */
	pressure_sensor_start();
	pressure_sensor_data_t press_data;

	/* DISTANCE SENSOR CONFIG */
	distance_sensor_start();
	distance_sensor_data_t dist_data;

	// SD CARD CONFIG //
	sdcStart(&SDCD1, &sd_card_config);

	/* MICROPHONES CONFIG */
	dfsdm_start();

	/* USB DATARATE TEST CONFIG */
	// static uint8_t tab[80000];

	// for(uint32_t i = 0 ; i < 80000 ; i++){
	// 	tab[i] = (uint8_t)i;
	// }

	/* CAMERA TEST CONFIG */
	ar0144_start();
	dcmi_start_from_shell();

	/* IR REMOTE TEST CONFIG */
	ir_remote_start();

	initGDBEvents();
	gdbStart();
  
	while (true){
		chThdSleepMilliseconds(100);

		if(isUSBConfigured()){
			//spawns the shell if the usb is connected
			spawn_shell();
		}

		if(!palReadLine(LINE_USER_BUTTON_N)){
			/* IMU READING */
			imu_get_data(&imu_data);
			chprintf((BaseSequentialStream *)&SD5, "gyroscope:         X       Y       Z\r\n");
			chprintf((BaseSequentialStream *)&SD5, "                 %5f     %5f     %5f\r\n", imu_data.rate_rad[IMU_X_AXIS], imu_data.rate_rad[IMU_Y_AXIS], imu_data.rate_rad[IMU_Z_AXIS]);
			chprintf((BaseSequentialStream *)&SD5, "Accelerometer:     X       Y       Z\r\n");
			chprintf((BaseSequentialStream *)&SD5, "                 %5f     %5f     %5f\r\n\r\n", imu_data.acceleration_ms2[IMU_X_AXIS], imu_data.acceleration_ms2[IMU_Y_AXIS], imu_data.acceleration_ms2[IMU_Z_AXIS]);

			/* PRESSURE LPS22HD */
			pressure_sensor_get_data(&press_data);
			chprintf((BaseSequentialStream *)&SD5, "Pressure:      %5f\r\n", press_data.pressure_hpa);
			chprintf((BaseSequentialStream *)&SD5, "Temperature:   %5f\r\n\r\n", press_data.temperature_deg_c);

			/* DISTANCE SENSOR READING */
			
			distance_sensor_get_data(&dist_data);
			chprintf((BaseSequentialStream *)&SD5, "Distance: %fmm, valid: %s, time: %dms\r\n\r\n", dist_data.distance_mm, dist_data.valid ? "true":"false", dist_data.timestamp);
			/* USB DATARATE TEST  */
			// //Sends 60MB of data
			// systime_t begin_time = chVTGetSystemTime();
			// chprintf((BaseSequentialStream *)&SDU2,"Begins the test\r\n"); 
			// for(uint32_t i = 0 ; i < 750 ; i++){
			// 	streamWrite((BaseSequentialStream *)&SDU2, tab, 80000);
			// }
			// chprintf((BaseSequentialStream *)&SDU2,"Test finished in %d ms\r\n\r\n", chVTGetSystemTime() - begin_time); 
		}

		
    }

}
