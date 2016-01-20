/**
 * \file  wb_sensors_epuck_camera.h
 *  Whiteboard Camera Sensor Class
 *  Created by
 *    \author Vlad Estivill-Castro
 *    Adapted to the EPuckRobotControlStatus Whiteboard Class by
 *    \author Dimitri Joukoff
 *    \date   5/05/2015.
 */

/*
 *
 * This class represents the camera available on the e-Puck.
 *
 * The Whiteboard itself is not intended to be used for streaming video,
 * but rather a store of information derived from images.  Thus, the proecss
 * responsible for processing the ePucks camera images must be either the
 * controller itself, or have a dedicated channel to its input.
 *
 * Thus, the implementation given here is an adaptation of MiPal's e-Puck
 * camera class, which is normally used for tasks like following lines etc.
 * The class is based on information gathered from analysising a single line
 * of the image for the selected colour channel.
 *
 * Through the Whiteboard, the controller posts current values for the channel(s)
 * which are enabled, and the remote enables/disables them and reads their values.
 *
 *
 * Class Hierarchy:
 *      (C++) EPuckRobotControlStatus
 *      (C)   wb_epuck_robot
 *      (C)   wb_sensors_epuck_camera <= This class
 *
 ********************************************************************************
 *
 *  Copyright 2015 Vlad Estivill-Castro/Dimitri Joukoff
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

#ifndef _WBSENSORSEPUCKCAMERA_
#define _WBSENSORSEPUCKCAMERA_

#ifdef WHITEBOARD_POSTER_STRING_CONVERSION
#include <sstream>
#include <ctype.h>
#endif

/** Enumeration of the Colour Channels available in camera of the e-Puck differential robot */
enum CAMERA_CHANNELS {
    CHANNEL_BLUE = 0,
    CHANNEL_RED,
    CHANNEL_GREEN,
    CHANNEL_GREY,
    NUMBER_CHANNELS
};

/** e-Puck Camera (MiPal Implementation)
 *  The e-Puck camera is a VGA color camera with a resolution of 640x480 pixels (24bits/pixel)
 *  Typically the camera is used with a smaller viewport (eg 52x39) or with a single line of pixels
 *
 *  Since the Whiteboard is not used for streaming media, the MiPal implementation of the
 *  Camera is provided.
 */
struct wb_sensors_epuck_camera {
    /** camera width */
    PROPERTY(uint8_t,width)
    /** camera height */
    PROPERTY(uint8_t,height)
    /** camera camera_threshold */
    PROPERTY(uint8_t,threshold)
    /** camera median per channel */
    ARRAY_PROPERTY(uint8_t, median, NUMBER_CHANNELS)
    /** camera total per channel */
    ARRAY_PROPERTY(uint8_t, totalpixel_count, NUMBER_CHANNELS)
    /** true = post regularly to the whiteboard, false, no reporting, sensor is off */
    PROPERTY(bool,on)
    /** channel selection */
    PROPERTY(uint8_t, channel)

#ifdef __cplusplus
    /** Default Constructor */
    wb_sensors_epuck_camera() :
      _width(0),
      _height(0),
      _threshold(0),
      _on(false)
      {}

    /** Copy Constructor */
    wb_sensors_epuck_camera(const wb_sensors_epuck_camera &other) :
        _width(other._width),
        _height(other._height),
        _threshold(other._threshold),
        _on(other._on)
        {
            for (   CAMERA_CHANNELS channel_i= CHANNEL_BLUE;
                    channel_i != CHANNEL_GREY;
                    channel_i = static_cast<CAMERA_CHANNELS>(static_cast<int>(channel_i) + 1))
            {
                _median[channel_i]=other._median[channel_i];
                _totalpixel_count[channel_i]=other._totalpixel_count[channel_i];
            }
        }

    /** Assignment Operator */
    wb_sensors_epuck_camera &operator= (const  wb_sensors_epuck_camera &other) {
        _width=other._width;
        _height=other._height;
        _threshold=other._threshold;
        for (   CAMERA_CHANNELS channel_i= CHANNEL_BLUE;
                channel_i != CHANNEL_GREY ;
                channel_i = static_cast<CAMERA_CHANNELS>(static_cast<int>(channel_i) + 1))
        {
            _median[channel_i]=other._median[channel_i];
            _totalpixel_count[channel_i]=other._totalpixel_count[channel_i];
        }
        _on=other._on;
        return *this;
    }

#ifdef WHITEBOARD_POSTER_STRING_CONVERSION

