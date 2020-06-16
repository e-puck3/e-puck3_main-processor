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

static THD_WORKING_AREA(waBlinker,128);
static THD_FUNCTION(Blinker,arg) {
	(void)arg;
	chRegSetThreadName("blinker");
	while(true){
		// palClearLine(LINE_STATUS_LED1_R);
		// chThdSleepMilliseconds(50);
		// palClearLine(LINE_STATUS_LED2_R);
		// chThdSleepMilliseconds(50);
		// palClearLine(LINE_STATUS_LED3_R);
		// chThdSleepMilliseconds(50);
		// palClearLine(LINE_STATUS_LED1_G);
		// chThdSleepMilliseconds(50);
		// palClearLine(LINE_STATUS_LED2_G);
		// chThdSleepMilliseconds(50);
		// palClearLine(LINE_STATUS_LED3_G);
		// chThdSleepMilliseconds(50);
		// palClearLine(LINE_STATUS_LED1_B);
		// chThdSleepMilliseconds(50);
		// palClearLine(LINE_STATUS_LED2_B);
		// chThdSleepMilliseconds(50);
		// palClearLine(LINE_STATUS_LED3_B);
		// chThdSleepMilliseconds(50);
		// palSetLine(LINE_STATUS_LED1_R);
		// chThdSleepMilliseconds(50);
		// palSetLine(LINE_STATUS_LED2_R);
		// chThdSleepMilliseconds(50);
		// palSetLine(LINE_STATUS_LED3_R);
		// chThdSleepMilliseconds(50);
		// palSetLine(LINE_STATUS_LED1_G);
		// chThdSleepMilliseconds(50);
		// palSetLine(LINE_STATUS_LED2_G);
		// chThdSleepMilliseconds(50);
		// palSetLine(LINE_STATUS_LED3_G);
		// chThdSleepMilliseconds(50);
		// palSetLine(LINE_STATUS_LED1_B);
		// chThdSleepMilliseconds(50);
		// palSetLine(LINE_STATUS_LED2_B);
		// chThdSleepMilliseconds(50);
		// palSetLine(LINE_STATUS_LED3_B);
		// chThdSleepMilliseconds(50);

		palClearLine(LINE_FRONT_LED_R);
		palClearLine(LINE_RIGHT_LED_R);
		palClearLine(LINE_REAR_LED_R);
		palClearLine(LINE_LEFT_LED_R);
		chThdSleepMilliseconds(500);
		palSetLine(LINE_FRONT_LED_R);
		palSetLine(LINE_RIGHT_LED_R);
		palSetLine(LINE_REAR_LED_R);
		palSetLine(LINE_LEFT_LED_R);
		chThdSleepMilliseconds(500);
		palClearLine(LINE_FRONT_LED_G);
		palClearLine(LINE_RIGHT_LED_G);
		palClearLine(LINE_REAR_LED_G);
		palClearLine(LINE_LEFT_LED_G);
		chThdSleepMilliseconds(500);
		palSetLine(LINE_FRONT_LED_G);
		palSetLine(LINE_RIGHT_LED_G);
		palSetLine(LINE_REAR_LED_G);
		palSetLine(LINE_LEFT_LED_G);
		chThdSleepMilliseconds(500);
		palClearLine(LINE_FRONT_LED_B);
		palClearLine(LINE_RIGHT_LED_B);
		palClearLine(LINE_REAR_LED_B);
		palClearLine(LINE_LEFT_LED_B);
		chThdSleepMilliseconds(500);
		palSetLine(LINE_FRONT_LED_B);
		palSetLine(LINE_RIGHT_LED_B);
		palSetLine(LINE_REAR_LED_B);
		palSetLine(LINE_LEFT_LED_B);
		chThdSleepMilliseconds(500);
		
	}
}

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

	chThdCreateStatic(waBlinker, sizeof(waBlinker), NORMALPRIO, Blinker, NULL);
  
	while (true){
		chThdSleepMilliseconds(500);
    }

}
