/**
 * @file	bypass_prog.c
 * @brief  	Bypass prog is a signal used to bypass some low level control of the 
 * 			power system of the robot. It is used when we want to program the programer itself
 * 
 * @written by  	Eliot Ferragni
 * @creation date	23.07.2020
 */

#include "ch.h"
#include "hal.h"
#include "bypass_prog.h"

/////////////////////////////////////////PUBLIC FUNCTIONS/////////////////////////////////////////



void bypassProgCheck(void){

	// if we read 1, it means the bypass ptog button is pressed.
	if(palReadLine(LINE_BYPASS_PROG)){
		// we reconfigure the pin as output and keep this signal active
		palSetLineMode(LINE_BYPASS_PROG, PAL_MODE_OUTPUT_PUSHPULL);
		palSetLine(LINE_BYPASS_PROG);
		// we also keep the power ON
		palSetLine(LINE_POWER_ON);
	}
}

