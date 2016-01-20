/**
 * file: epuckwhiteboard.cpp
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

#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <unistd.h>
#include <math.h>
#include <cmath>
#include <chrono>
#include "epuckwhiteboard.h"


/***
  * The camera code has not been tested
  * as the epuckMeanderLinesByGSM machine
  * does not use it.
  *
  * TODO :: Create a machine that uses the camera
  *
  */


using namespace webots;

/***
  * Function to return the Whiteboard event counter for the
  * requested message type.
  */
uint16_t getEventCounterForMessageType(guWhiteboard::WBTypes thisMsg) {
  gu_simple_whiteboard_descriptor* wbd = get_local_singleton_whiteboard();
  return wbd->wb->event_counters[thisMsg];
}

/***
  * Read the camera and copy the zero (0) scan line
  * into the imagePerChannel variable.
  *
  * This is based on MiPal's follow line usage of the camera.
  *
  * This is a VIRTAUL function to allow customisation for
  * alternative uses.
  *
  */
void ePuckWhiteboard::read_image() {
    ePuckWhiteboard::the_image= myCamera->getImage();
    for (int i = 0; i < wbcEPuckCamera_Control.width(); i++) {
        // imageGetBlue selects yellow on the ground very well
        // imageGetGreen selects magenta very well
        // imageGetRed selects blue/cyan very well
        imagePerChannel[CHANNEL_BLUE][i] = WEBOTS_PIXELS_MAX_VALUE-myCamera->imageGetBlue(the_image, wbcEPuckCamera_Control.width(), i, 0);
        imagePerChannel[CHANNEL_RED][i] = WEBOTS_PIXELS_MAX_VALUE-myCamera->imageGetRed(the_image, wbcEPuckCamera_Control.width(), i, 0);
        imagePerChannel[CHANNEL_GREEN][i] = WEBOTS_PIXELS_MAX_VALUE-myCamera->imageGetGreen(the_image, wbcEPuckCamera_Control.width(), i, 0);
        imagePerChannel[CHANNEL_GREY][i] = WEBOTS_PIXELS_MAX_VALUE-myCamera->imageGetGrey(the_image, wbcEPuckCamera_Control.width(), i, 0);
     }
}

/***
  * Image analysis routine.  This function returns the amount of visible
  * pixels of the given channel, aims at producing a color detection
  * routine.
  *
  *
  * This is based on MiPal's follow line usage of the camera.
  *
  * This is a VIRTAUL function to allow customisation for
  * alternative uses.
  *
  */
int16_t ePuckWhiteboard::find_total(int tab[], int sizeTab, int threshold){
    int16_t count=0;
    for (int i=0; i<sizeTab;i++){
        if (tab[i]>threshold) count++;
    }
    return count;
}
/***
  * Image analysis routine.  This function returns the position
  * of the peak contained in the array given in the argument.
  * (I have hesitation of what it actually does, Vlad)
  *
  * This is based on MiPal's follow line usage of the camera.
  *
  * This is a VIRTAUL function to allow customisation for
  * alternative uses.
  *
  */
int16_t ePuckWhiteboard::find_middle(int tab[], int sizeTab){

    int i,j;
    int *copy = (int *)malloc(sizeof(int)*sizeTab);
    int mean=0;
    int nb_best = sizeTab/10;
    int *index_bests = (int *)malloc(sizeof(int)*nb_best);

    // copy the tab, calculate the mean and
    // test if all the values are identical
    int identical=1;
    for (i=0; i<sizeTab;i++){
        copy[i]=tab[i];
        mean+=tab[i];
        if (tab[i]!=tab[0]) identical=0;
    }

    // exist with middle point if identical
    if (identical) {   free(copy);   	free(index_bests); return (int16_t) (sizeTab/2);  	      }

    mean/=sizeTab;

    // take the best values of the tab
    for (i=0; i<nb_best; i++){
        index_bests[i]=-1;
        int index=-1;
        int max=0;
        for (j=0; j<sizeTab; j++){
            if (max<copy[j] && copy[j]>mean){
                max=copy[j];
                index=j;
            }
        }
        index_bests[i]=index;
        copy[index]=0;
    }
    free(copy);
    //
    // calculate the position mean of th best values
    int firstMean=0;
    int count=0;
    for (i=0; i<nb_best; i++){
        if(index_bests[i]!=-1) {
            firstMean+=index_bests[i];
            count++;
        }
    }

    // count does not change send the middle
    if (count==0) { free(index_bests); return (int16_t) (sizeTab/2); }
    firstMean/=count;

    // eliminate extreme values
    int secondMean=0;
    count=0;
    for (i=0; i<nb_best; i++){
        if (index_bests[i]<firstMean+sizeTab/10 && index_bests[i]>firstMean-sizeTab/10) {
            count++;
            secondMean+=index_bests[i];
        }
    }
    free(index_bests);
    if (count==0) return (int16_t) (sizeTab/2);
    return (int16_t) (secondMean/count);
}

