/**
 * \file  wb_kinematic_motor.h
 *  Whiteboard Kinematic Motor Class
 *  Created by
 *    \author Rene Hexel
 *    \author Dimitri Joukoff (Modified Rene's original)
 *    \date   27/03/2015.
 */

/*
 *
 * This class represents the e-Puck's motor. (Individual motors)
 *
 * Through the Whiteboard, the controller posts current odometry values when the
 * motor's encoder is enabled, and the remote enables/disables the encoder and can
 * also turn the motor on/off.
 *
 *
 * Class Hierarchy:
 *      (C++) EPuckRobotControlStatus
 *      (C)   wb_epuck_robot
 *      (C)   wb_differential_robot
 *      (C)   wb_kinematic_motor    <= This class
 *
 ********************************************************************************
 *
 *  Copyright 2015 Rene Hexel
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
 *        This product includes software developed by Rene Hexel
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

#ifndef _WBMOTOR_
#define _WBMOTOR_

#include <sys/types.h>
#include <gu_util.h>

#define DEFAULT_KINEMATIC_SPEED  0
#define DEFAULT_KINEMATIC_ACCELERATION  0

/** Basic kinematic motor (i.e. motor to ground) struct */
struct wb_kinematic_motor {
	/** Speed setting -32767 to 32767 in mm/s */
	PROPERTY(int16_t, speed)
	/** Acceleration setting -32767 to 32767 in mm/s/s
            (zero means default acceleration) */
	PROPERTY(int16_t, accel)
	/** Odometer used for storing odometry in mm (to ground) */
	PROPERTY(int32_t, odo)

	/** Not all motors can be turned on/off, but it is possible */
	/** Status of the Motor (On = True (Default)/Off = False) */
	PROPERTY(bool, motorOn)
	/** Not all motors have encoders, or encoders can be turned on/off */
	/** Status of the Motor's Encoder (On = True /Off = False (Default)) */
	PROPERTY(bool, encoderOn)
    /** padding to shut up the compiler on 64 bit systems */
//      PROPERTY(uint16_t, padding)
#ifdef __cplusplus
	/** Default constructor */
	wb_kinematic_motor() : _speed(DEFAULT_KINEMATIC_SPEED), _accel(DEFAULT_KINEMATIC_ACCELERATION), _odo(0), _motorOn(true), _encoderOn(false) {}
	/* _padding(0)  // Not needed I think */

  /** Copy Constructor */
	wb_kinematic_motor(const wb_kinematic_motor &other) :
    _speed(other._speed),
    _accel(other._accel),
    _odo(other._odo),
    _motorOn(other._motorOn),
    _encoderOn(other._encoderOn) {}

  /** Assignment Operator */
	wb_kinematic_motor &operator= (const wb_kinematic_motor &other) {
    _speed = other._speed;
    _accel = other._accel;
    _odo = other._odo;
    _motorOn = other._motorOn;
    _encoderOn = other._encoderOn;
    return *this;
	}
#endif  //__cplusplus
};

#endif  // _WBMOTOR_
