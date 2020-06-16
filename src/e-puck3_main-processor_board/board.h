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

/*
 * This file has been automatically generated using ChibiStudio board
 * generator plugin. Do not edit manually.
 */

#ifndef BOARD_H
#define BOARD_H

/*===========================================================================*/
/* Driver constants.                                                         */
/*===========================================================================*/

/*
 * Setup for e-puck3 main processor board.
 */

/*
 * Board identifier.
 */
#define BOARD_EPUCK3_MAIN_PROCESSOR
#define BOARD_NAME                  "e-puck3 main processor"

/*
 * Ethernet PHY type.
 */
#define BOARD_PHY_ID                MII_LAN8742A_ID
#define BOARD_PHY_RMII

/*
 * Board oscillators-related settings.
 */
#if !defined(STM32_LSECLK)
#define STM32_LSECLK                32768U
#endif

#define STM32_LSEDRV                (3U << 3U)

#if !defined(STM32_HSECLK)
#define STM32_HSECLK                26000000U
#endif

#define STM32_HSE_BYPASS

/*
 * Board voltages.
 * Required for performance limits calculation.
 */
#define STM32_VDD                   300U

/*
 * MCU type as defined in the ST header.
 */
#define STM32F779xx

/*
 * IO pins assignments.
 */
#define GPIOA_ADC3_IN0              0U
#define GPIOA_ADC3_IN1              1U
#define GPIOA_ADC3_IN2              2U
#define GPIOA_USB_OTG_HS_ULPI_D0    3U
#define GPIOA_DAC_OUT1              4U
#define GPIOA_USB_OTG_HS_ULPI_CK    5U
#define GPIOA_DCMI_PIXCLK           6U
#define GPIOA_SDMMC_DET_N           7U
#define GPIOA_MHZ_26_CLK_OUT        8U
#define GPIOA_USB_FS_VBUS           9U
#define GPIOA_DCMI_D1               10U
#define GPIOA_USB_FS_DM             11U
#define GPIOA_USB_FS_DP             12U
#define GPIOA_SWDIO                 13U
#define GPIOA_SWCLK                 14U
#define GPIOA_UART7_TX              15U

#define GPIOB_USB_OTG_HS_ULPI_D1    0U
#define GPIOB_USB_OTG_HS_ULPI_D2    1U
#define GPIOB_SPI3_MOSI_ESP32       2U
#define GPIOB_SPI3_SCK_ESP32        3U
#define GPIOB_SPI3_MISO_ESP32       4U
#define GPIOB_USB_OTG_HS_ULPI_D7    5U
#define GPIOB_I2C1_SCL              6U
#define GPIOB_I2C1_SDA              7U
#define GPIOB_UART5_RX_ESP32_PROG   8U
#define GPIOB_UART5_TX_ESP32_PROG   9U
#define GPIOB_USB_OTG_HS_ULPI_D3    10U
#define GPIOB_USB_OTG_HS_ULPI_D4    11U
#define GPIOB_USB_OTG_HS_ULPI_D5    12U
#define GPIOB_USB_OTG_HS_ULPI_D6    13U
#define GPIOB_SPI2_MISO_IMU_PRESS   14U
#define GPIOB_SPI2_MOSI_IMU_PRESS   15U

#define GPIOC_USB_OTG_HS_ULPI_STP   0U
#define GPIOC_ADC3_IN11             1U
#define GPIOC_PIN2                  2U
#define GPIOC_PIN3                  3U
#define GPIOC_PIN4                  4U
#define GPIOC_PIN5                  5U
#define GPIOC_USART6_TX             6U
#define GPIOC_USART6_RX             7U
#define GPIOC_SDMMC1_D0             8U
#define GPIOC_SDMMC1_D1             9U
#define GPIOC_SDMMC1_D2             10U
#define GPIOC_SDMMC1_D3             11U
#define GPIOC_SDMMC1_CK             12U
#define GPIOC_PIN13                 13U
#define GPIOC_PIN14                 14U
#define GPIOC_PIN15                 15U

#define GPIOD_CAN1_RX               0U
#define GPIOD_CAN1_TX               1U
#define GPIOD_SDMMC1_CMD            2U
#define GPIOD_SPI2_SCK_IMU_PRESS    3U
#define GPIOD_IMU_INT1              4U
#define GPIOD_USART2_TX             5U
#define GPIOD_USART2_RX             6U
#define GPIOD_SPI1_MOSI             7U
#define GPIOD_USART3_TX_CMD_PROG    8U
#define GPIOD_USART3_RX_CMD_PROG    9U
#define GPIOD_DFSDM1_CKOUT          10U
#define GPIOD_PRESS_INT             11U
#define GPIOD_I2C4_SCL              12U
#define GPIOD_I2C4_SDA              13U
#define GPIOD_BYPASS_PROG           14U
#define GPIOD_TIM4_CH4_EXTCLK_DCMI  15U

#define GPIOE_OE_CAM1_N             0U
#define GPIOE_OE_CAM2_N             1U
#define GPIOE_SPI4_SCK              2U
#define GPIOE_IR_SIGNAL             3U
#define GPIOE_DSFDM1_DATIN3_MIC12   4U
#define GPIOE_SPI4_MISO             5U
#define GPIOE_SPI4_MOSI             6U
#define GPIOE_UART7_RX              7U
#define GPIOE_IMU_INT2              8U
#define GPIOE_UART7_RTS             9U
#define GPIOE_UART7_CTS             10U
#define GPIOE_SPI3_CS_N_ESP32       11U
#define GPIOE_DFSDM1_DATIN5_MIC34   12U
#define GPIOE_FRONT_LED_R           13U
#define GPIOE_FRONT_LED_G           14U
#define GPIOE_FRONT_LED_B           15U

#define GPIOF_USSR_BUTTON_N         0U
#define GPIOF_I2C2_SCL              1U
#define GPIOF_POWER_ON              2U
#define GPIOF_ADC3_IN9              3U
#define GPIOF_ADC3_IN14             4U
#define GPIOF_ADC3_IN15             5U
#define GPIOF_PIN6                  6U
#define GPIOF_PIN7                  7U
#define GPIOF_PIN8                  8U
#define GPIOF_PIN9                  9U
#define GPIOF_ADC3_IN8              10U
#define GPIOF_SPI2_CS_N_IMU         11U
#define GPIOF_SPI2_CS_N_PRESS       12U
#define GPIOF_RIGHT_LED_R           13U
#define GPIOF_RIGHT_LED_G           14U
#define GPIOF_RIGHT_LED_B           15U

#define GPIOG_REAR_LED_R            0U
#define GPIOG_REAR_LED_G            1U
#define GPIOG_REAR_LED_B            2U
#define GPIOG_LEFT_LED_R            3U
#define GPIOG_LEFT_LED_G            4U
#define GPIOG_LEFT_LED_B            5U
#define GPIOG_PIN6                  6U
#define GPIOG_SWCLK_PROG            7U
#define GPIOG_SWDIO_PROG            8U
#define GPIOG_SPI1_MISO             9U
#define GPIOG_DCMI_D2               10U
#define GPIOG_SPI1_SCK              11U
#define GPIOG_USART6_RTS            12U
#define GPIOG_USART6_CTS            13U
#define GPIOG_PIN14                 14U
#define GPIOG_EN_N_CAN_UC           15U

#define GPIOH_OSC_IN                0U
#define GPIOH_OSC_OUT               1U
#define GPIOH_PWR_BTN_STATE_N       2U
#define GPIOH_EN_TOF                3U
#define GPIOH_USB_OTG_HS_ULPI_NXT   4U
#define GPIOH_I2C2_SDA              5U
#define GPIOH_PIN6                  6U
#define GPIOH_PIN7                  7U
#define GPIOH_DCMI_HSYNC            8U
#define GPIOH_DCMI_D0               9U
#define GPIOH_EN_CAM1               10U
#define GPIOH_EN_CAM2               11U
#define GPIOH_DCMI_D3               12U
#define GPIOH_UART4_TX              13U
#define GPIOH_DCMI_D4               14U
#define GPIOH_DCMI_D11              15U

#define GPIOI_PIN0                  0U
#define GPIOI_DCMI_D8               1U
#define GPIOI_DCMI_D9               2U
#define GPIOI_DCMI_D10              3U
#define GPIOI_DCMI_D5               4U
#define GPIOI_DCMI_VSYNC            5U
#define GPIOI_DCMI_D6               6U
#define GPIOI_DCMI_D7               7U
#define GPIOI_PIN8                  8U
#define GPIOI_UART4_RX              9U
#define GPIOI_EN_PHY_HS             10U
#define GPIOI_USB_OTG_HS_ULPI_DIR   11U
#define GPIOI_PIN12                 12U
#define GPIOI_PIN13                 13U
#define GPIOI_PIN14                 14U
#define GPIOI_PIN15                 15U

#define GPIOJ_PIN0                  0U
#define GPIOJ_PIN1                  1U
#define GPIOJ_PIN2                  2U
#define GPIOJ_PIN3                  3U
#define GPIOJ_PIN4                  4U
#define GPIOJ_PIN5                  5U
#define GPIOJ_PIN6                  6U
#define GPIOJ_PIN7                  7U
#define GPIOJ_PIN8                  8U
#define GPIOJ_PIN9                  9U
#define GPIOJ_PIN10                 10U
#define GPIOJ_PIN11                 11U
#define GPIOJ_PIN12                 12U
#define GPIOJ_PIN13                 13U
#define GPIOJ_PIN14                 14U
#define GPIOJ_PIN15                 15U

#define GPIOK_PIN0                  0U
#define GPIOK_PIN1                  1U
#define GPIOK_PIN2                  2U
#define GPIOK_PIN3                  3U
#define GPIOK_PIN4                  4U
#define GPIOK_PIN5                  5U
#define GPIOK_PIN6                  6U
#define GPIOK_PIN7                  7U
#define GPIOK_PIN8                  8U
#define GPIOK_PIN9                  9U
#define GPIOK_PIN10                 10U
#define GPIOK_PIN11                 11U
#define GPIOK_PIN12                 12U
#define GPIOK_PIN13                 13U
#define GPIOK_PIN14                 14U
#define GPIOK_PIN15                 15U

/*
 * IO lines assignments.
 */
#define LINE_ADC3_IN0               PAL_LINE(GPIOA, 0U)
#define LINE_ADC3_IN1               PAL_LINE(GPIOA, 1U)
#define LINE_ADC3_IN2               PAL_LINE(GPIOA, 2U)
#define LINE_USB_OTG_HS_ULPI_D0     PAL_LINE(GPIOA, 3U)
#define LINE_DAC_OUT1               PAL_LINE(GPIOA, 4U)
#define LINE_USB_OTG_HS_ULPI_CK     PAL_LINE(GPIOA, 5U)
#define LINE_DCMI_PIXCLK            PAL_LINE(GPIOA, 6U)
#define LINE_SDMMC_DET_N            PAL_LINE(GPIOA, 7U)
#define LINE_MHZ_26_CLK_OUT         PAL_LINE(GPIOA, 8U)
#define LINE_USB_FS_VBUS            PAL_LINE(GPIOA, 9U)
#define LINE_DCMI_D1                PAL_LINE(GPIOA, 10U)
#define LINE_USB_FS_DM              PAL_LINE(GPIOA, 11U)
#define LINE_USB_FS_DP              PAL_LINE(GPIOA, 12U)
#define LINE_SWDIO                  PAL_LINE(GPIOA, 13U)
#define LINE_SWCLK                  PAL_LINE(GPIOA, 14U)
#define LINE_UART7_TX               PAL_LINE(GPIOA, 15U)
#define LINE_USB_OTG_HS_ULPI_D1     PAL_LINE(GPIOB, 0U)
#define LINE_USB_OTG_HS_ULPI_D2     PAL_LINE(GPIOB, 1U)
#define LINE_SPI3_MOSI_ESP32        PAL_LINE(GPIOB, 2U)
#define LINE_SPI3_SCK_ESP32         PAL_LINE(GPIOB, 3U)
#define LINE_SPI3_MISO_ESP32        PAL_LINE(GPIOB, 4U)
#define LINE_USB_OTG_HS_ULPI_D7     PAL_LINE(GPIOB, 5U)
#define LINE_I2C1_SCL               PAL_LINE(GPIOB, 6U)
#define LINE_I2C1_SDA               PAL_LINE(GPIOB, 7U)
#define LINE_UART5_RX_ESP32_PROG    PAL_LINE(GPIOB, 8U)
#define LINE_UART5_TX_ESP32_PROG    PAL_LINE(GPIOB, 9U)
#define LINE_USB_OTG_HS_ULPI_D3     PAL_LINE(GPIOB, 10U)
#define LINE_USB_OTG_HS_ULPI_D4     PAL_LINE(GPIOB, 11U)
#define LINE_USB_OTG_HS_ULPI_D5     PAL_LINE(GPIOB, 12U)
#define LINE_USB_OTG_HS_ULPI_D6     PAL_LINE(GPIOB, 13U)
#define LINE_SPI2_MISO_IMU_PRESS    PAL_LINE(GPIOB, 14U)
#define LINE_SPI2_MOSI_IMU_PRESS    PAL_LINE(GPIOB, 15U)
#define LINE_USB_OTG_HS_ULPI_STP    PAL_LINE(GPIOC, 0U)
#define LINE_ADC3_IN11              PAL_LINE(GPIOC, 1U)
#define LINE_USART6_TX              PAL_LINE(GPIOC, 6U)
#define LINE_USART6_RX              PAL_LINE(GPIOC, 7U)
#define LINE_SDMMC1_D0              PAL_LINE(GPIOC, 8U)
#define LINE_SDMMC1_D1              PAL_LINE(GPIOC, 9U)
#define LINE_SDMMC1_D2              PAL_LINE(GPIOC, 10U)
#define LINE_SDMMC1_D3              PAL_LINE(GPIOC, 11U)
#define LINE_SDMMC1_CK              PAL_LINE(GPIOC, 12U)
#define LINE_CAN1_RX                PAL_LINE(GPIOD, 0U)
#define LINE_CAN1_TX                PAL_LINE(GPIOD, 1U)
#define LINE_SDMMC1_CMD             PAL_LINE(GPIOD, 2U)
#define LINE_SPI2_SCK_IMU_PRESS     PAL_LINE(GPIOD, 3U)
#define LINE_IMU_INT1               PAL_LINE(GPIOD, 4U)
#define LINE_USART2_TX              PAL_LINE(GPIOD, 5U)
#define LINE_USART2_RX              PAL_LINE(GPIOD, 6U)
#define LINE_SPI1_MOSI              PAL_LINE(GPIOD, 7U)
#define LINE_USART3_TX_CMD_PROG     PAL_LINE(GPIOD, 8U)
#define LINE_USART3_RX_CMD_PROG     PAL_LINE(GPIOD, 9U)
#define LINE_DFSDM1_CKOUT           PAL_LINE(GPIOD, 10U)
#define LINE_PRESS_INT              PAL_LINE(GPIOD, 11U)
#define LINE_I2C4_SCL               PAL_LINE(GPIOD, 12U)
#define LINE_I2C4_SDA               PAL_LINE(GPIOD, 13U)
#define LINE_BYPASS_PROG            PAL_LINE(GPIOD, 14U)
#define LINE_TIM4_CH4_EXTCLK_DCMI   PAL_LINE(GPIOD, 15U)
#define LINE_OE_CAM1_N              PAL_LINE(GPIOE, 0U)
#define LINE_OE_CAM2_N              PAL_LINE(GPIOE, 1U)
#define LINE_SPI4_SCK               PAL_LINE(GPIOE, 2U)
#define LINE_IR_SIGNAL              PAL_LINE(GPIOE, 3U)
#define LINE_DSFDM1_DATIN3_MIC12    PAL_LINE(GPIOE, 4U)
#define LINE_SPI4_MISO              PAL_LINE(GPIOE, 5U)
#define LINE_SPI4_MOSI              PAL_LINE(GPIOE, 6U)
#define LINE_UART7_RX               PAL_LINE(GPIOE, 7U)
#define LINE_IMU_INT2               PAL_LINE(GPIOE, 8U)
#define LINE_UART7_RTS              PAL_LINE(GPIOE, 9U)
#define LINE_UART7_CTS              PAL_LINE(GPIOE, 10U)
#define LINE_SPI3_CS_N_ESP32        PAL_LINE(GPIOE, 11U)
#define LINE_DFSDM1_DATIN5_MIC34    PAL_LINE(GPIOE, 12U)
#define LINE_FRONT_LED_R            PAL_LINE(GPIOE, 13U)
#define LINE_FRONT_LED_G            PAL_LINE(GPIOE, 14U)
#define LINE_FRONT_LED_B            PAL_LINE(GPIOE, 15U)
#define LINE_USSR_BUTTON_N          PAL_LINE(GPIOF, 0U)
#define LINE_I2C2_SCL               PAL_LINE(GPIOF, 1U)
#define LINE_POWER_ON               PAL_LINE(GPIOF, 2U)
#define LINE_ADC3_IN9               PAL_LINE(GPIOF, 3U)
#define LINE_ADC3_IN14              PAL_LINE(GPIOF, 4U)
#define LINE_ADC3_IN15              PAL_LINE(GPIOF, 5U)
#define LINE_ADC3_IN8               PAL_LINE(GPIOF, 10U)
#define LINE_SPI2_CS_N_IMU          PAL_LINE(GPIOF, 11U)
#define LINE_SPI2_CS_N_PRESS        PAL_LINE(GPIOF, 12U)
#define LINE_RIGHT_LED_R            PAL_LINE(GPIOF, 13U)
#define LINE_RIGHT_LED_G            PAL_LINE(GPIOF, 14U)
#define LINE_RIGHT_LED_B            PAL_LINE(GPIOF, 15U)
#define LINE_REAR_LED_R             PAL_LINE(GPIOG, 0U)
#define LINE_REAR_LED_G             PAL_LINE(GPIOG, 1U)
#define LINE_REAR_LED_B             PAL_LINE(GPIOG, 2U)
#define LINE_LEFT_LED_R             PAL_LINE(GPIOG, 3U)
#define LINE_LEFT_LED_G             PAL_LINE(GPIOG, 4U)
#define LINE_LEFT_LED_B             PAL_LINE(GPIOG, 5U)
#define LINE_SWCLK_PROG             PAL_LINE(GPIOG, 7U)
#define LINE_SWDIO_PROG             PAL_LINE(GPIOG, 8U)
#define LINE_SPI1_MISO              PAL_LINE(GPIOG, 9U)
#define LINE_DCMI_D2                PAL_LINE(GPIOG, 10U)
#define LINE_SPI1_SCK               PAL_LINE(GPIOG, 11U)
#define LINE_USART6_RTS             PAL_LINE(GPIOG, 12U)
#define LINE_USART6_CTS             PAL_LINE(GPIOG, 13U)
#define LINE_EN_N_CAN_UC            PAL_LINE(GPIOG, 15U)
#define LINE_OSC_IN                 PAL_LINE(GPIOH, 0U)
#define LINE_OSC_OUT                PAL_LINE(GPIOH, 1U)
#define LINE_PWR_BTN_STATE_N        PAL_LINE(GPIOH, 2U)
#define LINE_EN_TOF                 PAL_LINE(GPIOH, 3U)
#define LINE_USB_OTG_HS_ULPI_NXT    PAL_LINE(GPIOH, 4U)
#define LINE_I2C2_SDA               PAL_LINE(GPIOH, 5U)
#define LINE_DCMI_HSYNC             PAL_LINE(GPIOH, 8U)
#define LINE_DCMI_D0                PAL_LINE(GPIOH, 9U)
#define LINE_EN_CAM1                PAL_LINE(GPIOH, 10U)
#define LINE_EN_CAM2                PAL_LINE(GPIOH, 11U)
#define LINE_DCMI_D3                PAL_LINE(GPIOH, 12U)
#define LINE_UART4_TX               PAL_LINE(GPIOH, 13U)
#define LINE_DCMI_D4                PAL_LINE(GPIOH, 14U)
#define LINE_DCMI_D11               PAL_LINE(GPIOH, 15U)
#define LINE_DCMI_D8                PAL_LINE(GPIOI, 1U)
#define LINE_DCMI_D9                PAL_LINE(GPIOI, 2U)
#define LINE_DCMI_D10               PAL_LINE(GPIOI, 3U)
#define LINE_DCMI_D5                PAL_LINE(GPIOI, 4U)
#define LINE_DCMI_VSYNC             PAL_LINE(GPIOI, 5U)
#define LINE_DCMI_D6                PAL_LINE(GPIOI, 6U)
#define LINE_DCMI_D7                PAL_LINE(GPIOI, 7U)
#define LINE_UART4_RX               PAL_LINE(GPIOI, 9U)
#define LINE_EN_PHY_HS              PAL_LINE(GPIOI, 10U)
#define LINE_USB_OTG_HS_ULPI_DIR    PAL_LINE(GPIOI, 11U)