/// ePuckWhiteboard constructor
ePuckWhiteboard::ePuckWhiteboard() : DifferentialWheels()  {

  /***
    * In this implementation of the controller, we make use of
    * the following E-Puck Modules:
    * + Ground Sensor Module   (optional extra for the E-Puck)
    * + Camera
    * + DifferentialWheels
    * + Encoders
    *
    */


  /***
    * Read the whiteboard event counters at the commencement of the run
    * for the control messages we use.  This allows the e-Puck to wait
    * for the user's application to send its first control message.
    *
    * Once the first control message is received, the "running" variable
    * is set TRUE.
    */
  ctrDifferentialRobotControl_old = getEventCounterForMessageType(guWhiteboard::kDifferentialRobotControl_v);
  ctrEPuckGSM_Control_old = getEventCounterForMessageType(guWhiteboard::kSENSORS_EPuckGSM_Control_v);
  ctrEPuckProximity_Control_old = getEventCounterForMessageType(guWhiteboard::kSENSORS_EPuckProximity_Control_v);
  ctrEPuckLight_Control_old = getEventCounterForMessageType(guWhiteboard::kSENSORS_EPuckLight_Control_v);
  ctrEPuckAccelControl_old = getEventCounterForMessageType(guWhiteboard::kSENSORS_EPuckAccel_Control_v);
  ctrEPuckCamera_Control_old = getEventCounterForMessageType(guWhiteboard::kSENSORS_EPuckCamera_Control_v);
  ctrEPuckLED_Control_old = getEventCounterForMessageType(guWhiteboard::kEMITTERS_EPuckLED_Control_v);


  /***
    * Ground Sensor Module
    *
    * Infrared sensors
    * Sensitive to all light, but red in particular
    *
    * 0 = Left Side
    * 1 = Middle
    * 2 = Right Side
    */
  gs[0] = getDistanceSensor("gs0");
  gs[1] = getDistanceSensor("gs1");
  gs[2] = getDistanceSensor("gs2");

  /*** They are disabled by default. */
  gs[0]->disable();
  gs[1]->disable();
  gs[2]->disable();

  /***
    * Proximity Sensors (Distance)
    *
    * Proximity sensors are numbered clockwise
    * 0 = 15  degrees
    * 1 = 45  degrees
    * 2 = 90  degrees
    * 3 = 170 degrees
    * 4 = 190 degrees
    * 5 = 270 degrees
    * 6 = 315 degrees
    * 7 = 345 degrees
    */
  ps[0] = getDistanceSensor("ps0");
  ps[1] = getDistanceSensor("ps1");
  ps[2] = getDistanceSensor("ps2");
  ps[3] = getDistanceSensor("ps3");
  ps[4] = getDistanceSensor("ps4");
  ps[5] = getDistanceSensor("ps5");
  ps[6] = getDistanceSensor("ps6");
  ps[7] = getDistanceSensor("ps7");

  /*** They are disabled by default. */
  ps[0]->disable();
  ps[1]->disable();
  ps[2]->disable();
  ps[3]->disable();
  ps[4]->disable();
  ps[5]->disable();
  ps[6]->disable();
  ps[7]->disable();

  /***
    * Light Sensors
    *
    * Useless for use as a proximity device.
    * Measures ambient light and the associated Webots World gives confusing results.
    *
    * Light sensors are numbered clockwise
    * 0 = 15  degrees
    * 1 = 45  degrees
    * 2 = 90  degrees
    * 3 = 170 degrees
    * 4 = 190 degrees
    * 5 = 270 degrees
    * 6 = 315 degrees
    * 7 = 345 degrees
    */
  ls[0] = getLightSensor("ls0");
  ls[1] = getLightSensor("ls1");
  ls[2] = getLightSensor("ls2");
  ls[3] = getLightSensor("ls3");
  ls[4] = getLightSensor("ls4");
  ls[5] = getLightSensor("ls5");
  ls[6] = getLightSensor("ls6");
  ls[7] = getLightSensor("ls7");

  /*** They are disabled by default. */
  ls[0]->disable();
  ls[1]->disable();
  ls[2]->disable();
  ls[3]->disable();
  ls[4]->disable();
  ls[5]->disable();
  ls[6]->disable();
  ls[7]->disable();

  /***
    * LED Lights
    *
    * Binary intensity single colour LEDs around the body.
    * By default they are single color
    * Green for the lower body
    * Red all others.
    *
    * LEDs are numbered clockwise (with exception of 1,8 & 9)
    * 0 = The whole ring is lite up,
    * 1 = 45 degrees
    * 2 = 90 degrees
    * 3 = 135 degrees
    * 4 = 175 & 185 degrees - "Tail Lights"
    * 5 = 225 degrees
    * 6 = 270 degrees
    * 7 = 315 degrees
    * 8 = Green Body Light
    * 9 = Light next to camera
    *
    * Webots allows other kinds of LED (Mapped Color, RGB and Analogue Intensity)
    * but the e-Puck does not use these.
    *
    */
  led[0] = getLED("led0");
  led[1] = getLED("led1");
  led[2] = getLED("led2");
  led[3] = getLED("led3");
  led[4] = getLED("led4");
  led[5] = getLED("led5");
  led[6] = getLED("led6");
  led[7] = getLED("led7");
  led[8] = getLED("led8");
  led[9] = getLED("led9");

  /*** They are off by default. */
  led[0]->set(0);
  led[1]->set(0);
  led[2]->set(0);
  led[3]->set(0);
  led[4]->set(0);
  led[5]->set(0);
  led[6]->set(0);
  led[7]->set(0);
  led[8]->set(0);
  led[9]->set(0);

  /***
    * Accelerometer
    *
    * The accelerometer has 3 axis:
    * X axis
    * Y axis
    * Z axis
    *
    */
  accel = getAccelerometer("accelerometer");
  /*** It is disabled by default. */
  accel->disable();

  /***
    * Camera
    *
    *
    */
  myCamera= getCamera ("camera");
  /*** It is disabled by default. */
  myCamera->disable();

  /***
    * Wheel Encoders
    *
    * As a differential robot, the e-Puck has two
    * encoders:
    * leftEncoder
    * rightEncoder
    *
    * We disable them at the start to be consistent
    * with the remainder of the controllers semantics.
    *
    */
  disableEncoders();

  /***
    * Reset the Wheel Encoders at the start.
    *
    * setEncoders(Left,Right)
    *
    */
  setEncoders(0.0,0.0);

  /***
    * Set the motor speeds to zero on start-up to
    * ensure the e-Puck is initially stationary.
    *
    * setSpeed(Left,Right)
    *
    */
  setSpeed(0.0,0.0);

  /***
    * Other e-Puck Sensors/Actuators
    *
    * The e-Puck has other sensors/actuators which
    * this implementation does not make use of.
    * They are:
    * + Speaker   "speaker"
    * + Mic       "mic0", "mic1", "mic2"
    * + Receiver  Receiver
    * + Emitter   Emitter
    *
    */

  printf("\f\n"); // Clear console

  /*** Once general behaviour is proven, use a robust random seeding technique */
  //  srand(static_cast<int>(std::chrono::system_clock::to_time_t(std::chrono::system_clock::now())));
  /*** But during initial testing, random is seeded with a fixed integer. */
  srand(1);
}

