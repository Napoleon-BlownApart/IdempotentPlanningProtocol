// File:          epuckMeanderLinesByGSM_Behaviour.cpp
// Date:          2015-03-23
// Description:   E-Puck Follows Line Controller using GSM & PS
// Author:
// Modifications:

// You may need to add webots include files such as
// <webots/DistanceSensor.hpp>, <webots/LED.hpp>, etc.
// and/or to add some other includes
#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <unistd.h>
#include <math.h>
#include <chrono>
//#include <time.h>
//#include <sys/time.h>
//#include <dispatch/dispatch.h>
#include <webots/Robot.hpp>
#include <webots/DifferentialWheels.hpp>
#include "epuckMeanderLinesByGSM_Behaviour.h"


using namespace webots;

// Here is the main class of your controller.
// This class defines how to initialize and how to run your controller.
// Note that this class derives Robot and so inherits all its functions
//class epuck_go_forwards : public Robot /**DifferentialWheels*/ {

// epuckMeanderLinesByGSM_Behaviour constructor
epuckMeanderLinesByGSM_Behaviour::epuckMeanderLinesByGSM_Behaviour() : DifferentialWheels()  {

  /***
  *  We make use of the following E-Puck Modules:
  *  * Ground Sensor Module   (optional extra for the E-Puck)
  *  * Camera
  *  * DifferentialWheels
  *  * Encoders
  *
  *  * Get an instance of the modules that aren't automatically provided:
  */
  gs[LEFT_GS] = getDistanceSensor("gs0");
  gs[CENTER_GS] = getDistanceSensor("gs1");
  gs[RIGHT_GS] = getDistanceSensor("gs2");
  ps[LEFT_PS] = getDistanceSensor("ps7");
  ps[RIGHT_PS] = getDistanceSensor("ps0");


  /** LightSensors
   *  Useless for use as a proximity device.
   *  Measures ambient light and the associated Webots World gives confusing results.
   *
   *  See the run()
   *    lead in for their enablement
   *    main loop for a print message of their values
   */
/*
  ls[0] = getLightSensor("ls0");
  ls[1] = getLightSensor("ls1");
  ls[2] = getLightSensor("ls2");
  ls[3] = getLightSensor("ls3");
  ls[4] = getLightSensor("ls4");
  ls[5] = getLightSensor("ls5");
  ls[6] = getLightSensor("ls6");
  ls[7] = getLightSensor("ls7");
*/

  /** Binary intensity single colour LEDs around the body.
   *  By default they are single color
   *  Green for the lower body
   *  Red all others.
   *
   *  Webots allows other kinds of LED (Mapped Color, RGB and Analogue Intensity)
   *  but the e-Puck does not use these.
   *
   *
   *  See the run()
   *    lead in for code that sets their state
   */
/*
  led[0] = getLED("led0");  // The whole ring is lite up.
  led[1] = getLED("led1");  // 45 degrees
  led[2] = getLED("led2");  // 90 degrees
  led[3] = getLED("led3");  // 135 degrees
  led[4] = getLED("led4");  // Tail Lights (175 & 185 degrees)
  led[5] = getLED("led5");  // 225 degrees
  led[6] = getLED("led6");  // 270 degrees
  led[7] = getLED("led7");  // 315 degrees
  led[8] = getLED("led8");  // Green Body Light
  led[9] = getLED("led9");  // Light next to camera
*/


  printf("\f\n"); // Clear console

  //Once general behaviour is proven, use a robust random seeding technique
//  srand(static_cast<int>(std::chrono::system_clock::to_time_t(std::chrono::system_clock::now())));

  // But during initial testing, random is seeded with a fixed integer.
  srand(1);
}

// epuckMeanderLinesByGSM_Behaviour destructor
epuckMeanderLinesByGSM_Behaviour::~epuckMeanderLinesByGSM_Behaviour() {
      // Enter here exit cleanup code
}

    // User defined function for initializing and running
    // the epuck_go_forwards class
