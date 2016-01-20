#ifndef ePuckWhiteboard_H_INCLUDED
#define ePuckWhiteboard_H_INCLUDED

/**
 * file: epuckwhiteboard.h
 *
 *  Webots controller for an e-Puck using idempotent messages via the gusimplewhiteboard
 *  Interfaces with the Subsumption Architecture ensemble; epuck...ByGSM.machine
 *
 * Created by Dimitri Joukoff
 * Copyright (c) 2015 Dimitri Joukoff @MiPal
 *
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
 *    This product includes software developed by Dimitri Joukoff.
 *
 * 4. Neither the name of the author nor the names of contributors
 *    may be used to endorse or promote products derived from this
 *    software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * 'AS IS' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER
 * OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
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
 */


#include <webots/Robot.hpp>
#include <webots/DifferentialWheels.hpp>
#include <webots/Accelerometer.hpp>
#include <webots/Camera.hpp>

#include "guwhiteboardtypelist_generated.h" // Whiteboard Class handlers
#include "typeClassDefs/EPuck_Messages.h"   // Whiteboard Classes

/** Webots Time Step in milliseconds */
const int TIME_STEP = 32;
const int  TIME_STEP_CAM = 64;
const int  WEBOTS_PIXELS_MAX_VALUE=255; /// Used by the MiPal Camera implementation
// Speed of the E-Puck
const double MAX_SPEED = 300.0;

/***
  * Sensor warm up time constants
  * Since Sensors take time before they can report
  * their values, a delay is required.
  *
  * Delay is measure in iterations of the Controller's RUN loop.
  */
const uint32_t WHEEL_ENCODER_DELAY = 0; /// Warm up time for the encoders in Webots is 0;
const uint32_t GSM_SENSOR_DELAY = 1;
const uint32_t PS_SENSOR_DELAY = 1;
const uint32_t LS_SENSOR_DELAY = 1;
const uint32_t ACCEL_DELAY = 1;
const uint32_t CAMERA_DELAY = 1;



class ePuckWhiteboard : public webots::DifferentialWheels {

  public:
    /**
     * ePuckWhiteboard constructor
     */
    ePuckWhiteboard();

    /**
     * ePuckWhiteboard destructor
     */
    virtual ~ePuckWhiteboard();

    /**
     * run() method as required by the Webots API.
     * After setting up initial conditions and requirements in the constructor,
     * the main run loop is entered.
     */
    void run();

    bool running = false;

  private:

    /***
      *  These methods are vitualised to enable customisations
      *  for specific applications.
      */
    virtual void actOnControlMessages ();
    virtual void sendStatusMessages ();
    virtual void read_image();
    virtual int16_t find_total(int tab[], int sizeTab, int threshold);
    virtual int16_t find_middle(int tab[], int sizeTab);

    /*** Handlers for the Whiteboard Classes used by the e-Puck */
    guWhiteboard::SENSORS_EPuckAccel_Control_t        wbhEPuckAccel_Control;
    guWhiteboard::SENSORS_EPuckAccel_Status_t         wbhEPuckAccel_Status;
    guWhiteboard::SENSORS_EPuckCamera_Control_t       wbhEPuckCamera_Control;
    guWhiteboard::SENSORS_EPuckCamera_Status_t        wbhEPuckCamera_Status;
    guWhiteboard::SENSORS_EPuckGSM_Control_t          wbhEPuckGSM_Control;
    guWhiteboard::SENSORS_EPuckGSM_Status_t           wbhEPuckGSM_Status;
    guWhiteboard::SENSORS_EPuckLight_Control_t        wbhEPuckLight_Control;
    guWhiteboard::SENSORS_EPuckLight_Status_t         wbhEPuckLight_Status;
    guWhiteboard::SENSORS_EPuckProximity_Control_t    wbhEPuckProximity_Control;
    guWhiteboard::SENSORS_EPuckProximity_Status_t     wbhEPuckProximity_Status;
    guWhiteboard::DifferentialRobotControl_t          wbhDifferentialRobot_Control;
    guWhiteboard::DifferentialRobotStatus_t           wbhDifferentialRobot_Status;
    guWhiteboard::EMITTERS_EPuckLED_Control_t         wbhEPuckLED_Control;
    guWhiteboard::EMITTERS_EPuckLED_Status_t          wbhEPuckLED_Status;

