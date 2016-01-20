/**
 * \file  wb_emitters_epuck_led.h
 *  Whiteboard LED Emitter Class
 *  Created by
 *    \author Dimitri Joukoff
 *    \date   5/05/2015.
 */

/*
 *
 * This class represents the 10 LEDs available on the e-Puck.  Through
 * the Whiteboard, the LEDs can be enabled/disabled as well as turned on/off.
 *
 * All the LEDs on the e-Puck are monochromatic and binary.
 *
 * Class Hierarchy:
 *      (C++) EPuckRobotControlStatus
 *      (C)   wb_epuck_robot
 *      (C)   wb_emitters_epuck_led <= This class
 *      (C)   wb_generic_emitter
 *
 ********************************************************************************
 *
 *  Copyright 2015 Dimitri Joukoff
 *  MiPal @ Griffith University
 *  All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above
 *    copyright notice, this list of conditions and the following
 *    disclaimer in the documentation and/or other materials
 *    provided with the distribution.
 *
 * 3. All advertising materials mentioning features or use of this
 *    software must display the following acknowledgement:
 *
 *        This product includes software developed by Dimitri Joukoff
 *        (MiPal @ Griffith University).
 *
 * 4. Neither the name of the author nor the names of contributors
 *    may be used to endorse or promote products derived from this
 *    software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * -----------------------------------------------------------------------
 * This program is free software; you can redistribute it and/or
 * modify it under the above terms or under the terms of the GNU
 * General Public License as published by the Free Software Foundation;
 * either version 2 of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, see http://www.gnu.org/licenses/
 * or write to the Free Software Foundation, Inc., 51 Franklin Street,
 * Fifth Floor, Boston, MA  02110-1301, USA.
 *
 */


#ifndef _WBEMITTERSPUCKLED_
#define _WBEMITTERSPUCKLED_

#include <sys/types.h>
#include <gu_util.h>

#ifdef WHITEBOARD_POSTER_STRING_CONVERSION
#include <sstream>
#include <ctype.h>
#endif

#include "wb_generic_analog_emitter_controlstatus.h"

/** e-Puck LEDs
 *  The e-Puck has 10 LED emitters
 *  They are mounted (when viewed from above/behind):
 *  0:  The whole upper ring is lite up red
 *  1:  Red 45 degrees
 *  2:  Red 90 degrees
 *  3   Red 135 degrees
 *  4:  Red Tail Lights (175 & 185 degrees) (Two LEDs)
 *  5:  Red 225 degrees
 *  6:  Red 270 degrees
 *  7:  Red 315 degrees
 *  8:  Green Body
 *  9:  Red to the right of the camera
 */
enum led_emitters {
  led0      = 0,
  LEDRING   = 0,  // Convenience (When viewed from above/behind)
  led1      = 1,
  LED45     = 1,  // Convenience (When viewed from above/behind)
  led2      = 2,
  LED90     = 2,  // Convenience (When viewed from above/behind)
  led3      = 3,
  LED135    = 3,  // Convenience (When viewed from above/behind)
  led4      = 4,
  LED180    = 4,  // Convenience (When viewed from above/behind)
  LEDTAIL   = 4,  // Convenience (When viewed from above/behind)
  led5      = 5,
  LED225    = 5,  // Convenience (When viewed from above/behind)
  led6      = 6,
  LED270    = 6,  // Convenience (When viewed from above/behind)
  led7      = 7,
  LED315    = 7,  // Convenience (When viewed from above/behind)
  led8      = 8,
  LEDBODY   = 8,  // Convenience (When viewed from above/behind)
  led9      = 9,
  LEDCAMERA = 9,  // Convenience (When viewed from above/behind)
  NUMBER_LED_EMITTERS
};

/** e-Puck LED Array Class */
struct wb_emitters_epuck_led {

  /** LED emitter array */
  ARRAY_PROPERTY(struct wb_generic_analog_emitter_controlstatus, led, NUMBER_LED_EMITTERS)

#ifdef __cplusplus
  /** Default constructor */
  wb_emitters_epuck_led() {
    memset(this, 0, sizeof(*this));
  }

  /** Copy Constructor */
  wb_emitters_epuck_led(const wb_emitters_epuck_led &other) {
    for ( led_emitters emitter = led0;
          emitter != NUMBER_LED_EMITTERS;
          emitter = static_cast<led_emitters>(static_cast<int>(emitter) + 1 )) {
      _led[emitter] = other._led[emitter];
    }
  }

  /** Assignment Operator */
  wb_emitters_epuck_led  &operator= (const wb_emitters_epuck_led &other) {
    for ( led_emitters emitter = led0;
          emitter != NUMBER_LED_EMITTERS;
          emitter = static_cast<led_emitters>(static_cast<int>(emitter) + 1 )) {
      _led[emitter] = other._led[emitter];
    }
    return *this;
  }

#ifdef WHITEBOARD_POSTER_STRING_CONVERSION

  const char PROPERTY_SEPARATOR = ':'; // Tilda
  // '|' (Colon) Property Separator has already been used further in this branch.

  const char FIELD_SERPARATOR = ',';

  /** String constructor */
  wb_emitters_epuck_led(const std::string &name) {
      from_string(name);
  }

  /** convert from a string */
  void from_string(const std::string &str)
  {
    std::istringstream iss(str);
    std::string token;
    getline(iss, token, PROPERTY_SEPARATOR);
    std::istringstream iss_led(token);
    {
      int i = 0;
      std::string subtoken;
      while (getline(iss_led, subtoken, FIELD_SERPARATOR)) {
        _led[i++].from_string(subtoken);
      }
    }
  }

  /** get string serialisation */
  std::string to_string() {
    using namespace std;
    ostringstream ss;
    for(int i=0; i<NUMBER_LED_EMITTERS-1; i++) {
      ss << this->led(i).to_string() << FIELD_SERPARATOR;
    }
    ss << this->led(NUMBER_LED_EMITTERS-1).to_string();
    return ss.str();
  }

  /** get message description */
  std::string description() {
    using namespace std;
    ostringstream ss;
    ss << "LED(";
    for(int i=0; i<NUMBER_LED_EMITTERS-1; i++) {
      ss << this->led(i).to_string() << FIELD_SERPARATOR;
    }
    ss << this->led(NUMBER_LED_EMITTERS-1).to_string() << ")";
    return ss.str();
  }
#endif // WHITEBOARD_POSTER_STRING_CONVERSION


#endif // __cplusplus

};

#endif  //  _WBEMITTERSPUCKLED_