/*===========================================================================*/
/* Driver pre-compile time settings.                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Derived constants and error checks.                                       */
/*===========================================================================*/

/*===========================================================================*/
/* Driver data structures and types.                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Driver macros.                                                            */
/*===========================================================================*/

/*
 * I/O ports initial setup, this configuration is established soon after reset
 * in the initialization code.
 * Please refer to the STM32 Reference Manual for details.
 */
#define PIN_MODE_INPUT(n)           (0U << ((n) * 2U))
#define PIN_MODE_OUTPUT(n)          (1U << ((n) * 2U))
#define PIN_MODE_ALTERNATE(n)       (2U << ((n) * 2U))
#define PIN_MODE_ANALOG(n)          (3U << ((n) * 2U))
#define PIN_ODR_LOW(n)              (0U << (n))
#define PIN_ODR_HIGH(n)             (1U << (n))
#define PIN_OTYPE_PUSHPULL(n)       (0U << (n))
#define PIN_OTYPE_OPENDRAIN(n)      (1U << (n))
#define PIN_OSPEED_VERYLOW(n)       (0U << ((n) * 2U))
#define PIN_OSPEED_LOW(n)           (1U << ((n) * 2U))
#define PIN_OSPEED_MEDIUM(n)        (2U << ((n) * 2U))
#define PIN_OSPEED_HIGH(n)          (3U << ((n) * 2U))
#define PIN_PUPDR_FLOATING(n)       (0U << ((n) * 2U))
#define PIN_PUPDR_PULLUP(n)         (1U << ((n) * 2U))
#define PIN_PUPDR_PULLDOWN(n)       (2U << ((n) * 2U))
#define PIN_AFIO_AF(n, v)           ((v) << (((n) % 8U) * 4U))

/*
 * GPIOA setup:
 *
 * PA0  - ADC3_IN0                  (analog).
 * PA1  - ADC3_IN1                  (analog).
 * PA2  - ADC3_IN2                  (analog).
 * PA3  - USB_OTG_HS_ULPI_D0        (alternate 10).
 * PA4  - DAC_OUT1                  (analog).
 * PA5  - USB_OTG_HS_ULPI_CK        (alternate 10).
 * PA6  - DCMI_PIXCLK               (alternate 13).
 * PA7  - SDMMC_DET_N               (input pullup).
 * PA8  - MHZ_26_CLK_OUT            (alternate 0).
 * PA9  - USB_FS_VBUS               (input floating).
 * PA10 - DCMI_D1                   (alternate 13).
 * PA11 - USB_FS_DM                 (alternate 10).
 * PA12 - USB_FS_DP                 (alternate 10).
 * PA13 - SWDIO                     (alternate 0).
 * PA14 - SWCLK                     (alternate 0).
 * PA15 - UART7_TX                  (alternate 12).
 */
#define VAL_GPIOA_MODER             (PIN_MODE_ANALOG(GPIOA_ADC3_IN0) |      \
                                     PIN_MODE_ANALOG(GPIOA_ADC3_IN1) |      \
                                     PIN_MODE_ANALOG(GPIOA_ADC3_IN2) |      \
                                     PIN_MODE_ALTERNATE(GPIOA_USB_OTG_HS_ULPI_D0) |\
                                     PIN_MODE_ANALOG(GPIOA_DAC_OUT1) |      \
                                     PIN_MODE_ALTERNATE(GPIOA_USB_OTG_HS_ULPI_CK) |\
                                     PIN_MODE_ALTERNATE(GPIOA_DCMI_PIXCLK) |\
                                     PIN_MODE_INPUT(GPIOA_SDMMC_DET_N) |    \
                                     PIN_MODE_ALTERNATE(GPIOA_MHZ_26_CLK_OUT) |\
                                     PIN_MODE_INPUT(GPIOA_USB_FS_VBUS) |    \
                                     PIN_MODE_ALTERNATE(GPIOA_DCMI_D1) |    \
                                     PIN_MODE_ALTERNATE(GPIOA_USB_FS_DM) |  \
                                     PIN_MODE_ALTERNATE(GPIOA_USB_FS_DP) |  \
                                     PIN_MODE_ALTERNATE(GPIOA_SWDIO) |      \
                                     PIN_MODE_ALTERNATE(GPIOA_SWCLK) |      \
                                     PIN_MODE_ALTERNATE(GPIOA_UART7_TX))
#define VAL_GPIOA_OTYPER            (PIN_OTYPE_PUSHPULL(GPIOA_ADC3_IN0) |   \
                                     PIN_OTYPE_PUSHPULL(GPIOA_ADC3_IN1) |   \
                                     PIN_OTYPE_PUSHPULL(GPIOA_ADC3_IN2) |   \
                                     PIN_OTYPE_PUSHPULL(GPIOA_USB_OTG_HS_ULPI_D0) |\
                                     PIN_OTYPE_PUSHPULL(GPIOA_DAC_OUT1) |   \
                                     PIN_OTYPE_PUSHPULL(GPIOA_USB_OTG_HS_ULPI_CK) |\
                                     PIN_OTYPE_PUSHPULL(GPIOA_DCMI_PIXCLK) |\
                                     PIN_OTYPE_PUSHPULL(GPIOA_SDMMC_DET_N) |\
                                     PIN_OTYPE_PUSHPULL(GPIOA_MHZ_26_CLK_OUT) |\
                                     PIN_OTYPE_PUSHPULL(GPIOA_USB_FS_VBUS) |\
                                     PIN_OTYPE_PUSHPULL(GPIOA_DCMI_D1) |    \
                                     PIN_OTYPE_PUSHPULL(GPIOA_USB_FS_DM) |  \
                                     PIN_OTYPE_PUSHPULL(GPIOA_USB_FS_DP) |  \
                                     PIN_OTYPE_PUSHPULL(GPIOA_SWDIO) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOA_SWCLK) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOA_UART7_TX))
#define VAL_GPIOA_OSPEEDR           (PIN_OSPEED_VERYLOW(GPIOA_ADC3_IN0) |   \
                                     PIN_OSPEED_VERYLOW(GPIOA_ADC3_IN1) |   \
                                     PIN_OSPEED_VERYLOW(GPIOA_ADC3_IN2) |   \
                                     PIN_OSPEED_HIGH(GPIOA_USB_OTG_HS_ULPI_D0) |\
                                     PIN_OSPEED_HIGH(GPIOA_DAC_OUT1) |      \
                                     PIN_OSPEED_HIGH(GPIOA_USB_OTG_HS_ULPI_CK) |\
                                     PIN_OSPEED_HIGH(GPIOA_DCMI_PIXCLK) |   \
                                     PIN_OSPEED_VERYLOW(GPIOA_SDMMC_DET_N) |\
                                     PIN_OSPEED_HIGH(GPIOA_MHZ_26_CLK_OUT) |\
                                     PIN_OSPEED_HIGH(GPIOA_USB_FS_VBUS) |   \
                                     PIN_OSPEED_HIGH(GPIOA_DCMI_D1) |       \
                                     PIN_OSPEED_HIGH(GPIOA_USB_FS_DM) |     \
                                     PIN_OSPEED_HIGH(GPIOA_USB_FS_DP) |     \
                                     PIN_OSPEED_HIGH(GPIOA_SWDIO) |         \
                                     PIN_OSPEED_HIGH(GPIOA_SWCLK) |         \
                                     PIN_OSPEED_HIGH(GPIOA_UART7_TX))
#define VAL_GPIOA_PUPDR             (PIN_PUPDR_FLOATING(GPIOA_ADC3_IN0) |   \
                                     PIN_PUPDR_FLOATING(GPIOA_ADC3_IN1) |   \
                                     PIN_PUPDR_FLOATING(GPIOA_ADC3_IN2) |   \
                                     PIN_PUPDR_FLOATING(GPIOA_USB_OTG_HS_ULPI_D0) |\
                                     PIN_PUPDR_FLOATING(GPIOA_DAC_OUT1) |   \
                                     PIN_PUPDR_FLOATING(GPIOA_USB_OTG_HS_ULPI_CK) |\
                                     PIN_PUPDR_FLOATING(GPIOA_DCMI_PIXCLK) |\
                                     PIN_PUPDR_PULLUP(GPIOA_SDMMC_DET_N) |  \
                                     PIN_PUPDR_FLOATING(GPIOA_MHZ_26_CLK_OUT) |\
                                     PIN_PUPDR_FLOATING(GPIOA_USB_FS_VBUS) |\
                                     PIN_PUPDR_FLOATING(GPIOA_DCMI_D1) |    \
                                     PIN_PUPDR_FLOATING(GPIOA_USB_FS_DM) |  \
                                     PIN_PUPDR_FLOATING(GPIOA_USB_FS_DP) |  \
                                     PIN_PUPDR_FLOATING(GPIOA_SWDIO) |      \
                                     PIN_PUPDR_FLOATING(GPIOA_SWCLK) |      \
                                     PIN_PUPDR_FLOATING(GPIOA_UART7_TX))
#define VAL_GPIOA_ODR               (PIN_ODR_LOW(GPIOA_ADC3_IN0) |          \
                                     PIN_ODR_LOW(GPIOA_ADC3_IN1) |          \
                                     PIN_ODR_LOW(GPIOA_ADC3_IN2) |          \
                                     PIN_ODR_HIGH(GPIOA_USB_OTG_HS_ULPI_D0) |\
                                     PIN_ODR_LOW(GPIOA_DAC_OUT1) |          \
                                     PIN_ODR_HIGH(GPIOA_USB_OTG_HS_ULPI_CK) |\
                                     PIN_ODR_HIGH(GPIOA_DCMI_PIXCLK) |      \
                                     PIN_ODR_HIGH(GPIOA_SDMMC_DET_N) |      \
                                     PIN_ODR_HIGH(GPIOA_MHZ_26_CLK_OUT) |   \
                                     PIN_ODR_HIGH(GPIOA_USB_FS_VBUS) |      \
                                     PIN_ODR_HIGH(GPIOA_DCMI_D1) |          \
                                     PIN_ODR_HIGH(GPIOA_USB_FS_DM) |        \
                                     PIN_ODR_HIGH(GPIOA_USB_FS_DP) |        \
                                     PIN_ODR_HIGH(GPIOA_SWDIO) |            \
                                     PIN_ODR_HIGH(GPIOA_SWCLK) |            \
                                     PIN_ODR_HIGH(GPIOA_UART7_TX))
#define VAL_GPIOA_AFRL              (PIN_AFIO_AF(GPIOA_ADC3_IN0, 0U) |      \
                                     PIN_AFIO_AF(GPIOA_ADC3_IN1, 0U) |      \
                                     PIN_AFIO_AF(GPIOA_ADC3_IN2, 0U) |      \
                                     PIN_AFIO_AF(GPIOA_USB_OTG_HS_ULPI_D0, 10U) |\
                                     PIN_AFIO_AF(GPIOA_DAC_OUT1, 0U) |      \
                                     PIN_AFIO_AF(GPIOA_USB_OTG_HS_ULPI_CK, 10U) |\
                                     PIN_AFIO_AF(GPIOA_DCMI_PIXCLK, 13U) |  \
                                     PIN_AFIO_AF(GPIOA_SDMMC_DET_N, 0U))
#define VAL_GPIOA_AFRH              (PIN_AFIO_AF(GPIOA_MHZ_26_CLK_OUT, 0U) |\
                                     PIN_AFIO_AF(GPIOA_USB_FS_VBUS, 0U) |   \
                                     PIN_AFIO_AF(GPIOA_DCMI_D1, 13U) |      \
                                     PIN_AFIO_AF(GPIOA_USB_FS_DM, 10U) |    \
                                     PIN_AFIO_AF(GPIOA_USB_FS_DP, 10U) |    \
                                     PIN_AFIO_AF(GPIOA_SWDIO, 0U) |         \
                                     PIN_AFIO_AF(GPIOA_SWCLK, 0U) |         \
                                     PIN_AFIO_AF(GPIOA_UART7_TX, 12U))