void epuckMeanderLinesByGSM_Behaviour::run() {

  running = true;

  printf("Max Speed = %6.6f\n",getMaxSpeed());
  printf("Speed Unit = %6.6f\n",getSpeedUnit());


  /*** Setup sample rates for the E-Puck Modules we are using
  */
  gs[LEFT_GS]->enable(TIME_STEP);
  gs[CENTER_GS]->enable(TIME_STEP);
  gs[RIGHT_GS]->enable(TIME_STEP);
  ps[LEFT_PS]->enable(TIME_STEP);
  ps[RIGHT_PS]->enable(TIME_STEP);
  enableEncoders(TIME_STEP);

/*  // Enable the LightSensors with the chosen sample period
  ls[0]->enable(TIME_STEP);
  ls[1]->enable(TIME_STEP);
  ls[2]->enable(TIME_STEP);
  ls[3]->enable(TIME_STEP);
  ls[4]->enable(TIME_STEP);
  ls[5]->enable(TIME_STEP);
  ls[6]->enable(TIME_STEP);
  ls[7]->enable(TIME_STEP);
*/

/*
  // 0 = OFF / 1 = ON
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
*/


  enum SearchStates state = FORWARD;
  enum Direction possibleDirections = UNDECIDED;
  enum Direction whichWay = UNDECIDED;

  int gsLeftPathTrigger = 0, gsCenterPathTrigger = 0, gsRightPathTrigger = 0;
  int gsLeftIntersectionTrigger = 0, gsCenterIntersectionTrigger = 0, gsRightIntersectionTrigger = 0;


  /*** Get the E-Puck going.
  */
  setEncoders(0.0,0.0);
  setSpeed(MAX_SPEED,MAX_SPEED);

  printf("I am at Position (col,row) (%d,%d)\n", curPosition.x,curPosition.y);


  // Main loop:
  // Perform simulation steps of 64 milliseconds
  // and leave the loop when the simulation is over
  while (step(TIME_STEP) != -1) {

    //   This is a test of the LightSensor device
    // printf("Lightsensors: %f,%f,%f,%f,%f,%f,%f,%f\n",ls[0]->getValue(),ls[1]->getValue(),ls[2]->getValue(),ls[3]->getValue(),ls[4]->getValue(),ls[5]->getValue(),ls[6]->getValue(),ls[7]->getValue() );

    /**  Take a snapshot of pertinent E-PUCK STATE variables for this iteration
    */
    double leftPS = ps[LEFT_PS]->getValue();
    double rightPS = ps[RIGHT_PS]->getValue();
    double leftGS = gs[LEFT_GS]->getValue();
    double centerGS = gs[CENTER_GS]->getValue();
    double rightGS = gs[RIGHT_GS]->getValue();

    // main loop based on states
    switch (state) {

      case FORWARD:
      {
        if (leftPS > RANGE_THRESHOLD) {
          printf("Detected Obstacle with Left Sensor\n");
          whichWay = RIGHT;
          encStateB4Maneuver = getEncoders();
//          printf("Lenc %3.3f | Renc %3.3f\n",encStateB4Maneuver.encoder[0],encStateB4Maneuver.encoder[1]);
          curPosition.angle = (curPosition.angle + 180) % 360;
          returning = true;
          state = TURN;
          break;
        }
        if (rightPS > RANGE_THRESHOLD) {
          printf("Detected Obstacle with Right Sensor\n");
          whichWay = LEFT;
          encStateB4Maneuver = getEncoders();
//          printf("Lenc %3.3f | Renc %3.3f\n",encStateB4Maneuver.encoder[0],encStateB4Maneuver.encoder[1]);
          curPosition.angle = (curPosition.angle + 180) % 360;  // Adding 180 is the same as subtracting 180 but the modulus function handles additions easier, so we add.
          returning = true;
          state = TURN;
          break;
        }

        if (leftGS > PATH_THRESHOLD) {
          gsLeftPathTrigger++;
        } else {
          gsLeftPathTrigger = 0;
        }

        if (centerGS < INTERSECTION_THRESHOLD) {
          gsCenterIntersectionTrigger++;
        } else {
          gsCenterIntersectionTrigger = 0;
        }
        if (rightGS > PATH_THRESHOLD) {
          gsRightPathTrigger++;
        } else {
          gsRightPathTrigger = 0;
        }

        if (gsCenterIntersectionTrigger >= SENSOR_TRIGGER_SIZE) {
          possibleDirections = UNDECIDED;
          state = INTERSECTION;
          encStateB4Maneuver = getEncoders();
          gsLeftPathTrigger = 0;
          gsRightPathTrigger = 0;
          gsLeftIntersectionTrigger = 0;
          gsRightIntersectionTrigger = 0;
          if (!returning) updatePosition();
          returning = false;
          printf("I am at Position (col,row) (%d,%d)\n", curPosition.x,curPosition.y);
        } else {
          if (gsLeftPathTrigger >= SENSOR_TRIGGER_SIZE) {
            double diff = (leftGS - rightGS);
//                printf("Too Far Right  |  Diff: %3.3f\n",diff);
            setSpeed(MAX_SPEED-(ALIGN_GAIN*diff),MAX_SPEED+(ALIGN_GAIN*diff));
            gsLeftPathTrigger = 0;
          }
          if (gsRightPathTrigger >= SENSOR_TRIGGER_SIZE) {
            double diff = (rightGS - leftGS);
//                printf("Too Far Left  |  Diff: %3.3f\n",diff);
            setSpeed(MAX_SPEED+(ALIGN_GAIN*diff),MAX_SPEED-(ALIGN_GAIN*diff));
            gsRightPathTrigger = 0;
          }
        }
        break;
      }
      case INTERSECTION:
      {
//            printf("Checking what possible directions are available.\n");

        if (leftPS > RANGE_THRESHOLD) { // UNTESTED as normally there are not obstructions at intersections.
//          setSpeed(TURN_FACTOR*MAX_SPEED,-TURN_FACTOR*MAX_SPEED); // Could possibily improve performance if this were included.
          whichWay = RIGHT;
          encStateB4Maneuver = getEncoders();
          if ((curPosition.x = GRID_WIDTH && curPosition.angle == 0) ||
              (curPosition.y = GRID_HEIGHT && curPosition.angle == 90) ||
              (curPosition.x = 1 && curPosition.angle == 180) ||
              (curPosition.y = 1 && curPosition.angle == 270)) {
            curPosition.angle = (curPosition.angle + 180) % 360; // Since we are at an intersection that is on the edge of the map
                                                                 // with no path to the right, the turning behaviour will cause a 180 degree turn.
          } else {
            curPosition.angle = (curPosition.angle + 90) % 360; // Since we are at an intersection, the turning behaviour will encounter the path
                                                                // to the right, which will be 90 degrees
          }
//          returning = true;   // Should there be an obstruction (eg another agent), then we are not actually returning,
                                // since we never departed the intersection.
          state = TURN;
          break;
        }
        if (rightPS > RANGE_THRESHOLD) {  // UNTESTED as normally there are not obstructions at intersections.
//          setSpeed(-TURN_FACTOR*MAX_SPEED,TURN_FACTOR*MAX_SPEED); // Could possibily improve performance if this were included.
          whichWay = LEFT;
          encStateB4Maneuver = getEncoders();
          if ((curPosition.x = GRID_WIDTH && curPosition.angle == 180) ||
              (curPosition.y = GRID_HEIGHT && curPosition.angle == 270) ||
              (curPosition.x = 1 && curPosition.angle == 0) ||
              (curPosition.y = 1 && curPosition.angle == 90)) {
            curPosition.angle = (curPosition.angle + 180) % 360; // Since we are at an intersection that is on the edge of the map
                                                                 // with no path to the right, the turning behaviour will cause a 180 degree turn.
                                                                 // Adding 180 is the same as subtracting 180 but the modulus function handles additions easier, so we add.
          } else {
              curPosition.angle = (curPosition.angle != 0) ? curPosition.angle-90 : 270;  // Since we are at an intersection, the turning behaviour will encounter the path
                                                                                          // to the right, which will be 90 degrees
          }
//          returning = true;   // Should there be an obstruction (eg another agent), then we are not actually returning,
                                // since we never departed the intersection, and therefore the reactive behaviour will not re-encounter this intersection
          state = TURN;
          break;
        }

        if (leftGS > PATH_THRESHOLD) {
          gsLeftPathTrigger++;
          gsLeftIntersectionTrigger = 0;
        } else if (leftGS < INTERSECTION_THRESHOLD) {
          gsLeftIntersectionTrigger++;
          gsLeftPathTrigger = 0;
        } else {
          gsLeftPathTrigger = 0;
          gsLeftIntersectionTrigger = 0;
        }

        if (centerGS > PATH_THRESHOLD) {
          gsCenterPathTrigger++;
          gsCenterIntersectionTrigger = 0;
        } else if (centerGS < INTERSECTION_THRESHOLD) {
          gsCenterPathTrigger = 0;
          gsCenterIntersectionTrigger++;
        } else {
          gsCenterPathTrigger = 0;
          gsCenterIntersectionTrigger = 0;
        }

        if (rightGS > PATH_THRESHOLD) {
          gsRightPathTrigger++;
          gsRightIntersectionTrigger = 0;
        } else if (rightGS < INTERSECTION_THRESHOLD) {
          gsRightIntersectionTrigger++;
          gsRightPathTrigger = 0;
        } else {
          gsRightPathTrigger = 0;
          gsRightIntersectionTrigger = 0;
        }

        if (gsCenterIntersectionTrigger >= SENSOR_TRIGGER_SIZE) {  // Ground Sensor Module is in the intersection
//            printf("Done analysing environment, adjusting trajectory.\n");
          if (gsLeftIntersectionTrigger >= SENSOR_TRIGGER_SIZE) {
            double diff = (rightGS - leftGS);
//                printf("Too Far Right  |  Diff: %3.3f\n",diff);
            setSpeed((TURN_FACTOR*MAX_SPEED)-(ALIGN_GAIN*0.5*diff),(TURN_FACTOR*MAX_SPEED)+(ALIGN_GAIN*0.5*diff));
//                gsLeftIntersectionTrigger = 0;
          }
          if (gsRightIntersectionTrigger >= SENSOR_TRIGGER_SIZE) {
            double diff = (leftGS - rightGS);
//                printf("Too Far Left  |  Diff: %3.3f\n",diff);
            setSpeed((TURN_FACTOR*MAX_SPEED)+(ALIGN_GAIN*0.5*diff),(TURN_FACTOR*MAX_SPEED)-(ALIGN_GAIN*0.5*diff));
//                gsRightIntersectionTrigger = 0;
          }
        } else {  // Ground Sensor Module is beyond the intersection
          if (gsLeftPathTrigger >= SENSOR_TRIGGER_SIZE) {
            double diff = (leftGS - rightGS);
//                printf("Too Far Right  |  Diff: %3.3f\n",diff);
            setSpeed((TURN_FACTOR*MAX_SPEED)-(ALIGN_GAIN*diff),(TURN_FACTOR*MAX_SPEED)+(ALIGN_GAIN*diff));
            gsLeftPathTrigger = 0;
          }
          if (gsRightPathTrigger >= SENSOR_TRIGGER_SIZE) {
            double diff = (rightGS - leftGS);
//                printf("Too Far Left  |  Diff: %3.3f\n",diff);
            setSpeed((TURN_FACTOR*MAX_SPEED)+(ALIGN_GAIN*diff),(TURN_FACTOR*MAX_SPEED)-(ALIGN_GAIN*diff));
            gsRightPathTrigger = 0;
            }
        }
//            printf("Done correcting trajectory.\n");

//            printf("LT (p)=%d/(i)=%d | RT (p)=%d/(i)=%d | CT (p)=%d/(i)=%d\n",gsLeftPathTrigger, gsLeftIntersectionTrigger, gsRightPathTrigger, gsRightIntersectionTrigger, gsCenterPathTrigger, gsCenterIntersectionTrigger );
        if ( !(possibleDirections & LEFT) && (gsLeftPathTrigger >= SENSOR_TRIGGER_SIZE) && (gsCenterIntersectionTrigger >= SENSOR_TRIGGER_SIZE)) {
          possibleDirections = static_cast<Direction>(possibleDirections | LEFT);
//              printf("CAN turn LEFT\n");
        }
        if ( !(possibleDirections & STRAIGHT) && (gsCenterPathTrigger >= SENSOR_TRIGGER_SIZE) && ((gsLeftPathTrigger == 0) || (gsRightPathTrigger == 0))) {
          possibleDirections =  static_cast<Direction>(possibleDirections | STRAIGHT);
//              printf("CAN go STRAIGHT\n");
        }
        if ( !(possibleDirections & RIGHT) && (gsRightPathTrigger >= SENSOR_TRIGGER_SIZE) && (gsCenterIntersectionTrigger >= SENSOR_TRIGGER_SIZE)) {
          possibleDirections =  static_cast<Direction>(possibleDirections | RIGHT);
//              printf("CAN turn RIGHT\n");
        }
//            printf("Done possible paths.\n");


        if (getRightEncoder()>encStateB4Maneuver.encoder[RIGHT_ENC] + INTERSECTION_ALIGN || getLeftEncoder()> encStateB4Maneuver.encoder[LEFT_ENC] + INTERSECTION_ALIGN) {    // The E-Puck's axle is approximately in the center of the intersection
          printf("Choose Direction (%d) ", possibleDirections);
          if (possibleDirections == 0) {
            printf("!!**!! Alignnemt Error Occurred\n");
            state = STOP;
          } else {
            state = TURN;
            whichWay = chooseDirection(possibleDirections);
            if (whichWay == LEFT) {
              curPosition.angle = (curPosition.angle != 0) ? curPosition.angle-90 : 270;
              printf("**Will turn LEFT\n");
            }
            if (whichWay == RIGHT) {
              curPosition.angle = (curPosition.angle+90)%360;
              printf("**Will turn RIGHT\n");
            }
            if (whichWay == STRAIGHT) printf("**Will go STRAIGHT \n");

            gsLeftPathTrigger = 0;
            gsCenterPathTrigger = 0;
            gsRightPathTrigger = 0;

            gsLeftIntersectionTrigger = 0;
            gsCenterIntersectionTrigger = 0;
            gsRightIntersectionTrigger = 0;

  //              printf("Resetting Encoders.\n");
            encStateB4Maneuver = getEncoders();
          }
//              printf("Going into TURN.\n");
        }
        break;
      }
      case TURN:
      {

//        double leftEncTarget = MIN_TURN, rightEncTarget = MIN_TURN;

//        if (whichWay != UNDECIDED) {
          switch (whichWay) {
            case STRAIGHT:
            {
              whichWay = UNDECIDED;
              state = FORWARD;
//                  printf("Continuing FORWARD\n");
              break;
            }
            case RIGHT:
            {
//              leftEncTarget = encStateB4Maneuver.encoder[LEFT_ENC] + MIN_TURN;
//              rightEncTarget = encStateB4Maneuver.encoder[RIGHT_ENC] - MIN_TURN;
//                  printf("Commencing Right Turn\n");
              setSpeed(TURN_FACTOR*MAX_SPEED,-TURN_FACTOR*MAX_SPEED);
              break;
            }
            case LEFT:
            {
//              leftEncTarget = encStateB4Maneuver.encoder[LEFT_ENC] - MIN_TURN;
//              rightEncTarget = encStateB4Maneuver.encoder[RIGHT_ENC] + MIN_TURN;
//            printf("TURN TO LEFT L: %3.0f | R: %3.0f\n",encStateB4Maneuver.encoder[LEFT_ENC],encStateB4Maneuver.encoder[RIGHT_ENC]);
//            printf("TARGET L: %3.3f | R: %3.3f\n",leftEncTarget,rightEncTarget);
//                  printf("Commencing Left Turn\n");
              setSpeed(-TURN_FACTOR*MAX_SPEED,TURN_FACTOR*MAX_SPEED);
              break;
            }
            default:
            {
              printf("An invalid direction was selected:  %d\n",whichWay);
              exit(1);
            }
//          }
//          whichWay = UNDECIDED;
        }
//        double leftEnc = getLeftEncoder();
//        double rightEnc = getRightEncoder();
//            printf("L: %3.0f | R: %3.0f\n",getLeftEncoder(),getRightEncoder());
//        printf("Lenc: %3.3f | R: %3.3f\n",leftEnc,rightEnc);
        if (whichWay == LEFT) {
          if (encStateB4Maneuver.encoder[LEFT_ENC] - getLeftEncoder() > MIN_TURN) {
            state = ALIGN;
          }
        } else if (whichWay == RIGHT) {
          if (encStateB4Maneuver.encoder[RIGHT_ENC] - getRightEncoder() > MIN_TURN) {
            state = ALIGN;
          }

        }


//        if ( leftEnc > leftEncTarget) { // One of the outer Ground Sensor Module sensors should be over a path @ 260
//          state = ALIGN;
////            state = STOP;
////              printf("going to ALIGN\n");
//        }
        break;

      }
      case ALIGN:
      {
        if (whichWay == UNDECIDED) {

          if (leftGS > PATH_THRESHOLD) {
            gsLeftPathTrigger++;
          } else {
            gsLeftPathTrigger = 0;
          }

          if (rightGS > PATH_THRESHOLD) {
            gsRightPathTrigger++;
          } else {
            gsRightPathTrigger = 0;
          }

          if (gsLeftPathTrigger >= SENSOR_TRIGGER_SIZE) { // E-Puck was turning left
            whichWay = LEFT;
//                printf("I have been Turning Left\n");
             gsLeftPathTrigger = 0;
             gsRightPathTrigger = 0;
          }
          if (gsRightPathTrigger >= SENSOR_TRIGGER_SIZE) { // E-Puck was turning right
            whichWay = RIGHT;
//                printf("I have been Turning Right\n");
             gsLeftPathTrigger = 0;
             gsRightPathTrigger = 0;
          }

        }
        switch (whichWay) {
          case RIGHT:
          {
//                printf("L:%3.3f  C:%3.3f  R:%3.3f",gs[0]->getValue(),gs[1]->getValue(),gs[2]->getValue());
            if (leftGS > PATH_THRESHOLD) {
              gsLeftPathTrigger++;
            } else {
              gsLeftPathTrigger = 0;
            }
            if (gsLeftPathTrigger >= SENSOR_TRIGGER_SIZE) {
//                  printf("Completed turn going to FORWARD\n");
              state = FORWARD;
              whichWay = UNDECIDED;
            }
            break;
          }
          case LEFT:
          {
            if (rightGS > PATH_THRESHOLD) {
              gsRightPathTrigger++;
            } else {
              gsRightPathTrigger = 0;
            }
           if (gsRightPathTrigger >= SENSOR_TRIGGER_SIZE) { // E-Puck was turning right
//                  printf("Completed turn going to FORWARD\n");
              state = FORWARD;
              whichWay = UNDECIDED;
            }
            break;
          }
          default:
            break;
        }
        if (state == FORWARD) {
          printf("I am now heading %d degrees\n", curPosition.angle);
        }
        break;

      }
      case STOP:
      {
        setSpeed(0,0);
        break;
      }
      default:
      {
        printf("An invalid state has been reached:  %d\n",state);
        exit(1);
      }
    }
  }
}

