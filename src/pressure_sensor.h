/**
 * @file	pressure_sensor.h
 * @brief  	High level driver for a pressure sensor
 * 
 * @written by  	Eliot Ferragni
 * @creation date	10.07.2020
 */

#ifndef PRESSURE_SENSOR
#define PRESSURE_SENSOR

#include "hal.h"

#define SPI_PRESSURE_SENSOR SPID2

/********************        PRESSURE SENSOR DATA STRUCTURES       ********************/

typedef struct{
	int32_t						pressure_raw;		// raw pressure
	float						pressure_hpa;		// pressure in hPa
	int16_t						temperature_raw;	// raw temperature
	float						temperature_deg_c;	// temperature in °C
}pressure_sensor_data_t;

/********************               Public functions               ********************/

/**
 * @brief Starts the IMU thread
 */
void pressure_sensor_start(void);

/**
 * @brief Gets the last data
 * 
 * @param data pressure_sensor_data_t pointer to store the data
 */
void pressure_sensor_get_data(pressure_sensor_data_t* data);
#endif /* PRESSURE_SENSOR */
