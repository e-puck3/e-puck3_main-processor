/**
 * @file	lps22hd.h
 * @brief  	Low level driver for a lps22hd pressure sensore connected with SPI
 * 
 * @written by  	Eliot Ferragni
 * @creation date	10.07.2020
 */

#ifndef LPS22HD_H
#define LPS22HD_H

#include "hal.h"

/********************         LPS22HD CONFIGURATION OPTIONS        ********************/

typedef enum{
	LPS22HD_POWER_DOWN	= 0x00,
	LPS22HD_1_HZ 		= 0x01,
	LPS22HD_10_HZ		= 0x02,
	LPS22HD_25_HZ 		= 0x03,
	LPS22HD_50_HZ		= 0x04,
	LPS22HD_75_HZ		= 0x05
}lps22hd_freq_t;

/********************       LPS22HD CONFIGURATION STRUCTURES       ********************/

typedef struct{
	lps22hd_freq_t 		freq;
}lps22hd_conf_t;

typedef struct{
	SPIDriver*					spid;
	const SPIConfig* 			spi_cfg;
	const lps22hd_conf_t* 		cfg;
	ioline_t 					int_line;

}lps22hd_device_t;

/********************            LPS22HD DATA STRUCTURES           ********************/

typedef struct{
	int32_t						pressure_raw;		// raw pressure
	float						pressure_hpa;		// pressure in hPa
	int16_t						temperature_raw;	// raw temperature
	float						temperature_deg_c;	// temperature in °C
}lps22hd_data_t;

/********************               Public functions               ********************/

/**
 * @brief Configures the given lps22hd device
 * 
 * @param dev 	lps22hd_device_t pointer
 * @return 		MSG_OK if no error occurred
 */
msg_t lps22hd_configure(lps22hd_device_t* dev);

/**
 * @brief 	Reads new data from the given lps22hd device
 * 			No conversion done. Only the raw data fields are filled
 * 
 * @param dev 	lps22hd_device_t pointer
 * @param data 	lps22hd_data_t pointer to store the new data
 * 
 * @return 		MSG_OK if no error occurred
 */
msg_t lps22hd_read_raw_data(lps22hd_device_t* dev, lps22hd_data_t* data);

/**
 * @brief 	Reads new data from the given lps22hd device
 * 			A conversion is done. All the fields are filled
 * 
 * @param dev 	lps22hd_device_t pointer
 * @param data 	lps22hd_data_t pointer to store the new data
 * 
 * @return 		MSG_OK if no error occurred
 */
msg_t lps22hd_read_converted_data(lps22hd_device_t* dev, lps22hd_data_t* data);
#endif /* LPS22HD_H */
