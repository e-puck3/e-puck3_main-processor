/**
 * @file	distance_sensor.h
 * @brief  	High level driver for a distance sensor
 * 
 * @written by  	Eliot Ferragni
 * @creation date	10.07.2020
 */

#ifndef DISTANCE_SENSOR_H
#define DISTANCE_SENSOR_H

#include "hal.h"

#define I2C_DISTANCE_SENSOR I2CD1

/********************              DISTANCE SENSOR DATA STRUCTURES             ********************/

typedef struct{

}distance_data_t;

/********************               Public functions               ********************/

/**
 * @brief Starts the IMU thread
 */
void distance_sensor_start(void);

/**
 * @brief Gets the last data
 * 
 * @param data distance_sensor_data_t pointer to store the data
 */
void distance_sensor_get_data(imu_data_t* data);
#endif /* DISTANCE_SENSOR_H */