/*
 * GPIOB setup:
 *
 * PB0  - USB_OTG_HS_ULPI_D1        (alternate 10).
 * PB1  - USB_OTG_HS_ULPI_D2        (alternate 10).
 * PB2  - SPI3_MOSI_ESP32           (alternate 7).
 * PB3  - SPI3_SCK_ESP32            (alternate 6).
 * PB4  - SPI3_MISO_ESP32           (alternate 6).
 * PB5  - USB_OTG_HS_ULPI_D7        (alternate 10).
 * PB6  - I2C1_SCL                  (alternate 4).
 * PB7  - I2C1_SDA                  (alternate 4).
 * PB8  - UART5_RX_ESP32_PROG       (alternate 7).
 * PB9  - UART5_TX_ESP32_PROG       (alternate 7).
 * PB10 - USB_OTG_HS_ULPI_D3        (alternate 10).
 * PB11 - USB_OTG_HS_ULPI_D4        (alternate 10).
 * PB12 - USB_OTG_HS_ULPI_D5        (alternate 10).
 * PB13 - USB_OTG_HS_ULPI_D6        (alternate 10).
 * PB14 - SPI2_MISO_IMU_PRESS       (alternate 5).
 * PB15 - SPI2_MOSI_IMU_PRESS       (alternate 5).
 */
#define VAL_GPIOB_MODER             (PIN_MODE_ALTERNATE(GPIOB_USB_OTG_HS_ULPI_D1) |\
                                     PIN_MODE_ALTERNATE(GPIOB_USB_OTG_HS_ULPI_D2) |\
                                     PIN_MODE_ALTERNATE(GPIOB_SPI3_MOSI_ESP32) |\
                                     PIN_MODE_ALTERNATE(GPIOB_SPI3_SCK_ESP32) |\
                                     PIN_MODE_ALTERNATE(GPIOB_SPI3_MISO_ESP32) |\
                                     PIN_MODE_ALTERNATE(GPIOB_USB_OTG_HS_ULPI_D7) |\
                                     PIN_MODE_ALTERNATE(GPIOB_I2C1_SCL) |   \
                                     PIN_MODE_ALTERNATE(GPIOB_I2C1_SDA) |   \
                                     PIN_MODE_ALTERNATE(GPIOB_UART5_RX_ESP32_PROG) |\
                                     PIN_MODE_ALTERNATE(GPIOB_UART5_TX_ESP32_PROG) |\
                                     PIN_MODE_ALTERNATE(GPIOB_USB_OTG_HS_ULPI_D3) |\
                                     PIN_MODE_ALTERNATE(GPIOB_USB_OTG_HS_ULPI_D4) |\
                                     PIN_MODE_ALTERNATE(GPIOB_USB_OTG_HS_ULPI_D5) |\
                                     PIN_MODE_ALTERNATE(GPIOB_USB_OTG_HS_ULPI_D6) |\
                                     PIN_MODE_ALTERNATE(GPIOB_SPI2_MISO_IMU_PRESS) |\
                                     PIN_MODE_ALTERNATE(GPIOB_SPI2_MOSI_IMU_PRESS))
#define VAL_GPIOB_OTYPER            (PIN_OTYPE_PUSHPULL(GPIOB_USB_OTG_HS_ULPI_D1) |\
                                     PIN_OTYPE_PUSHPULL(GPIOB_USB_OTG_HS_ULPI_D2) |\
                                     PIN_OTYPE_PUSHPULL(GPIOB_SPI3_MOSI_ESP32) |\
                                     PIN_OTYPE_PUSHPULL(GPIOB_SPI3_SCK_ESP32) |\
                                     PIN_OTYPE_PUSHPULL(GPIOB_SPI3_MISO_ESP32) |\
                                     PIN_OTYPE_PUSHPULL(GPIOB_USB_OTG_HS_ULPI_D7) |\
                                     PIN_OTYPE_OPENDRAIN(GPIOB_I2C1_SCL) |  \
                                     PIN_OTYPE_OPENDRAIN(GPIOB_I2C1_SDA) |  \
                                     PIN_OTYPE_PUSHPULL(GPIOB_UART5_RX_ESP32_PROG) |\
                                     PIN_OTYPE_PUSHPULL(GPIOB_UART5_TX_ESP32_PROG) |\
                                     PIN_OTYPE_PUSHPULL(GPIOB_USB_OTG_HS_ULPI_D3) |\
                                     PIN_OTYPE_PUSHPULL(GPIOB_USB_OTG_HS_ULPI_D4) |\
                                     PIN_OTYPE_PUSHPULL(GPIOB_USB_OTG_HS_ULPI_D5) |\
                                     PIN_OTYPE_PUSHPULL(GPIOB_USB_OTG_HS_ULPI_D6) |\
                                     PIN_OTYPE_PUSHPULL(GPIOB_SPI2_MISO_IMU_PRESS) |\
                                     PIN_OTYPE_PUSHPULL(GPIOB_SPI2_MOSI_IMU_PRESS))
#define VAL_GPIOB_OSPEEDR           (PIN_OSPEED_HIGH(GPIOB_USB_OTG_HS_ULPI_D1) |\
                                     PIN_OSPEED_HIGH(GPIOB_USB_OTG_HS_ULPI_D2) |\
                                     PIN_OSPEED_HIGH(GPIOB_SPI3_MOSI_ESP32) |\
                                     PIN_OSPEED_HIGH(GPIOB_SPI3_SCK_ESP32) |\
                                     PIN_OSPEED_HIGH(GPIOB_SPI3_MISO_ESP32) |\
                                     PIN_OSPEED_HIGH(GPIOB_USB_OTG_HS_ULPI_D7) |\
                                     PIN_OSPEED_HIGH(GPIOB_I2C1_SCL) |      \
                                     PIN_OSPEED_HIGH(GPIOB_I2C1_SDA) |      \
                                     PIN_OSPEED_HIGH(GPIOB_UART5_RX_ESP32_PROG) |\
                                     PIN_OSPEED_HIGH(GPIOB_UART5_TX_ESP32_PROG) |\
                                     PIN_OSPEED_HIGH(GPIOB_USB_OTG_HS_ULPI_D3) |\
                                     PIN_OSPEED_HIGH(GPIOB_USB_OTG_HS_ULPI_D4) |\
                                     PIN_OSPEED_HIGH(GPIOB_USB_OTG_HS_ULPI_D5) |\
                                     PIN_OSPEED_HIGH(GPIOB_USB_OTG_HS_ULPI_D6) |\
                                     PIN_OSPEED_HIGH(GPIOB_SPI2_MISO_IMU_PRESS) |\
                                     PIN_OSPEED_HIGH(GPIOB_SPI2_MOSI_IMU_PRESS))
#define VAL_GPIOB_PUPDR             (PIN_PUPDR_FLOATING(GPIOB_USB_OTG_HS_ULPI_D1) |\
                                     PIN_PUPDR_FLOATING(GPIOB_USB_OTG_HS_ULPI_D2) |\
                                     PIN_PUPDR_FLOATING(GPIOB_SPI3_MOSI_ESP32) |\
                                     PIN_PUPDR_FLOATING(GPIOB_SPI3_SCK_ESP32) |\
                                     PIN_PUPDR_FLOATING(GPIOB_SPI3_MISO_ESP32) |\
                                     PIN_PUPDR_FLOATING(GPIOB_USB_OTG_HS_ULPI_D7) |\
                                     PIN_PUPDR_FLOATING(GPIOB_I2C1_SCL) |   \
                                     PIN_PUPDR_FLOATING(GPIOB_I2C1_SDA) |   \
                                     PIN_PUPDR_FLOATING(GPIOB_UART5_RX_ESP32_PROG) |\
                                     PIN_PUPDR_FLOATING(GPIOB_UART5_TX_ESP32_PROG) |\
                                     PIN_PUPDR_FLOATING(GPIOB_USB_OTG_HS_ULPI_D3) |\
                                     PIN_PUPDR_FLOATING(GPIOB_USB_OTG_HS_ULPI_D4) |\
                                     PIN_PUPDR_FLOATING(GPIOB_USB_OTG_HS_ULPI_D5) |\
                                     PIN_PUPDR_FLOATING(GPIOB_USB_OTG_HS_ULPI_D6) |\
                                     PIN_PUPDR_FLOATING(GPIOB_SPI2_MISO_IMU_PRESS) |\
                                     PIN_PUPDR_FLOATING(GPIOB_SPI2_MOSI_IMU_PRESS))
#define VAL_GPIOB_ODR               (PIN_ODR_HIGH(GPIOB_USB_OTG_HS_ULPI_D1) |\
                                     PIN_ODR_HIGH(GPIOB_USB_OTG_HS_ULPI_D2) |\
                                     PIN_ODR_HIGH(GPIOB_SPI3_MOSI_ESP32) |  \
                                     PIN_ODR_HIGH(GPIOB_SPI3_SCK_ESP32) |   \
                                     PIN_ODR_HIGH(GPIOB_SPI3_MISO_ESP32) |  \
                                     PIN_ODR_HIGH(GPIOB_USB_OTG_HS_ULPI_D7) |\
                                     PIN_ODR_HIGH(GPIOB_I2C1_SCL) |         \
                                     PIN_ODR_HIGH(GPIOB_I2C1_SDA) |         \
                                     PIN_ODR_HIGH(GPIOB_UART5_RX_ESP32_PROG) |\
                                     PIN_ODR_HIGH(GPIOB_UART5_TX_ESP32_PROG) |\
                                     PIN_ODR_HIGH(GPIOB_USB_OTG_HS_ULPI_D3) |\
                                     PIN_ODR_HIGH(GPIOB_USB_OTG_HS_ULPI_D4) |\
                                     PIN_ODR_HIGH(GPIOB_USB_OTG_HS_ULPI_D5) |\
                                     PIN_ODR_HIGH(GPIOB_USB_OTG_HS_ULPI_D6) |\
                                     PIN_ODR_HIGH(GPIOB_SPI2_MISO_IMU_PRESS) |\
                                     PIN_ODR_HIGH(GPIOB_SPI2_MOSI_IMU_PRESS))
#define VAL_GPIOB_AFRL              (PIN_AFIO_AF(GPIOB_USB_OTG_HS_ULPI_D1, 10U) |\
                                     PIN_AFIO_AF(GPIOB_USB_OTG_HS_ULPI_D2, 10U) |\
                                     PIN_AFIO_AF(GPIOB_SPI3_MOSI_ESP32, 7U) |\
                                     PIN_AFIO_AF(GPIOB_SPI3_SCK_ESP32, 6U) |\
                                     PIN_AFIO_AF(GPIOB_SPI3_MISO_ESP32, 6U) |\
                                     PIN_AFIO_AF(GPIOB_USB_OTG_HS_ULPI_D7, 10U) |\
                                     PIN_AFIO_AF(GPIOB_I2C1_SCL, 4U) |      \
                                     PIN_AFIO_AF(GPIOB_I2C1_SDA, 4U))
#define VAL_GPIOB_AFRH              (PIN_AFIO_AF(GPIOB_UART5_RX_ESP32_PROG, 7U) |\
                                     PIN_AFIO_AF(GPIOB_UART5_TX_ESP32_PROG, 7U) |\
                                     PIN_AFIO_AF(GPIOB_USB_OTG_HS_ULPI_D3, 10U) |\
                                     PIN_AFIO_AF(GPIOB_USB_OTG_HS_ULPI_D4, 10U) |\
                                     PIN_AFIO_AF(GPIOB_USB_OTG_HS_ULPI_D5, 10U) |\
                                     PIN_AFIO_AF(GPIOB_USB_OTG_HS_ULPI_D6, 10U) |\
                                     PIN_AFIO_AF(GPIOB_SPI2_MISO_IMU_PRESS, 5U) |\
                                     PIN_AFIO_AF(GPIOB_SPI2_MOSI_IMU_PRESS, 5U))

/*
 * GPIOC setup:
 *
 * PC0  - USB_OTG_HS_ULPI_STP       (alternate 10).
 * PC1  - ADC3_IN11                 (analog).
 * PC2  - PIN2                      (input pulldown).
 * PC3  - PIN3                      (input pulldown).
 * PC4  - PIN4                      (input pulldown).
 * PC5  - PIN5                      (input pulldown).
 * PC6  - USART6_TX                 (alternate 8).
 * PC7  - USART6_RX                 (alternate 8).
 * PC8  - SDMMC1_D0                 (alternate 12).
 * PC9  - SDMMC1_D1                 (alternate 12).
 * PC10 - SDMMC1_D2                 (alternate 12).
 * PC11 - SDMMC1_D3                 (alternate 12).
 * PC12 - SDMMC1_CK                 (alternate 12).
 * PC13 - PIN13                     (input pulldown).
 * PC14 - PIN14                     (input pulldown).
 * PC15 - PIN15                     (input pulldown).
 */
#define VAL_GPIOC_MODER             (PIN_MODE_ALTERNATE(GPIOC_USB_OTG_HS_ULPI_STP) |\
                                     PIN_MODE_ANALOG(GPIOC_ADC3_IN11) |     \
                                     PIN_MODE_INPUT(GPIOC_PIN2) |           \
                                     PIN_MODE_INPUT(GPIOC_PIN3) |           \
                                     PIN_MODE_INPUT(GPIOC_PIN4) |           \
                                     PIN_MODE_INPUT(GPIOC_PIN5) |           \
                                     PIN_MODE_ALTERNATE(GPIOC_USART6_TX) |  \
                                     PIN_MODE_ALTERNATE(GPIOC_USART6_RX) |  \
                                     PIN_MODE_ALTERNATE(GPIOC_SDMMC1_D0) |  \
                                     PIN_MODE_ALTERNATE(GPIOC_SDMMC1_D1) |  \
                                     PIN_MODE_ALTERNATE(GPIOC_SDMMC1_D2) |  \
                                     PIN_MODE_ALTERNATE(GPIOC_SDMMC1_D3) |  \
                                     PIN_MODE_ALTERNATE(GPIOC_SDMMC1_CK) |  \
                                     PIN_MODE_INPUT(GPIOC_PIN13) |          \
                                     PIN_MODE_INPUT(GPIOC_PIN14) |          \
                                     PIN_MODE_INPUT(GPIOC_PIN15))
#define VAL_GPIOC_OTYPER            (PIN_OTYPE_PUSHPULL(GPIOC_USB_OTG_HS_ULPI_STP) |\
                                     PIN_OTYPE_PUSHPULL(GPIOC_ADC3_IN11) |  \
                                     PIN_OTYPE_PUSHPULL(GPIOC_PIN2) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOC_PIN3) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOC_PIN4) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOC_PIN5) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOC_USART6_TX) |  \
                                     PIN_OTYPE_PUSHPULL(GPIOC_USART6_RX) |  \
                                     PIN_OTYPE_PUSHPULL(GPIOC_SDMMC1_D0) |  \
                                     PIN_OTYPE_PUSHPULL(GPIOC_SDMMC1_D1) |  \
                                     PIN_OTYPE_PUSHPULL(GPIOC_SDMMC1_D2) |  \
                                     PIN_OTYPE_PUSHPULL(GPIOC_SDMMC1_D3) |  \
                                     PIN_OTYPE_PUSHPULL(GPIOC_SDMMC1_CK) |  \
                                     PIN_OTYPE_PUSHPULL(GPIOC_PIN13) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOC_PIN14) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOC_PIN15))
#define VAL_GPIOC_OSPEEDR           (PIN_OSPEED_HIGH(GPIOC_USB_OTG_HS_ULPI_STP) |\
                                     PIN_OSPEED_VERYLOW(GPIOC_ADC3_IN11) |  \
                                     PIN_OSPEED_VERYLOW(GPIOC_PIN2) |       \
                                     PIN_OSPEED_VERYLOW(GPIOC_PIN3) |       \
                                     PIN_OSPEED_VERYLOW(GPIOC_PIN4) |       \
                                     PIN_OSPEED_VERYLOW(GPIOC_PIN5) |       \
                                     PIN_OSPEED_HIGH(GPIOC_USART6_TX) |     \
                                     PIN_OSPEED_HIGH(GPIOC_USART6_RX) |     \
                                     PIN_OSPEED_HIGH(GPIOC_SDMMC1_D0) |     \
                                     PIN_OSPEED_HIGH(GPIOC_SDMMC1_D1) |     \
                                     PIN_OSPEED_HIGH(GPIOC_SDMMC1_D2) |     \
                                     PIN_OSPEED_HIGH(GPIOC_SDMMC1_D3) |     \
                                     PIN_OSPEED_HIGH(GPIOC_SDMMC1_CK) |     \
                                     PIN_OSPEED_VERYLOW(GPIOC_PIN13) |      \
                                     PIN_OSPEED_VERYLOW(GPIOC_PIN14) |      \
                                     PIN_OSPEED_VERYLOW(GPIOC_PIN15))