epuckMeanderLinesByGSM_Behaviour::rotationalEncoders epuckMeanderLinesByGSM_Behaviour::getEncoders() {
  rotationalEncoders currState;
  currState.encoder[0] = getLeftEncoder();
  currState.encoder[1] = getRightEncoder();
  return currState;
}

epuckMeanderLinesByGSM_Behaviour::Direction epuckMeanderLinesByGSM_Behaviour::chooseDirection (Direction possibleDirections) {
  int numChoices = 0;
  if (possibleDirections & STRAIGHT) numChoices++;
  if (possibleDirections & RIGHT) numChoices++;
  if (possibleDirections & LEFT) numChoices++;

  // Only one possible way to go, so return immediately.
  if (numChoices == 1) return possibleDirections;
  // Otherwise pick a direction
  int choice = (rand() % numChoices)+1;
  if ((possibleDirections & STRAIGHT) && (choice-- == 1)) {
    return STRAIGHT;
  }
  if ((possibleDirections & RIGHT) && (choice-- == 1)) {
    return RIGHT;
  }
  return LEFT;
}

void epuckMeanderLinesByGSM_Behaviour::setInitialPosition(int x, int y, int angle) {
  if (!running) {
    curPosition.x = x;
    curPosition.y = y;
    curPosition.angle = angle;
  }
}

void epuckMeanderLinesByGSM_Behaviour::updatePosition() {

  switch(curPosition.angle) {
    case 0:
      curPosition.y--;
      break;
    case 90:
      curPosition.x++;
      break;
    case 180:
      curPosition.y++;
      break;
    case 270:
      curPosition.x--;
      break;
  }



}
