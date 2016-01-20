/**
 * \file  wb_sensors_epuck_accel.h
 *  Whiteboard Accelerometer Sensor Class
 *  Created by
 *    \author Dimitri Joukoff
 *    \date   5/05/2015.
 */

/*
 *
 * This class represents the accelerometer available on the e-Puck.
 *
 * Through the Whiteboard, the controller posts current values for the axis
 * which are enabled, and the remote enables/disables them and reads their values.
 *
 *
 * Class Hierarchy:
 *      (C++) EPuckRobotControlStatus
 *      (C)   wb_epuck_robot
 *      (C)   wb_sensors_epuck_accel <= This class
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

#ifndef _WBSENSORSEPUCKACCELSTATUS_
#define _WBSENSORSEPUCKACCELSTATUS_

#include <sys/types.h>
#include <gu_util.h>

#ifdef WHITEBOARD_POSTER_STRING_CONVERSION
#include <sstream>
#include <ctype.h>
#endif

#include "wb_generic_analog_sensor_status.h"

/** e-Puck 3-Axis Accelerometer
 *  The e-Puck's accelerometer reports acceleration in m/s^2
 */
struct wb_sensors_epuck_accel_status {
  /** X Axis force */
  PROPERTY(struct wb_generic_analog_sensor_status, x)
  /** Y Axis force */
  PROPERTY(struct wb_generic_analog_sensor_status, y)
  /** Z Axis force */
  PROPERTY(struct wb_generic_analog_sensor_status, z)

#ifdef __cplusplus
  /** Default Constructor */
  wb_sensors_epuck_accel_status() : _x(), _y(), _z() {}

  /** Copy Constructor */
  wb_sensors_epuck_accel_status(const wb_sensors_epuck_accel_status &other) : _x(other._x), _y(other._y), _z(other._z) {}

  /** Assignment Operator */
  wb_sensors_epuck_accel_status &operator= (const  wb_sensors_epuck_accel_status &other) {
    _x = other._x;
    _y = other._y;
    _z = other._z;
    return *this;
  }

#ifdef WHITEBOARD_POSTER_STRING_CONVERSION

  const char PROPERTY_SEPARATOR = ':';
  // '|' (Pipe) Property Separator has already been used further in this branch.

  /** String constructor */
  wb_sensors_epuck_accel_status(const std::string &name) {
      from_string(name);
  }

  /** convert from a string */
  void from_string(const std::string &str)
  {
    std::istringstream iss(str);
    std::string token;
    getline(iss, token, PROPERTY_SEPARATOR);
    _x.from_string(token);
    getline(iss, token, PROPERTY_SEPARATOR);
    _y.from_string(token);
     getline(iss, token, PROPERTY_SEPARATOR);
    _z.from_string(token);
 }


  /** get string serialisation */
  std::string to_string() {
    using namespace std;
    ostringstream ss;
    ss << this->x().to_string() << PROPERTY_SEPARATOR \
       << this->y().to_string() << PROPERTY_SEPARATOR \
       << this->z().to_string();
    return ss.str();
  }

  /** get message description */
  std::string description() {
    using namespace std;
    ostringstream ss;
    ss << "x" << this->x().description() << " " \
       << "y" << this->y().description() << " " \
       << "z" << this->z().description();
    return ss.str();
  }
#endif // WHITEBOARD_POSTER_STRING_CONVERSION

#endif // __cplusplus

};

#endif // _WBSENSORSEPUCKACCELSTATUS_