#define VAL_GPIOC_PUPDR             (PIN_PUPDR_FLOATING(GPIOC_USB_OTG_HS_ULPI_STP) |\
                                     PIN_PUPDR_FLOATING(GPIOC_ADC3_IN11) |  \
                                     PIN_PUPDR_PULLDOWN(GPIOC_PIN2) |       \
                                     PIN_PUPDR_PULLDOWN(GPIOC_PIN3) |       \
                                     PIN_PUPDR_PULLDOWN(GPIOC_PIN4) |       \
                                     PIN_PUPDR_PULLDOWN(GPIOC_PIN5) |       \
                                     PIN_PUPDR_FLOATING(GPIOC_USART6_TX) |  \
                                     PIN_PUPDR_FLOATING(GPIOC_USART6_RX) |  \
                                     PIN_PUPDR_FLOATING(GPIOC_SDMMC1_D0) |  \
                                     PIN_PUPDR_FLOATING(GPIOC_SDMMC1_D1) |  \
                                     PIN_PUPDR_FLOATING(GPIOC_SDMMC1_D2) |  \
                                     PIN_PUPDR_FLOATING(GPIOC_SDMMC1_D3) |  \
                                     PIN_PUPDR_FLOATING(GPIOC_SDMMC1_CK) |  \
                                     PIN_PUPDR_PULLDOWN(GPIOC_PIN13) |      \
                                     PIN_PUPDR_PULLDOWN(GPIOC_PIN14) |      \
                                     PIN_PUPDR_PULLDOWN(GPIOC_PIN15))
#define VAL_GPIOC_ODR               (PIN_ODR_HIGH(GPIOC_USB_OTG_HS_ULPI_STP) |\
                                     PIN_ODR_HIGH(GPIOC_ADC3_IN11) |        \
                                     PIN_ODR_HIGH(GPIOC_PIN2) |             \
                                     PIN_ODR_HIGH(GPIOC_PIN3) |             \
                                     PIN_ODR_HIGH(GPIOC_PIN4) |             \
                                     PIN_ODR_HIGH(GPIOC_PIN5) |             \
                                     PIN_ODR_HIGH(GPIOC_USART6_TX) |        \
                                     PIN_ODR_HIGH(GPIOC_USART6_RX) |        \
                                     PIN_ODR_HIGH(GPIOC_SDMMC1_D0) |        \
                                     PIN_ODR_HIGH(GPIOC_SDMMC1_D1) |        \
                                     PIN_ODR_HIGH(GPIOC_SDMMC1_D2) |        \
                                     PIN_ODR_HIGH(GPIOC_SDMMC1_D3) |        \
                                     PIN_ODR_HIGH(GPIOC_SDMMC1_CK) |        \
                                     PIN_ODR_HIGH(GPIOC_PIN13) |            \
                                     PIN_ODR_HIGH(GPIOC_PIN14) |            \
                                     PIN_ODR_HIGH(GPIOC_PIN15))
#define VAL_GPIOC_AFRL              (PIN_AFIO_AF(GPIOC_USB_OTG_HS_ULPI_STP, 10U) |\
                                     PIN_AFIO_AF(GPIOC_ADC3_IN11, 0U) |     \
                                     PIN_AFIO_AF(GPIOC_PIN2, 0U) |          \
                                     PIN_AFIO_AF(GPIOC_PIN3, 0U) |          \
                                     PIN_AFIO_AF(GPIOC_PIN4, 0U) |          \
                                     PIN_AFIO_AF(GPIOC_PIN5, 0U) |          \
                                     PIN_AFIO_AF(GPIOC_USART6_TX, 8U) |     \
                                     PIN_AFIO_AF(GPIOC_USART6_RX, 8U))
#define VAL_GPIOC_AFRH              (PIN_AFIO_AF(GPIOC_SDMMC1_D0, 12U) |    \
                                     PIN_AFIO_AF(GPIOC_SDMMC1_D1, 12U) |    \
                                     PIN_AFIO_AF(GPIOC_SDMMC1_D2, 12U) |    \
                                     PIN_AFIO_AF(GPIOC_SDMMC1_D3, 12U) |    \
                                     PIN_AFIO_AF(GPIOC_SDMMC1_CK, 12U) |    \
                                     PIN_AFIO_AF(GPIOC_PIN13, 0U) |         \
                                     PIN_AFIO_AF(GPIOC_PIN14, 0U) |         \
                                     PIN_AFIO_AF(GPIOC_PIN15, 0U))

/*
 * GPIOD setup:
 *
 * PD0  - CAN1_RX                   (alternate 9).
 * PD1  - CAN1_TX                   (alternate 9).
 * PD2  - SDMMC1_CMD                (alternate 12).
 * PD3  - SPI2_SCK_IMU_PRESS        (alternate 5).
 * PD4  - IMU_INT1                  (input floating).
 * PD5  - USART2_TX                 (alternate 7).
 * PD6  - USART2_RX                 (alternate 7).
 * PD7  - SPI1_MOSI                 (alternate 5).
 * PD8  - USART3_TX_CMD_PROG        (alternate 7).
 * PD9  - USART3_RX_CMD_PROG        (alternate 7).
 * PD10 - DFSDM1_CKOUT              (alternate 3).
 * PD11 - PRESS_INT                 (input floating).
 * PD12 - I2C4_SCL                  (alternate 4).
 * PD13 - I2C4_SDA                  (alternate 4).
 * PD14 - BYPASS_PROG               (input floating).
 * PD15 - TIM4_CH4_EXTCLK_DCMI      (alternate 2).
 */
#define VAL_GPIOD_MODER             (PIN_MODE_ALTERNATE(GPIOD_CAN1_RX) |    \
                                     PIN_MODE_ALTERNATE(GPIOD_CAN1_TX) |    \
                                     PIN_MODE_ALTERNATE(GPIOD_SDMMC1_CMD) | \
                                     PIN_MODE_ALTERNATE(GPIOD_SPI2_SCK_IMU_PRESS) |\
                                     PIN_MODE_INPUT(GPIOD_IMU_INT1) |       \
                                     PIN_MODE_ALTERNATE(GPIOD_USART2_TX) |  \
                                     PIN_MODE_ALTERNATE(GPIOD_USART2_RX) |  \
                                     PIN_MODE_ALTERNATE(GPIOD_SPI1_MOSI) |  \
                                     PIN_MODE_ALTERNATE(GPIOD_USART3_TX_CMD_PROG) |\
                                     PIN_MODE_ALTERNATE(GPIOD_USART3_RX_CMD_PROG) |\
                                     PIN_MODE_ALTERNATE(GPIOD_DFSDM1_CKOUT) |\
                                     PIN_MODE_INPUT(GPIOD_PRESS_INT) |      \
                                     PIN_MODE_ALTERNATE(GPIOD_I2C4_SCL) |   \
                                     PIN_MODE_ALTERNATE(GPIOD_I2C4_SDA) |   \
                                     PIN_MODE_INPUT(GPIOD_BYPASS_PROG) |    \
                                     PIN_MODE_ALTERNATE(GPIOD_TIM4_CH4_EXTCLK_DCMI))
#define VAL_GPIOD_OTYPER            (PIN_OTYPE_PUSHPULL(GPIOD_CAN1_RX) |    \
                                     PIN_OTYPE_PUSHPULL(GPIOD_CAN1_TX) |    \
                                     PIN_OTYPE_PUSHPULL(GPIOD_SDMMC1_CMD) | \
                                     PIN_OTYPE_PUSHPULL(GPIOD_SPI2_SCK_IMU_PRESS) |\
                                     PIN_OTYPE_PUSHPULL(GPIOD_IMU_INT1) |   \
                                     PIN_OTYPE_PUSHPULL(GPIOD_USART2_TX) |  \
                                     PIN_OTYPE_PUSHPULL(GPIOD_USART2_RX) |  \
                                     PIN_OTYPE_PUSHPULL(GPIOD_SPI1_MOSI) |  \
                                     PIN_OTYPE_PUSHPULL(GPIOD_USART3_TX_CMD_PROG) |\
                                     PIN_OTYPE_PUSHPULL(GPIOD_USART3_RX_CMD_PROG) |\
                                     PIN_OTYPE_PUSHPULL(GPIOD_DFSDM1_CKOUT) |\
                                     PIN_OTYPE_PUSHPULL(GPIOD_PRESS_INT) |  \
                                     PIN_OTYPE_OPENDRAIN(GPIOD_I2C4_SCL) |  \
                                     PIN_OTYPE_OPENDRAIN(GPIOD_I2C4_SDA) |  \
                                     PIN_OTYPE_PUSHPULL(GPIOD_BYPASS_PROG) |\
                                     PIN_OTYPE_PUSHPULL(GPIOD_TIM4_CH4_EXTCLK_DCMI))
#define VAL_GPIOD_OSPEEDR           (PIN_OSPEED_HIGH(GPIOD_CAN1_RX) |       \
                                     PIN_OSPEED_HIGH(GPIOD_CAN1_TX) |       \
                                     PIN_OSPEED_HIGH(GPIOD_SDMMC1_CMD) |    \
                                     PIN_OSPEED_HIGH(GPIOD_SPI2_SCK_IMU_PRESS) |\
                                     PIN_OSPEED_HIGH(GPIOD_IMU_INT1) |      \
                                     PIN_OSPEED_HIGH(GPIOD_USART2_TX) |     \
                                     PIN_OSPEED_HIGH(GPIOD_USART2_RX) |     \
                                     PIN_OSPEED_HIGH(GPIOD_SPI1_MOSI) |     \
                                     PIN_OSPEED_HIGH(GPIOD_USART3_TX_CMD_PROG) |\
                                     PIN_OSPEED_HIGH(GPIOD_USART3_RX_CMD_PROG) |\
                                     PIN_OSPEED_HIGH(GPIOD_DFSDM1_CKOUT) |  \
                                     PIN_OSPEED_HIGH(GPIOD_PRESS_INT) |     \
                                     PIN_OSPEED_HIGH(GPIOD_I2C4_SCL) |      \
                                     PIN_OSPEED_HIGH(GPIOD_I2C4_SDA) |      \
                                     PIN_OSPEED_VERYLOW(GPIOD_BYPASS_PROG) |\
                                     PIN_OSPEED_HIGH(GPIOD_TIM4_CH4_EXTCLK_DCMI))
#define VAL_GPIOD_PUPDR             (PIN_PUPDR_FLOATING(GPIOD_CAN1_RX) |    \
                                     PIN_PUPDR_FLOATING(GPIOD_CAN1_TX) |    \
                                     PIN_PUPDR_FLOATING(GPIOD_SDMMC1_CMD) | \
                                     PIN_PUPDR_FLOATING(GPIOD_SPI2_SCK_IMU_PRESS) |\
                                     PIN_PUPDR_FLOATING(GPIOD_IMU_INT1) |   \
                                     PIN_PUPDR_FLOATING(GPIOD_USART2_TX) |  \
                                     PIN_PUPDR_FLOATING(GPIOD_USART2_RX) |  \
                                     PIN_PUPDR_FLOATING(GPIOD_SPI1_MOSI) |  \
                                     PIN_PUPDR_FLOATING(GPIOD_USART3_TX_CMD_PROG) |\
                                     PIN_PUPDR_FLOATING(GPIOD_USART3_RX_CMD_PROG) |\
                                     PIN_PUPDR_FLOATING(GPIOD_DFSDM1_CKOUT) |\
                                     PIN_PUPDR_FLOATING(GPIOD_PRESS_INT) |  \
                                     PIN_PUPDR_FLOATING(GPIOD_I2C4_SCL) |   \
                                     PIN_PUPDR_FLOATING(GPIOD_I2C4_SDA) |   \
                                     PIN_PUPDR_FLOATING(GPIOD_BYPASS_PROG) |\
                                     PIN_PUPDR_FLOATING(GPIOD_TIM4_CH4_EXTCLK_DCMI))
#define VAL_GPIOD_ODR               (PIN_ODR_HIGH(GPIOD_CAN1_RX) |          \
                                     PIN_ODR_HIGH(GPIOD_CAN1_TX) |          \
                                     PIN_ODR_HIGH(GPIOD_SDMMC1_CMD) |       \
                                     PIN_ODR_HIGH(GPIOD_SPI2_SCK_IMU_PRESS) |\
                                     PIN_ODR_HIGH(GPIOD_IMU_INT1) |         \
                                     PIN_ODR_HIGH(GPIOD_USART2_TX) |        \
                                     PIN_ODR_HIGH(GPIOD_USART2_RX) |        \
                                     PIN_ODR_HIGH(GPIOD_SPI1_MOSI) |        \
                                     PIN_ODR_HIGH(GPIOD_USART3_TX_CMD_PROG) |\
                                     PIN_ODR_HIGH(GPIOD_USART3_RX_CMD_PROG) |\
                                     PIN_ODR_HIGH(GPIOD_DFSDM1_CKOUT) |     \
                                     PIN_ODR_HIGH(GPIOD_PRESS_INT) |        \
                                     PIN_ODR_HIGH(GPIOD_I2C4_SCL) |         \
                                     PIN_ODR_HIGH(GPIOD_I2C4_SDA) |         \
                                     PIN_ODR_HIGH(GPIOD_BYPASS_PROG) |      \
                                     PIN_ODR_HIGH(GPIOD_TIM4_CH4_EXTCLK_DCMI))
#define VAL_GPIOD_AFRL              (PIN_AFIO_AF(GPIOD_CAN1_RX, 9U) |       \
                                     PIN_AFIO_AF(GPIOD_CAN1_TX, 9U) |       \
                                     PIN_AFIO_AF(GPIOD_SDMMC1_CMD, 12U) |   \
                                     PIN_AFIO_AF(GPIOD_SPI2_SCK_IMU_PRESS, 5U) |\
                                     PIN_AFIO_AF(GPIOD_IMU_INT1, 0U) |      \
                                     PIN_AFIO_AF(GPIOD_USART2_TX, 7U) |     \
                                     PIN_AFIO_AF(GPIOD_USART2_RX, 7U) |     \
                                     PIN_AFIO_AF(GPIOD_SPI1_MOSI, 5U))
#define VAL_GPIOD_AFRH              (PIN_AFIO_AF(GPIOD_USART3_TX_CMD_PROG, 7U) |\
                                     PIN_AFIO_AF(GPIOD_USART3_RX_CMD_PROG, 7U) |\
                                     PIN_AFIO_AF(GPIOD_DFSDM1_CKOUT, 3U) |  \
                                     PIN_AFIO_AF(GPIOD_PRESS_INT, 0U) |     \
                                     PIN_AFIO_AF(GPIOD_I2C4_SCL, 4U) |      \
                                     PIN_AFIO_AF(GPIOD_I2C4_SDA, 4U) |      \
                                     PIN_AFIO_AF(GPIOD_BYPASS_PROG, 0U) |   \
                                     PIN_AFIO_AF(GPIOD_TIM4_CH4_EXTCLK_DCMI, 2U))

/*
 * GPIOE setup:
 *
 * PE0  - OE_CAM1_N                 (output pushpull maximum).
 * PE1  - OE_CAM2_N                 (output pushpull maximum).
 * PE2  - SPI4_SCK                  (alternate 5).
 * PE3  - IR_SIGNAL                 (input floating).
 * PE4  - DSFDM1_DATIN3_MIC12       (alternate 10).
 * PE5  - SPI4_MISO                 (alternate 5).
 * PE6  - SPI4_MOSI                 (alternate 5).
 * PE7  - UART7_RX                  (alternate 8).
 * PE8  - IMU_INT2                  (input floating).
 * PE9  - UART7_RTS                 (alternate 8).
 * PE10 - UART7_CTS                 (alternate 8).
 * PE11 - SPI3_CS_N_ESP32           (alternate 0).
 * PE12 - DFSDM1_DATIN5_MIC34       (alternate 6).
 * PE13 - FRONT_LED_R               (output pushpull maximum).
 * PE14 - FRONT_LED_G               (output pushpull maximum).
 * PE15 - FRONT_LED_B               (output pushpull maximum).
 */
