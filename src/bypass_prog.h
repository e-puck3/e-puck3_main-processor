/**
 * @file	bypass_prog.h
 * @brief  	Bypass prog is a signal used to bypass some low level control of the 
 * 			power system of the robot. It is used when we want to program the programer itself
 * 
 * @written by  	Eliot Ferragni
 * @creation date	23.07.2020
 */

#ifndef BYPASS_PROG_H
#define BYPASS_PROG_H

#include "ch.h"
#include "hal.h"



/**
 * @brief 	Checks if the bypass prog signal is active. If so, keep this signal active
 * 			and and keep the robot ON
 * 			
 * 			Need to be called before everything in the main (even halInit) in order to catch 
 * 			correctly the button pressed and not miss it because the system init took to much time.
 */	
void bypassProgCheck(void);


#endif  /* BYPASS_PROG_H */