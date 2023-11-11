/***************************************************************************//**
 * @file
 * @brief An EZSP host application library for retrieving Ember stack
 *******************************************************************************
 * # License
 * <b>Copyright 2018 Silicon Laboratories Inc. www.silabs.com</b>
 *******************************************************************************
 *
 * The licensor of this software is Silicon Laboratories Inc. Your use of this
 * software is governed by the terms of Silicon Labs Master Software License
 * Agreement (MSLA) available at
 * www.silabs.com/about-us/legal/master-software-license-agreement. This
 * software is distributed to you in Source Code format and is governed by the
 * sections of the MSLA applicable to Source Code.
 *
 ******************************************************************************/

#include "app/framework/include/af.h"
#include "app/util/serial/sl_zigbee_command_interpreter.h"
#include "app/util/common/common.h"
#include "app/util/ezsp/ezsp-protocol.h"
#include "app/util/ezsp/ezsp.h"
#include "counters-ota.h"

#if defined(OTA_COUNTERS_ENABLED)

static EmberStatus sendCluster(EmberNodeId destination,
                               uint16_t clusterId,
                               uint8_t length,
                               uint8_t *contents)
{
  EmberApsFrame apsFrame;
  uint8_t sequence;
  apsFrame.profileId = EMBER_PRIVATE_PROFILE_ID;
  apsFrame.clusterId = clusterId;
  apsFrame.sourceEndpoint = 0;
  apsFrame.destinationEndpoint = 0;
  apsFrame.options = (EMBER_APS_OPTION_RETRY
                      | EMBER_APS_OPTION_ENABLE_ROUTE_DISCOVERY);
  return ezspSendUnicast(EMBER_OUTGOING_DIRECT,
                         destination,
                         &apsFrame,
                         0,  // message tag
                         length,  // mesage length
                         contents,
                         &sequence);
}

EmberStatus emberSendCountersRequest(EmberNodeId destination,
                                     bool clearCounters)
{
  return sendCluster(destination,
                     (clearCounters
                      ? EMBER_REPORT_AND_CLEAR_COUNTERS_REQUEST
                      : EMBER_REPORT_COUNTERS_REQUEST),
                     0,
                     NULL);
}

bool emberIsIncomingCountersRequest(EmberApsFrame *apsFrame, EmberNodeId sender)
{
  uint8_t i;
  uint8_t length = 0;
  uint16_t counters[EMBER_COUNTER_TYPE_COUNT];
  uint8_t payload[MAX_PAYLOAD_LENGTH];

  if (apsFrame->profileId != EMBER_PRIVATE_PROFILE_ID
      || (apsFrame->clusterId != EMBER_REPORT_COUNTERS_REQUEST
          && apsFrame->clusterId != EMBER_REPORT_AND_CLEAR_COUNTERS_REQUEST)) {
    return false;
  }

  ezspReadAndClearCounters(counters);

  for (i = 0; i < EMBER_COUNTER_TYPE_COUNT; i++) {
    uint16_t val = counters[i];
    if (val != 0) {
      payload[length] = i;
      payload[length + 1] = LOW_BYTE(val);
      payload[length + 2] = HIGH_BYTE(val);
      length += 3;
    }
    if (length + 3 > MAX_PAYLOAD_LENGTH
        || (length
            && (i + 1 == EMBER_COUNTER_TYPE_COUNT))) {
      // The response cluster is the request id with the high bit set.
      sendCluster(sender, apsFrame->clusterId | 0x8000, length, payload);
      length = 0;
    }
  }

  return true;
}

bool emberIsIncomingCountersResponse(EmberApsFrame *apsFrame)
{
  return (apsFrame->profileId == EMBER_PRIVATE_PROFILE_ID
          && (apsFrame->clusterId == EMBER_REPORT_AND_CLEAR_COUNTERS_RESPONSE
              || apsFrame->clusterId == EMBER_REPORT_COUNTERS_RESPONSE));
}

bool emberIsOutgoingCountersResponse(EmberApsFrame *apsFrame,
                                     EmberStatus status)
{
  return emberIsIncomingCountersResponse(apsFrame);
}

#endif