#define VAL_GPIOE_MODER             (PIN_MODE_OUTPUT(GPIOE_OE_CAM1_N) |     \
                                     PIN_MODE_OUTPUT(GPIOE_OE_CAM2_N) |     \
                                     PIN_MODE_ALTERNATE(GPIOE_SPI4_SCK) |   \
                                     PIN_MODE_INPUT(GPIOE_IR_SIGNAL) |      \
                                     PIN_MODE_ALTERNATE(GPIOE_DSFDM1_DATIN3_MIC12) |\
                                     PIN_MODE_ALTERNATE(GPIOE_SPI4_MISO) |  \
                                     PIN_MODE_ALTERNATE(GPIOE_SPI4_MOSI) |  \
                                     PIN_MODE_ALTERNATE(GPIOE_UART7_RX) |   \
                                     PIN_MODE_INPUT(GPIOE_IMU_INT2) |       \
                                     PIN_MODE_ALTERNATE(GPIOE_UART7_RTS) |  \
                                     PIN_MODE_ALTERNATE(GPIOE_UART7_CTS) |  \
                                     PIN_MODE_ALTERNATE(GPIOE_SPI3_CS_N_ESP32) |\
                                     PIN_MODE_ALTERNATE(GPIOE_DFSDM1_DATIN5_MIC34) |\
                                     PIN_MODE_OUTPUT(GPIOE_FRONT_LED_R) |   \
                                     PIN_MODE_OUTPUT(GPIOE_FRONT_LED_G) |   \
                                     PIN_MODE_OUTPUT(GPIOE_FRONT_LED_B))
#define VAL_GPIOE_OTYPER            (PIN_OTYPE_PUSHPULL(GPIOE_OE_CAM1_N) |  \
                                     PIN_OTYPE_PUSHPULL(GPIOE_OE_CAM2_N) |  \
                                     PIN_OTYPE_PUSHPULL(GPIOE_SPI4_SCK) |   \
                                     PIN_OTYPE_PUSHPULL(GPIOE_IR_SIGNAL) |  \
                                     PIN_OTYPE_PUSHPULL(GPIOE_DSFDM1_DATIN3_MIC12) |\
                                     PIN_OTYPE_PUSHPULL(GPIOE_SPI4_MISO) |  \
                                     PIN_OTYPE_PUSHPULL(GPIOE_SPI4_MOSI) |  \
                                     PIN_OTYPE_PUSHPULL(GPIOE_UART7_RX) |   \
                                     PIN_OTYPE_PUSHPULL(GPIOE_IMU_INT2) |   \
                                     PIN_OTYPE_PUSHPULL(GPIOE_UART7_RTS) |  \
                                     PIN_OTYPE_PUSHPULL(GPIOE_UART7_CTS) |  \
                                     PIN_OTYPE_PUSHPULL(GPIOE_SPI3_CS_N_ESP32) |\
                                     PIN_OTYPE_PUSHPULL(GPIOE_DFSDM1_DATIN5_MIC34) |\
                                     PIN_OTYPE_PUSHPULL(GPIOE_FRONT_LED_R) |\
                                     PIN_OTYPE_PUSHPULL(GPIOE_FRONT_LED_G) |\
                                     PIN_OTYPE_PUSHPULL(GPIOE_FRONT_LED_B))
#define VAL_GPIOE_OSPEEDR           (PIN_OSPEED_HIGH(GPIOE_OE_CAM1_N) |     \
                                     PIN_OSPEED_HIGH(GPIOE_OE_CAM2_N) |     \
                                     PIN_OSPEED_HIGH(GPIOE_SPI4_SCK) |      \
                                     PIN_OSPEED_HIGH(GPIOE_IR_SIGNAL) |     \
                                     PIN_OSPEED_HIGH(GPIOE_DSFDM1_DATIN3_MIC12) |\
                                     PIN_OSPEED_HIGH(GPIOE_SPI4_MISO) |     \
                                     PIN_OSPEED_HIGH(GPIOE_SPI4_MOSI) |     \
                                     PIN_OSPEED_HIGH(GPIOE_UART7_RX) |      \
                                     PIN_OSPEED_HIGH(GPIOE_IMU_INT2) |      \
                                     PIN_OSPEED_HIGH(GPIOE_UART7_RTS) |     \
                                     PIN_OSPEED_HIGH(GPIOE_UART7_CTS) |     \
                                     PIN_OSPEED_HIGH(GPIOE_SPI3_CS_N_ESP32) |\
                                     PIN_OSPEED_HIGH(GPIOE_DFSDM1_DATIN5_MIC34) |\
                                     PIN_OSPEED_HIGH(GPIOE_FRONT_LED_R) |   \
                                     PIN_OSPEED_HIGH(GPIOE_FRONT_LED_G) |   \
                                     PIN_OSPEED_HIGH(GPIOE_FRONT_LED_B))
#define VAL_GPIOE_PUPDR             (PIN_PUPDR_FLOATING(GPIOE_OE_CAM1_N) |  \
                                     PIN_PUPDR_FLOATING(GPIOE_OE_CAM2_N) |  \
                                     PIN_PUPDR_FLOATING(GPIOE_SPI4_SCK) |   \
                                     PIN_PUPDR_FLOATING(GPIOE_IR_SIGNAL) |  \
                                     PIN_PUPDR_FLOATING(GPIOE_DSFDM1_DATIN3_MIC12) |\
                                     PIN_PUPDR_FLOATING(GPIOE_SPI4_MISO) |  \
                                     PIN_PUPDR_FLOATING(GPIOE_SPI4_MOSI) |  \
                                     PIN_PUPDR_FLOATING(GPIOE_UART7_RX) |   \
                                     PIN_PUPDR_FLOATING(GPIOE_IMU_INT2) |   \
                                     PIN_PUPDR_FLOATING(GPIOE_UART7_RTS) |  \
                                     PIN_PUPDR_FLOATING(GPIOE_UART7_CTS) |  \
                                     PIN_PUPDR_FLOATING(GPIOE_SPI3_CS_N_ESP32) |\
                                     PIN_PUPDR_FLOATING(GPIOE_DFSDM1_DATIN5_MIC34) |\
                                     PIN_PUPDR_FLOATING(GPIOE_FRONT_LED_R) |\
                                     PIN_PUPDR_FLOATING(GPIOE_FRONT_LED_G) |\
                                     PIN_PUPDR_FLOATING(GPIOE_FRONT_LED_B))
#define VAL_GPIOE_ODR               (PIN_ODR_HIGH(GPIOE_OE_CAM1_N) |        \
                                     PIN_ODR_HIGH(GPIOE_OE_CAM2_N) |        \
                                     PIN_ODR_HIGH(GPIOE_SPI4_SCK) |         \
                                     PIN_ODR_HIGH(GPIOE_IR_SIGNAL) |        \
                                     PIN_ODR_HIGH(GPIOE_DSFDM1_DATIN3_MIC12) |\
                                     PIN_ODR_HIGH(GPIOE_SPI4_MISO) |        \
                                     PIN_ODR_HIGH(GPIOE_SPI4_MOSI) |        \
                                     PIN_ODR_HIGH(GPIOE_UART7_RX) |         \
                                     PIN_ODR_HIGH(GPIOE_IMU_INT2) |         \
                                     PIN_ODR_HIGH(GPIOE_UART7_RTS) |        \
                                     PIN_ODR_HIGH(GPIOE_UART7_CTS) |        \
                                     PIN_ODR_HIGH(GPIOE_SPI3_CS_N_ESP32) |  \
                                     PIN_ODR_HIGH(GPIOE_DFSDM1_DATIN5_MIC34) |\
                                     PIN_ODR_HIGH(GPIOE_FRONT_LED_R) |      \
                                     PIN_ODR_HIGH(GPIOE_FRONT_LED_G) |      \
                                     PIN_ODR_HIGH(GPIOE_FRONT_LED_B))
#define VAL_GPIOE_AFRL              (PIN_AFIO_AF(GPIOE_OE_CAM1_N, 0U) |     \
                                     PIN_AFIO_AF(GPIOE_OE_CAM2_N, 0U) |     \
                                     PIN_AFIO_AF(GPIOE_SPI4_SCK, 5U) |      \
                                     PIN_AFIO_AF(GPIOE_IR_SIGNAL, 0U) |     \
                                     PIN_AFIO_AF(GPIOE_DSFDM1_DATIN3_MIC12, 10U) |\
                                     PIN_AFIO_AF(GPIOE_SPI4_MISO, 5U) |     \
                                     PIN_AFIO_AF(GPIOE_SPI4_MOSI, 5U) |     \
                                     PIN_AFIO_AF(GPIOE_UART7_RX, 8U))
#define VAL_GPIOE_AFRH              (PIN_AFIO_AF(GPIOE_IMU_INT2, 0U) |      \
                                     PIN_AFIO_AF(GPIOE_UART7_RTS, 8U) |     \
                                     PIN_AFIO_AF(GPIOE_UART7_CTS, 8U) |     \
                                     PIN_AFIO_AF(GPIOE_SPI3_CS_N_ESP32, 0U) |\
                                     PIN_AFIO_AF(GPIOE_DFSDM1_DATIN5_MIC34, 6U) |\
                                     PIN_AFIO_AF(GPIOE_FRONT_LED_R, 0U) |   \
                                     PIN_AFIO_AF(GPIOE_FRONT_LED_G, 0U) |   \
                                     PIN_AFIO_AF(GPIOE_FRONT_LED_B, 0U))

/*
 * GPIOF setup:
 *
 * PF0  - USSR_BUTTON_N             (input pullup).
 * PF1  - I2C2_SCL                  (alternate 4).
 * PF2  - POWER_ON                  (output pushpull minimum).
 * PF3  - ADC3_IN9                  (analog).
 * PF4  - ADC3_IN14                 (analog).
 * PF5  - ADC3_IN15                 (analog).
 * PF6  - PIN6                      (input pulldown).
 * PF7  - PIN7                      (input pulldown).
 * PF8  - PIN8                      (input pulldown).
 * PF9  - PIN9                      (input pulldown).
 * PF10 - ADC3_IN8                  (analog).
 * PF11 - SPI2_CS_N_IMU             (output pushpull maximum).
 * PF12 - SPI2_CS_N_PRESS           (output pushpull maximum).
 * PF13 - RIGHT_LED_R               (output pushpull maximum).
 * PF14 - RIGHT_LED_G               (output pushpull maximum).
 * PF15 - RIGHT_LED_B               (output pushpull maximum).
 */
#define VAL_GPIOF_MODER             (PIN_MODE_INPUT(GPIOF_USSR_BUTTON_N) |  \
                                     PIN_MODE_ALTERNATE(GPIOF_I2C2_SCL) |   \
                                     PIN_MODE_OUTPUT(GPIOF_POWER_ON) |      \
                                     PIN_MODE_ANALOG(GPIOF_ADC3_IN9) |      \
                                     PIN_MODE_ANALOG(GPIOF_ADC3_IN14) |     \
                                     PIN_MODE_ANALOG(GPIOF_ADC3_IN15) |     \
                                     PIN_MODE_INPUT(GPIOF_PIN6) |           \
                                     PIN_MODE_INPUT(GPIOF_PIN7) |           \
                                     PIN_MODE_INPUT(GPIOF_PIN8) |           \
                                     PIN_MODE_INPUT(GPIOF_PIN9) |           \
                                     PIN_MODE_ANALOG(GPIOF_ADC3_IN8) |      \
                                     PIN_MODE_OUTPUT(GPIOF_SPI2_CS_N_IMU) | \
                                     PIN_MODE_OUTPUT(GPIOF_SPI2_CS_N_PRESS) |\
                                     PIN_MODE_OUTPUT(GPIOF_RIGHT_LED_R) |   \
                                     PIN_MODE_OUTPUT(GPIOF_RIGHT_LED_G) |   \
                                     PIN_MODE_OUTPUT(GPIOF_RIGHT_LED_B))
#define VAL_GPIOF_OTYPER            (PIN_OTYPE_PUSHPULL(GPIOF_USSR_BUTTON_N) |\
                                     PIN_OTYPE_OPENDRAIN(GPIOF_I2C2_SCL) |  \
                                     PIN_OTYPE_PUSHPULL(GPIOF_POWER_ON) |   \
                                     PIN_OTYPE_PUSHPULL(GPIOF_ADC3_IN9) |   \
                                     PIN_OTYPE_PUSHPULL(GPIOF_ADC3_IN14) |  \
                                     PIN_OTYPE_PUSHPULL(GPIOF_ADC3_IN15) |  \
                                     PIN_OTYPE_PUSHPULL(GPIOF_PIN6) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOF_PIN7) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOF_PIN8) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOF_PIN9) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOF_ADC3_IN8) |   \
                                     PIN_OTYPE_PUSHPULL(GPIOF_SPI2_CS_N_IMU) |\
                                     PIN_OTYPE_PUSHPULL(GPIOF_SPI2_CS_N_PRESS) |\
                                     PIN_OTYPE_PUSHPULL(GPIOF_RIGHT_LED_R) |\
                                     PIN_OTYPE_PUSHPULL(GPIOF_RIGHT_LED_G) |\
                                     PIN_OTYPE_PUSHPULL(GPIOF_RIGHT_LED_B))
#define VAL_GPIOF_OSPEEDR           (PIN_OSPEED_HIGH(GPIOF_USSR_BUTTON_N) | \
                                     PIN_OSPEED_HIGH(GPIOF_I2C2_SCL) |      \
                                     PIN_OSPEED_VERYLOW(GPIOF_POWER_ON) |   \
                                     PIN_OSPEED_VERYLOW(GPIOF_ADC3_IN9) |   \
                                     PIN_OSPEED_VERYLOW(GPIOF_ADC3_IN14) |  \
                                     PIN_OSPEED_VERYLOW(GPIOF_ADC3_IN15) |  \
                                     PIN_OSPEED_VERYLOW(GPIOF_PIN6) |       \
                                     PIN_OSPEED_VERYLOW(GPIOF_PIN7) |       \
                                     PIN_OSPEED_VERYLOW(GPIOF_PIN8) |       \
                                     PIN_OSPEED_VERYLOW(GPIOF_PIN9) |       \
                                     PIN_OSPEED_VERYLOW(GPIOF_ADC3_IN8) |   \
                                     PIN_OSPEED_HIGH(GPIOF_SPI2_CS_N_IMU) | \
                                     PIN_OSPEED_HIGH(GPIOF_SPI2_CS_N_PRESS) |\
                                     PIN_OSPEED_HIGH(GPIOF_RIGHT_LED_R) |   \
                                     PIN_OSPEED_HIGH(GPIOF_RIGHT_LED_G) |   \
                                     PIN_OSPEED_HIGH(GPIOF_RIGHT_LED_B))
#define VAL_GPIOF_PUPDR             (PIN_PUPDR_PULLUP(GPIOF_USSR_BUTTON_N) |\
                                     PIN_PUPDR_FLOATING(GPIOF_I2C2_SCL) |   \
                                     PIN_PUPDR_FLOATING(GPIOF_POWER_ON) |   \
                                     PIN_PUPDR_FLOATING(GPIOF_ADC3_IN9) |   \
                                     PIN_PUPDR_FLOATING(GPIOF_ADC3_IN14) |  \
                                     PIN_PUPDR_FLOATING(GPIOF_ADC3_IN15) |  \
                                     PIN_PUPDR_PULLDOWN(GPIOF_PIN6) |       \
                                     PIN_PUPDR_PULLDOWN(GPIOF_PIN7) |       \
                                     PIN_PUPDR_PULLDOWN(GPIOF_PIN8) |       \
                                     PIN_PUPDR_PULLDOWN(GPIOF_PIN9) |       \
                                     PIN_PUPDR_FLOATING(GPIOF_ADC3_IN8) |   \
                                     PIN_PUPDR_FLOATING(GPIOF_SPI2_CS_N_IMU) |\
                                     PIN_PUPDR_FLOATING(GPIOF_SPI2_CS_N_PRESS) |\
                                     PIN_PUPDR_FLOATING(GPIOF_RIGHT_LED_R) |\
                                     PIN_PUPDR_FLOATING(GPIOF_RIGHT_LED_G) |\
                                     PIN_PUPDR_FLOATING(GPIOF_RIGHT_LED_B))
