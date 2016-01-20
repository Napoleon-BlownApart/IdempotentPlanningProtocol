/**
 * \file  wb_sensors_epuck_proximity.h
 *  Whiteboard Proximity Sensor Class
 *  Created by
 *    \author Dimitri Joukoff
 *    \date   5/05/2015.
 */

/*
 *
 * This class represents the 8 Infrared Proximity Sensors available on the e-Puck.
 *
 * Through the Whiteboard, the controller posts current values for those
 * which are enabled, and the remote enables/disables them and reads their values.
 *
 * The proximity sensors are co-located with the Light seonsors and have a similar
 * naming scheme.  The proximity sensors seem to be better for obstacle avoidance.
 *
 * Class Hierarchy:
 *      (C++) EPuckRobotControlStatus
 *      (C)   wb_epuck_robot
 *      (C)   wb_sensors_epuck_proximity <= This class
 *      (C)   wb_generic_sensor
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

#ifndef EPUCK_PROXIMITY_SENSOR_LIST
#define EPUCK_PROXIMITY_SENSOR_LIST


/** e-Puck Proximity Sensors
 *  The e-Puck has eight (8) infrared proximity sensors (ps0 - ps7)
 *  that are mounted around the body of the e-Puck
 */
//#pragma Clang diagnosticc push
//#pragma Clang diagnostic ignored "-Wduplicate-enum"
enum proximity_sensors {
  ps0 = 0,
  FRONT_RIGHT_PS = 0,  // Convenience (When viewed from above/behind)
  ps1,
  ps2,
  ps3,
  ps4,
  ps5,
  ps6,
  ps7,
  FRONT_LEFT_PS = 7,  // Convenience (When viewed from above/behind)
  NUMBER_PROXIMITY_SENSORS
};
//#pragma Clang diagnostic pop
#endif // EPUCK_PROXIMITY_SENSOR_LIST

#ifndef _WBSENSORSEPUCKPROXIMITYSTATUS_
#define _WBSENSORSEPUCKPROXIMITYSTATUS_

#include <sys/types.h>
#include <gu_util.h>

#ifdef WHITEBOARD_POSTER_STRING_CONVERSION
#include <sstream>
#include <ctype.h>
#endif

#include "wb_generic_analog_sensor_status.h"

/** e-Puck Proximity Sensor Array Class */
struct wb_sensors_epuck_proximity_status {

  /** Proximity sensor array */
  ARRAY_PROPERTY(struct wb_generic_analog_sensor_status, ps, NUMBER_PROXIMITY_SENSORS)

#ifdef __cplusplus
  /** Default constructor */
  wb_sensors_epuck_proximity_status() {
    memset(this, 0, sizeof(*this));
  }

  /** Copy Constructor */
  wb_sensors_epuck_proximity_status(const wb_sensors_epuck_proximity_status &other) {
    for ( proximity_sensors sensor = ps0;
          sensor != NUMBER_PROXIMITY_SENSORS;
          sensor = static_cast<proximity_sensors>(static_cast<int>(sensor) + 1 )) {
      _ps[sensor] = other._ps[sensor];
    }
  }

  /** Assignment Operator */
  wb_sensors_epuck_proximity_status  &operator= (const wb_sensors_epuck_proximity_status &other) {
    for ( proximity_sensors sensor = ps0;
          sensor != NUMBER_PROXIMITY_SENSORS;
          sensor = static_cast<proximity_sensors>(static_cast<int>(sensor) + 1 )) {
       _ps[sensor] = other._ps[sensor];
    }
    return *this;
  }

#ifdef WHITEBOARD_POSTER_STRING_CONVERSION

  const char PROPERTY_SEPARATOR = ':'; // Tilda
  // '|' (Colon) Property Separator has already been used further in this branch.

  const char FIELD_SERPARATOR = ',';

  /** String constructor */
  wb_sensors_epuck_proximity_status(const std::string &name) {
      from_string(name);
  }

  /** convert from a string */
  void from_string(const std::string &str)
  {
    std::istringstream iss(str);
    std::string token;
    getline(iss, token, PROPERTY_SEPARATOR);
    std::istringstream iss_ps(token);
    {
      int i = 0;
      std::string subtoken;
      while (getline(iss_ps, subtoken, FIELD_SERPARATOR)) {
        _ps[i++].from_string(subtoken);
      }
    }
  }

  /** get string serialisation */
  std::string to_string() {
    using namespace std;
    ostringstream ss;
    for(int i=0; i<NUMBER_PROXIMITY_SENSORS-1; i++) {
      ss << this->ps(i).to_string() << FIELD_SERPARATOR;
    }
    ss << this->ps(NUMBER_PROXIMITY_SENSORS-1).to_string();
    return ss.str();
  }

  /** get message description */
  std::string description() {
    using namespace std;
    ostringstream ss;
    ss << "ps(";
    for(int i=0; i<NUMBER_PROXIMITY_SENSORS-1; i++) {
      ss << this->ps(i).to_string() << FIELD_SERPARATOR;
    }
    ss << this->ps(NUMBER_PROXIMITY_SENSORS-1).to_string() << ")";
    return ss.str();
  }
#endif // WHITEBOARD_POSTER_STRING_CONVERSION

#endif // __cplusplus

};

#endif  //  _WBSENSORSEPUCKPROXIMITYSTATUS_
