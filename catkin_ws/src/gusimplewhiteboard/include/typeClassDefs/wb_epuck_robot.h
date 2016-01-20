/**
 * \file  wb_epuck_robot.h
 *  Whiteboard ePuck Robot Control/Status Class
 *  Created by
 *    \author Dimitri Joukoff
 *    \date   5/05/2015.
 */

/*
 *
 * This is the C implementation of the e-Puck Robot Control/Status class.  It is an
 * assembly, using the principles of composition and modularity, of the communication
 * structures used by the sensors, emitters, and motors when operating the e-Puck
 * through the Whiteboard.
 *
 * It is designed such that it is agnostic to both the driver and controller
 * implementations.  Thus it could be used to operate a real e-Puck or, as has been
 * the case in the MiPal Lab, a simulated e-Puck in Webots, or other simulation
 * software (eg Gazebo, Morse).
 *
 * The class can easily be extended to include standard e-Puck functions that haven't
 * been implemented here (Bluetooth, Microphone, Speaker) and other optional modules
 * available for the e-Puck (e-RandB, GumStix Overo Earth, etc).
 *
 * The class incorporates a control/status architecture, so the driver implementation
 * listens to commands from a controller and executes them.  The controller listens
 * to status information and determines what the next control instruction should be.
 * The Whiteboard serves as the middleware between the controller and the driver.
 *
 *
 * Class Hierarchy:
 *      (C++) EPuckRobotControlStatus
 *      (C)   wb_epuck_robot          <= This class
 *      (C)   wb_VARIOUS
 *      (C)   wb_generic_sensor/wb_generic_emitter/wb_kinematic_motor
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

#ifndef _WBEPUCKROBOT_
#define _WBEPUCKROBOT_

#include <sys/types.h>
// Griffith Universities 'magic' utilities library.
#include <gu_util.h>

// The 'wb_' includes below are implementations of the various sub-systems
// implmented in the Whiteboard.
#include "wb_differential_robot.h"
#include "wb_sensors_epuck_gsm.h"
#include "wb_sensors_epuck_proximity.h"
#include "wb_sensors_epuck_light.h"
#include "wb_sensors_epuck_accel.h"
#include "wb_sensors_epuck_camera.h"
#include "wb_emitters_epuck_led.h"

/** Useful definitions when working with an ePuck */
#define WHEEL_RADIUS 20.5f  // mm
#define AXLE_WIDTH 52.0f    // mm

struct wb_epuck_robot {

  /** e-Puck Motors
   *  The e-Puck has two (2) motors (left & right)
   *
   *  Motor commands are accepted by the ePuck in 1000ths of a revolution per second.
   *  The maximum speed that can be commanded is +/- 1000 (ie 1 revolution/second).
   *  Converting the speed units to millimeters, the maximum speed that can be
   *  commanded is approximately +/- 128.8mm/sec.
   *
   *  Each motor also has an encoder with a resolution of 1/1000th of a rotation.
   *  With its wheel radius, a single encoder tick represents 0.1288mm travelled
   *
   */
  PROPERTY(struct wb_differential_robot, motors)

   /** e-Puck Ground Sensor Module
   *  Optional module that has three (3) Photo-diodes (gs0 - gs2)
   *  They are mounted as a module at the front of the e-Puck, under the camera
   *  The sensors are aligned on the Y axis
   */
  PROPERTY(struct wb_sensors_epuck_gsm, gsm)

  /** e-Puck Proximity Sensors
   *  The e-Puck's eight (8) infrared proximity sensors (ps0 - ps7)
   *  are mounted around the body of the e-Puck
   */
  PROPERTY(struct wb_sensors_epuck_proximity, ps)

  /** e-Puck LightSensors
   *  The e-Puck's eight (8) LightSensors (ls0 - ls7)
   *  are almost co-positioned with the proximity sensors
   */
  PROPERTY(struct wb_sensors_epuck_light, ls)

  /** e-Puck 3-Axis Accelerometer
   *  The accelerometer reports acceleration in m/s^2
   */
  PROPERTY(struct wb_sensors_epuck_accel, accel)

  /** e-Puck Camera (MiPal Implementation)
   *  The e-Puck camera is a VGA color camera with a resolution of 640x480 pixels (24bits/pixel)
   *  Typically the camera is used with a smaller viewport (eg 52x39) or with a single line of pixels
   *
   *  Since the Whiteboard is not used for streaming media, the MiPal implementation of the
   *  Camera is provided in this class through the 'wb_sensor_epuck_camera.h' definition.
   *  However, as with other modules, this can be altered to meet the user's needs.
   */
  PROPERTY(struct wb_sensors_epuck_camera, cam)

  /** e-Puck LEDs
   *  The e-Puck has 10 LED emitters
   *  They are mounted:
   *  0:  The whole upper ring is lite up red
   *  1:  Red 45 degrees
   *  2:  Red 90 degrees
   *  3   Red 135 degrees
   *  4:  Red Tail Lights (175 & 185 degrees) (Two LEDs)
   *  5:  Red 225 degrees
   *  6:  Red 270 degrees
   *  7:  Red 315 degrees
   *  8:  Green Body
   *  9:  Red next to camera
   */
  PROPERTY(struct wb_emitters_epuck_led, leds)

  /** OTHER DEVICES NOT IMPLEMENTED IN THE CURRENT VERSION
   *
   *  Speaker
   *  Microphone
   *  Battery Monitoring functions
   *  Bluetooth & RS232 communication
   *
   *  Other optional devices
   */

//   /** e-Puck Speaker
//    *  The e-Puck's speaker is able to play WAV files or produce tones.
//    */
//   PROPERTY(struct wb_emitter_epuck_speaker, spk)
//
//   /** e-Puck Microphone
//    *  The e-Puck has 3 microphones
//    */
//   PROPERTY(struct wb_sensor_epuck_mic, mic)

#ifdef __cplusplus
    /** Default Constructor */
    wb_epuck_robot() : _motors(), _gsm(), _ps(), _ls(), _accel(), _cam(), _leds() {}
#endif // __cplusplus


};


#endif // _WBEPUCKROBOT_
