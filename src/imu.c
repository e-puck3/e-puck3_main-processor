/**
 * @file	imu.c
 * @brief  	High level driver for an IMU
 * 
 * @written by  	Eliot Ferragni
 * @creation date	09.07.2020
 */
 
#include "ch.h"
#include "hal.h"
#include "lsm6dsox.h"
#include "imu.h"

/*
 * Maximum speed SPI configuration (13.5MHz, CPHA=0, CPOL=0, MSb first, 8bits) from APB1 54MHz.
 */
static const SPIConfig spicfg_imu = {
  false,
  NULL,
  LINE_SPI2_CS_N_IMU,
  SPI_CR1_BR_0,   // clk/4
  SPI_CR2_DS_2 | SPI_CR2_DS_1 | SPI_CR2_DS_0	//8bits
};

static const lsm6dsox_conf_t imu_cfg = {
	.gyro_freq		= LSM6DSOX_GYRO_6_66_KHZ,
	.gyro_scale		= LSM6DSOX_GYRO_2000_DPS,
	.accel_freq		= LSM6DSOX_ACCEL_6_66_KHZ,
	.accel_scale	= LSM6DSOX_ACCEL_2G
};

static lsm6dsox_device_t lsm6dsox = {
	.spid			= &SPI_IMU,
	.spi_cfg		= &spicfg_imu,
	.cfg 			= &imu_cfg,
	.int1_line 		= LINE_IMU_INT1,
	.int2_line 		= LINE_IMU_INT2,
};

static lsm6dsox_data_t lsm6dsox_data;

static THD_WORKING_AREA(waIMU,128);
static THD_FUNCTION(thdIMU,arg) {
	(void)arg;
	chRegSetThreadName("IMU");

	lsm6dsox_configure(&lsm6dsox);

	while(true){
		
		lsm6dsox_read_converted_data(&lsm6dsox, &lsm6dsox_data);

		//the sensor is configured to output ODR/2 Hz for accelerometer
		//and 1442 Hz for gyroscope -> ~1ms refresh rate
		chThdSleepMilliseconds(1);
		
	}
}

void imu_start(void){
	chThdCreateStatic(waIMU, sizeof(waIMU), NORMALPRIO, thdIMU, NULL);
}

void imu_get_data(imu_data_t* data){
	static uint8_t i = 0;

	for(i = 0 ; i < IMU_NB_AXIS ; i++){
		data->rate_raw[i] 			= lsm6dsox_data.rate_raw[i];
		data->rate_rad[i]			= lsm6dsox_data.rate_rad[i];
		data->acceleration_raw[i]	= lsm6dsox_data.acceleration_raw[i];
		data->acceleration_ms2[i]	= lsm6dsox_data.acceleration_ms2[i];
	}
}




