/**
 * @file	uart_cmd.c
 * @brief  	Manages the uart_cmd transmission between the f746 and the f779
 * 
 * @written by  	Eliot Ferragni
 * @creation date	06.08.2020
 */

#include "ch.h"
#include "hal.h"
#include "uart_cmd.h"
#include "serial_datagram.h"
#include "chprintf.h"


/**
 *  Messages payload :
 *  Motor telemetry from programmer : 'T' DT1 RPM1 DT2 RPM2 DT3 RPM3 DT4 RPM4 (DT = duty cycle in float, RPM = rpm in float) => 33 bytes
 *  Voltage measurements from programmer : 'V' VBUS BATTERY TEMPERATURE ( VBUS, BATTERY and TEMPERATURE in float) => 13 bytes
 *  
 *  Motor orders to programmer : 'M' DT1 DT2 DT3 DT4 (DT = duty cycle in uint8_t) => 5 bytes
 */

#define TELEMETRY_MSG_ID        'T'
#define TELEMETRY_MSG_LEN       33
#define VOLTAGE_MSG_ID          'V'
#define VOLTAGE_MSG_LEN         13
#define MOTOR_MSG_ID            'M'
#define MOTOR_MSG_LEN           5

static voltage_measurement_t voltages;
static motor_telemetry_t motors_telemetry[4];

static uint8_t duty_cycle_to_send[4];

static void uart_cmd_cb(const void *message, size_t len, void *arg){
	(void) arg;

    static uint8_t* buffer_8bits;
    static float* buffer_float;

    buffer_8bits = (uint8_t*) message;
    buffer_float = (float*) &buffer_8bits[1];

    // Motors telemetry receiving
    if(buffer_8bits[0] == TELEMETRY_MSG_ID && len == TELEMETRY_MSG_LEN){
        motors_telemetry[BRUSHLESS_MOTOR_1].actual_duty_cycle = buffer_float[0];
        motors_telemetry[BRUSHLESS_MOTOR_1].rpm = buffer_float[1];
        motors_telemetry[BRUSHLESS_MOTOR_2].actual_duty_cycle = buffer_float[2];
        motors_telemetry[BRUSHLESS_MOTOR_2].rpm = buffer_float[3];
        motors_telemetry[BRUSHLESS_MOTOR_3].actual_duty_cycle = buffer_float[4];
        motors_telemetry[BRUSHLESS_MOTOR_3].rpm = buffer_float[5];
        motors_telemetry[BRUSHLESS_MOTOR_4].actual_duty_cycle = buffer_float[6];
        motors_telemetry[BRUSHLESS_MOTOR_4].rpm = buffer_float[7];

        // chprintf((BaseSequentialStream *)&SD5, "motor 1: %f dt and %f rpm \r\n", motors_telemetry[BRUSHLESS_MOTOR_1].actual_duty_cycle, motors_telemetry[BRUSHLESS_MOTOR_1].rpm);
        // chprintf((BaseSequentialStream *)&SD5, "motor 2: %f dt and %f rpm \r\n", motors_telemetry[BRUSHLESS_MOTOR_2].actual_duty_cycle, motors_telemetry[BRUSHLESS_MOTOR_2].rpm);
        // chprintf((BaseSequentialStream *)&SD5, "motor 3: %f dt and %f rpm \r\n", motors_telemetry[BRUSHLESS_MOTOR_3].actual_duty_cycle, motors_telemetry[BRUSHLESS_MOTOR_3].rpm);
        // chprintf((BaseSequentialStream *)&SD5, "motor 4: %f dt and %f rpm \r\n\r\n", motors_telemetry[BRUSHLESS_MOTOR_4].actual_duty_cycle, motors_telemetry[BRUSHLESS_MOTOR_4].rpm);
    }
    // voltage measurements receiving
    else if(buffer_8bits[0] == VOLTAGE_MSG_ID && len == VOLTAGE_MSG_LEN){
        voltages.vbus = buffer_float[0];
        voltages.battery = buffer_float[1];
        voltages.temperature = buffer_float[2];
        // chprintf((BaseSequentialStream *)&SD5, "vbus : %f V, Battery : %f V, Temp : %f °C\r\n\r\n", voltages.vbus, voltages.battery, voltages.temperature);
    }
    // chprintf((BaseSequentialStream *)&SD5, "time: %d dt\r\n\r\n", chVTGetSystemTimeX());
}

