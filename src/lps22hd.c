/**
 * @file	lps22hd.c
 * @brief  	Low level driver for a lsm6dsox pressure sensore connected with SPI
 * 
 * @written by  	Eliot Ferragni
 * @creation date	10.07.2020
 */
 
#include "ch.h"
#include "hal.h"
#include "math.h"
#include "lps22hd.h"

/********************               LPS22HD REGISTERS              ********************/



/********************        Bit definition for REG_CTRL1_XL       ********************/


/********************              LPS22HD WRITE/READ              ********************/
#define READ_CMD 						0x80
#define WRITE_CMD						0x00



/********************               Internal buffers               ********************/
#define MAX_SPI_FRAME_LENGTH			6	
static uint8_t txbuf[MAX_SPI_FRAME_LENGTH] = {0};
static uint8_t rxbuf[MAX_SPI_FRAME_LENGTH] = {0};


/********************                   Constants                  ********************/


/********************              Internal functions              ********************/
static msg_t _write_reg(lps22hd_device_t* press, uint8_t reg, uint8_t val){

	txbuf[0] = reg | WRITE_CMD;
	txbuf[1] = val;

	spiAcquireBus(press->spid);
	spiStart(press->spid, press->spi_cfg);
	spiSelect(press->spid);
	spiExchange(press->spid, 2, txbuf, rxbuf);
	spiUnselect(press->spid);
	spiReleaseBus(press->spid);

	return MSG_OK;
}

static msg_t _read_reg(lps22hd_device_t* press, uint8_t reg){

	txbuf[0] = reg | READ_CMD;

	spiAcquireBus(press->spid);
	spiStart(press->spid, press->spi_cfg);
	spiSelect(press->spid);
	spiExchange(press->spid, 2, txbuf, rxbuf);
	spiUnselect(press->spid);
	spiReleaseBus(press->spid);

	return MSG_OK;
}

static msg_t _read_reg_multi(lps22hd_device_t* press, uint8_t reg, uint8_t len){
	
	txbuf[0] = reg | READ_CMD;

	if(len >= MAX_SPI_FRAME_LENGTH){
		return MSG_RESET;
	}

	spiAcquireBus(press->spid);
	spiStart(press->spid, press->spi_cfg);
	spiSelect(press->spid);
	spiExchange(press->spid, 1 + len, txbuf, rxbuf);
	spiUnselect(press->spid);
	spiReleaseBus(press->spid);

	return MSG_OK;
}



