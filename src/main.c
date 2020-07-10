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

// #define I2C_TEST
// #ifdef I2C_TEST
// int rd_write_verification( VL53L1_Dev_t *dev, uint16_t addr, uint32_t expected_value)
// {
// 	VL53L1_Error Status  = VL53L1_ERROR_NONE;
// 	uint8_t bytes[4],mbytes[4];
// 	uint16_t words[2];
// 	uint32_t dword;
// 	int i;
// 	VL53L1_ReadMulti(dev, addr, mbytes, 4);
// 	for (i=0; i<4; i++){ VL53L1_RdByte(dev, addr+i, &bytes[i]); }
// 	for (i=0; i<2; i++){ VL53L1_RdWord(dev, addr+i*2, &words[i]); }
// 	Status = VL53L1_RdDWord(dev, addr, &dword);
	
// 	chprintf((BaseSequentialStream *)&SD5, "expected   = %8x,\r\n",expected_value);
// 	chprintf((BaseSequentialStream *)&SD5, "read_multi = %2x, %2x, %2x, %2x\r\n", mbytes[0],mbytes[1],mbytes[2],mbytes[3]);
// 	chprintf((BaseSequentialStream *)&SD5, "read_bytes = %2x, %2x, %2x, %2x\r\n", bytes[0],bytes[1],bytes[2],bytes[3]);
// 	chprintf((BaseSequentialStream *)&SD5, "read words = %4x, %4x\r\n",words[0],words[1]);
// 	chprintf((BaseSequentialStream *)&SD5, "read dword = %8x\r\n",dword);
	
// 	if((mbytes[0]<<24 | mbytes[1]<<16 | mbytes[2]<<8 | mbytes[3]) != expected_value) return (1);
// 	if((bytes[0]<<24 | bytes[1]<<16 | bytes[2]<<8 | bytes[3]) != expected_value) return (2);
// 	if((words[0]<<16 | words[1]) != expected_value) return (3);
// 	if(dword != expected_value) return(4);
// 	return Status;
	
// }
// #define REG 0x3A
// void i2c_test(VL53L1_Dev_t *dev)
// {
// 	VL53L1_Error Status  = VL53L1_ERROR_NONE;
// 	VL53L1_Error Status2  = VL53L1_ERROR_NONE;
// 	int err_count = 0;
// 	static uint8_t buff[4] = {0x11,0x22,0x33,0x44};
// 	static uint8_t long_out[135] ={0x29, 0x02, 0x10, 0x00, 0x22, 0xBC, 0xCC, 0x81, 0x80, 0x07, 0x16, 0x00, 0xFF, 0xFD,
// 							0xF7, 0xDE, 0xFF, 0x0F, 0x00, 0x15, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
// 							0x44, 0x00, 0x2C, 0x00, 0x11, 0x0A, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
// 							0x00, 0x11, 0x02, 0x00, 0x02, 0x08, 0x00, 0x08, 0x10, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0xFF,
// 							0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x0B, 0x00, 0x00, 0x02, 0x14, 0x21, 0x00, 0x00,
// 							0x02, 0x00, 0x00, 0x00, 0x00, 0xC8, 0x00, 0x00, 0x38, 0xFF, 0x01, 0x00, 0x01, 0x00, 0x02, 0x00,
// 							0x9D, 0x07, 0x00, 0xD2, 0x05, 0x01, 0x68, 0x00, 0xC0, 0x08, 0x38, 0x00, 0x00, 0x00, 0x00, 0x03,
// 							0xB6, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x07, 0x05, 0x06, 0x06, 0x01, 0x00, 0x02,
// 							0xC7, 0xFF, 0x8B, 0x00, 0x00, 0x00, 0x01, 0x01, 0x40};
// 	static uint8_t long_in[135]= {0xff};
//   	int i=0;

// 	Status = rd_write_verification(dev, 0x010f, 0xeacc10ff);			// verify the Chip ID works
// 	chprintf((BaseSequentialStream *)&SD5, "read 0xeacc10ff %d\r\n", Status);

// 	Status = VL53L1_WriteMulti(dev, 0x0001,  long_out, 135);			// check if WriteMulti can write 135 bytes
// 	chprintf((BaseSequentialStream *)&SD5, "WriteMulti %d\r\n", Status);
// 	Status = VL53L1_ReadMulti(dev, 0x0001,  long_in, 135);			// check if WriteMulti can read 135 bytes
// 	chprintf((BaseSequentialStream *)&SD5, "ReadMulti %d\r\n", Status);