    /*** Local instances of the Whiteboard Classes used by the e-Puck */
    guWhiteboard::SENSORS_EPuckAccel_Control          wbcEPuckAccel_Control, wbcEPuckAccel_Control_old;
    guWhiteboard::SENSORS_EPuckAccel_Status           wbcEPuckAccel_Status;
    guWhiteboard::SENSORS_EPuckCamera_ControlStatus   wbcEPuckCamera_Control, wbcEPuckCamera_Control_old;
    guWhiteboard::SENSORS_EPuckCamera_ControlStatus   wbcEPuckCamera_Status;
    guWhiteboard::SENSORS_EPuckGSM_Control            wbcEPuckGSM_Control, wbcEPuckGSM_Control_old;
    guWhiteboard::SENSORS_EPuckGSM_Status             wbcEPuckGSM_Status;
    guWhiteboard::SENSORS_EPuckLight_Control          wbcEPuckLight_Control, wbcEPuckLight_Control_old;
    guWhiteboard::SENSORS_EPuckLight_Status           wbcEPuckLight_Status;
    guWhiteboard::SENSORS_EPuckProximity_Control      wbcEPuckProximity_Control, wbcEPuckProximity_Control_old;
    guWhiteboard::SENSORS_EPuckProximity_Status       wbcEPuckProximity_Status;
    guWhiteboard::DifferentialRobotControlStatus      wbcDifferentialRobot_Control, wbcDifferentialRobot_Control_old;
    guWhiteboard::DifferentialRobotControlStatus      wbcDifferentialRobot_Status;
    guWhiteboard::EMITTERS_EPuckLED_ControlStatus     wbcEPuckLED_Control, wbcEPuckLED_Control_old;
    guWhiteboard::EMITTERS_EPuckLED_ControlStatus     wbcEPuckLED_Status;

    webots::DistanceSensor* gs[3];  /// Ground Sensor Module
    webots::DistanceSensor* ps[8];  /// Proximity sensors
    webots::LightSensor* ls[8];     /// Light Sensors
    webots::LED* led[10];           /// LEDs
    webots::Accelerometer* accel;   /// Accelerometer
    webots::Camera* myCamera;       /// Camera (MiPal implementation is used here.)

    /***
      * Internal state monitoring to enable more efficient operation.
      * If the controller knows that an actuator/sensor has been turned
      * off by the user's application, then there is not need to call
      * the e-Puck simulator's corresponding functions.
      *
      */
    bool    motorEncoderEnabled = false;
    bool    leftMotorOn = true;
    bool    rightMotorOn = true;
    double  leftMotorSpeed = 0.0;
    double  rightMotorSpeed = 0.0;
    uint8_t cameraChannel;

    /***
      * Whiteboard event counters to keep track of incoming messages.
      * No point getting a message from the whiteboard if the message
      * is the same one from the last iteration.
      */
    uint16_t ctrDifferentialRobotControl, ctrDifferentialRobotControl_old;
    uint16_t ctrEPuckGSM_Control, ctrEPuckGSM_Control_old;
    uint16_t ctrEPuckProximity_Control, ctrEPuckProximity_Control_old;
    uint16_t ctrEPuckLight_Control, ctrEPuckLight_Control_old;
    uint16_t ctrEPuckAccelControl, ctrEPuckAccelControl_old;
    uint16_t ctrEPuckCamera_Control, ctrEPuckCamera_Control_old;
    uint16_t ctrEPuckLED_Control, ctrEPuckLED_Control_old;

    int *imagePerChannel[NUMBER_CHANNELS];  /// buffers  to read the pixels
    const unsigned char *the_image;         /// image buffer

    /***
      * Keeps track of the number of iterations through the main 'run' loop.
      * Each iteration is equivalent to TIME_STEP milliseconds.
      */
    uint32_t iteration = 0;
    /***
      * Counters for each sensor to track warm up time.
      * Since Sensors take time before they can report
      * their values, a delay is required.
      *
      * NOTE:  The motors are always on in Webots.
      *
      * Delay is measure in iterations of the Controller's RUN loop.
      */
    uint32_t wheel_encoder_enable_delay[2];
    uint32_t gs_enable_delay[3];
    uint32_t ps_enable_delay[8];
    uint32_t ls_enable_delay[8];
    uint32_t accel_enable_delay;
    uint32_t cam_enable_delay;

};
#endif // ePuckWhiteboard_H_INCLUDED
