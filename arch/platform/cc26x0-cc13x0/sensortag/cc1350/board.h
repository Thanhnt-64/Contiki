/*
 * Copyright (c) 2014, Texas Instruments Incorporated - http://www.ti.com/
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the copyright holder nor the names of its
 *    contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE
 * COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED
 * OF THE POSSIBILITY OF SUCH DAMAGE.
 */
/*---------------------------------------------------------------------------*/
/** \addtogroup cc26xx-srf-tag
 * @{
 *
 * \defgroup sensortag-cc13xx-peripherals CC1350 Sensortag Peripherals
 *
 * Defines related to the CC1350 Sensortag
 *
 * This file provides connectivity information on LEDs, Buttons, UART and
 * other peripherals
 *
 * This file can be used as the basis to configure other boards using the
 * CC13xx code as their basis.
 *
 * This file is not meant to be modified by the user.
 * @{
 *
 * \file
 * Header file with definitions related to the I/O connections on the TI
 * Sensortag
 *
 * \note   Do not include this file directly. It gets included by contiki-conf
 *         after all relevant directives have been set.
 */
/*---------------------------------------------------------------------------*/
#ifndef BOARD_H_
#define BOARD_H_
/*---------------------------------------------------------------------------*/
#include "ioc.h"
/*---------------------------------------------------------------------------*/
/**
 * \name LED HAL configuration
 *
 * Those values are not meant to be modified by the user
 * @{
 */
#define LEDS_CONF_COUNT                 1
#define LEDS_CONF_RED                   1
/** @} */
/*---------------------------------------------------------------------------*/
/**
 * \name LED IOID mappings
 *
 * Those values are not meant to be modified by the user
 * @{
 */
#define BOARD_IOID_LED_1          IOID_10
/** @} */
/*---------------------------------------------------------------------------*/
/**
 * \name UART IOID mapping
 *
 * Those values are not meant to be modified by the user
 * @{
 */
#define BOARD_IOID_DP4_UARTRX     IOID_28
#define BOARD_IOID_DP5_UARTTX     IOID_29

#if BOARD_CONF_DEBUGGER_DEVPACK
#define BOARD_IOID_UART_RX        BOARD_IOID_DP4_UARTRX
#define BOARD_IOID_UART_TX        BOARD_IOID_DP5_UARTTX
#else
#define BOARD_IOID_UART_RX        IOID_17
#define BOARD_IOID_UART_TX        IOID_16
#endif

#define BOARD_IOID_UART_CTS       IOID_UNUSED
#define BOARD_IOID_UART_RTS       IOID_UNUSED
#define BOARD_UART_RX             (1 << BOARD_IOID_UART_RX)
#define BOARD_UART_TX             (1 << BOARD_IOID_UART_TX)
#define BOARD_UART_CTS            (1 << BOARD_IOID_UART_CTS)
#define BOARD_UART_RTS            (1 << BOARD_IOID_UART_RTS)
/** @} */
/*---------------------------------------------------------------------------*/
/**
 * \name Button IOID mapping
 *
 * Those values are not meant to be modified by the user
 * @{
 */
#define BOARD_IOID_KEY_LEFT       IOID_15
#define BOARD_IOID_KEY_RIGHT      IOID_4
#define BOARD_KEY_LEFT            (1 << BOARD_IOID_KEY_LEFT)
#define BOARD_KEY_RIGHT           (1 << BOARD_IOID_KEY_RIGHT)
/** @} */
/*---------------------------------------------------------------------------*/
/**
 * \name Buzzer configuration
 * @{
 */
#define BOARD_IOID_BUZZER         IOID_21 /**< Buzzer Pin */
/** @} */
/*---------------------------------------------------------------------------*/
/**
 * \name Reed Relay IOID mapping
 *
 * Those values are not meant to be modified by the user
 * @{
 */
#define BOARD_IOID_REED_RELAY     IOID_1
/** @} */
/*---------------------------------------------------------------------------*/
/**
 * \name External flash IOID mapping and part-related constants
 *
 * Those values are not meant to be modified by the user
 * @{
 */
#define EXT_FLASH_SPI_CONTROLLER    SPI_CONTROLLER_SPI0

#define EXT_FLASH_SPI_PIN_SCK       IOID_17
#define EXT_FLASH_SPI_PIN_MOSI      IOID_19
#define EXT_FLASH_SPI_PIN_MISO      IOID_18
#define EXT_FLASH_SPI_PIN_CS        IOID_14

#define EXT_FLASH_DEVICE_ID         0x14
#define EXT_FLASH_MID               0xC2

#define EXT_FLASH_PROGRAM_PAGE_SIZE 256
#define EXT_FLASH_ERASE_SECTOR_SIZE 4096
/** @} */
/*---------------------------------------------------------------------------*/
/**
 * \brief I2C IOID mappings
 *
 * Those values are not meant to be modified by the user
 * @{
 */