// 	for (i=0; i<135; i++) if(long_in[i] != long_out[i])err_count++;

// 	for(uint16_t j = 0 ; j < 135 ; j++){
// 		chprintf((BaseSequentialStream *)&SD5, "%d %x %x\r\n", j, long_out[j], long_in[j]);
// 	}
// 	chprintf((BaseSequentialStream *)&SD5, "err_count %d\r\n", err_count);

// 	Status = VL53L1_WriteMulti(dev, REG,  buff, 4);				// check WriteMulti
// 	chprintf((BaseSequentialStream *)&SD5, "write 0x11223344 %d\r\n", Status);
// 	Status = rd_write_verification(dev, REG, 0x11223344);
// 	chprintf((BaseSequentialStream *)&SD5, "read 0x11223344 %d\r\n", Status);

// 	Status = VL53L1_WrDWord(dev, REG, 0xffeeddcc);				// check WrDWord
// 	chprintf((BaseSequentialStream *)&SD5, "write 0xffeeddcc %d\r\n", Status);
// 	Status = rd_write_verification(dev, REG, 0xffeeddcc);
// 	chprintf((BaseSequentialStream *)&SD5, "read 0xffeeddcc %d\r\n", Status);

// 	Status = VL53L1_WrWord(dev, REG, 0x5566);					// check WrWord
// 	Status2 = VL53L1_WrWord(dev, REG+2, 0x7788);
// 	chprintf((BaseSequentialStream *)&SD5, "write 0x5566 7788 %d %d\r\n", Status, Status2);
// 	rd_write_verification(dev, REG, 0x55667788);
// 	chprintf((BaseSequentialStream *)&SD5, "read 0x55667788 %d\r\n", Status);

// 	for (i=0; i<4; i++){ VL53L1_WrByte (dev, REG+i, buff[i]); }
// 	chprintf((BaseSequentialStream *)&SD5, "write 0x11 22 33 44\r\n");
// 	Status = rd_write_verification(dev, REG,0x11223344);
// 	chprintf((BaseSequentialStream *)&SD5, "read 0x1122334 %d\r\n", Status);
// }

// #endif


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
 * Maximum speed SPI configuration (13.5MHz, CPHA=0, CPOL=0, MSb first, 8bits).
 */
static const SPIConfig spicfg_press = {
  false,
  NULL,
  LINE_SPI2_CS_N_PRESS,
  SPI_CR1_BR_0,   // clk/4
  SPI_CR2_DS_2 | SPI_CR2_DS_1 | SPI_CR2_DS_0	//8bits
};

/*
 * I2C configuration object.
 * I2C2_TIMINGR: 1 MHz with I2CCLK = 216 MHz, rise time = 0 ns,
 *               fall time = 0 ns (0x00A02B91)
 */
static const I2CConfig i2c2config_vl53l1 = {
    .timingr    = 0x00A02B91,
    .cr1        = 0,
    .cr2        = 0,
};
static VL53L1_Dev_t vl53l1_dev;

/*
 * SD card configuration object.
 */
