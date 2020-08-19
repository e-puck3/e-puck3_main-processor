/**
 * @file	user_shell.c
 * @brief  	File containing functions and definitions to handle the shell provided by ChibiOS
 * 
 * @written by  	Eliot Ferragni
 * @creation date	12.03.2019
 */

#include "ch.h"
#include "hal.h"
#include "shell.h"
#include <stdlib.h>
#include <string.h>

#include "chprintf.h"
#include "user_shell.h"
#include "fatfs_cmd.h"
#include "dfsdm_cmd.h"
#include "dcmi_cmd.h"
#include "threads_utilities.h"
#include "uart_cmd.h"


static THD_WORKING_AREA(waShell,4096);

static char sc_histbuf[SHELL_MAX_HIST_BUFF];
static char* completion_buffer[SHELL_MAX_COMPLETIONS];

static const ShellCommand commands[] = {
  FATFS_SHELL_CMD
  DFSDM_SHELL_CMD
  DCMI_SHELL_CMD
  THREADS_UTILITIES_SHELL_CMD
  UART_CMD_SHELL_CMD
  {NULL, NULL}
};

static const ShellConfig shell_cfg = {
	(BaseSequentialStream *)&SHELL_PORT,
	commands,
	sc_histbuf,
	sizeof(sc_histbuf),
	completion_buffer,
};

void spawn_shell(void){
	static thread_t *shellTh = NULL;
	if(shellTh == NULL){
		shellTh = chThdCreateStatic(waShell, sizeof(waShell), NORMALPRIO + 1, shellThread, (void *)&shell_cfg);
	}	
}