#define BOARD_IOID_SDA            IOID_5 /**< Interface 0 SDA: All sensors bar MPU */
#define BOARD_IOID_SCL            IOID_6 /**< Interface 0 SCL: All sensors bar MPU */
#define BOARD_IOID_SDA_HP         IOID_8 /**< Interface 1 SDA: MPU */
#define BOARD_IOID_SCL_HP         IOID_9 /**< Interface 1 SCL: MPU */
/** @} */
/*---------------------------------------------------------------------------*/
/**
 * \brief MPU IOID mappings
 *
 * Those values are not meant to be modified by the user
 * @{
 */
#define BOARD_IOID_MPU_INT        IOID_7
#define BOARD_IOID_MPU_POWER      IOID_12
#define BOARD_MPU_INT             (1 << BOARD_IOID_MPU_INT)
#define BOARD_MPU_POWER           (1 << BOARD_IOID_MPU_POWER)
/** @} */
/*---------------------------------------------------------------------------*/
/**
 * \brief Board devpack IOID mappings (LCD etc.)
 *
 * Those values are not meant to be modified by the user
 * @{
 */
#define BOARD_IOID_AUDIOFS_TDO        IOID_16
#define BOARD_IOID_DEVPACK_CS         IOID_20
#define BOARD_IOID_DEVPK_LCD_EXTCOMIN IOID_22
#define BOARD_IOID_AUDIODO            IOID_22
#define BOARD_IOID_DP2                IOID_23
#define BOARD_IOID_DP1                IOID_24
#define BOARD_IOID_DP0                IOID_25
#define BOARD_IOID_DP3                IOID_27
#define BOARD_IOID_DEVPK_ID           IOID_30
#define BOARD_DEVPACK_CS              (1 << BOARD_IOID_DEVPACK_CS)
/** @} */
/*---------------------------------------------------------------------------*/
/**
 * \brief TMP Sensor
 *
 * Those values are not meant to be modified by the user
 * @{
 */
#define BOARD_IOID_TMP_RDY          IOID_11
/** @} */
/*---------------------------------------------------------------------------*/
/**
 * \brief Digital Microphone
 *
 * Those values are not meant to be modified by the user
 * @{
 */
#define BOARD_IOID_MIC_POWER        IOID_13
#define BOARD_IOID_AUDIO_DI         IOID_2
#define BOARD_IOID_AUDIO_CLK        IOID_3
/** @} */
/*---------------------------------------------------------------------------*/
/**
 * \name RF Front End configuration
 *
 * Those values are not meant to be modified by the user
 * @{
 */
#define RF_CORE_CONF_RADIO_SETUP_FRONT_END_MODE 0x01 /* Single-Ended, RFP */
#define RF_CORE_CONF_RADIO_SETUP_BIAS_MODE      0x01 /* External */
#define RF_CORE_CONF_PROP_FRONT_END_MODE        0x02 /* Single-Ended, RFN */
#define RF_CORE_CONF_PROP_BIAS_MODE             0x01 /* External */
/** @} */
/*---------------------------------------------------------------------------*/
/**
 * \name Board-specific overrides
 *
 * Those values are not meant to be modified by the user
 * @{
 */
#define IEEE_MODE_CONF_BOARD_OVERRIDES        ADI_HALFREG_OVERRIDE(0, 16, 0x7, 1),
#define RF_BLE_CONF_BOARD_OVERRIDES           ADI_HALFREG_OVERRIDE(0, 16, 0x7, 1),
#define SMARTRF_SETTINGS_CONF_BOARD_OVERRIDES ADI_HALFREG_OVERRIDE(0, 16, 0x7, 2),

#define SMARTRF_SETTINGS_CONF_RSSI_OFFSET_779_930  0x00F688A3
#define SMARTRF_SETTINGS_CONF_OVERRIDE_TRIM_OFFSET 0x00018883
/** @} */
/*---------------------------------------------------------------------------*/
/**
 * \brief Board indices for the button HAL
 *
 * Those values are not meant to be modified by the user
 * @{
 */
#define BOARD_BUTTON_HAL_INDEX_KEY_LEFT   0x00
#define BOARD_BUTTON_HAL_INDEX_KEY_RIGHT  0x01
#define BOARD_BUTTON_HAL_INDEX_REED_RELAY 0xFF
/** @} */
/*---------------------------------------------------------------------------*/
/**
 * \brief ROM bootloader configuration
 *
 * Sensortags do not support the bootloader
 * @{
 */
#define CCFG_CONF_BL_PIN_NUMBER   IOID_UNUSED
#define CCFG_CONF_BL_LEVEL        0
/** @} */
/*---------------------------------------------------------------------------*/
/**
 * \name Device string used on startup
 * @{
 */
#define BOARD_STRING "TI CC1350 SensorTag"

/** @} */
/*---------------------------------------------------------------------------*/
/**
 * \brief Board specific iniatialisation
 * @{
 */
void board_init(void);
/** @} */
/*---------------------------------------------------------------------------*/
#endif /* BOARD_H_ */
/*---------------------------------------------------------------------------*/
/**
 * @}
 * @}
 */
