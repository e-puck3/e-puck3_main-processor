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
static const SPIConfig spicfg_imu = {
  false,
  NULL,
  LINE_SPI2_CS_N_IMU,
  /*SPI_CR1_BR_1 | */SPI_CR1_BR_0,   // clk/4
  SPI_CR2_DS_2 | SPI_CR2_DS_1 | SPI_CR2_DS_0	//8bits
};

/*
 * Maximum speed SPI configuration (6.75MHz, CPHA=0, CPOL=0, MSb first, 8bits).
 */
static const SPIConfig spicfg_press = {
  false,
  NULL,
  LINE_SPI2_CS_N_PRESS,
  SPI_CR1_BR_1 | SPI_CR1_BR_0,   // clk/8
  SPI_CR2_DS_2 | SPI_CR2_DS_1 | SPI_CR2_DS_0	//8bits
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

	sdStart(&SD5, &ser_cfg_esp32);

	chThdCreateStatic(waBlinker, sizeof(waBlinker), NORMALPRIO, Blinker, NULL);

	uint8_t txbuf[30];
	uint8_t rxbuf[30];

	/* IMU CONFIG */

	txbuf[0] = 0x10; // write register 0x10 (CTRL1_XL)
	txbuf[1] = 0xA0; // write high performance mode accelerometer 2g
	spiAcquireBus(&SPID2);
	spiStart(&SPID2, &spicfg_imu);
	spiSelect(&SPID2);
	spiExchange(&SPID2, 2, txbuf, rxbuf);
	spiUnselect(&SPID2);
	spiReleaseBus(&SPID2);

	txbuf[0] = 0x11; // write register 0x11 (CTRL2_G)
	txbuf[1] = 0xA0 | 0x0C; // write high performance mode gyroscope 2000dps
	spiAcquireBus(&SPID2);
	spiStart(&SPID2, &spicfg_imu);
	spiSelect(&SPID2);
	spiExchange(&SPID2, 2, txbuf, rxbuf);
	spiUnselect(&SPID2);
	spiReleaseBus(&SPID2);
  
	while (true){
		chThdSleepMilliseconds(100);

		/* IMU READING */
		txbuf[0] = 0x80 | 0x22; // read register 0x22
		txbuf[1] = 0;
		spiAcquireBus(&SPID2);
		spiStart(&SPID2, &spicfg_imu);
		spiSelect(&SPID2);
		spiExchange(&SPID2, 1+12, txbuf, rxbuf);
		spiUnselect(&SPID2);
		spiReleaseBus(&SPID2);
		chprintf((BaseSequentialStream *)&SD5, "gyroscope:         X       Y       Z\r\n");
		chprintf((BaseSequentialStream *)&SD5, "                 %5d     %5d     %5d\r\n", (int16_t)(rxbuf[1] | rxbuf[2]<<8), (int16_t)(rxbuf[3] | rxbuf[4]<<8), (int16_t)(rxbuf[5] | rxbuf[6]<<8));
		chprintf((BaseSequentialStream *)&SD5, "Accelerometer:     X       Y       Z\r\n");
		chprintf((BaseSequentialStream *)&SD5, "                 %5d     %5d     %5d\r\n\r\n", (int16_t)(rxbuf[7] | rxbuf[8]<<8), (int16_t)(rxbuf[9] | rxbuf[10]<<8), (int16_t)(rxbuf[11] | rxbuf[12]<<8));

		/* IMU */
		// txbuf[0] = 0x80 | 0x0F;
		// txbuf[1] = 0;
		// spiAcquireBus(&SPID2);
		// spiStart(&SPID2, &spicfg_imu);
		// spiSelect(&SPID2);
		// spiExchange(&SPID2, 2, txbuf, rxbuf);
		// spiUnselect(&SPID2);
		// spiReleaseBus(&SPID2);

		// chprintf((BaseSequentialStream *)&SD5, "Register : %d %d \r\n", rxbuf[0], rxbuf[1]);
    }

}
