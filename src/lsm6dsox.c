/**
 * @file	lsm6dsox.c
 * @brief  	Low level driver for a lsm6dsox IMU connected with SPI
 * 
 * @written by  	Eliot Ferragni
 * @creation date	09.07.2020
 */
 
#include "ch.h"
#include "hal.h"
#include "math.h"
#include "lsm6dsox.h"

/********************              LSM6DSOX REGISTERS              ********************/

#define REG_FUNC_CFG_ACCESS				0x01
#define REG_PIN_CTRL					0x02
#define REG_RESERVED					0x03
#define REG_S4S_TPH_L					0x04
#define REG_S4S_TPH_H					0x05
#define REG_S4S_RR						0x06
#define REG_FIFO_CTRL1					0x07
#define REG_FIFO_CTRL2					0x08
#define REG_FIFO_CTRL3					0x09
#define REG_FIFO_CTRL4					0x0A
#define REG_COUNTER_BDR_REG1			0x0B
#define REG_COUNTER_BDR_REG2			0x0C
#define REG_INT1_CTRL					0x0D
#define REG_INT2_CTRL					0x0E
#define REG_WHO_AM_I					0x0F
#define REG_CTRL1_XL					0x10
#define REG_CTRL2_G						0x11
#define REG_CTRL3_C						0x12
#define REG_CTRL4_C						0x13
#define REG_CTRL5_C						0x14
#define REG_CTRL6_C						0x15
#define REG_CTRL7_G						0x16
#define REG_CTRL8_XL					0x17
#define REG_CTRL9_XL					0x18
#define REG_CTRL10_C					0x19
#define REG_ALL_INT_SRC					0x1A
#define REG_WAKE_UP_SRC					0x1B
#define REG_TAP_SRC						0x1C
#define REG_D6D_SRC						0x1D
#define REG_STATUS_REG					0x1E
#define REG_RESERVED_1					0x1F
#define REG_OUT_TEMP_L					0x20
#define REG_OUT_TEMP_H					0x21
#define REG_OUTX_L_G					0x22
#define REG_OUTX_H_G					0x23
#define REG_OUTY_L_G					0x24
#define REG_OUTY_H_G					0x25
#define REG_OUTZ_L_G					0x26
#define REG_OUTZ_H_G					0x27
#define REG_OUTX_L_A					0x28
#define REG_OUTX_H_A					0x29
#define REG_OUTY_L_A					0x2A
#define REG_OUTY_H_A					0x2B
#define REG_OUTZ_L_A					0x2C
#define REG_OUTZ_H_A					0x2D
#define REG_RESERVED_2					0x2E	//RESERVED from 0x2E to 0x34
#define REG_EMB_FUNC_STATUS_MAINPAGE	0x35
#define REG_FSM_STATUS_A_MAINPAGE		0x36
#define REG_FSM_STATUS_B_MAINPAGE		0x37
#define REG_MLC_STATUS_MAINPAGE			0x38
#define REG_STATUS_MASTER_MAINPAGE		0x39
#define REG_FIFO_STATUS1				0x3A
#define REG_FIFO_STATUS2				0x3B
#define REG_RESERVED_3					0x3C	//RESERVED from 0x3C to 0x3F
#define REG_TIMESTAMP0					0x40
#define REG_TIMESTAMP1					0x41
#define REG_TIMESTAMP2					0x42
#define REG_TIMESTAMP3					0x43
#define REG_RESERVED_4					0x44	//RESERVED from 0x44 to 0x48
#define REG_UI_STATUS_REG_OIS			0x49
#define REG_UI_OUTX_L_G_OIS				0x4A
#define REG_UI_OUTX_H_G_OIS				0x4B
#define REG_UI_OUTY_L_G_OIS				0x4C
#define REG_UI_OUTY_H_G_OIS				0x4D
#define REG_UI_OUTZ_L_G_OIS				0x4E
#define REG_UI_OUTZ_H_G_OIS				0x4F
#define REG_UI_OUTX_L_A_OIS				0x50
#define REG_UI_OUTX_H_A_OIS				0x51
#define REG_UI_OUTY_L_A_OIS				0x52
#define REG_UI_OUTY_H_A_OIS				0x53
#define REG_UI_OUTZ_L_A_OIS				0x54
#define REG_UI_OUTZ_H_A_OIS				0x55
#define REG_TAP_CFG0					0x56
#define REG_TAP_CFG1					0x57
#define REG_TAP_CFG2					0x58
#define REG_TAP_THS_6D					0x59
#define REG_INT_DUR2					0x5A
#define REG_WAKE_UP_THS					0x5B
#define REG_WAKE_UP_DUR					0x5C
#define REG_FREE_FALL					0x5D
#define REG_MD1_CFG						0x5E
#define REG_MD2_CFG						0x5F
#define REG_S4S_ST_CMD_CODE				0x60
#define REG_S4S_DT_REG					0x61
#define REG_I3C_BUS_AVB					0x62
#define REG_INTERNAL_FREQ_FINE 			0x63
#define REG_RESERVED5					0x64	//RESERVED from 0x64 to 0x6E
#define REG_UI_INT_OIS					0x6F
#define REG_UI_CTRL1_OIS				0x70
#define REG_UI_CTRL2_OIS				0x71
#define REG_UI_CTRL3_OIS				0x72
#define REG_X_OFS_USR					0x73
#define REG_Y_OFS_USR					0x74
#define REG_Z_OFS_USR					0x75
#define REG_RESERVED_6					0x76	//RESERVED from 0x76 to 0x77
#define REG_FIFO_DATA_OUT_TAG			0x78
#define REG_FIFO_DATA_OUT_X_L			0x79
#define REG_FIFO_DATA_OUT_X_H			0x7A
#define REG_FIFO_DATA_OUT_Y_L			0x7B
#define REG_FIFO_DATA_OUT_Y_H			0x7C
#define REG_FIFO_DATA_OUT_Z_L			0x7D
#define REG_FIFO_DATA_OUT_Z_H			0x7E

