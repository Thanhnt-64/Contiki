/***************************************************************************//**
 * @file
 * @brief CANopen Parameters Object Management
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

#ifndef _CANOPEN_PARAM_PRIV_H_
#define _CANOPEN_PARAM_PRIV_H_

/********************************************************************************************************
 ********************************************************************************************************
 *                                            INCLUDE FILES
 ********************************************************************************************************
 *******************************************************************************************************/

#include  <cpu/include/cpu.h>

#include  <canopen/include/canopen_core.h>
#include  <canopen/include/canopen_obj.h>
#include  <canopen/include/canopen_param.h>

/********************************************************************************************************
 ********************************************************************************************************
 *                                         FUNCTION PROTOTYPES
 ********************************************************************************************************
 *******************************************************************************************************/

#if (CANOPEN_OBJ_PARAM_EN == DEF_ENABLED)
void CANopen_ParamStore(CANOPEN_PARAM *p_pg,
                        CANOPEN_NODE  *p_node,
                        RTOS_ERR      *p_err);

void CANopen_ParamRestore(CANOPEN_PARAM *p_pg,
                          CANOPEN_NODE  *p_node,
                          RTOS_ERR      *p_err);
#endif

/********************************************************************************************************
 ********************************************************************************************************
 *                                               MODULE END
 ********************************************************************************************************
 *******************************************************************************************************/

#endif // _CANOPEN_PARAM_PRIV_H_