#define VAL_GPIOF_ODR               (PIN_ODR_HIGH(GPIOF_USSR_BUTTON_N) |    \
                                     PIN_ODR_HIGH(GPIOF_I2C2_SCL) |         \
                                     PIN_ODR_LOW(GPIOF_POWER_ON) |          \
                                     PIN_ODR_HIGH(GPIOF_ADC3_IN9) |         \
                                     PIN_ODR_HIGH(GPIOF_ADC3_IN14) |        \
                                     PIN_ODR_HIGH(GPIOF_ADC3_IN15) |        \
                                     PIN_ODR_HIGH(GPIOF_PIN6) |             \
                                     PIN_ODR_HIGH(GPIOF_PIN7) |             \
                                     PIN_ODR_HIGH(GPIOF_PIN8) |             \
                                     PIN_ODR_HIGH(GPIOF_PIN9) |             \
                                     PIN_ODR_HIGH(GPIOF_ADC3_IN8) |         \
                                     PIN_ODR_HIGH(GPIOF_SPI2_CS_N_IMU) |    \
                                     PIN_ODR_HIGH(GPIOF_SPI2_CS_N_PRESS) |  \
                                     PIN_ODR_HIGH(GPIOF_RIGHT_LED_R) |      \
                                     PIN_ODR_HIGH(GPIOF_RIGHT_LED_G) |      \
                                     PIN_ODR_HIGH(GPIOF_RIGHT_LED_B))
#define VAL_GPIOF_AFRL              (PIN_AFIO_AF(GPIOF_USSR_BUTTON_N, 0U) | \
                                     PIN_AFIO_AF(GPIOF_I2C2_SCL, 4U) |      \
                                     PIN_AFIO_AF(GPIOF_POWER_ON, 0U) |      \
                                     PIN_AFIO_AF(GPIOF_ADC3_IN9, 0U) |      \
                                     PIN_AFIO_AF(GPIOF_ADC3_IN14, 0U) |     \
                                     PIN_AFIO_AF(GPIOF_ADC3_IN15, 0U) |     \
                                     PIN_AFIO_AF(GPIOF_PIN6, 0U) |          \
                                     PIN_AFIO_AF(GPIOF_PIN7, 0U))
#define VAL_GPIOF_AFRH              (PIN_AFIO_AF(GPIOF_PIN8, 0U) |          \
                                     PIN_AFIO_AF(GPIOF_PIN9, 0U) |          \
                                     PIN_AFIO_AF(GPIOF_ADC3_IN8, 0U) |      \
                                     PIN_AFIO_AF(GPIOF_SPI2_CS_N_IMU, 0U) | \
                                     PIN_AFIO_AF(GPIOF_SPI2_CS_N_PRESS, 0U) |\
                                     PIN_AFIO_AF(GPIOF_RIGHT_LED_R, 0U) |   \
                                     PIN_AFIO_AF(GPIOF_RIGHT_LED_G, 0U) |   \
                                     PIN_AFIO_AF(GPIOF_RIGHT_LED_B, 0U))

/*
 * GPIOG setup:
 *
 * PG0  - REAR_LED_R                (output pushpull maximum).
 * PG1  - REAR_LED_G                (output pushpull maximum).
 * PG2  - REAR_LED_B                (output pushpull maximum).
 * PG3  - LEFT_LED_R                (output pushpull maximum).
 * PG4  - LEFT_LED_G                (output pushpull maximum).
 * PG5  - LEFT_LED_B                (output pushpull maximum).
 * PG6  - PIN6                      (input pulldown).
 * PG7  - SWCLK_PROG                (input floating).
 * PG8  - SWDIO_PROG                (input floating).
 * PG9  - SPI1_MISO                 (alternate 5).
 * PG10 - DCMI_D2                   (alternate 13).
 * PG11 - SPI1_SCK                  (alternate 5).
 * PG12 - USART6_RTS                (alternate 8).
 * PG13 - USART6_CTS                (alternate 8).
 * PG14 - PIN14                     (input pulldown).
 * PG15 - EN_N_CAN_UC               (output pushpull minimum).
 */
#define VAL_GPIOG_MODER             (PIN_MODE_OUTPUT(GPIOG_REAR_LED_R) |    \
                                     PIN_MODE_OUTPUT(GPIOG_REAR_LED_G) |    \
                                     PIN_MODE_OUTPUT(GPIOG_REAR_LED_B) |    \
                                     PIN_MODE_OUTPUT(GPIOG_LEFT_LED_R) |    \
                                     PIN_MODE_OUTPUT(GPIOG_LEFT_LED_G) |    \
                                     PIN_MODE_OUTPUT(GPIOG_LEFT_LED_B) |    \
                                     PIN_MODE_INPUT(GPIOG_PIN6) |           \
                                     PIN_MODE_INPUT(GPIOG_SWCLK_PROG) |     \
                                     PIN_MODE_INPUT(GPIOG_SWDIO_PROG) |     \
                                     PIN_MODE_ALTERNATE(GPIOG_SPI1_MISO) |  \
                                     PIN_MODE_ALTERNATE(GPIOG_DCMI_D2) |    \
                                     PIN_MODE_ALTERNATE(GPIOG_SPI1_SCK) |   \
                                     PIN_MODE_ALTERNATE(GPIOG_USART6_RTS) | \
                                     PIN_MODE_ALTERNATE(GPIOG_USART6_CTS) | \
                                     PIN_MODE_INPUT(GPIOG_PIN14) |          \
                                     PIN_MODE_OUTPUT(GPIOG_EN_N_CAN_UC))
#define VAL_GPIOG_OTYPER            (PIN_OTYPE_PUSHPULL(GPIOG_REAR_LED_R) | \
                                     PIN_OTYPE_PUSHPULL(GPIOG_REAR_LED_G) | \
                                     PIN_OTYPE_PUSHPULL(GPIOG_REAR_LED_B) | \
                                     PIN_OTYPE_PUSHPULL(GPIOG_LEFT_LED_R) | \
                                     PIN_OTYPE_PUSHPULL(GPIOG_LEFT_LED_G) | \
                                     PIN_OTYPE_PUSHPULL(GPIOG_LEFT_LED_B) | \
                                     PIN_OTYPE_PUSHPULL(GPIOG_PIN6) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOG_SWCLK_PROG) | \
                                     PIN_OTYPE_PUSHPULL(GPIOG_SWDIO_PROG) | \
                                     PIN_OTYPE_PUSHPULL(GPIOG_SPI1_MISO) |  \
                                     PIN_OTYPE_PUSHPULL(GPIOG_DCMI_D2) |    \
                                     PIN_OTYPE_PUSHPULL(GPIOG_SPI1_SCK) |   \
                                     PIN_OTYPE_PUSHPULL(GPIOG_USART6_RTS) | \
                                     PIN_OTYPE_PUSHPULL(GPIOG_USART6_CTS) | \
                                     PIN_OTYPE_PUSHPULL(GPIOG_PIN14) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOG_EN_N_CAN_UC))
#define VAL_GPIOG_OSPEEDR           (PIN_OSPEED_HIGH(GPIOG_REAR_LED_R) |    \
                                     PIN_OSPEED_HIGH(GPIOG_REAR_LED_G) |    \
                                     PIN_OSPEED_HIGH(GPIOG_REAR_LED_B) |    \
                                     PIN_OSPEED_HIGH(GPIOG_LEFT_LED_R) |    \
                                     PIN_OSPEED_HIGH(GPIOG_LEFT_LED_G) |    \
                                     PIN_OSPEED_HIGH(GPIOG_LEFT_LED_B) |    \
                                     PIN_OSPEED_VERYLOW(GPIOG_PIN6) |       \
                                     PIN_OSPEED_HIGH(GPIOG_SWCLK_PROG) |    \
                                     PIN_OSPEED_HIGH(GPIOG_SWDIO_PROG) |    \
                                     PIN_OSPEED_HIGH(GPIOG_SPI1_MISO) |     \
                                     PIN_OSPEED_HIGH(GPIOG_DCMI_D2) |       \
                                     PIN_OSPEED_HIGH(GPIOG_SPI1_SCK) |      \
                                     PIN_OSPEED_HIGH(GPIOG_USART6_RTS) |    \
                                     PIN_OSPEED_HIGH(GPIOG_USART6_CTS) |    \
                                     PIN_OSPEED_VERYLOW(GPIOG_PIN14) |      \
                                     PIN_OSPEED_VERYLOW(GPIOG_EN_N_CAN_UC))
#define VAL_GPIOG_PUPDR             (PIN_PUPDR_FLOATING(GPIOG_REAR_LED_R) | \
                                     PIN_PUPDR_FLOATING(GPIOG_REAR_LED_G) | \
                                     PIN_PUPDR_FLOATING(GPIOG_REAR_LED_B) | \
                                     PIN_PUPDR_FLOATING(GPIOG_LEFT_LED_R) | \
                                     PIN_PUPDR_FLOATING(GPIOG_LEFT_LED_G) | \
                                     PIN_PUPDR_FLOATING(GPIOG_LEFT_LED_B) | \
                                     PIN_PUPDR_PULLDOWN(GPIOG_PIN6) |       \
                                     PIN_PUPDR_FLOATING(GPIOG_SWCLK_PROG) | \
                                     PIN_PUPDR_FLOATING(GPIOG_SWDIO_PROG) | \
                                     PIN_PUPDR_FLOATING(GPIOG_SPI1_MISO) |  \
                                     PIN_PUPDR_FLOATING(GPIOG_DCMI_D2) |    \
                                     PIN_PUPDR_FLOATING(GPIOG_SPI1_SCK) |   \
                                     PIN_PUPDR_FLOATING(GPIOG_USART6_RTS) | \
                                     PIN_PUPDR_FLOATING(GPIOG_USART6_CTS) | \
                                     PIN_PUPDR_PULLDOWN(GPIOG_PIN14) |      \
                                     PIN_PUPDR_FLOATING(GPIOG_EN_N_CAN_UC))
#define VAL_GPIOG_ODR               (PIN_ODR_HIGH(GPIOG_REAR_LED_R) |       \
                                     PIN_ODR_HIGH(GPIOG_REAR_LED_G) |       \
                                     PIN_ODR_HIGH(GPIOG_REAR_LED_B) |       \
                                     PIN_ODR_HIGH(GPIOG_LEFT_LED_R) |       \
                                     PIN_ODR_HIGH(GPIOG_LEFT_LED_G) |       \
                                     PIN_ODR_HIGH(GPIOG_LEFT_LED_B) |       \
                                     PIN_ODR_HIGH(GPIOG_PIN6) |             \
                                     PIN_ODR_HIGH(GPIOG_SWCLK_PROG) |       \
                                     PIN_ODR_HIGH(GPIOG_SWDIO_PROG) |       \
                                     PIN_ODR_HIGH(GPIOG_SPI1_MISO) |        \
                                     PIN_ODR_HIGH(GPIOG_DCMI_D2) |          \
                                     PIN_ODR_HIGH(GPIOG_SPI1_SCK) |         \
                                     PIN_ODR_HIGH(GPIOG_USART6_RTS) |       \
                                     PIN_ODR_HIGH(GPIOG_USART6_CTS) |       \
                                     PIN_ODR_HIGH(GPIOG_PIN14) |            \
                                     PIN_ODR_HIGH(GPIOG_EN_N_CAN_UC))
#define VAL_GPIOG_AFRL              (PIN_AFIO_AF(GPIOG_REAR_LED_R, 0U) |    \
                                     PIN_AFIO_AF(GPIOG_REAR_LED_G, 0U) |    \
                                     PIN_AFIO_AF(GPIOG_REAR_LED_B, 0U) |    \
                                     PIN_AFIO_AF(GPIOG_LEFT_LED_R, 0U) |    \
                                     PIN_AFIO_AF(GPIOG_LEFT_LED_G, 0U) |    \
                                     PIN_AFIO_AF(GPIOG_LEFT_LED_B, 0U) |    \
                                     PIN_AFIO_AF(GPIOG_PIN6, 0U) |          \
                                     PIN_AFIO_AF(GPIOG_SWCLK_PROG, 0U))
#define VAL_GPIOG_AFRH              (PIN_AFIO_AF(GPIOG_SWDIO_PROG, 0U) |    \
                                     PIN_AFIO_AF(GPIOG_SPI1_MISO, 5U) |     \
                                     PIN_AFIO_AF(GPIOG_DCMI_D2, 13U) |      \
                                     PIN_AFIO_AF(GPIOG_SPI1_SCK, 5U) |      \
                                     PIN_AFIO_AF(GPIOG_USART6_RTS, 8U) |    \
                                     PIN_AFIO_AF(GPIOG_USART6_CTS, 8U) |    \
                                     PIN_AFIO_AF(GPIOG_PIN14, 0U) |         \
                                     PIN_AFIO_AF(GPIOG_EN_N_CAN_UC, 0U))

/*
 * GPIOH setup:
 *
 * PH0  - OSC_IN                    (input floating).
 * PH1  - OSC_OUT                   (input floating).
 * PH2  - PWR_BTN_STATE_N           (input floating).
 * PH3  - EN_TOF                    (output pushpull minimum).
 * PH4  - USB_OTG_HS_ULPI_NXT       (alternate 10).
 * PH5  - I2C2_SDA                  (alternate 4).
 * PH6  - PIN6                      (input pulldown).
 * PH7  - PIN7                      (input pulldown).
 * PH8  - DCMI_HSYNC                (alternate 13).
 * PH9  - DCMI_D0                   (alternate 13).
 * PH10 - EN_CAM1                   (output pushpull maximum).
 * PH11 - EN_CAM2                   (output pushpull maximum).
 * PH12 - DCMI_D3                   (alternate 13).
 * PH13 - UART4_TX                  (alternate 8).
 * PH14 - DCMI_D4                   (alternate 13).
 * PH15 - DCMI_D11                  (alternate 13).
 */
#define VAL_GPIOH_MODER             (PIN_MODE_INPUT(GPIOH_OSC_IN) |         \
                                     PIN_MODE_INPUT(GPIOH_OSC_OUT) |        \
                                     PIN_MODE_INPUT(GPIOH_PWR_BTN_STATE_N) |\
                                     PIN_MODE_OUTPUT(GPIOH_EN_TOF) |        \
                                     PIN_MODE_ALTERNATE(GPIOH_USB_OTG_HS_ULPI_NXT) |\
                                     PIN_MODE_ALTERNATE(GPIOH_I2C2_SDA) |   \
                                     PIN_MODE_INPUT(GPIOH_PIN6) |           \
                                     PIN_MODE_INPUT(GPIOH_PIN7) |           \
                                     PIN_MODE_ALTERNATE(GPIOH_DCMI_HSYNC) | \
                                     PIN_MODE_ALTERNATE(GPIOH_DCMI_D0) |    \
                                     PIN_MODE_OUTPUT(GPIOH_EN_CAM1) |       \
                                     PIN_MODE_OUTPUT(GPIOH_EN_CAM2) |       \
                                     PIN_MODE_ALTERNATE(GPIOH_DCMI_D3) |    \
                                     PIN_MODE_ALTERNATE(GPIOH_UART4_TX) |   \
                                     PIN_MODE_ALTERNATE(GPIOH_DCMI_D4) |    \
                                     PIN_MODE_ALTERNATE(GPIOH_DCMI_D11))
#define VAL_GPIOH_OTYPER            (PIN_OTYPE_PUSHPULL(GPIOH_OSC_IN) |     \
                                     PIN_OTYPE_PUSHPULL(GPIOH_OSC_OUT) |    \
                                     PIN_OTYPE_PUSHPULL(GPIOH_PWR_BTN_STATE_N) |\
                                     PIN_OTYPE_PUSHPULL(GPIOH_EN_TOF) |     \
                                     PIN_OTYPE_PUSHPULL(GPIOH_USB_OTG_HS_ULPI_NXT) |\
                                     PIN_OTYPE_OPENDRAIN(GPIOH_I2C2_SDA) |  \
                                     PIN_OTYPE_PUSHPULL(GPIOH_PIN6) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOH_PIN7) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOH_DCMI_HSYNC) | \
                                     PIN_OTYPE_PUSHPULL(GPIOH_DCMI_D0) |    \
                                     PIN_OTYPE_PUSHPULL(GPIOH_EN_CAM1) |    \
                                     PIN_OTYPE_PUSHPULL(GPIOH_EN_CAM2) |    \
                                     PIN_OTYPE_PUSHPULL(GPIOH_DCMI_D3) |    \
                                     PIN_OTYPE_PUSHPULL(GPIOH_UART4_TX) |   \
                                     PIN_OTYPE_PUSHPULL(GPIOH_DCMI_D4) |    \
                                     PIN_OTYPE_PUSHPULL(GPIOH_DCMI_D11))
