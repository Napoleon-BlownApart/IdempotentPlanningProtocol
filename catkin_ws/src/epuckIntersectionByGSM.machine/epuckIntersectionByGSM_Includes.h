#include <stdio.h>
#include <cstdlib>
// CLFSM
#include "CLMacros.h"

//GUSIMPLEWHITEBOARD
#include "guwhiteboardtypelist_generated.h" // Whiteboard Class handlers

//WHITEBOARD CLASSES
#include "typeClassDefs/EPuck_Messages.h"

using namespace guWhiteboard;
//#define DEBUG

// Number of consecutive sensor readings required to make a decision.
#define SENSOR_TRIGGER_SIZE 4

// Infrared Sensor return value thresholds used for navigation.
#define PATH_THRESHOLD 690
#define INTERSECTION_THRESHOLD 380

// Because the line/intersection markings are not anti-aliased, the transition between
// 'On the marking' and 'Off the marking' is stark and produces large deltas during calculations.
// Therefore use a very small feedback gain, otherwise the robot goes out of control.
#define ALIGN_GAIN 0.04

// Infrared Sensors (PS7 & PS0) return value for range approx =  15mm.
#define RANGE_THRESHOLD 500

// Minimum turn distance (using the Wheel Encoders as the Unit of Measure) to clear the path.
// The TURN behaviour only requires that the GMS sensors move to the right/left of the path
// Once they clear the path, the ALIGN behaviour takes care of their return to the path on
// completion of the turn.
#define MIN_TURN 310
#define INTERSECTION_ALIGN 260

// Speed of the E-Puck
#define MAX_SPEED 300.0
// Speed reduction factor when aligning at intersections and turning
#define TURN_FACTOR 0.333

// Size of the grid the e-Puck is navigating on.
#define GRID_WIDTH 6
#define GRID_HEIGHT 6

/***
 * Defines the possible directions that the robot can
 * choose from when navigating an intersection
 */
//enum Direction {
//  UNDECIDED     = 0x00,
//  STRAIGHT      = 0x01,
//  RIGHT         = 0x02,
//  LEFT          = 0x04,
//  AROUND        = 0x08
//};


struct position {
  int x;      // 1 is on the left of the map
  int y;      // 1 is at the top of the map
  int angle;  // 0, 90, 180, 270 (0 is up/north)
};

struct rotationalEncoders {
  int32_t encoder[2];
};