// ePuckWhiteboard destructor
ePuckWhiteboard::~ePuckWhiteboard() {
  /***
    * Since the camera allocates memory for its buffers,
    * we release the memory on exist.  But we check to see
    * if this is needed.
    */
  for (CAMERA_CHANNELS channel= CAMERA_CHANNELS::CHANNEL_BLUE;
       channel != CAMERA_CHANNELS::NUMBER_CHANNELS;
       channel = static_cast<CAMERA_CHANNELS>(static_cast<int>(channel) + 1))
  {
    if (!(&imagePerChannel[channel])) {
      free(imagePerChannel[channel]);
    }
  }

}

/// e-Puck run loop, as required by the Webots API.
void ePuckWhiteboard::run() {


  printf("Max Speed = %6.6f\n",getMaxSpeed());
  printf("Speed Unit = %6.6f\n",getSpeedUnit());
  // Main loop
  int result;
  do {
    iteration++;
    /** Control First */
    actOnControlMessages();
    /** then Report Status */
    if (running) sendStatusMessages();

    result = step(TIME_STEP);
    usleep(10); //give wb message   a chance to enable/disable devices
  } while (result != -1);
}

/** Act on Control Messages
 *  Check all actuators/sensors to determine
 *  if they are enabled and send current values.
 *
 *  In some cases, where an actuator is not
 *  able to provide a 'sensor' value, the last
 *  command is returned instead.
 *
 */
