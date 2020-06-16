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
  
	while (true){
		chThdSleepMilliseconds(500);
		chprintf((BaseSequentialStream *)&SD5, "Un joli test \r\n");
    }

}
