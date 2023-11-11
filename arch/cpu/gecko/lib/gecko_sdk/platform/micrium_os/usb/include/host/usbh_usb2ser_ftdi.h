/***************************************************************************//**
 * @file
 * @brief USB Host - Future Technology Devices International (Ftdi)
 *        Serial Adapter Driver
 *******************************************************************************
 * # License
 * <b>Copyright 2018 Silicon Laboratories Inc. www.silabs.com</b>
 *******************************************************************************
 *
 * The licensor of this software is Silicon Laboratories Inc.  Your use of this
 * software is governed by the terms of Silicon Labs Master Software License
 * Agreement (MSLA) available at
 * www.silabs.com/about-us/legal/master-software-license-agreement.
 * The software is governed by the sections of the MSLA applicable to Micrium
 * Software.
 *
 ******************************************************************************/

/********************************************************************************************************
 ********************************************************************************************************
 *                                               MODULE
 ********************************************************************************************************
 *******************************************************************************************************/

#ifndef  _USBH_USB2SER_FTDI_H_
#define  _USBH_USB2SER_FTDI_H_

/********************************************************************************************************
 ********************************************************************************************************
 *                                               INCLUDE FILES
 ********************************************************************************************************
 *******************************************************************************************************/

#include  <usb/include/host/usbh_usb2ser.h>

/********************************************************************************************************
 ********************************************************************************************************
 *                                               EXTERNS
 ********************************************************************************************************
 *******************************************************************************************************/

#ifdef   USBH_USB2SER_FTDI_MODULE
#define  USBH_USB2SER_FTDI_EXT
#else
#define  USBH_USB2SER_FTDI_EXT  extern
#endif

/********************************************************************************************************
 ********************************************************************************************************
 *                                           GLOBAL VARIABLES
 ********************************************************************************************************
 *******************************************************************************************************/

extern USBH_USB2SER_ADAPTER_DRV USBH_USB2SER_FTDI_Drv;

/********************************************************************************************************
 ********************************************************************************************************
 *                                               MODULE END
 ********************************************************************************************************
 *******************************************************************************************************/

#endif
