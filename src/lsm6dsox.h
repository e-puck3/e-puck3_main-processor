/**
 * @file	lsm6dsox.h
 * @brief  	Low level driver for a lsm6dsox IMU conencted with SPI
 * 
 * @written by  	Eliot Ferragni
 * @creation date	09.07.2020
 */

#ifndef LSM6DSOX_H
#define LSM6DSOX_H

typedef enum{
	// only valid if G_HM_MODE = 0 in CTRL_7_G (16h) (default value)
	LSM6DSOX_GYRO_POWER_DOWN	= 0x00
	LSM6DSOX_GYRO_12_5_HZ		= 0x01,	// 12.5 Hz
	LSM6DSOX_GYRO_26_HZ			= 0x02,	// 26 Hz
	LSM6DSOX_GYRO_52_HZ			= 0x03, // 52 Hz
	LSM6DSOX_GYRO_104_HZ		= 0x04, // 104 Hz
	LSM6DSOX_GYRO_208_HZ		= 0x05, // 208 Hz
	LSM6DSOX_GYRO_416_HZ		= 0x06, // 416 Hz
	LSM6DSOX_GYRO_833_HZ		= 0x07, // 833 Hz
	LSM6DSOX_GYRO_1_66_KHZ		= 0x08, // 1.66 KHz
	LSM6DSOX_GYRO_3_33_KHZ		= 0x09, // 3.33 KHz
	LSM6DSOX_GYRO_6_66_KHZ		= 0x0A, // 6.66 KHz
}lsm6dsox_gyro_freq_t;

typedef enum{
	LSM6DSOX_GYRO_250_DPS		= 0x00,
	LSM6DSOX_GYRO_500_DPS		= 0x01,
	LSM6DSOX_GYRO_1000_DPS		= 0x02,
	LSM6DSOX_GYRO_2000_DPS		= 0x03,
}lsm6dsox_gyro_scale_t;

typedef enum{
	// only valid if XL_HM_MODE = 0 in CTRL_6_C (15h) (default value)
	LSM6DSOX_ACCEL_POWER_DOWN	= 0x00
	LSM6DSOX_ACCEL_12_5_HZ		= 0x01,	// 12.5 Hz
	LSM6DSOX_ACCEL_26_HZ		= 0x02,	// 26 Hz
	LSM6DSOX_ACCEL_52_HZ		= 0x03, // 52 Hz
	LSM6DSOX_ACCEL_104_HZ		= 0x04, // 104 Hz
	LSM6DSOX_ACCEL_208_HZ		= 0x05, // 208 Hz
	LSM6DSOX_ACCEL_416_HZ		= 0x06, // 416 Hz
	LSM6DSOX_ACCEL_833_HZ		= 0x07, // 833 Hz
	LSM6DSOX_ACCEL_1_66_KHZ		= 0x08, // 1.66 KHz
	LSM6DSOX_ACCEL_3_33_KHZ		= 0x09, // 3.33 KHz
	LSM6DSOX_ACCEL_6_66_KHZ		= 0x0A, // 6.66 KHz
}lsm6dsox_accel_freq_t;

typedef enum{
	// only valid if XL_FS_MODE = 0 in CTRL_8_XL (17h) (default value)
	LSM6DSOX_ACCEL_2G = 0x00,
	LSM6DSOX_ACCEL_4G = 0x02,
	LSM6DSOX_ACCEL_8G = 0x03,
	LSM6DSOX_ACCEL_16G = 0x01,
}lsm6dsox_accel_scale_t;

typedef struct{
	lsm6dsox_gyro_freq_t	gyro_freq;
	lsm6dsox_gyro_scale_t	gyro_scale;
	lsm6dsox_accel_freq_t	accel_freq;
	lsm6dsox_accel_scale_t	accel_scale;
}lsm6dsox_register_conf_t;

typedef struct{
	SPIDriver*					spid;
	SPIConfig* 					spi_cfg;
	lsm6dsox_register_conf_t* 	reg;
	ioline_t 					cs_line;
	ioline_t 					int1_line;
	ioline_t 					int2_line;
}lsm6dsox_device_t;

typedef enum{
	LSM6DSOX_X_AXIS			= 0,
	LSM6DSOX_Y_AXIS,
	LSM6DSOX_Z_AXIS,
	LSM6DSOX_NB_AXIS
}lsm6dsox_axis_t;

typedef struct{
	int16_t			rate_raw[NB_AXIS];
	float			rate_rad[NB_AXIS];
	int16_t			acceleration_raw[NB_AXIS];
	float			acceleration_g[NB_AXIS];
}lsm6dsox_data_t;
#endif /* LSM6DSOX_H */
