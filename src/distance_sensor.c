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

#define MIN_VALID_DISTANCE_MM 		40
#define MAX_VALID_DISTANCE_MM 		1500

static distance_sensor_data_t _distance_data;

/********************              Internal functions              ********************/

// Uncomment to compile with i2c tests functions
// #define I2C_TEST

#ifdef I2C_TEST
#include "chprintf"
static int _rd_write_verification( VL53L1_Dev_t *dev, uint16_t addr, uint32_t expected_value)
{
	VL53L1_Error Status  = VL53L1_ERROR_NONE;
	uint8_t bytes[4],mbytes[4];
	uint16_t words[2];
	uint32_t dword;
	int i;
	VL53L1_ReadMulti(dev, addr, mbytes, 4);
	for (i=0; i<4; i++){ VL53L1_RdByte(dev, addr+i, &bytes[i]); }
	for (i=0; i<2; i++){ VL53L1_RdWord(dev, addr+i*2, &words[i]); }
	Status = VL53L1_RdDWord(dev, addr, &dword);
	
	chprintf((BaseSequentialStream *)&SD5, "expected   = %8x,\r\n",expected_value);
	chprintf((BaseSequentialStream *)&SD5, "read_multi = %2x, %2x, %2x, %2x\r\n", mbytes[0],mbytes[1],mbytes[2],mbytes[3]);
	chprintf((BaseSequentialStream *)&SD5, "read_bytes = %2x, %2x, %2x, %2x\r\n", bytes[0],bytes[1],bytes[2],bytes[3]);
	chprintf((BaseSequentialStream *)&SD5, "read words = %4x, %4x\r\n",words[0],words[1]);
	chprintf((BaseSequentialStream *)&SD5, "read dword = %8x\r\n",dword);
	
	if((mbytes[0]<<24 | mbytes[1]<<16 | mbytes[2]<<8 | mbytes[3]) != expected_value) return (1);
	if((bytes[0]<<24 | bytes[1]<<16 | bytes[2]<<8 | bytes[3]) != expected_value) return (2);
	if((words[0]<<16 | words[1]) != expected_value) return (3);
	if(dword != expected_value) return(4);
	return Status;
	
}
#define REG 0x3A
static void _i2c_test(VL53L1_Dev_t *dev)
{
	VL53L1_Error Status  = VL53L1_ERROR_NONE;
	VL53L1_Error Status2  = VL53L1_ERROR_NONE;
	int err_count = 0;
	static uint8_t buff[4] = {0x11,0x22,0x33,0x44};
	static uint8_t long_out[135] ={0x29, 0x02, 0x10, 0x00, 0x22, 0xBC, 0xCC, 0x81, 0x80, 0x07, 0x16, 0x00, 0xFF, 0xFD,
							0xF7, 0xDE, 0xFF, 0x0F, 0x00, 0x15, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
							0x44, 0x00, 0x2C, 0x00, 0x11, 0x0A, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
							0x00, 0x11, 0x02, 0x00, 0x02, 0x08, 0x00, 0x08, 0x10, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0xFF,
							0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x0B, 0x00, 0x00, 0x02, 0x14, 0x21, 0x00, 0x00,
							0x02, 0x00, 0x00, 0x00, 0x00, 0xC8, 0x00, 0x00, 0x38, 0xFF, 0x01, 0x00, 0x01, 0x00, 0x02, 0x00,
							0x9D, 0x07, 0x00, 0xD2, 0x05, 0x01, 0x68, 0x00, 0xC0, 0x08, 0x38, 0x00, 0x00, 0x00, 0x00, 0x03,
							0xB6, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x07, 0x05, 0x06, 0x06, 0x01, 0x00, 0x02,
							0xC7, 0xFF, 0x8B, 0x00, 0x00, 0x00, 0x01, 0x01, 0x40};
	static uint8_t long_in[135]= {0xff};
  	int i=0;

	Status = _rd_write_verification(dev, 0x010f, 0xeacc10ff);			// verify the Chip ID works
	chprintf((BaseSequentialStream *)&SD5, "read 0xeacc10ff %d\r\n", Status);

	Status = VL53L1_WriteMulti(dev, 0x0001,  long_out, 135);			// check if WriteMulti can write 135 bytes
	chprintf((BaseSequentialStream *)&SD5, "WriteMulti %d\r\n", Status);
	Status = VL53L1_ReadMulti(dev, 0x0001,  long_in, 135);			// check if WriteMulti can read 135 bytes
	chprintf((BaseSequentialStream *)&SD5, "ReadMulti %d\r\n", Status);

	for (i=0; i<135; i++) if(long_in[i] != long_out[i])err_count++;

	for(uint16_t j = 0 ; j < 135 ; j++){
		chprintf((BaseSequentialStream *)&SD5, "%d %x %x\r\n", j, long_out[j], long_in[j]);
	}
	chprintf((BaseSequentialStream *)&SD5, "err_count %d\r\n", err_count);

	Status = VL53L1_WriteMulti(dev, REG,  buff, 4);				// check WriteMulti
	chprintf((BaseSequentialStream *)&SD5, "write 0x11223344 %d\r\n", Status);
	Status = _rd_write_verification(dev, REG, 0x11223344);
	chprintf((BaseSequentialStream *)&SD5, "read 0x11223344 %d\r\n", Status);

	Status = VL53L1_WrDWord(dev, REG, 0xffeeddcc);				// check WrDWord
	chprintf((BaseSequentialStream *)&SD5, "write 0xffeeddcc %d\r\n", Status);
	Status = _rd_write_verification(dev, REG, 0xffeeddcc);
	chprintf((BaseSequentialStream *)&SD5, "read 0xffeeddcc %d\r\n", Status);

	Status = VL53L1_WrWord(dev, REG, 0x5566);					// check WrWord
	Status2 = VL53L1_WrWord(dev, REG+2, 0x7788);
	chprintf((BaseSequentialStream *)&SD5, "write 0x5566 7788 %d %d\r\n", Status, Status2);
	_rd_write_verification(dev, REG, 0x55667788);
	chprintf((BaseSequentialStream *)&SD5, "read 0x55667788 %d\r\n", Status);

	for (i=0; i<4; i++){ VL53L1_WrByte (dev, REG+i, buff[i]); }
	chprintf((BaseSequentialStream *)&SD5, "write 0x11 22 33 44\r\n");
	Status = _rd_write_verification(dev, REG,0x11223344);
	chprintf((BaseSequentialStream *)&SD5, "read 0x1122334 %d\r\n", Status);
}
#endif /* I2C_TEST */