void ePuckWhiteboard::actOnControlMessages() {

  bool motorSpeedChanged = false;

  /** Act on Wheels first. */
  ctrDifferentialRobotControl = getEventCounterForMessageType(guWhiteboard::kDifferentialRobotControl_v);
  if (ctrDifferentialRobotControl_old != ctrDifferentialRobotControl) {
    running = true;
    wbcDifferentialRobot_Control = wbhDifferentialRobot_Control.get();
    /** Encoders before motors */
    if (!motorEncoderEnabled && (wbcDifferentialRobot_Control.left_motor().encoderOn() || wbcDifferentialRobot_Control.right_motor().encoderOn())) {
        enableEncoders(TIME_STEP);
        motorEncoderEnabled = true;
        printf("%d - Encoders Enabled\n",iteration);
        /***
          * Webots does not allow differential control of the encoders.
          * So we reset both the warm up delay counter at the same time.
          *
          * If this changes in the future, then the surrounding segement of
          * code will need to be changed to enable individual control of the
          * encoders.
          *
          */
        wheel_encoder_enable_delay[0] = wheel_encoder_enable_delay[1] = 0;
    }
    else
    if (motorEncoderEnabled && !(wbcDifferentialRobot_Control.left_motor().encoderOn() || wbcDifferentialRobot_Control.right_motor().encoderOn())) {
        wbcDifferentialRobot_Status.left_motor().set_odo(static_cast<uint16_t>(getLeftEncoder()));
        wbcDifferentialRobot_Status.right_motor().set_odo(static_cast<uint16_t>(getRightEncoder()));
        disableEncoders();
        motorEncoderEnabled = false;
        printf("%d - Encoders Disabled\n",iteration);
    }
    /** Now handle motors. */
    /** Speed change due to motors being turned on/off */
    if (   (wbcDifferentialRobot_Control.left_motor().motorOn() != wbcDifferentialRobot_Control_old.left_motor().motorOn())
        || (wbcDifferentialRobot_Control.right_motor().motorOn() != wbcDifferentialRobot_Control_old.right_motor().motorOn())
       )
    {
      if (wbcDifferentialRobot_Control.left_motor().motorOn() != wbcDifferentialRobot_Control_old.left_motor().motorOn()) {
        motorSpeedChanged = true;
        if (!wbcDifferentialRobot_Control.left_motor().motorOn()) {
          leftMotorOn = false;
          leftMotorSpeed = 0;
          printf("%d - Left Motor Off\n",iteration);
        } else {
          leftMotorSpeed = static_cast<double>(wbcDifferentialRobot_Control.left_motor().speed());  // TODO (DRJ) Motor Speed Calibration
          leftMotorOn = true;
           printf("%d - Left Motor On\n",iteration);
       }
      }
      if (wbcDifferentialRobot_Control.right_motor().motorOn() != wbcDifferentialRobot_Control_old.right_motor().motorOn()) {
        motorSpeedChanged = true;
        if (!wbcDifferentialRobot_Control.right_motor().motorOn()) {
          rightMotorOn = false;
          rightMotorSpeed = 0;
          printf("%d - Right Motor Off\n",iteration);
        } else {
          rightMotorSpeed = static_cast<double>(wbcDifferentialRobot_Control.right_motor().speed());  // TODO (DRJ) Motor Speed Calibration
          rightMotorOn = true;
          printf("%d - Right Motor On\n",iteration);
        }
      }
    }
    /** Speed change due to changes in speed */
    else
    if (   (wbcDifferentialRobot_Control.left_motor().speed() != wbcDifferentialRobot_Control_old.left_motor().speed())
        || (wbcDifferentialRobot_Control.right_motor().speed() != wbcDifferentialRobot_Control_old.right_motor().speed())
        && (wbcDifferentialRobot_Control.left_motor().motorOn() || wbcDifferentialRobot_Control.right_motor().motorOn())
       )
    {
      if (wbcDifferentialRobot_Control.left_motor().motorOn() && (wbcDifferentialRobot_Control.left_motor().speed() != wbcDifferentialRobot_Control_old.left_motor().speed())) {
        motorSpeedChanged = true;
        leftMotorSpeed = static_cast<double>(wbcDifferentialRobot_Control.left_motor().speed());  // TODO (DRJ) Motor Speed Calibration
        printf("%d - Left Motor Speed Changed\n",iteration);
      }
      if (wbcDifferentialRobot_Control.right_motor().motorOn() && (wbcDifferentialRobot_Control.right_motor().speed() != wbcDifferentialRobot_Control_old.right_motor().speed())) {
        motorSpeedChanged = true;
        rightMotorSpeed = static_cast<double>(wbcDifferentialRobot_Control.right_motor().speed());  // TODO (DRJ) Motor Speed Calibration
        printf("%d - Right Motor Speed Changed\n",iteration);
      }
    }
    if (motorSpeedChanged) {
      setSpeed(leftMotorSpeed,rightMotorSpeed);
      printf("%d - Change Speed\n",iteration);
      motorSpeedChanged = false;
    }
    /** make current control message the previous for next round. */
    ctrDifferentialRobotControl_old = ctrDifferentialRobotControl;
    wbcDifferentialRobot_Control_old = wbcDifferentialRobot_Control;
  }

  /** Turn on/off sensors as required. */

  /** GSM Sensors */
  ctrEPuckGSM_Control = getEventCounterForMessageType(guWhiteboard::kSENSORS_EPuckGSM_Control_v);
  if (ctrEPuckGSM_Control_old != ctrEPuckGSM_Control) {
    running = true;
    wbcEPuckGSM_Control = wbhEPuckGSM_Control.get();
    for (gsm_sensors sensor = gs0; sensor < NUMBER_GSM_SENSORS; sensor = static_cast<gsm_sensors>(static_cast<int>(sensor) + 1 )) {
      if (wbcEPuckGSM_Control.gs(sensor) != wbcEPuckGSM_Control_old.gs(sensor)) {
        if (wbcEPuckGSM_Control.gs(sensor)) {
          gs[static_cast<gsm_sensors>(static_cast<int>(sensor))]->enable(TIME_STEP);
          printf("%d - gs(%d) Enabled\n",iteration,static_cast<int>(sensor));
          gs_enable_delay[static_cast<int>(sensor)] = 0;
        } else {
          gs[static_cast<gsm_sensors>(static_cast<int>(sensor))]->disable();
          printf("%d - gs(%d) Disabled\n",iteration,static_cast<int>(sensor));
        }
      }
    }
    /** make current control message the previous for next round. */
    ctrEPuckGSM_Control_old = ctrEPuckGSM_Control;
    wbcEPuckGSM_Control_old = wbcEPuckGSM_Control;
  }

  /** Proximity Sensors */
  ctrEPuckProximity_Control = getEventCounterForMessageType(guWhiteboard::kSENSORS_EPuckProximity_Control_v);
  if (ctrEPuckProximity_Control_old != ctrEPuckProximity_Control) {
    running = true;
    wbcEPuckProximity_Control = wbhEPuckProximity_Control.get();
    for (proximity_sensors sensor = ps0; sensor < NUMBER_PROXIMITY_SENSORS; sensor = static_cast<proximity_sensors>(static_cast<int>(sensor) + 1 )) {
      if (wbcEPuckProximity_Control.ps(sensor) != wbcEPuckProximity_Control_old.ps(sensor)) {
        if (wbcEPuckProximity_Control.ps(sensor)) {
          ps[static_cast<gsm_sensors>(static_cast<int>(sensor))]->enable(TIME_STEP);
          printf("%d - ps(%d) Enabled\n",iteration,static_cast<int>(sensor));
          ps_enable_delay[static_cast<int>(sensor)] = 0;
        } else {
          ps[static_cast<gsm_sensors>(static_cast<int>(sensor))]->disable();
          printf("%d - ps(%d) Disabled\n",iteration,static_cast<int>(sensor));
        }
      }
    }
    /** make current control message the previous for next round. */
    ctrEPuckProximity_Control_old = ctrEPuckProximity_Control;
    wbcEPuckProximity_Control_old = wbcEPuckProximity_Control;
  }

  /** Light Sensors */
  ctrEPuckLight_Control = getEventCounterForMessageType(guWhiteboard::kSENSORS_EPuckLight_Control_v);
  if (ctrEPuckLight_Control_old != ctrEPuckLight_Control) {
    running = true;
    wbcEPuckLight_Control = wbhEPuckLight_Control.get();
    for (light_sensors sensor = ls0; sensor < NUMBER_LIGHT_SENSORS; sensor = static_cast<light_sensors>(static_cast<int>(sensor) + 1 )) {
      if (wbcEPuckLight_Control.ls(sensor).enabled() != wbcEPuckLight_Control_old.ls(sensor).enabled()) {
        if (wbcEPuckLight_Control.ls(sensor).enabled()) {
          ls[static_cast<light_sensors>(static_cast<int>(sensor))]->enable(TIME_STEP);
          printf("%d - ls(%d) Enabled\n",iteration,static_cast<int>(sensor));
          ls_enable_delay[static_cast<int>(sensor)] = 0;
        } else {
          ls[static_cast<light_sensors>(static_cast<int>(sensor))]->disable();
          printf("%d - ls(%d) Disabled\n",iteration,static_cast<int>(sensor));
        }
      }
    }
    /** make current control message the previous for next round. */
    ctrEPuckLight_Control_old = ctrEPuckLight_Control;
    wbcEPuckLight_Control_old = wbcEPuckLight_Control;
  }

  /** Accelerometer Sensor */
  ctrEPuckAccelControl = getEventCounterForMessageType(guWhiteboard::kSENSORS_EPuckAccel_Control_v);
  if (ctrEPuckAccelControl_old != ctrEPuckAccelControl) {
    running = true;
    wbcEPuckAccel_Control = wbhEPuckAccel_Control.get();
    if ( (wbcEPuckAccel_Control.x().enabled() || wbcEPuckAccel_Control.y().enabled() || wbcEPuckAccel_Control.z().enabled())  !=
         (wbcEPuckAccel_Control_old.x().enabled() || wbcEPuckAccel_Control_old.y().enabled() || wbcEPuckAccel_Control_old.z().enabled())) {
      if ((wbcEPuckAccel_Control.x().enabled() || wbcEPuckAccel_Control.y().enabled() || wbcEPuckAccel_Control.z().enabled())) {
        accel->enable(TIME_STEP);
        printf("%d - Accelerometer Enabled\n",iteration);
        accel_enable_delay = 0;
      } else {
        accel->disable();
        printf("%d - Accelerometer Disabled\n",iteration);
      }
    }
    /** make current control message the previous for next round. */
    ctrEPuckAccelControl_old = ctrEPuckAccelControl;
    wbcEPuckAccel_Control_old = wbcEPuckAccel_Control;
  }

  /***
    * Camera
    * In this implementation, the client can only:
    * + Turn the camera on/off
    *
    * Future enhancements can allow the client to:
    * + Set the width & height of the image they need to process,
    * + Select the colour channel to use
    *   (The MiPal implementation performs calculations on all the channels by default.)
    *
    */
  /** Handle On/Off before channel selection */
  ctrEPuckCamera_Control = getEventCounterForMessageType(guWhiteboard::kSENSORS_EPuckCamera_Control_v);
  if (ctrEPuckCamera_Control_old != ctrEPuckCamera_Control) {
    running = true;
    wbcEPuckCamera_Control = wbhEPuckCamera_Control.get();
    if (wbcEPuckCamera_Control.on() != wbcEPuckCamera_Control_old.on()) {
      if (wbcEPuckCamera_Control.on()) {
        myCamera->enable(TIME_STEP_CAM);
        /*** Initialise the static camera information when the camera is turned on. */
        wbcEPuckCamera_Status.set_width(myCamera->getWidth());
        wbcEPuckCamera_Status.set_height(myCamera->getHeight());
        wbcEPuckCamera_Status.set_threshold(0);
        for (CAMERA_CHANNELS channel= CAMERA_CHANNELS::CHANNEL_BLUE;
             channel != CAMERA_CHANNELS::NUMBER_CHANNELS;
             channel = static_cast<CAMERA_CHANNELS>(static_cast<int>(channel) + 1))
        {
            imagePerChannel[channel]= (int *)malloc(sizeof(int)*wbcEPuckCamera_Status.width());
        }
        wbcEPuckCamera_Status.set_on(true);
        printf("%d - Camera Enabled\n",iteration);
        cam_enable_delay = 0;
      } else {
        myCamera->disable();
        for (CAMERA_CHANNELS channel= CAMERA_CHANNELS::CHANNEL_BLUE;
             channel != CAMERA_CHANNELS::NUMBER_CHANNELS;
             channel = static_cast<CAMERA_CHANNELS>(static_cast<int>(channel) + 1))
        {
            free(imagePerChannel[channel]);
            imagePerChannel[channel] = NULL;
        }
        wbcEPuckCamera_Status.set_on(false);
        printf("%d - Camera Disabled\n",iteration);
      }
    }
    if (wbcEPuckCamera_Control.on() && (wbcEPuckCamera_Control.channel() != wbcEPuckCamera_Control_old.channel())) {
     cameraChannel = wbcEPuckCamera_Control.channel();
    }
    /** make current control message the previous for next round. */
    ctrEPuckCamera_Control_old = ctrEPuckCamera_Control;
    wbcEPuckCamera_Control_old = wbcEPuckCamera_Control;
  }

  /** Act on LED settings */
  ctrEPuckLED_Control = getEventCounterForMessageType(guWhiteboard::kEMITTERS_EPuckLED_Control_v);
  if (ctrEPuckLED_Control_old != ctrEPuckLED_Control) {
    running = true;
    wbcEPuckLED_Control = wbhEPuckLED_Control.get();
    for (led_emitters emitter = led0; emitter < NUMBER_LED_EMITTERS; emitter = static_cast<led_emitters>(static_cast<int>(emitter) + 1 )) {
      if (wbcEPuckLED_Control.led(emitter).enabled() != wbcEPuckLED_Control_old.led(emitter).enabled()) {
        if (!wbcEPuckLED_Control.led(emitter).enabled()) {
          led[static_cast<led_emitters>(static_cast<int>(emitter))]->set(0);
          printf("%d - LED (%d) Disabled\n",iteration,static_cast<int>(emitter));
        }
      }
      if (wbcEPuckLED_Control.led(emitter).enabled() && (wbcEPuckLED_Control.led(emitter).value() != wbcEPuckLED_Control_old.led(emitter).value())) {
        led[static_cast<led_emitters>(static_cast<int>(emitter))]->set(wbcEPuckLED_Control.led(emitter).value());
        printf("%d - LED (%d) set to %d\n",iteration,static_cast<int>(emitter), wbcEPuckLED_Control.led(emitter).value());
      }
    }
    /** make current control message the previous for next round. */
    ctrEPuckLED_Control_old = ctrEPuckLED_Control;
    wbcEPuckLED_Control_old = wbcEPuckLED_Control;
  }
}

