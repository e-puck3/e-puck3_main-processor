/**
 * @file	lps22hd.c
 * @brief  	Low level driver for a lps22hd pressure sensore connected with SPI
 * 
 * @written by  	Eliot Ferragni
 * @creation date	10.07.2020
 */
 
#include "ch.h"
#include "hal.h"
#include "math.h"
#include "lps22hd.h"

/********************               LPS22HD REGISTERS              ********************/

#define REG_RESERVED_1		0x00 //RESERVED from 0x00 to 0x0A
#define REG_INTERRUPT_CFG	0x0B
#define REG_THS_P_L			0x0C
#define REG_THS_P_H			0x0D
#define REG_RESERVED_2		0x0E
#define REG_WHO_AM_I		0x0F
#define REG_CTRL_REG1		0x10
#define REG_CTRL_REG2		0x11
#define REG_CTRL_REG3		0x12
#define REG_RESERVED_3		0x13
#define REG_FIFO_CTRL		0x14
#define REG_REF_P_XL		0x15
#define REG_REF_P_L			0x16
#define REG_REF_P_H			0x17
#define REG_RPDS_L			0x18
#define REG_RPDS_H			0x19
#define REG_RES_CONF		0x1A
#define REG_RESERVED_4		0x1B //RESERVED from 0x1B to 0x24
#define REG_INT_SOURCE		0x25
#define REG_FIFO_STATUS		0x26
#define REG_STATUS			0x27
#define REG_PRESS_OUT_XL	0x28
#define REG_PRESS_OUT_L		0x29
#define REG_PRESS_OUT_H		0x2A
#define REG_TEMP_OUT_L		0x2B
#define REG_TEMP_OUT_H		0x2C
#define REG_RESERVED_5		0x2D //RESERVED from 0x2D to 0x32
#define REG_LPFP_RES		0x33

/********************        Bit definition for CTRL_REG1       ********************/
#define CTRL_REG1_ODR(x) 				((x & 0x7) << 4)
#define CTRL_REG1_EN_LPFP				(1 << 3)
#define CTRL_REG1_LPFP_CFG				(1 << 2)
#define CTRL_REG1_BDU					(1 << 1)
#define CTRL_REG1_SIM					(1 << 0)

/********************        Bit definition for CTRL_REG2       ********************/
#define CTRL_REG2_BOOT					(1 << 7)
#define CTRL_REG2_FIFO_EN				(1 << 6)
#define CTRL_REG2_STOP_ON_FTH			(1 << 5)
#define CTRL_REG2_IF_ADD_INC			(1 << 4)
#define CTRL_REG2_I2C_DIS				(1 << 3)
#define CTRL_REG2_SWRESET				(1 << 2)
#define CTRL_REG2_ONE_SHOT				(1 << 0)

/********************              LPS22HD WRITE/READ              ********************/
#define READ_CMD 						0x80
#define WRITE_CMD						0x00



/********************               Internal buffers               ********************/
#define MAX_SPI_FRAME_LENGTH			6
static uint8_t txbuf[MAX_SPI_FRAME_LENGTH] = {0};
static uint8_t rxbuf[MAX_SPI_FRAME_LENGTH] = {0};


/********************                   Constants                  ********************/

#define LSB_BY_HPA 						4096
#define LSB_BY_DEG_C					100

/********************              Internal functions              ********************/
static msg_t _write_reg(lps22hd_device_t* dev, uint8_t reg, uint8_t val){

	txbuf[0] = reg | WRITE_CMD;
	txbuf[1] = val;

	spiAcquireBus(dev->spid);
	spiStart(dev->spid, dev->spi_cfg);
	spiSelect(dev->spid);
	spiExchange(dev->spid, 2, txbuf, rxbuf);
	spiUnselect(dev->spid);
	spiReleaseBus(dev->spid);

	return MSG_OK;
}

// static msg_t _read_reg(lps22hd_device_t* dev, uint8_t reg){

// 	txbuf[0] = reg | READ_CMD;

// 	spiAcquireBus(dev->spid);
// 	spiStart(dev->spid, dev->spi_cfg);
// 	spiSelect(dev->spid);
// 	spiExchange(dev->spid, 2, txbuf, rxbuf);
// 	spiUnselect(dev->spid);
// 	spiReleaseBus(dev->spid);

// 	return MSG_OK;
// }

static msg_t _read_reg_multi(lps22hd_device_t* dev, uint8_t reg, uint8_t len){
	
	txbuf[0] = reg | READ_CMD;

	if(len >= MAX_SPI_FRAME_LENGTH){
		return MSG_RESET;
	}

	spiAcquireBus(dev->spid);
	spiStart(dev->spid, dev->spi_cfg);
	spiSelect(dev->spid);
	spiExchange(dev->spid, 1 + len, txbuf, rxbuf);
	spiUnselect(dev->spid);
	spiReleaseBus(dev->spid);

	return MSG_OK;
}

/********************               Public functions               ********************/

msg_t lps22hd_configure(lps22hd_device_t* dev){

	
	_write_reg(dev, REG_CTRL_REG2, CTRL_REG2_IF_ADD_INC | CTRL_REG2_I2C_DIS);

	_write_reg(dev, REG_CTRL_REG1, CTRL_REG1_ODR(dev->cfg->freq));

	return MSG_OK;
}

msg_t lps22hd_read_raw_data(lps22hd_device_t* dev, lps22hd_data_t* data){
	_read_reg_multi(dev, REG_PRESS_OUT_XL, 5);

	data->pressure_raw = (int32_t)(rxbuf[1] | ((int32_t)rxbuf[2])<<8 | ((int32_t)rxbuf[3])<<16);
	data->temperature_raw = (int16_t)(rxbuf[4] | ((int16_t)rxbuf[5])<<8);

	return MSG_OK;
}

msg_t lps22hd_read_converted_data(lps22hd_device_t* dev, lps22hd_data_t* data){

	lps22hd_read_raw_data(dev, data);

	data->pressure_hpa = (float)data->pressure_raw / LSB_BY_HPA;
	data->temperature_deg_c = (float)data->temperature_raw / LSB_BY_DEG_C;

	return MSG_OK;
}