static void _configure(VL53L1_Dev_t* dev){

	//Reset
	palClearLine(LINE_EN_TOF);
	chThdSleepMilliseconds(10);
	palSetLine(LINE_EN_TOF);
	chThdSleepMilliseconds(10);

	VL53L1_WaitDeviceBooted(dev);
	VL53L1_DataInit(dev);

	VL53L1_StaticInit(dev);
	VL53L1_SetPresetMode(dev, VL53L1_PRESETMODE_LITE_RANGING);
	VL53L1_SetDistanceMode(dev, VL53L1_DISTANCEMODE_SHORT);
	VL53L1_SetMeasurementTimingBudgetMicroSeconds(dev, 20000);
	// VL53L1_SetInterMeasurementPeriodMilliSeconds(dev, 100);
	VL53L1_StartMeasurement(dev);
}


static THD_WORKING_AREA(waDistanceSensor,1024);
static THD_FUNCTION(thdDistanceSensor,arg) {
	(void)arg;
	chRegSetThreadName("Distance Sensor");

	static VL53L1_RangingMeasurementData_t RangingData;
	int8_t status;
	uint8_t first_time = 1;

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

	static VL53L1_Dev_t vl53l1_dev = {
		.I2cHandle 	= &I2C_DISTANCE_SENSOR,
		.I2cDevAddr = 0x52, //8bit address
	};

	// I2C config
	i2cStart(vl53l1_dev.I2cHandle, &i2c2config_vl53l1);

	_configure(&vl53l1_dev);

	while(true){
		
		status = VL53L1_WaitMeasurementDataReady(&vl53l1_dev); // polls at 1ms
		if(status == VL53L1_ERROR_NONE){

			if(first_time){
				VL53L1_ClearInterruptAndStartMeasurement(&vl53l1_dev);
				first_time = 0;
			}else{
				VL53L1_GetRangingMeasurementData(&vl53l1_dev, &RangingData);
				VL53L1_ClearInterruptAndStartMeasurement(&vl53l1_dev);

				_distance_data.distance_mm = RangingData.RangeMilliMeter;
				if(_distance_data.distance_mm < MIN_VALID_DISTANCE_MM || _distance_data.distance_mm > MAX_VALID_DISTANCE_MM){
					_distance_data.valid = false;
				}
				else{
					_distance_data.valid = true;
				}
				_distance_data.timestamp = chVTGetSystemTime();
			}
		}
		
	}
}

/********************               Public functions               ********************/

void distance_sensor_start(void){
	chThdCreateStatic(waDistanceSensor, sizeof(waDistanceSensor), NORMALPRIO, thdDistanceSensor, NULL);
}

void distance_sensor_get_data(distance_sensor_data_t* data){
	data->distance_mm 	= _distance_data.distance_mm;
	data->valid 		= _distance_data.valid;
	data->timestamp 	= _distance_data.timestamp;
}




