/**
 * @file	uart_cmd.h
 * @brief  	Manages the uart_cmd transmission between the f746 and the f779
 * 
 * @written by  	Eliot Ferragni
 * @creation date	06.08.2020
 */

#ifndef UART_CMD_H
#define UART_CMD_H

#define UART_CMD_PORT 	SD3

typedef struct{
	float	vbus;
	float	battery;
	float	temperature;
}voltage_measurement_t;

typedef struct{
	float	actual_duty_cycle;
	float	rpm;
}motor_telemetry_t;

/**
 * Brushless motors list from motors.h of e-puck3_programmer
 */
typedef enum
{
    BRUSHLESS_MOTOR_1 = 0,
    BRUSHLESS_MOTOR_2,
    BRUSHLESS_MOTOR_3,
    BRUSHLESS_MOTOR_4,
    NB_OF_BRUSHLESS_MOTOR,
}brushless_motors_names_t;


/**
 * @brief Starts the uart cmd threads
 */
void uartCmdStart(void);

/**
 * @brief 	Gets the measurements values and put them into the 
 * 			voltage_measurement_t* pointer given.
 * 
 * @param measurements Pointer to the voltage_measurement_t structure to fill
 */	
void voltageMesurementGet(voltage_measurement_t* measurements);

/**
 * @brief               Changes the duty cycle of the given motor. The duty cycle is internally
 *                      changed with a ramp.
 * 
 * @param motor_id	    Motor to change the duty cycle. See brushless_motors_names_t
 * @param duty_cycle    Duty cycle to apply. Between 0 and 100.
 */
void motorSetDutyCycle(brushless_motors_names_t motor_id, uint8_t duty_cycle);

/**
 * @brief 	Gets the telemetry of the available motor and stores it in the 
 * 			motor_telemetry_t* pointer given.
 * 
 * @param motor_id	    Motor to get the telemetry from. See brushless_motors_names_t
 * @param telemetry 	Pointer to the motor_telemetry_t structure to fill
 */	
void motorGetTelemetry(brushless_motors_names_t motor_id, motor_telemetry_t* telemetry);




#endif  /* UART_CMD_H */