/** Send Status Messages
 *  Check all actuators/sensors to determine
 *  if they are enabled and send current values.
 *
 *  In some cases, where an actuator is not
 *  able to provide a 'sensor' value, the last
 *  command is returned instead.
 *
 */
void ePuckWhiteboard::sendStatusMessages() {
  /** Encoders before motors */
  if (motorEncoderEnabled) {
    wbcDifferentialRobot_Status.left_motor().set_encoderOn(true);
    wbcDifferentialRobot_Status.right_motor().set_encoderOn(true);
    wheel_encoder_enable_delay[0]++;
    if (wheel_encoder_enable_delay[0] > WHEEL_ENCODER_DELAY) {
//    if (wbcDifferentialRobot_Control.left_motor().encoderOn() == wbcDifferentialRobot_Control_old.left_motor().encoderOn()) {
      wbcDifferentialRobot_Status.left_motor().set_odo(static_cast<int32_t>(getLeftEncoder()));
    }
    wheel_encoder_enable_delay[1]++;
    if (wheel_encoder_enable_delay[1] > WHEEL_ENCODER_DELAY) {
//    if (wbcDifferentialRobot_Control.right_motor().encoderOn() == wbcDifferentialRobot_Control_old.right_motor().encoderOn()) {
      wbcDifferentialRobot_Status.right_motor().set_odo(static_cast<int32_t>(getRightEncoder()));
    }
  } else {
    wbcDifferentialRobot_Status.left_motor().set_encoderOn(false);
    wbcDifferentialRobot_Status.right_motor().set_encoderOn(false);
  }
  /** Now handle motors. */
  if (leftMotorOn) {
    wbcDifferentialRobot_Status.left_motor().set_motorOn(true);
    if (wbcDifferentialRobot_Control.left_motor().motorOn() == wbcDifferentialRobot_Control_old.left_motor().motorOn()) {
      wbcDifferentialRobot_Status.left_motor().set_speed(static_cast<int16_t>(getLeftSpeed()));
    }
  } else {
    wbcDifferentialRobot_Status.left_motor().set_motorOn(false);
    wbcDifferentialRobot_Status.left_motor().set_speed(0);
  }
  if (rightMotorOn) {
    wbcDifferentialRobot_Status.right_motor().set_motorOn(true);
    if (wbcDifferentialRobot_Control.right_motor().motorOn() == wbcDifferentialRobot_Control_old.right_motor().motorOn()) {
      wbcDifferentialRobot_Status.right_motor().set_speed(static_cast<int16_t>(getRightSpeed()));
    }
  } else {
    wbcDifferentialRobot_Status.right_motor().set_motorOn(false);
    wbcDifferentialRobot_Status.right_motor().set_speed(0);
  }
  wbhDifferentialRobot_Status.set(wbcDifferentialRobot_Status);

  /** Now other Sensors. */

  /*** GSM Sensors */
  for (gsm_sensors sensor = gs0; sensor < NUMBER_GSM_SENSORS; sensor = static_cast<gsm_sensors>(static_cast<int>(sensor) + 1 )) {
    if (gs[static_cast<gsm_sensors>(static_cast<int>(sensor))]->getSamplingPeriod() != 0) {
      gs_enable_delay[static_cast<int>(sensor)]++;
      if (gs_enable_delay[static_cast<int>(sensor)] > GSM_SENSOR_DELAY) {
        wbcEPuckGSM_Status.gs(sensor).set_enabled(true);
        wbcEPuckGSM_Status.gs(sensor).set_value(static_cast<int32_t>(gs[static_cast<gsm_sensors>(static_cast<int>(sensor))]->getValue()));
      }
    } else {
      wbcEPuckGSM_Status.gs(sensor).set_enabled(false);
      wbcEPuckGSM_Status.gs(sensor).set_value(0);
    }
  }
  wbhEPuckGSM_Status.set(wbcEPuckGSM_Status);

  /*** Proximity Sensors */
  for (proximity_sensors sensor = ps0; sensor < NUMBER_PROXIMITY_SENSORS; sensor = static_cast<proximity_sensors>(static_cast<int>(sensor) + 1 )) {
    if (ps[static_cast<proximity_sensors>(static_cast<int>(sensor))]->getSamplingPeriod() != 0) {
      ps_enable_delay[static_cast<int>(sensor)]++;
      if (ps_enable_delay[static_cast<int>(sensor)] > PS_SENSOR_DELAY) {
        wbcEPuckProximity_Status.ps(sensor).set_enabled(true);
        wbcEPuckProximity_Status.ps(sensor).set_value(static_cast<int32_t>(ps[static_cast<proximity_sensors>(static_cast<int>(sensor))]->getValue()));
      }
    } else {
      wbcEPuckProximity_Status.ps(sensor).set_enabled(false);
      wbcEPuckProximity_Status.ps(sensor).set_value(0);
    }
  }
  wbhEPuckProximity_Status.set(wbcEPuckProximity_Status);

  /*** Light Sensors */
  for (light_sensors sensor = ls0; sensor < NUMBER_LIGHT_SENSORS; sensor = static_cast<light_sensors>(static_cast<int>(sensor) + 1 )) {
    if (ls[static_cast<light_sensors>(static_cast<int>(sensor))]->getSamplingPeriod() != 0) {
      ls_enable_delay[static_cast<int>(sensor)]++;
      if (ls_enable_delay[static_cast<int>(sensor)] > LS_SENSOR_DELAY) {
        wbcEPuckLight_Status.ls(sensor).set_enabled(true);
        wbcEPuckLight_Status.ls(sensor).set_value(static_cast<int32_t>(ps[static_cast<light_sensors>(static_cast<int>(sensor))]->getValue()));
      }
    } else {
      wbcEPuckLight_Status.ls(sensor).set_enabled(false);
      wbcEPuckLight_Status.ls(sensor).set_value(0);
    }
  }
  wbhEPuckLight_Status.set(wbcEPuckLight_Status);

  /*** Accelerometer Sensor */
  if (accel->getSamplingPeriod() !=0) {
    accel_enable_delay++;
    if (accel_enable_delay > ACCEL_DELAY) {
  //    if (!(&accel->getValues()[0])) {
      if (!isnan(accel->getValues()[0])) {
        wbcEPuckAccel_Status.x().set_enabled(true);
        double xAccel = accel->getValues()[1];
        wbcEPuckAccel_Status.x().set_value(static_cast<int32_t>(accel->getValues()[1]));
      } else {
        wbcEPuckAccel_Status.x().set_enabled(false);
        wbcEPuckAccel_Status.x().set_value(0);
      }
  //    if (!(&accel->getValues()[1])) {
      if (!isnan(accel->getValues()[1])) {
        wbcEPuckAccel_Status.y().set_enabled(true);
        wbcEPuckAccel_Status.y().set_value(static_cast<int32_t>(accel->getValues()[1]));
      } else {
        wbcEPuckAccel_Status.y().set_enabled(false);
        wbcEPuckAccel_Status.y().set_value(0);
      }
  //    if (!(&accel->getValues()[2])) {
      if (!isnan(accel->getValues()[2])) {
        wbcEPuckAccel_Status.z().set_enabled(true);
        wbcEPuckAccel_Status.z().set_value(static_cast<int32_t>(accel->getValues()[2]));
      } else {
        wbcEPuckAccel_Status.z().set_enabled(false);
        wbcEPuckAccel_Status.z().set_value(0);
      }
  }
  }
  wbhEPuckAccel_Status.set(wbcEPuckAccel_Status);

  /** Camera
   *  In this implementation, the client can only:
   *  * Turn the camera on/off
   *  * Select the colour channel to use
   *    (The MiPal implementation performs calculations on all the channels by default.)
   *
   *  Future enhancements can allow the client to:
   *  * Set the width & height of the image they need to process,
   *
   *
   */
  /** Handle On/Off before channel selection */
  if (wbcEPuckCamera_Control.on()) {
    cam_enable_delay++;
    if (cam_enable_delay > CAMERA_DELAY) {
      read_image();
      for (CAMERA_CHANNELS channel = CAMERA_CHANNELS::CHANNEL_BLUE;
           channel != CAMERA_CHANNELS::NUMBER_CHANNELS;
           channel = static_cast<CAMERA_CHANNELS>(static_cast<int>(channel) + 1))
      {
        wbcEPuckCamera_Status.set_totalpixel_count(find_total(imagePerChannel[channel], wbcEPuckCamera_Status.width(), wbcEPuckCamera_Status.threshold()), channel);
        wbcEPuckCamera_Status.set_median(find_middle(imagePerChannel[channel], wbcEPuckCamera_Status.width()), channel);
      }
    }
  }
  wbhEPuckCamera_Status.set(wbcEPuckCamera_Status);

  /** Act on LED settings
   *  Here, we just copy the most recent control
   *  over to the status & post it.
   *
   *  The LED emitter does not have a means of
   *  determining if it's on or off etc.  Therefore
   *  we assume that the last command indicates its
   *  state.
   */
  wbcEPuckLED_Status = wbcEPuckLED_Control;
  wbhEPuckLED_Status.set(wbcEPuckLED_Status);
}

int main(int argc, char **argv)
{
  ePuckWhiteboard* controller = new ePuckWhiteboard();
  controller->run();
  delete controller;
  return 0;
}


