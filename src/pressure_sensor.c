/**
 * @file	pressure_sensor.c
 * @brief  	High level driver for a pressure sensor
 * 
 * @written by  	Eliot Ferragni
 * @creation date	10.07.2020
 */
 
#include "ch.h"
#include "hal.h"
#include "lps22hd.h"
#include "pressure_sensor.h"

static lps22hd_data_t _lps22hd_data;

static THD_WORKING_AREA(waPressureSensor,128);
static THD_FUNCTION(thdPressureSensor,arg) {
	(void)arg;
	chRegSetThreadName("Pressure Sensor");

	/*
	 * Maximum speed SPI configuration (13.5MHz, CPHA=0, CPOL=0, MSb first, 8bits) from APB1 54MHz.
	 */
	static const SPIConfig spicfg_pressure_sensor = {
	  false,
	  NULL,
	  LINE_SPI2_CS_N_PRESS,
	  SPI_CR1_BR_0,   // clk/4
	  SPI_CR2_DS_2 | SPI_CR2_DS_1 | SPI_CR2_DS_0	//8bits
	};

	static const lps22hd_conf_t pressure_sensor_cfg = {
		.freq		= LPS22HD_75_HZ,
	};

	static lps22hd_device_t lps22hd = {
		.spid			= &SPI_PRESSURE_SENSOR,
		.spi_cfg		= &spicfg_pressure_sensor,
		.cfg 			= &pressure_sensor_cfg,
		.int_line 		= LINE_PRESS_INT,
	};

	lps22hd_configure(&lps22hd);

	while(true){
		
		lps22hd_read_converted_data(&lps22hd, &_lps22hd_data);

		//the sensor is configured to output ODR/2 Hz -> ~27ms refresh rate
		chThdSleepMilliseconds(27);
		
	}
}

void pressure_sensor_start(void){
	chThdCreateStatic(waPressureSensor, sizeof(waPressureSensor), NORMALPRIO, thdPressureSensor, NULL);
}

void pressure_sensor_get_data(pressure_sensor_data_t* data){

	data->pressure_raw 			= _lps22hd_data.pressure_raw;
	data->pressure_hpa			= _lps22hd_data.pressure_hpa;
	data->temperature_raw		= _lps22hd_data.temperature_raw;
	data->temperature_deg_c		= _lps22hd_data.temperature_deg_c;
}