  const char PROPERTY_SEPARATOR = '~'; // Tilda
  // '|' (Pipe) Property Separator has already been used further in this branch.
  // ':' (Colon) Property Separator has already been used further in this branch.

  const char FIELD_SERPARATOR = ',';

  /** String constructor */
  wb_sensors_epuck_camera(const std::string &name) {
      from_string(name);
  }

  /** convert from a string */
  void from_string(const std::string &str)
  {
    std::istringstream iss(str);
    std::string token;
    getline(iss, token, PROPERTY_SEPARATOR);
    _width = static_cast<uint8_t>(atof(token.c_str()));
    getline(iss, token, PROPERTY_SEPARATOR);
    _height = static_cast<uint8_t>(atof(token.c_str()));
    getline(iss, token, PROPERTY_SEPARATOR);
    _threshold = static_cast<uint8_t>(atoi(token.c_str()));
    getline(iss, token, PROPERTY_SEPARATOR);
    std::istringstream iss_median(token);
    {
      int i = 0;
      std::string subtoken;
      while (getline(iss_median, subtoken, FIELD_SERPARATOR)) {
        _median[i++] = static_cast<uint8_t>(atoi(subtoken.c_str()));
      }
    }
    getline(iss, token, PROPERTY_SEPARATOR);
    std::istringstream iss_totalpixel_count(token);
    {
      int i = 0;
      std::string subtoken;
      while (getline(iss_totalpixel_count, subtoken, FIELD_SERPARATOR)) {
        _totalpixel_count[i++] = static_cast<uint8_t>(atoi(subtoken.c_str()));
      }
    }
    getline(iss, token, PROPERTY_SEPARATOR);
    _on = (token.compare("T") == 0) ? true : false;
    getline(iss, token, PROPERTY_SEPARATOR);
    _channel = static_cast<uint8_t>(atoi(token.c_str()));
  }

  /** get string serialisation */
  std::string to_string() {
    using namespace std;
    ostringstream ss;
    ss << static_cast<int>(this->width()) << PROPERTY_SEPARATOR \
       << static_cast<int>(this->height()) << PROPERTY_SEPARATOR \
       << static_cast<int>(this->threshold()) << PROPERTY_SEPARATOR;
    for(int i=0; i<NUMBER_CHANNELS-1; i++) {
      ss << static_cast<int>(this->median(i)) << FIELD_SERPARATOR;
    }
    ss << static_cast<int>(this->median(NUMBER_CHANNELS-1)) << PROPERTY_SEPARATOR;
    for(int i=0; i<NUMBER_CHANNELS-1; i++) {
      ss << static_cast<int>(this->totalpixel_count(i)) << FIELD_SERPARATOR;
    }
    ss << static_cast<int>(this->totalpixel_count(NUMBER_CHANNELS-1)) << PROPERTY_SEPARATOR;
    ss << ((this->on()) ? "True" : "False") << PROPERTY_SEPARATOR \
       << static_cast<int>(this->channel());
    return ss.str();
  }

  /** get message description */
  std::string description() {
    using namespace std;
    ostringstream ss;
    ss << "W("  << static_cast<int>(this->width()) << ") " \
       << "H("  << static_cast<int>(this->height()) << ") " \
       << "T("  << static_cast<int>(this->threshold()) << ") " \
       << "M(";
    for(int i=0; i<NUMBER_CHANNELS-1; i++) {
      ss << static_cast<int>(this->median(i)) << ", ";
    }
    ss << static_cast<int>(this->median(NUMBER_CHANNELS-1)) << ") " \
       << "tpc(";
    for(int i=0; i<NUMBER_CHANNELS-1; i++) {
      ss << static_cast<int>(this->totalpixel_count(i)) << ", ";
    }
    ss << static_cast<int>(this->totalpixel_count(NUMBER_CHANNELS-1)) << ") ";
    ss << "On(" << ((this->on()) ? "True" : "False") << ") " \
       << "C("  << static_cast<int>(this->channel()) << ")";
    return ss.str();
  }
#endif // WHITEBOARD_POSTER_STRING_CONVERSION

#endif // __cplusplus
};

#endif // _WBSENSORSEPUCKCAMERA_
