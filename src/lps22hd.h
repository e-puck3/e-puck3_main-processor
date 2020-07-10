/**
 * @file	lps22hd.h
 * @brief  	Low level driver for a lsm6dsox pressure sensore connected with SPI
 * 
 * @written by  	Eliot Ferragni
 * @creation date	10.07.2020
 */

#ifndef LPS22HD_H
#define LPS22HD_H

#include "hal.h"

/********************        LSM6DSOX CONFIGURATION OPTIONS        ********************/


/********************       LSM6DSOX CONFIGURATION STRUCTURES      ********************/

typedef struct{

}lps22hd_conf_t;

typedef struct{
	SPIDriver*					spid;
	const SPIConfig* 			spi_cfg;
	const lps22hd_conf_t* 		cfg;
	ioline_t 					int1_line;

}lps22hd_device_t;

/********************           LSM6DSOX DATA STRUCTURES           ********************/

typedef struct{

}lps22hd_data_t;

/********************               Public functions               ********************/

/**
 * @brief Configures the given lsm6dsox device
 * 
 * @param imu 	lsm6dsox_device_t pointer
 * @return 		MSG_OK if no error occurred
 */
msg_t lps22hd_configure(lps22hd_device_t* imu);

/**
 * @brief 	Reads new data from the given lps22hd device
 * 			No conversion done. Only the raw data fields are filled
 * 
 * @param imu 	lps22hd_device_t pointer
 * @param data 	lps22hd_data_t pointer to store the new data
 * 
 * @return 		MSG_OK if no error occurred
 */
msg_t lps22hd_read_raw_data(lps22hd_device_t* imu, lps22hd_data_t* data);

/**
 * @brief 	Reads new data from the given lps22hd device
 * 			A conversion is done. All the fields are filled
 * 
 * @param imu 	lps22hd_device_t pointer
 * @param data 	lps22hd_data_t pointer to store the new data
 * 
 * @return 		MSG_OK if no error occurred
 */
msg_t lps22hd_read_converted_data(lps22hd_device_t* imu, lps22hd_data_t* data);
#endif /* LPS22HD_H */