/********************        Bit definition for REG_CTRL1_XL       ********************/
#define CTRL1_XL_ODR_XL(x) 				((x & 0x0F) << 4)
#define CTRL1_XL_FS_XL(x)				((x & 0x03) << 2)
#define CTRL1_XL_LPF2_XL_EN 			(1 << 1)

/********************          Bit definition for CTRL2_G          ********************/
#define CTRL2_G_ODR_G(x)				((x & 0x0F) << 4)
#define CTRL2_G_FS_G(x)					((x & 0x03) << 2)
#define CTRL2_G_FS_125					(1 << 1)


/********************              LSM6DSOX WRITE/READ             ********************/
#define READ_CMD 						0x80
#define WRITE_CMD						0x00



/********************               Internal buffers               ********************/
#define MAX_SPI_FRAME_LENGTH			30	
static uint8_t txbuf[MAX_SPI_FRAME_LENGTH] = {0};
static uint8_t rxbuf[MAX_SPI_FRAME_LENGTH] = {0};


/********************                   Constants                  ********************/
#define STANDARD_GRAVITY   				9.80665f
#define INT16_MAX_VALUE 				32768.0f

#define GYRO_SCALE_TO_DPS(scale)		((scale + 1) * 250)
#define ACCEL_SCALE_TO_REG(scale)		(scale >> 5)
#define ACCEL_SCALE_TO_G(scale)			(scale & 0x1F)

/********************              Internal functions              ********************/

msg_t _lsm6dsox_write_reg(lsm6dsox_device_t* imu, uint8_t reg, uint8_t val){

	txbuf[0] = reg | WRITE_CMD;
	txbuf[1] = val;

	spiAcquireBus(imu->spid);
	spiStart(imu->spid, imu->spi_cfg);
	spiSelect(imu->spid);
	spiExchange(imu->spid, 2, txbuf, rxbuf);
	spiUnselect(imu->spid);
	spiReleaseBus(imu->spid);

	return MSG_OK;
}

msg_t _lsm6dsox_read_reg(lsm6dsox_device_t* imu, uint8_t reg){

	txbuf[0] = reg | READ_CMD;

	spiAcquireBus(imu->spid);
	spiStart(imu->spid, imu->spi_cfg);
	spiSelect(imu->spid);
	spiExchange(imu->spid, 2, txbuf, rxbuf);
	spiUnselect(imu->spid);
	spiReleaseBus(imu->spid);

	return MSG_OK;
}