#define VAL_GPIOH_OSPEEDR           (PIN_OSPEED_HIGH(GPIOH_OSC_IN) |        \
                                     PIN_OSPEED_HIGH(GPIOH_OSC_OUT) |       \
                                     PIN_OSPEED_VERYLOW(GPIOH_PWR_BTN_STATE_N) |\
                                     PIN_OSPEED_VERYLOW(GPIOH_EN_TOF) |     \
                                     PIN_OSPEED_HIGH(GPIOH_USB_OTG_HS_ULPI_NXT) |\
                                     PIN_OSPEED_HIGH(GPIOH_I2C2_SDA) |      \
                                     PIN_OSPEED_VERYLOW(GPIOH_PIN6) |       \
                                     PIN_OSPEED_VERYLOW(GPIOH_PIN7) |       \
                                     PIN_OSPEED_HIGH(GPIOH_DCMI_HSYNC) |    \
                                     PIN_OSPEED_HIGH(GPIOH_DCMI_D0) |       \
                                     PIN_OSPEED_HIGH(GPIOH_EN_CAM1) |       \
                                     PIN_OSPEED_HIGH(GPIOH_EN_CAM2) |       \
                                     PIN_OSPEED_HIGH(GPIOH_DCMI_D3) |       \
                                     PIN_OSPEED_HIGH(GPIOH_UART4_TX) |      \
                                     PIN_OSPEED_HIGH(GPIOH_DCMI_D4) |       \
                                     PIN_OSPEED_HIGH(GPIOH_DCMI_D11))
#define VAL_GPIOH_PUPDR             (PIN_PUPDR_FLOATING(GPIOH_OSC_IN) |     \
                                     PIN_PUPDR_FLOATING(GPIOH_OSC_OUT) |    \
                                     PIN_PUPDR_FLOATING(GPIOH_PWR_BTN_STATE_N) |\
                                     PIN_PUPDR_FLOATING(GPIOH_EN_TOF) |     \
                                     PIN_PUPDR_FLOATING(GPIOH_USB_OTG_HS_ULPI_NXT) |\
                                     PIN_PUPDR_FLOATING(GPIOH_I2C2_SDA) |   \
                                     PIN_PUPDR_PULLDOWN(GPIOH_PIN6) |       \
                                     PIN_PUPDR_PULLDOWN(GPIOH_PIN7) |       \
                                     PIN_PUPDR_FLOATING(GPIOH_DCMI_HSYNC) | \
                                     PIN_PUPDR_FLOATING(GPIOH_DCMI_D0) |    \
                                     PIN_PUPDR_FLOATING(GPIOH_EN_CAM1) |    \
                                     PIN_PUPDR_FLOATING(GPIOH_EN_CAM2) |    \
                                     PIN_PUPDR_FLOATING(GPIOH_DCMI_D3) |    \
                                     PIN_PUPDR_FLOATING(GPIOH_UART4_TX) |   \
                                     PIN_PUPDR_FLOATING(GPIOH_DCMI_D4) |    \
                                     PIN_PUPDR_FLOATING(GPIOH_DCMI_D11))
#define VAL_GPIOH_ODR               (PIN_ODR_HIGH(GPIOH_OSC_IN) |           \
                                     PIN_ODR_HIGH(GPIOH_OSC_OUT) |          \
                                     PIN_ODR_HIGH(GPIOH_PWR_BTN_STATE_N) |  \
                                     PIN_ODR_LOW(GPIOH_EN_TOF) |            \
                                     PIN_ODR_HIGH(GPIOH_USB_OTG_HS_ULPI_NXT) |\
                                     PIN_ODR_HIGH(GPIOH_I2C2_SDA) |         \
                                     PIN_ODR_HIGH(GPIOH_PIN6) |             \
                                     PIN_ODR_HIGH(GPIOH_PIN7) |             \
                                     PIN_ODR_HIGH(GPIOH_DCMI_HSYNC) |       \
                                     PIN_ODR_HIGH(GPIOH_DCMI_D0) |          \
                                     PIN_ODR_LOW(GPIOH_EN_CAM1) |           \
                                     PIN_ODR_LOW(GPIOH_EN_CAM2) |           \
                                     PIN_ODR_HIGH(GPIOH_DCMI_D3) |          \
                                     PIN_ODR_HIGH(GPIOH_UART4_TX) |         \
                                     PIN_ODR_HIGH(GPIOH_DCMI_D4) |          \
                                     PIN_ODR_HIGH(GPIOH_DCMI_D11))
#define VAL_GPIOH_AFRL              (PIN_AFIO_AF(GPIOH_OSC_IN, 0U) |        \
                                     PIN_AFIO_AF(GPIOH_OSC_OUT, 0U) |       \
                                     PIN_AFIO_AF(GPIOH_PWR_BTN_STATE_N, 0U) |\
                                     PIN_AFIO_AF(GPIOH_EN_TOF, 0U) |        \
                                     PIN_AFIO_AF(GPIOH_USB_OTG_HS_ULPI_NXT, 10U) |\
                                     PIN_AFIO_AF(GPIOH_I2C2_SDA, 4U) |      \
                                     PIN_AFIO_AF(GPIOH_PIN6, 0U) |          \
                                     PIN_AFIO_AF(GPIOH_PIN7, 0U))
#define VAL_GPIOH_AFRH              (PIN_AFIO_AF(GPIOH_DCMI_HSYNC, 13U) |   \
                                     PIN_AFIO_AF(GPIOH_DCMI_D0, 13U) |      \
                                     PIN_AFIO_AF(GPIOH_EN_CAM1, 0U) |       \
                                     PIN_AFIO_AF(GPIOH_EN_CAM2, 0U) |       \
                                     PIN_AFIO_AF(GPIOH_DCMI_D3, 13U) |      \
                                     PIN_AFIO_AF(GPIOH_UART4_TX, 8U) |      \
                                     PIN_AFIO_AF(GPIOH_DCMI_D4, 13U) |      \
                                     PIN_AFIO_AF(GPIOH_DCMI_D11, 13U))

/*
 * GPIOI setup:
 *
 * PI0  - PIN0                      (input pulldown).
 * PI1  - DCMI_D8                   (alternate 13).
 * PI2  - DCMI_D9                   (alternate 13).
 * PI3  - DCMI_D10                  (alternate 13).
 * PI4  - DCMI_D5                   (alternate 13).
 * PI5  - DCMI_VSYNC                (alternate 13).
 * PI6  - DCMI_D6                   (alternate 13).
 * PI7  - DCMI_D7                   (alternate 13).
 * PI8  - PIN8                      (input pulldown).
 * PI9  - UART4_RX                  (alternate 8).
 * PI10 - EN_PHY_HS                 (output pushpull minimum).
 * PI11 - USB_OTG_HS_ULPI_DIR       (alternate 10).
 * PI12 - PIN12                     (input pulldown).
 * PI13 - PIN13                     (input pulldown).
 * PI14 - PIN14                     (input pulldown).
 * PI15 - PIN15                     (input pulldown).
 */
#define VAL_GPIOI_MODER             (PIN_MODE_INPUT(GPIOI_PIN0) |           \
                                     PIN_MODE_ALTERNATE(GPIOI_DCMI_D8) |    \
                                     PIN_MODE_ALTERNATE(GPIOI_DCMI_D9) |    \
                                     PIN_MODE_ALTERNATE(GPIOI_DCMI_D10) |   \
                                     PIN_MODE_ALTERNATE(GPIOI_DCMI_D5) |    \
                                     PIN_MODE_ALTERNATE(GPIOI_DCMI_VSYNC) | \
                                     PIN_MODE_ALTERNATE(GPIOI_DCMI_D6) |    \
                                     PIN_MODE_ALTERNATE(GPIOI_DCMI_D7) |    \
                                     PIN_MODE_INPUT(GPIOI_PIN8) |           \
                                     PIN_MODE_ALTERNATE(GPIOI_UART4_RX) |   \
                                     PIN_MODE_OUTPUT(GPIOI_EN_PHY_HS) |     \
                                     PIN_MODE_ALTERNATE(GPIOI_USB_OTG_HS_ULPI_DIR) |\
                                     PIN_MODE_INPUT(GPIOI_PIN12) |          \
                                     PIN_MODE_INPUT(GPIOI_PIN13) |          \
                                     PIN_MODE_INPUT(GPIOI_PIN14) |          \
                                     PIN_MODE_INPUT(GPIOI_PIN15))
#define VAL_GPIOI_OTYPER            (PIN_OTYPE_PUSHPULL(GPIOI_PIN0) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOI_DCMI_D8) |    \
                                     PIN_OTYPE_PUSHPULL(GPIOI_DCMI_D9) |    \
                                     PIN_OTYPE_PUSHPULL(GPIOI_DCMI_D10) |   \
                                     PIN_OTYPE_PUSHPULL(GPIOI_DCMI_D5) |    \
                                     PIN_OTYPE_PUSHPULL(GPIOI_DCMI_VSYNC) | \
                                     PIN_OTYPE_PUSHPULL(GPIOI_DCMI_D6) |    \
                                     PIN_OTYPE_PUSHPULL(GPIOI_DCMI_D7) |    \
                                     PIN_OTYPE_PUSHPULL(GPIOI_PIN8) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOI_UART4_RX) |   \
                                     PIN_OTYPE_PUSHPULL(GPIOI_EN_PHY_HS) |  \
                                     PIN_OTYPE_PUSHPULL(GPIOI_USB_OTG_HS_ULPI_DIR) |\
                                     PIN_OTYPE_PUSHPULL(GPIOI_PIN12) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOI_PIN13) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOI_PIN14) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOI_PIN15))
#define VAL_GPIOI_OSPEEDR           (PIN_OSPEED_VERYLOW(GPIOI_PIN0) |       \
                                     PIN_OSPEED_HIGH(GPIOI_DCMI_D8) |       \
                                     PIN_OSPEED_HIGH(GPIOI_DCMI_D9) |       \
                                     PIN_OSPEED_HIGH(GPIOI_DCMI_D10) |      \
                                     PIN_OSPEED_HIGH(GPIOI_DCMI_D5) |       \
                                     PIN_OSPEED_HIGH(GPIOI_DCMI_VSYNC) |    \
                                     PIN_OSPEED_HIGH(GPIOI_DCMI_D6) |       \
                                     PIN_OSPEED_HIGH(GPIOI_DCMI_D7) |       \
                                     PIN_OSPEED_VERYLOW(GPIOI_PIN8) |       \
                                     PIN_OSPEED_HIGH(GPIOI_UART4_RX) |      \
                                     PIN_OSPEED_VERYLOW(GPIOI_EN_PHY_HS) |  \
                                     PIN_OSPEED_HIGH(GPIOI_USB_OTG_HS_ULPI_DIR) |\
                                     PIN_OSPEED_VERYLOW(GPIOI_PIN12) |      \
                                     PIN_OSPEED_VERYLOW(GPIOI_PIN13) |      \
                                     PIN_OSPEED_VERYLOW(GPIOI_PIN14) |      \
                                     PIN_OSPEED_VERYLOW(GPIOI_PIN15))
#define VAL_GPIOI_PUPDR             (PIN_PUPDR_PULLDOWN(GPIOI_PIN0) |       \
                                     PIN_PUPDR_FLOATING(GPIOI_DCMI_D8) |    \
                                     PIN_PUPDR_FLOATING(GPIOI_DCMI_D9) |    \
                                     PIN_PUPDR_FLOATING(GPIOI_DCMI_D10) |   \
                                     PIN_PUPDR_FLOATING(GPIOI_DCMI_D5) |    \
                                     PIN_PUPDR_FLOATING(GPIOI_DCMI_VSYNC) | \
                                     PIN_PUPDR_FLOATING(GPIOI_DCMI_D6) |    \
                                     PIN_PUPDR_FLOATING(GPIOI_DCMI_D7) |    \
                                     PIN_PUPDR_PULLDOWN(GPIOI_PIN8) |       \
                                     PIN_PUPDR_FLOATING(GPIOI_UART4_RX) |   \
                                     PIN_PUPDR_FLOATING(GPIOI_EN_PHY_HS) |  \
                                     PIN_PUPDR_FLOATING(GPIOI_USB_OTG_HS_ULPI_DIR) |\
                                     PIN_PUPDR_PULLDOWN(GPIOI_PIN12) |      \
                                     PIN_PUPDR_PULLDOWN(GPIOI_PIN13) |      \
                                     PIN_PUPDR_PULLDOWN(GPIOI_PIN14) |      \
                                     PIN_PUPDR_PULLDOWN(GPIOI_PIN15))
#define VAL_GPIOI_ODR               (PIN_ODR_HIGH(GPIOI_PIN0) |             \
                                     PIN_ODR_HIGH(GPIOI_DCMI_D8) |          \
                                     PIN_ODR_HIGH(GPIOI_DCMI_D9) |          \
                                     PIN_ODR_HIGH(GPIOI_DCMI_D10) |         \
                                     PIN_ODR_HIGH(GPIOI_DCMI_D5) |          \
                                     PIN_ODR_HIGH(GPIOI_DCMI_VSYNC) |       \
                                     PIN_ODR_HIGH(GPIOI_DCMI_D6) |          \
                                     PIN_ODR_HIGH(GPIOI_DCMI_D7) |          \
                                     PIN_ODR_HIGH(GPIOI_PIN8) |             \
                                     PIN_ODR_HIGH(GPIOI_UART4_RX) |         \
                                     PIN_ODR_LOW(GPIOI_EN_PHY_HS) |         \
                                     PIN_ODR_HIGH(GPIOI_USB_OTG_HS_ULPI_DIR) |\
                                     PIN_ODR_HIGH(GPIOI_PIN12) |            \
                                     PIN_ODR_HIGH(GPIOI_PIN13) |            \
                                     PIN_ODR_HIGH(GPIOI_PIN14) |            \
                                     PIN_ODR_HIGH(GPIOI_PIN15))
#define VAL_GPIOI_AFRL              (PIN_AFIO_AF(GPIOI_PIN0, 0U) |          \
                                     PIN_AFIO_AF(GPIOI_DCMI_D8, 13U) |      \
                                     PIN_AFIO_AF(GPIOI_DCMI_D9, 13U) |      \
                                     PIN_AFIO_AF(GPIOI_DCMI_D10, 13U) |     \
                                     PIN_AFIO_AF(GPIOI_DCMI_D5, 13U) |      \
                                     PIN_AFIO_AF(GPIOI_DCMI_VSYNC, 13U) |   \
                                     PIN_AFIO_AF(GPIOI_DCMI_D6, 13U) |      \
                                     PIN_AFIO_AF(GPIOI_DCMI_D7, 13U))
#define VAL_GPIOI_AFRH              (PIN_AFIO_AF(GPIOI_PIN8, 0U) |          \
                                     PIN_AFIO_AF(GPIOI_UART4_RX, 8U) |      \
                                     PIN_AFIO_AF(GPIOI_EN_PHY_HS, 0U) |     \
                                     PIN_AFIO_AF(GPIOI_USB_OTG_HS_ULPI_DIR, 10U) |\
                                     PIN_AFIO_AF(GPIOI_PIN12, 0U) |         \
                                     PIN_AFIO_AF(GPIOI_PIN13, 0U) |         \
                                     PIN_AFIO_AF(GPIOI_PIN14, 0U) |         \
                                     PIN_AFIO_AF(GPIOI_PIN15, 0U))

