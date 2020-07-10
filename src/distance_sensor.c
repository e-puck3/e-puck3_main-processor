/**
 * @file	distance_sensor.c
 * @brief  	High level driver for a distance sensor
 * 
 * @written by  	Eliot Ferragni
 * @creation date	10.07.2020
 */
 
#include "ch.h"
#include "hal.h"
#include "vl53l1_api.h"
#include "distance_sensor.h"

/*
 * I2C configuration object.
 * I2C2_TIMINGR: 1 MHz with I2CCLK = 216 MHz, rise time = 0 ns,
 *               fall time = 0 ns (0x00A02B91)
 */
static const I2CConfig i2c2config_vl53l1 = {
    .timingr    = 0x00A02B91,
    .cr1        = 0,
    .cr2        = 0,
};
static VL53L1_Dev_t vl53l1_dev;

/********************              Internal functions              ********************/

static void _configure(void){

}


static THD_WORKING_AREA(waDistanceSensor,128);
static THD_FUNCTION(thdDistanceSensor,arg) {
	(void)arg;
	chRegSetThreadName("Distance Sensor");

	

	while(true){
		
		


		chThdSleepMilliseconds(1);
		
	}
}

void distance_sensor_start(void){
	chThdCreateStatic(waDistanceSensor, sizeof(waDistanceSensor), NORMALPRIO, thdDistanceSensor, NULL);
}

void distance_sensor_get_data(distance_data_t* data){
	
}




