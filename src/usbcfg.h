/*
    ChibiOS - Copyright (C) 2006..2018 Giovanni Di Sirio

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and
    limitations under the License.
*/

/**
 * @modified by        Eliot Ferragni
 * @last modification  27.02.2019
 */
#include "ch.h"
#include "hal.h"

#ifndef USBCFG_H
#define USBCFG_H

/*  Comment if you only want to have one USB serial port. 
    You can't have two serial ports
    if you don't have enough endpoints to run them
    (we need 2 IN endpoints and 1 OUT endpoints for each serial port)
*/
#define USE_TWO_USB_FS_SERIAL
#define USE_TWO_USB_HS_SERIAL

//power asked to the computer in 2mA increment (min 100mA, max 500mA)
#define USB_POWER              50          //(100mA)

#define USB_DEVICE_VID      0x1D50
#define USB_DEVICE_PID      0x6018
#define USB_VENDOR_NAME     "EPFL"
#define USB_DEVICE_NAME     "E-PUCK3 MAIN PROCESSOR"

#define USB_FS_SERIAL_NUMBER   "EPUCK3FS"
#define USB_FS_SERIAL1_NAME    "Serial FS 1"
#ifdef USE_TWO_USB_FS_SERIAL
#define USB_FS_SERIAL2_NAME    "Serial FS 2"
#endif /* USE_TWO_USB_FS_SERIAL */

#define USB_HS_SERIAL_NUMBER   "EPUCK3HS"
#define USB_HS_SERIAL1_NAME    "Serial HS 1"
#ifdef USE_TWO_USB_HS_SERIAL
#define USB_HS_SERIAL2_NAME    "Serial HS 2"
#endif /* USE_TWO_USB_HS_SERIAL */

#define USB_FS_SERIAL_1          SDUFS1
#ifdef USE_TWO_USB_FS_SERIAL
#define USB_FS_SERIAL_2          SDUFS2
#endif /* USE_TWO_USB_FS_SERIAL */

#define USB_HS_SERIAL_1          SDUHS1
#ifdef USE_TWO_USB_HS_SERIAL
#define USB_HS_SERIAL_2          SDUHS2
#endif /* USE_TWO_USB_HS_SERIAL */

typedef enum{
    SERIAL_1_INTERFACE = 0,
    SERIAL_2_INTERFACE,
    NUM_INTERFACES,
}interface_name_t;

typedef enum{
    CONTROL_LINE_RTS = 0,
    CONTROL_LINE_DTR,
    NUM_CONTROL_LINE,
}control_line_t;

#define USB_FS_DATA_SIZE                   0x40
#define USB_HS_DATA_SIZE                   0x200

extern SerialUSBDriver SDUFS1;
#ifdef USE_TWO_USB_FS_SERIAL
extern SerialUSBDriver SDUFS2;
#endif /* USE_TWO_USB_FS_SERIAL */

extern SerialUSBDriver SDUHS1;
#ifdef USE_TWO_USB_HS_SERIAL
extern SerialUSBDriver SDUHS2;
#endif /* USE_TWO_USB_FS_SERIAL */

/*
* Initializes two serial-over-USB CDC drivers and starts and connects the USB.
*/
void usbFSSerialStart(void);
void usbHSSerialStart(void);

/**
 * @brief Returns if the USB is configured or not
 * @return 1 or 0
 */
uint8_t isUSBFSConfigured(void);
uint8_t isUSBHSConfigured(void);

/**
 * @brief   Returns the state of the selected control line of the selected interface
 * 
 * @param interface     See interface_name_t
 * @param rts_dtr       See control_line_object_t
 * 
 * @return              The state desired
 */
uint8_t getControlLineStateFS(interface_name_t interface, control_line_t rts_dtr);
uint8_t getControlLineStateHS(interface_name_t interface, control_line_t rts_dtr);

#endif  /* USBCFG_H */

/** @} */