static const SDCConfig sd_card_config = {
    .bus_width = SDC_MODE_4BIT,
};

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

	uint8_t txbuf[30];
	uint8_t rxbuf[30];

	/* IMU CONFIG */
	imu_start();
	imu_data_t imu_data;
	

	/* PRESSURE CONFIG */
	txbuf[0] = 0x10; // write register 0x10 (CTRL_REG1)
	txbuf[1] = 0x50; // write 75Hz output rate
	spiAcquireBus(&SPID2);
	spiStart(&SPID2, &spicfg_press);
	spiSelect(&SPID2);
	spiExchange(&SPID2, 2, txbuf, rxbuf);
	spiUnselect(&SPID2);
	spiReleaseBus(&SPID2);

	/* DISTANCE SENSOR CONFIG */
	int8_t status;
	static VL53L1_RangingMeasurementData_t RangingData;
	uint8_t byteData;
	uint16_t wordData;
	i2cStart(&I2CD1, &i2c2config_vl53l1);

	palClearLine(LINE_EN_TOF);
	chThdSleepMilliseconds(10);
	palSetLine(LINE_EN_TOF);
	chThdSleepMilliseconds(10);
	vl53l1_dev.I2cHandle = &I2CD1;
	vl53l1_dev.I2cDevAddr = 0x52; //8bit address
	VL53L1_RdByte(&vl53l1_dev, 0x010F, &byteData);
	// chprintf((BaseSequentialStream *)&SD5, "VL53L1X Model_ID: %02X\n\r", byteData);
	VL53L1_RdByte(&vl53l1_dev, 0x0110, &byteData);
	// chprintf((BaseSequentialStream *)&SD5, "VL53L1X Module_Type: %02X\n\r", byteData);
	VL53L1_RdWord(&vl53l1_dev, 0x010F, &wordData);
	// chprintf((BaseSequentialStream *)&SD5, "VL53L1X: %02X\n\r", wordData);
	status = VL53L1_WaitDeviceBooted(&vl53l1_dev);
	// chprintf((BaseSequentialStream *)&SD5, "VL53L1_WaitDeviceBooted %d\r\n", status);
	status = VL53L1_DataInit(&vl53l1_dev);
	// chprintf((BaseSequentialStream *)&SD5, "VL53L1_DataInit %d\r\n", status);
	status = VL53L1_StaticInit(&vl53l1_dev);
	// chprintf((BaseSequentialStream *)&SD5, "VL53L1_StaticInit %d\r\n", status);
	status = VL53L1_SetPresetMode(&vl53l1_dev, VL53L1_PRESETMODE_LITE_RANGING);
	// chprintf((BaseSequentialStream *)&SD5, "VL53L1_SetPresetMode %d\r\n", status);
	status = VL53L1_SetDistanceMode(&vl53l1_dev, VL53L1_DISTANCEMODE_SHORT);
	// chprintf((BaseSequentialStream *)&SD5, "VL53L1_SetDistanceMode %d\r\n", status);
	status = VL53L1_SetMeasurementTimingBudgetMicroSeconds(&vl53l1_dev, 20000);
	// chprintf((BaseSequentialStream *)&SD5, "VL53L1_SetMeasurementTimingBudgetMicroSeconds %d\r\n", status);
	// status = VL53L1_SetInterMeasurementPeriodMilliSeconds(&vl53l1_dev, 100);
	// chprintf((BaseSequentialStream *)&SD5, "VL53L1_SetInterMeasurementPeriodMilliSeconds %d\r\n", status);
	status = VL53L1_StartMeasurement(&vl53l1_dev);
	// chprintf((BaseSequentialStream *)&SD5, "VL53L1_StartMeasurement %d\r\n", status);
	uint8_t first_time = 1;

	// i2c_test(&vl53l1_dev);

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
			txbuf[0] = 0x80 | 0x28; // read register 0x28
			txbuf[1] = 0;
			spiAcquireBus(&SPID2);
			spiStart(&SPID2, &spicfg_press);
			spiSelect(&SPID2);
			spiExchange(&SPID2, 1+5, txbuf, rxbuf);
			spiUnselect(&SPID2);
			spiReleaseBus(&SPID2);
			chprintf((BaseSequentialStream *)&SD5, "Pressure:      %5f\r\n", (float)(rxbuf[1] | rxbuf[2]<<8 | rxbuf[3]<<16)/4096);
			chprintf((BaseSequentialStream *)&SD5, "Temperature:   %5f\r\n\r\n", (float)(rxbuf[4] | rxbuf[5]<<8)/100);

			/* DISTANCE SENSOR READING */
			status = VL53L1_WaitMeasurementDataReady(&vl53l1_dev);
			if(status == 0){
				if(first_time){
					VL53L1_ClearInterruptAndStartMeasurement(&vl53l1_dev);
					first_time = 0;
				}else{
					status = VL53L1_GetRangingMeasurementData(&vl53l1_dev, &RangingData);
					chprintf((BaseSequentialStream *)&SD5, "status: %d, distance: %d, signal rate: %.2f, ambiant rate: %.2f time: %d\r\n\r\n", RangingData.RangeStatus,RangingData.RangeMilliMeter,
													RangingData.SignalRateRtnMegaCps/65536.0,RangingData.AmbientRateRtnMegaCps/65336.0, chVTGetSystemTime());
					VL53L1_ClearInterruptAndStartMeasurement(&vl53l1_dev);
				}
			}

			/* USB DATARATE TEST  */
			// //Sends 60MB of data
			// systime_t begin_time = chVTGetSystemTime();
			// chprintf((BaseSequentialStream *)&SDU1,"Begins the test\r\n"); 
			// for(uint32_t i = 0 ; i < 750 ; i++){
			// 	streamWrite((BaseSequentialStream *)&SDU1, tab, 80000);
			// }
			// chprintf((BaseSequentialStream *)&SDU1,"Test finished in %d ms\r\n\r\n", chVTGetSystemTime() - begin_time); 
		}

		
    }

}
