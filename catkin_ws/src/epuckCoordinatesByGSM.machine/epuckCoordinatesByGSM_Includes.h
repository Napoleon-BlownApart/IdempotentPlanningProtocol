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
#define INTERSECTION_THRESHOLD 380

// Size of the grid the e-Puck is navigating on.
#define GRID_WIDTH 6
#define GRID_HEIGHT 6

struct position {
  int x;      // 1 is on the left of the map
  int y;      // 1 is at the top of the map
  int angle;  // 0, 90, 180, 270 (0 is up/north)
};