/*
 * Thread dedicated to the reading of the frames received
*/
static THD_WORKING_AREA(uart_cmd_rx_wa, 1024);
static THD_FUNCTION(uart_cmd_rx, arg)
{
	chRegSetThreadName("uart_cmd_rx");
	(void)arg;

    serial_datagram_rcv_handler_t rcv_handler;
    char rcv_buffer[100];

    serial_datagram_rcv_handler_init(&rcv_handler,
                                     rcv_buffer,
                                     sizeof(rcv_buffer),
                                     uart_cmd_cb,
                                     NULL);
    uint8_t c;
    while (1) {
        chnReadTimeout((BaseChannel*)&UART_CMD_PORT, &c, 1, TIME_INFINITE);
        serial_datagram_receive(&rcv_handler, &c, 1);
    }
}

/*
 * a simple wrapper to the system write function
*/
static void _stream_values_sndfn(void *arg, const void *p, size_t len)
{
    if (len > 0) {
        chnWrite((BaseSequentialStream*)arg, (const uint8_t*)p, len);
    }
}

/*
 * Thread dedicated to the sending of the frames
*/
static THD_WORKING_AREA(uart_cmd_tx_wa, 1024);
static THD_FUNCTION(uart_cmd_tx, arg)
{
	chRegSetThreadName("uart_cmd_tx");
	(void)arg;

    char send_buf[100];

    char* send_id = send_buf;

    while (1) {
        *send_id = MOTOR_MSG_ID;
        send_buf[1] = duty_cycle_to_send[BRUSHLESS_MOTOR_1];
        send_buf[2] = duty_cycle_to_send[BRUSHLESS_MOTOR_2];
        send_buf[3] = duty_cycle_to_send[BRUSHLESS_MOTOR_3];
        send_buf[4] = duty_cycle_to_send[BRUSHLESS_MOTOR_4];

    	serial_datagram_send(send_buf, MOTOR_MSG_LEN, _stream_values_sndfn, &UART_CMD_PORT);
    	chThdSleepMilliseconds(10);
    }
}


void uartCmdStart(void){
	static const SerialConfig ser_cfg_uart_cmd = {
	    .speed = 27000000,
	    .cr1 = 0,
	    .cr2 = 0,
	    .cr3 = 0,
	};

	sdStart(&UART_CMD_PORT, &ser_cfg_uart_cmd);

	chThdCreateStatic(uart_cmd_tx_wa, sizeof(uart_cmd_tx_wa), NORMALPRIO, uart_cmd_tx, NULL);

	chThdCreateStatic(uart_cmd_rx_wa, sizeof(uart_cmd_rx_wa), NORMALPRIO, uart_cmd_rx, NULL);
}

void voltageMesurementGet(voltage_measurement_t* measurements){
    measurements->vbus = voltages.vbus;
    measurements->battery = voltages.battery;
    measurements->temperature = voltages.temperature;
}

void motorSetDutyCycle(brushless_motors_names_t motor_id, uint8_t duty_cycle){
    if(motor_id > NB_OF_BRUSHLESS_MOTOR){
        return;
    }
    duty_cycle_to_send[motor_id] = duty_cycle;
}

void motorGetTelemetry(brushless_motors_names_t motor_id, motor_telemetry_t* telemetry){
    if(motor_id > NB_OF_BRUSHLESS_MOTOR){
        return;
    }

    telemetry->actual_duty_cycle = motors_telemetry[motor_id].actual_duty_cycle;
    telemetry->rpm = motors_telemetry[motor_id].rpm;
}

void cmd_motor_set_duty_cycle(BaseSequentialStream *chp, int argc, char *argv[])
{
  (void)argv;
  if(argc == 2)
  {
    char *endptr;
    uint8_t motNumber = strtol(argv[0], &endptr, 0);
    float speed = strtol(argv[1], &endptr, 0);

    brushless_motors_names_t motor_id;
    if(motNumber == 1){
      motor_id = 0;
    }else if(motNumber == 2){
      motor_id = 1;
    }else if(motNumber == 3){
      motor_id = 2;
    }else if(motNumber == 4){
      motor_id = 3;
    }else{
      return;
    }
    motorSetDutyCycle(motor_id, speed);

  }
  else
  {
      chprintf(chp, "motor_set_duty_cycle motNumber speed (0-100) \r\n");
  }
}

