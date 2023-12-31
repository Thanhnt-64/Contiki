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
 */

package org.contikios.cooja.interfaces;

import org.contikios.cooja.ClassDescription;
import org.contikios.cooja.Mote;
import org.contikios.cooja.MoteInterface;
import org.contikios.cooja.util.EventTriggers;

/**
 * A LED represents three mote LEDs (green, yellow and red). An implementation should notify all
 * observers if any of the LEDs states are changed.
 * 
 * @author Fredrik Osterlind
 */
@ClassDescription("LEDs")
public abstract class LED implements MoteInterface {

  protected final EventTriggers<EventTriggers.Update, Mote> triggers = new EventTriggers<>();

  /**
   * @return True if any LED is on, false otherwise
   */
  public abstract boolean isAnyOn();
  
  /**
   * @return True if green LED is on, false otherwise
   */
  public abstract boolean isGreenOn();

  /**
   * @return True if yellow LED is on, false otherwise
   */
  public abstract boolean isYellowOn();
  
  /**
   * @return True if red LED is on, false otherwise
   */
  public abstract boolean isRedOn();

  /**
   * Returns the LED state change triggers for this mote interface.
   *
   * @return the LED state change triggers for this mote interface.
   */
  public EventTriggers<EventTriggers.Update, Mote> getTriggers() {
    return triggers;
  }

}
