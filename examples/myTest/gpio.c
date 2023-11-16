/*
 * Copyright (c) 2006, Swedish Institute of Computer Science.
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
 * 3. Neither the name of the Institute nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE INSTITUTE AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE INSTITUTE OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 * This file is part of the Contiki operating system.
 *
 */

/**
 * \file
 *         A very simple Contiki application showing how Contiki programs look
 * \author
 *         Adam Dunkels <adam@sics.se>
 */

#include "contiki.h"
// #include "net/routing/rpl-lite/rpl-dag-root.h"
// #include <stdio.h> /* For printf() */
// #include "net/routing/rpl-lite/rpl.h"
// #include "net/ipv6/uip-ds6-route.h"
// #include "net/ipv6/uip-sr.h"
// #include "net/ipv6/uip.h"

/* Log configuration */
#include "sys/log.h"
#include "gpio-hal.h"
#include "mgm24-conf.h"
#include "em_device.h"
#include "em_chip.h"
#include "em_cmu.h"
#include "em_gpio.h"
#include "em_emu.h"

#define LED_PORT    gpioPortD
#define LED_PIN     1
/*---------------------------------------------------------------------------*/
PROCESS(gpio_process, "gpio process");
AUTOSTART_PROCESSES(&gpio_process);
/*---------------------------------------------------------------------------*/

void Delay(uint32_t ms) {
    for (volatile uint32_t i = 0; i < ms * 7000; i++) {
        // Delay loop
    }
}

PROCESS_THREAD(gpio_process, ev, data)
{
  //static struct etimer timer;

  PROCESS_BEGIN();
  CHIP_Init();
  /* Setup a periodic timer that expires after 10 seconds. */
  //etimer_set(&timer, CLOCK_SECOND*10);
  CMU_ClockEnable(cmuClock_GPIO, true);
  GPIO_PinModeSet(LED_PORT, LED_PIN, gpioModePushPull, 0);
  while(1) {
    
    GPIO_PinOutSet(LED_PORT, LED_PIN);
    Delay(500);

        // Turn off the LED
    printf("Hello world from Thanh\n");
    //PROCESS_WAIT_EVENT_UNTIL(etimer_expired(&timer));

    //etimer_reset(&timer);
    GPIO_PinOutClear(LED_PORT, LED_PIN);
    Delay(500);
  }

  PROCESS_END();
}
/*---------------------------------------------------------------------------*/
