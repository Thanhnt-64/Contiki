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
#include "leds.h"
#include "em_device.h"
#include "em_chip.h"
#include "em_cmu.h"
#include "em_gpio.h"
#include "em_emu.h"

#define LED_PORT    gpioPortD
#define LED_PIN     1

PROCESS(ledToggle, "ledToggle");
PROCESS_THREAD(ledToglle, ev, data){

	static struct etimer timerRed;

	PROCESS_BEGIN();

	printf("Timers set!\r\n ");

	etimer_set(&timerRed, 1000);

	while(1) {
		PROCESS_WAIT_EVENT();
		if(etimer_expired(&timerRed)) {
			printf("Timer expired for RED...\r\n");
			leds_toggle(LEDS_RED);
			etimer_reset(&timerRed);
		}
	}
	PROCESS_END();
}