/*
 * GPIOJ setup:
 *
 * PJ0  - PIN0                      (input pulldown).
 * PJ1  - PIN1                      (input pulldown).
 * PJ2  - PIN2                      (input pulldown).
 * PJ3  - PIN3                      (input pulldown).
 * PJ4  - PIN4                      (input pulldown).
 * PJ5  - PIN5                      (input pulldown).
 * PJ6  - PIN6                      (input pulldown).
 * PJ7  - PIN7                      (input pulldown).
 * PJ8  - PIN8                      (input pulldown).
 * PJ9  - PIN9                      (input pulldown).
 * PJ10 - PIN10                     (input pulldown).
 * PJ11 - PIN11                     (input pulldown).
 * PJ12 - PIN12                     (input pulldown).
 * PJ13 - PIN13                     (input pulldown).
 * PJ14 - PIN14                     (input pulldown).
 * PJ15 - PIN15                     (input pulldown).
 */
#define VAL_GPIOJ_MODER             (PIN_MODE_INPUT(GPIOJ_PIN0) |           \
                                     PIN_MODE_INPUT(GPIOJ_PIN1) |           \
                                     PIN_MODE_INPUT(GPIOJ_PIN2) |           \
                                     PIN_MODE_INPUT(GPIOJ_PIN3) |           \
                                     PIN_MODE_INPUT(GPIOJ_PIN4) |           \
                                     PIN_MODE_INPUT(GPIOJ_PIN5) |           \
                                     PIN_MODE_INPUT(GPIOJ_PIN6) |           \
                                     PIN_MODE_INPUT(GPIOJ_PIN7) |           \
                                     PIN_MODE_INPUT(GPIOJ_PIN8) |           \
                                     PIN_MODE_INPUT(GPIOJ_PIN9) |           \
                                     PIN_MODE_INPUT(GPIOJ_PIN10) |          \
                                     PIN_MODE_INPUT(GPIOJ_PIN11) |          \
                                     PIN_MODE_INPUT(GPIOJ_PIN12) |          \
                                     PIN_MODE_INPUT(GPIOJ_PIN13) |          \
                                     PIN_MODE_INPUT(GPIOJ_PIN14) |          \
                                     PIN_MODE_INPUT(GPIOJ_PIN15))
#define VAL_GPIOJ_OTYPER            (PIN_OTYPE_PUSHPULL(GPIOJ_PIN0) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOJ_PIN1) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOJ_PIN2) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOJ_PIN3) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOJ_PIN4) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOJ_PIN5) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOJ_PIN6) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOJ_PIN7) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOJ_PIN8) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOJ_PIN9) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOJ_PIN10) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOJ_PIN11) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOJ_PIN12) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOJ_PIN13) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOJ_PIN14) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOJ_PIN15))
#define VAL_GPIOJ_OSPEEDR           (PIN_OSPEED_VERYLOW(GPIOJ_PIN0) |       \
                                     PIN_OSPEED_VERYLOW(GPIOJ_PIN1) |       \
                                     PIN_OSPEED_VERYLOW(GPIOJ_PIN2) |       \
                                     PIN_OSPEED_VERYLOW(GPIOJ_PIN3) |       \
                                     PIN_OSPEED_VERYLOW(GPIOJ_PIN4) |       \
                                     PIN_OSPEED_VERYLOW(GPIOJ_PIN5) |       \
                                     PIN_OSPEED_VERYLOW(GPIOJ_PIN6) |       \
                                     PIN_OSPEED_VERYLOW(GPIOJ_PIN7) |       \
                                     PIN_OSPEED_VERYLOW(GPIOJ_PIN8) |       \
                                     PIN_OSPEED_VERYLOW(GPIOJ_PIN9) |       \
                                     PIN_OSPEED_VERYLOW(GPIOJ_PIN10) |      \
                                     PIN_OSPEED_VERYLOW(GPIOJ_PIN11) |      \
                                     PIN_OSPEED_VERYLOW(GPIOJ_PIN12) |      \
                                     PIN_OSPEED_VERYLOW(GPIOJ_PIN13) |      \
                                     PIN_OSPEED_VERYLOW(GPIOJ_PIN14) |      \
                                     PIN_OSPEED_VERYLOW(GPIOJ_PIN15))
#define VAL_GPIOJ_PUPDR             (PIN_PUPDR_PULLDOWN(GPIOJ_PIN0) |       \
                                     PIN_PUPDR_PULLDOWN(GPIOJ_PIN1) |       \
                                     PIN_PUPDR_PULLDOWN(GPIOJ_PIN2) |       \
                                     PIN_PUPDR_PULLDOWN(GPIOJ_PIN3) |       \
                                     PIN_PUPDR_PULLDOWN(GPIOJ_PIN4) |       \
                                     PIN_PUPDR_PULLDOWN(GPIOJ_PIN5) |       \
                                     PIN_PUPDR_PULLDOWN(GPIOJ_PIN6) |       \
                                     PIN_PUPDR_PULLDOWN(GPIOJ_PIN7) |       \
                                     PIN_PUPDR_PULLDOWN(GPIOJ_PIN8) |       \
                                     PIN_PUPDR_PULLDOWN(GPIOJ_PIN9) |       \
                                     PIN_PUPDR_PULLDOWN(GPIOJ_PIN10) |      \
                                     PIN_PUPDR_PULLDOWN(GPIOJ_PIN11) |      \
                                     PIN_PUPDR_PULLDOWN(GPIOJ_PIN12) |      \
                                     PIN_PUPDR_PULLDOWN(GPIOJ_PIN13) |      \
                                     PIN_PUPDR_PULLDOWN(GPIOJ_PIN14) |      \
                                     PIN_PUPDR_PULLDOWN(GPIOJ_PIN15))
#define VAL_GPIOJ_ODR               (PIN_ODR_HIGH(GPIOJ_PIN0) |             \
                                     PIN_ODR_HIGH(GPIOJ_PIN1) |             \
                                     PIN_ODR_HIGH(GPIOJ_PIN2) |             \
                                     PIN_ODR_HIGH(GPIOJ_PIN3) |             \
                                     PIN_ODR_HIGH(GPIOJ_PIN4) |             \
                                     PIN_ODR_HIGH(GPIOJ_PIN5) |             \
                                     PIN_ODR_HIGH(GPIOJ_PIN6) |             \
                                     PIN_ODR_HIGH(GPIOJ_PIN7) |             \
                                     PIN_ODR_HIGH(GPIOJ_PIN8) |             \
                                     PIN_ODR_HIGH(GPIOJ_PIN9) |             \
                                     PIN_ODR_HIGH(GPIOJ_PIN10) |            \
                                     PIN_ODR_HIGH(GPIOJ_PIN11) |            \
                                     PIN_ODR_HIGH(GPIOJ_PIN12) |            \
                                     PIN_ODR_HIGH(GPIOJ_PIN13) |            \
                                     PIN_ODR_HIGH(GPIOJ_PIN14) |            \
                                     PIN_ODR_HIGH(GPIOJ_PIN15))
#define VAL_GPIOJ_AFRL              (PIN_AFIO_AF(GPIOJ_PIN0, 0U) |          \
                                     PIN_AFIO_AF(GPIOJ_PIN1, 0U) |          \
                                     PIN_AFIO_AF(GPIOJ_PIN2, 0U) |          \
                                     PIN_AFIO_AF(GPIOJ_PIN3, 0U) |          \
                                     PIN_AFIO_AF(GPIOJ_PIN4, 0U) |          \
                                     PIN_AFIO_AF(GPIOJ_PIN5, 0U) |          \
                                     PIN_AFIO_AF(GPIOJ_PIN6, 0U) |          \
                                     PIN_AFIO_AF(GPIOJ_PIN7, 0U))
#define VAL_GPIOJ_AFRH              (PIN_AFIO_AF(GPIOJ_PIN8, 0U) |          \
                                     PIN_AFIO_AF(GPIOJ_PIN9, 0U) |          \
                                     PIN_AFIO_AF(GPIOJ_PIN10, 0U) |         \
                                     PIN_AFIO_AF(GPIOJ_PIN11, 0U) |         \
                                     PIN_AFIO_AF(GPIOJ_PIN12, 0U) |         \
                                     PIN_AFIO_AF(GPIOJ_PIN13, 0U) |         \
                                     PIN_AFIO_AF(GPIOJ_PIN14, 0U) |         \
                                     PIN_AFIO_AF(GPIOJ_PIN15, 0U))

/*
 * GPIOK setup:
 *
 * PK0  - PIN0                      (input pulldown).
 * PK1  - PIN1                      (input pulldown).
 * PK2  - PIN2                      (input pulldown).
 * PK3  - PIN3                      (input pulldown).
 * PK4  - PIN4                      (input pulldown).
 * PK5  - PIN5                      (input pulldown).
 * PK6  - PIN6                      (input pulldown).
 * PK7  - PIN7                      (input pulldown).
 * PK8  - PIN8                      (input pulldown).
 * PK9  - PIN9                      (input pulldown).
 * PK10 - PIN10                     (input pulldown).
 * PK11 - PIN11                     (input pulldown).
 * PK12 - PIN12                     (input pulldown).
 * PK13 - PIN13                     (input pulldown).
 * PK14 - PIN14                     (input pulldown).
 * PK15 - PIN15                     (input pulldown).
 */
#define VAL_GPIOK_MODER             (PIN_MODE_INPUT(GPIOK_PIN0) |           \
                                     PIN_MODE_INPUT(GPIOK_PIN1) |           \
                                     PIN_MODE_INPUT(GPIOK_PIN2) |           \
                                     PIN_MODE_INPUT(GPIOK_PIN3) |           \
                                     PIN_MODE_INPUT(GPIOK_PIN4) |           \
                                     PIN_MODE_INPUT(GPIOK_PIN5) |           \
                                     PIN_MODE_INPUT(GPIOK_PIN6) |           \
                                     PIN_MODE_INPUT(GPIOK_PIN7) |           \
                                     PIN_MODE_INPUT(GPIOK_PIN8) |           \
                                     PIN_MODE_INPUT(GPIOK_PIN9) |           \
                                     PIN_MODE_INPUT(GPIOK_PIN10) |          \
                                     PIN_MODE_INPUT(GPIOK_PIN11) |          \
                                     PIN_MODE_INPUT(GPIOK_PIN12) |          \
                                     PIN_MODE_INPUT(GPIOK_PIN13) |          \
                                     PIN_MODE_INPUT(GPIOK_PIN14) |          \
                                     PIN_MODE_INPUT(GPIOK_PIN15))
#define VAL_GPIOK_OTYPER            (PIN_OTYPE_PUSHPULL(GPIOK_PIN0) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOK_PIN1) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOK_PIN2) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOK_PIN3) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOK_PIN4) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOK_PIN5) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOK_PIN6) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOK_PIN7) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOK_PIN8) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOK_PIN9) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOK_PIN10) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOK_PIN11) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOK_PIN12) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOK_PIN13) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOK_PIN14) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOK_PIN15))
#define VAL_GPIOK_OSPEEDR           (PIN_OSPEED_VERYLOW(GPIOK_PIN0) |       \
                                     PIN_OSPEED_VERYLOW(GPIOK_PIN1) |       \
                                     PIN_OSPEED_VERYLOW(GPIOK_PIN2) |       \
                                     PIN_OSPEED_VERYLOW(GPIOK_PIN3) |       \
                                     PIN_OSPEED_VERYLOW(GPIOK_PIN4) |       \
                                     PIN_OSPEED_VERYLOW(GPIOK_PIN5) |       \
                                     PIN_OSPEED_VERYLOW(GPIOK_PIN6) |       \
                                     PIN_OSPEED_VERYLOW(GPIOK_PIN7) |       \
                                     PIN_OSPEED_VERYLOW(GPIOK_PIN8) |       \
                                     PIN_OSPEED_VERYLOW(GPIOK_PIN9) |       \
                                     PIN_OSPEED_VERYLOW(GPIOK_PIN10) |      \
                                     PIN_OSPEED_VERYLOW(GPIOK_PIN11) |      \
                                     PIN_OSPEED_VERYLOW(GPIOK_PIN12) |      \
                                     PIN_OSPEED_VERYLOW(GPIOK_PIN13) |      \
                                     PIN_OSPEED_VERYLOW(GPIOK_PIN14) |      \
                                     PIN_OSPEED_VERYLOW(GPIOK_PIN15))
#define VAL_GPIOK_PUPDR             (PIN_PUPDR_PULLDOWN(GPIOK_PIN0) |       \
                                     PIN_PUPDR_PULLDOWN(GPIOK_PIN1) |       \
                                     PIN_PUPDR_PULLDOWN(GPIOK_PIN2) |       \
                                     PIN_PUPDR_PULLDOWN(GPIOK_PIN3) |       \
                                     PIN_PUPDR_PULLDOWN(GPIOK_PIN4) |       \
                                     PIN_PUPDR_PULLDOWN(GPIOK_PIN5) |       \
                                     PIN_PUPDR_PULLDOWN(GPIOK_PIN6) |       \
                                     PIN_PUPDR_PULLDOWN(GPIOK_PIN7) |       \
                                     PIN_PUPDR_PULLDOWN(GPIOK_PIN8) |       \
                                     PIN_PUPDR_PULLDOWN(GPIOK_PIN9) |       \
                                     PIN_PUPDR_PULLDOWN(GPIOK_PIN10) |      \
                                     PIN_PUPDR_PULLDOWN(GPIOK_PIN11) |      \
                                     PIN_PUPDR_PULLDOWN(GPIOK_PIN12) |      \
                                     PIN_PUPDR_PULLDOWN(GPIOK_PIN13) |      \
                                     PIN_PUPDR_PULLDOWN(GPIOK_PIN14) |      \
                                     PIN_PUPDR_PULLDOWN(GPIOK_PIN15))
#define VAL_GPIOK_ODR               (PIN_ODR_HIGH(GPIOK_PIN0) |             \
                                     PIN_ODR_HIGH(GPIOK_PIN1) |             \
                                     PIN_ODR_HIGH(GPIOK_PIN2) |             \
                                     PIN_ODR_HIGH(GPIOK_PIN3) |             \
                                     PIN_ODR_HIGH(GPIOK_PIN4) |             \
                                     PIN_ODR_HIGH(GPIOK_PIN5) |             \
                                     PIN_ODR_HIGH(GPIOK_PIN6) |             \
                                     PIN_ODR_HIGH(GPIOK_PIN7) |             \
                                     PIN_ODR_HIGH(GPIOK_PIN8) |             \
                                     PIN_ODR_HIGH(GPIOK_PIN9) |             \
                                     PIN_ODR_HIGH(GPIOK_PIN10) |            \
                                     PIN_ODR_HIGH(GPIOK_PIN11) |            \
                                     PIN_ODR_HIGH(GPIOK_PIN12) |            \
                                     PIN_ODR_HIGH(GPIOK_PIN13) |            \
                                     PIN_ODR_HIGH(GPIOK_PIN14) |            \
                                     PIN_ODR_HIGH(GPIOK_PIN15))
#define VAL_GPIOK_AFRL              (PIN_AFIO_AF(GPIOK_PIN0, 0U) |          \
                                     PIN_AFIO_AF(GPIOK_PIN1, 0U) |          \
                                     PIN_AFIO_AF(GPIOK_PIN2, 0U) |          \
                                     PIN_AFIO_AF(GPIOK_PIN3, 0U) |          \
                                     PIN_AFIO_AF(GPIOK_PIN4, 0U) |          \
                                     PIN_AFIO_AF(GPIOK_PIN5, 0U) |          \
                                     PIN_AFIO_AF(GPIOK_PIN6, 0U) |          \
                                     PIN_AFIO_AF(GPIOK_PIN7, 0U))
#define VAL_GPIOK_AFRH              (PIN_AFIO_AF(GPIOK_PIN8, 0U) |          \
                                     PIN_AFIO_AF(GPIOK_PIN9, 0U) |          \
                                     PIN_AFIO_AF(GPIOK_PIN10, 0U) |         \
                                     PIN_AFIO_AF(GPIOK_PIN11, 0U) |         \
                                     PIN_AFIO_AF(GPIOK_PIN12, 0U) |         \
                                     PIN_AFIO_AF(GPIOK_PIN13, 0U) |         \
                                     PIN_AFIO_AF(GPIOK_PIN14, 0U) |         \
                                     PIN_AFIO_AF(GPIOK_PIN15, 0U))

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

#if !defined(_FROM_ASM_)
#ifdef __cplusplus
extern "C" {
#endif
  void boardInit(void);
#ifdef __cplusplus
}
#endif
#endif /* _FROM_ASM_ */

#endif /* BOARD_H */
