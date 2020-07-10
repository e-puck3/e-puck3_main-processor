/**
 * @file	imu.h
 * @brief  	High level driver for an IMU
 * 
 * @written by  	Eliot Ferragni
 * @creation date	09.07.2020
 */

#ifndef IMU_H
#define IMU_H

#include "hal.h"

#define SPI_IMU SPID2

/********************              IMU DATA STRUCTURES             ********************/

typedef enum{
	IMU_X_AXIS			= 0,
	IMU_Y_AXIS,
	IMU_Z_AXIS,
	IMU_NB_AXIS
}imu_axis_t;

typedef struct{
	int16_t			rate_raw[IMU_NB_AXIS];				// raw rates values
	float			rate_rad[IMU_NB_AXIS];				// rates values in rad/s
	int16_t			acceleration_raw[IMU_NB_AXIS];		// raw accelerations values
	float			acceleration_ms2[IMU_NB_AXIS];		// accelerations values in m/s^2
}imu_data_t;

/********************               Public functions               ********************/

/**
 * @brief Starts the IMU thread
 */
void imu_start(void);

/**
 * @brief Gets the last data
 * 
 * @param data imu_data_t pointer to store the data
 */
void imu_get_data(imu_data_t* data);
#endif /* IMU_H */
