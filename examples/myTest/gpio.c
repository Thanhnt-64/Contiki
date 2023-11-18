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
#include "leds.h"

#define LED_PORT    gpioPortC
#define LED_PIN     3
#define LED_PORT1    gpioPortC
#define LED_PIN1     2
/*---------------------------------------------------------------------------*/
PROCESS(gpio_process, "gpio process");
AUTOSTART_PROCESSES(&gpio_process);
/*---------------------------------------------------------------------------*/

void Delay(uint32_t ms) {
    for (volatile uint32_t i = 0; i < ms * 7000; i++){
        // Delay loop
    }
}

PROCESS_THREAD(gpio_process, ev, data)
{
  static struct etimer timer;

  PROCESS_BEGIN();
  etimer_set(&timer, CLOCK_SECOND * 10);
  gpio_hal_init();
  leds_init();
  while(1) {
    leds_single_on(1);
    gpio_hal_arch_pin_set_output(LED_PORT, LED_PIN);
    PROCESS_WAIT_EVENT_UNTIL(etimer_expired(&timer));
    etimer_reset(&timer);
  }

  PROCESS_END();
}
/*---------------------------------------------------------------------------*/
