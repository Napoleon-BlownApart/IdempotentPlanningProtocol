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
#define SENSOR_TRIGGER_SIZE 3

// Infrared Sensor return value thresholds used for navigation.
#define PATH_THRESHOLD 680

// Because the line/intersection markings are not anti-aliased, the transition between
// 'On the marking' and 'Off the marking' is stark and produces large deltas during calculations.
// Therefore use a very small feedback gain, otherwise the robot goes out of control.
#define ALIGN_GAIN 0.04

// Speed of the E-Puck
#define MAX_SPEED 300.0