msg_t _lsm6dsox_read_reg_multi(lsm6dsox_device_t* imu, uint8_t reg, uint8_t len){
	
	txbuf[0] = reg | READ_CMD;

	if(len >= MAX_SPI_FRAME_LENGTH){
		return MSG_RESET;
	}

	spiAcquireBus(imu->spid);
	spiStart(imu->spid, imu->spi_cfg);
	spiSelect(imu->spid);
	spiExchange(imu->spid, 1 + len, txbuf, rxbuf);
	spiUnselect(imu->spid);
	spiReleaseBus(imu->spid);

	return MSG_OK;
}

/********************               Public functions               ********************/

msg_t lsm6dsox_configure(lsm6dsox_device_t* imu){

	_lsm6dsox_write_reg(imu, REG_CTRL2_G, CTRL2_G_ODR_G(imu->cfg->gyro_freq) | CTRL2_G_FS_G(imu->cfg->gyro_scale));

	_lsm6dsox_write_reg(imu, REG_CTRL1_XL, CTRL1_XL_ODR_XL(imu->cfg->accel_freq) | CTRL1_XL_FS_XL(ACCEL_SCALE_TO_REG(imu->cfg->accel_scale)));

	imu->gyro_raw_to_rad_s = (GYRO_SCALE_TO_DPS(imu->cfg->gyro_scale)) * M_PI / (INT16_MAX_VALUE * 180);
	imu->accel_raw_to_m_ss = (ACCEL_SCALE_TO_G(imu->cfg->accel_scale) * STANDARD_GRAVITY) / INT16_MAX_VALUE;

	return MSG_OK;
}

msg_t lsm6dsox_read_raw_data(lsm6dsox_device_t* imu, lsm6dsox_data_t* data){
	_lsm6dsox_read_reg_multi(imu, REG_OUTX_L_G, 12);

	data->rate_raw[LSM6DSOX_X_AXIS]			= (int16_t)(rxbuf[1] | rxbuf[2]<<8);
	data->rate_raw[LSM6DSOX_Y_AXIS]			= (int16_t)(rxbuf[3] | rxbuf[4]<<8);
	data->rate_raw[LSM6DSOX_Z_AXIS]			= (int16_t)(rxbuf[5] | rxbuf[6]<<8);
	data->acceleration_raw[LSM6DSOX_X_AXIS]	= (int16_t)(rxbuf[7] | rxbuf[8]<<8);
	data->acceleration_raw[LSM6DSOX_Y_AXIS]	= (int16_t)(rxbuf[9] | rxbuf[10]<<8);
	data->acceleration_raw[LSM6DSOX_Z_AXIS]	= (int16_t)(rxbuf[11] | rxbuf[12]<<8);

	return MSG_OK;
}

msg_t lsm6dsox_read_converted_data(lsm6dsox_device_t* imu, lsm6dsox_data_t* data){

	lsm6dsox_read_raw_data(imu, data);

	data->rate_rad[LSM6DSOX_X_AXIS]			= data->rate_raw[LSM6DSOX_X_AXIS] * imu->gyro_raw_to_rad_s;
	data->rate_rad[LSM6DSOX_Y_AXIS]			= data->rate_raw[LSM6DSOX_Y_AXIS] * imu->gyro_raw_to_rad_s;
	data->rate_rad[LSM6DSOX_Z_AXIS]			= data->rate_raw[LSM6DSOX_Z_AXIS] * imu->gyro_raw_to_rad_s;
	data->acceleration_ms2[LSM6DSOX_X_AXIS]	= data->acceleration_raw[LSM6DSOX_X_AXIS] * imu->accel_raw_to_m_ss;
	data->acceleration_ms2[LSM6DSOX_Y_AXIS]	= data->acceleration_raw[LSM6DSOX_Y_AXIS] * imu->accel_raw_to_m_ss;
	data->acceleration_ms2[LSM6DSOX_Z_AXIS]	= data->acceleration_raw[LSM6DSOX_Z_AXIS] * imu->accel_raw_to_m_ss;

	return MSG_OK;
}



