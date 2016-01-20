/**
 * \file  wb_sensors_epuck_gsm.h
 *  Whiteboard Ground Sensor Module Class
 *  Created by
 *    \author Dimitri Joukoff
 *    \date   5/05/2015.
 */

/*
 *
 * This class represents the 3 Photo-diodes that are locaed on the (optional)
 * Ground Sensor Module available for the e-Puck. They are mounted as a module
 * at the front of the e-Puck, under the camera.  The sensors are aligned on
 * the Y axis
 *
 * Through the Whiteboard, the controller posts current values for those which
 * are enabled, and the remote enables/disables them and reads their values.
 *
 *
 * Class Hierarchy:
 *      (C++) EPuckRobotControlStatus
 *      (C)   wb_epuck_robot
 *      (C)   wb_sensors_epuck_gsm <= This class
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

#ifndef GSM_SENSOR_LIST
#define GSM_SENSOR_LIST

/** The e-Puck Ground Sensor Module (GSM)
 * The GSM has three (3) Photo-diodes (gs0 - gs2)
 * They are mounted as a module at the front of the e-Puck, under the camera.
 *  The sensors are aligned on the Y axis.
 */
enum gsm_sensors {
  gs0       = 0,
  LEFT_GS   = 0,  // Convenience (When viewed from above/behind)
  gs1       = 1,
  CENTER_GS = 1,  // Convenience (When viewed from above/behind)
  gs2       = 2,
  RIGHT_GS  = 2,  // Convenience (When viewed from above/behind)
  NUMBER_GSM_SENSORS
};

#endif // GSM_SENSOR_LIST

#ifndef _WBSENSORSEPUCKGSMCONTROL_
#define _WBSENSORSEPUCKGSMCONTROL_

#include <sys/types.h>
#include <gu_util.h>

#ifdef WHITEBOARD_POSTER_STRING_CONVERSION
#include <sstream>
#include <ctype.h>
#endif

//#include "wb_generic_analog_sensor_control.h"

/** e-Puck Ground Sensor Module Sensor Array Class */
struct wb_sensors_epuck_gsm_control {

  /** Ground Sensor Module sensor array */
//  ARRAY_PROPERTY(struct wb_generic_analog_sensor_control, gs, NUMBER_GSM_SENSORS)
  BIT_ARRAY_PROPERTY(gs, NUMBER_GSM_SENSORS)


#ifdef __cplusplus
  /** Default Constructor */
//  wb_sensors_epuck_gsm_control() {
//    memset(this, 0, sizeof(*this));
//  }
  wb_sensors_epuck_gsm_control() :
    _gs()
    {}

  /** Copy Constructor */
//  wb_sensors_epuck_gsm_control(const wb_sensors_epuck_gsm_control &other) {
//    for ( gsm_sensors sensor = gs0;
//          sensor != NUMBER_GSM_SENSORS;
//          sensor = static_cast<gsm_sensors>(static_cast<int>(sensor) + 1 )) {
//      _gs[sensor] = other._gs[sensor];
//    }
//  }
  wb_sensors_epuck_gsm_control(const wb_sensors_epuck_gsm_control &other) {
    *this = other;
  }

  /** Assignment Operator */
//  wb_sensors_epuck_gsm_control  &operator= (const wb_sensors_epuck_gsm_control &other) {
//    for ( gsm_sensors sensor = gs0;
//          sensor != NUMBER_GSM_SENSORS;
//          sensor = static_cast<gsm_sensors>(static_cast<int>(sensor) + 1 )) {
//      _gs[sensor] = other._gs[sensor];
//    }
//    return *this;
//  }
  wb_sensors_epuck_gsm_control  &operator= (const wb_sensors_epuck_gsm_control &other) {
    std::copy(std::begin(other._gs), std::end(other._gs), std::begin(_gs));
    return *this;
  }

//#ifdef WHITEBOARD_POSTER_STRING_CONVERSION
//
//  const char PROPERTY_SEPARATOR = ':'; // Tilda
//  // '|' (Colon) Property Separator has already been used further in this branch.
//
//  const char FIELD_SERPARATOR = ',';
//
//  /** String constructor */
//  wb_sensors_epuck_gsm_control(const std::string &name) {
//      from_string(name);
//  }
//
//  /** convert from a string */
//  void from_string(const std::string &str)
//  {
//    std::istringstream iss(str);
//    std::string token;
//    getline(iss, token, PROPERTY_SEPARATOR);
////    printf("Token is %s\n",token.c_str());
//    std::istringstream iss_gs(token);
//    {
//      int i = 0;
//      std::string subtoken;
//      while (getline(iss_gs, subtoken, FIELD_SERPARATOR)) {
//        _gs[i++].from_string(subtoken);
//      }
//      _gs[i].from_string(subtoken);
//    }
//  }
//
//  /** get string serialisation */
//  std::string to_string() {
//    using namespace std;
//    ostringstream ss;
//    for(int i=0; i<NUMBER_GSM_SENSORS-1; i++) {
//      ss << this->gs(i).to_string() << FIELD_SERPARATOR;
//    }
//    ss << this->gs(NUMBER_GSM_SENSORS-1).to_string();
////    printf("To String::=> %s",ss.str().c_str());
//    return ss.str();
//  }
//
//  /** get message description */
//  std::string description() {
//    using namespace std;
//    ostringstream ss;
//    ss << "gs(";
//    for(int i=0; i<NUMBER_GSM_SENSORS-1; i++) {
//      ss << this->gs(i).to_string() << FIELD_SERPARATOR;
//    }
//    ss << this->gs(NUMBER_GSM_SENSORS-1).to_string() << ")";
////    printf("Desc::=> %s",ss.str().c_str());
//    return ss.str();
//  }
//#endif // WHITEBOARD_POSTER_STRING_CONVERSION

#ifdef WHITEBOARD_POSTER_STRING_CONVERSION

  const char PROPERTY_SEPARATOR = '|'; // Pipe

  const char FIELD_SERPARATOR = ',';

  /** String constructor */
  wb_sensors_epuck_gsm_control(const std::string &name) {
      from_string(name);
  }

  /** convert from a string */
  void from_string(const std::string &str)
  {
    std::istringstream iss(str);
    std::string token;
    getline(iss, token, PROPERTY_SEPARATOR);
    std::istringstream iss_gs(token);
    {
      int i = 0;
      std::string subtoken;
      while (getline(iss_gs, subtoken, FIELD_SERPARATOR)) {
        this->set_gs(static_cast<uint8_t>(atoi(subtoken.c_str())),i++);
      }
    }
  }

  /** get string serialisation */
  std::string to_string() {
    using namespace std;
    ostringstream ss;
    for(int i=0; i<(NUMBER_GSM_SENSORS-1); i++) {
      ss << this->gs(i) << FIELD_SERPARATOR;
    }
    ss << this->gs(NUMBER_GSM_SENSORS-1);
    return ss.str();
  }

  /** get message description */
  std::string description() {
    using namespace std;
    ostringstream ss;
    ss << "gs(";
    for(int i=0; i<( (NUMBER_GSM_SENSORS-1) ); i++) {
      ss << static_cast<int>(this->gs(i)) << ", ";
    }
    ss << static_cast<int>(this->gs(NUMBER_GSM_SENSORS-1)) << ") ";
    return ss.str();
  }
#endif // WHITEBOARD_POSTER_STRING_CONVERSION


#endif // __cplusplus

};

#endif // _WBSENSORSEPUCKGSMCONTROL_


