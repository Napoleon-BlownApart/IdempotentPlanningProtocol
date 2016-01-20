#ifndef SENSORS_Intersection_Status_DEFINED
#define SENSORS_Intersection_Status_DEFINED

#include <cstdlib>
#include <stdlib.h>
#include <cstring>
#include <sstream>
#include <gu_util.h>
#include "gusimplewhiteboard.h"
#include "wb_sensors_intersection_status.h"

namespace guWhiteboard {

  class SENSORS_Intersection_Status: public wb_sensors_intersection_status {

    public:
      SENSORS_Intersection_Status() : wb_sensors_intersection_status() {}
#ifdef WHITEBOARD_POSTER_STRING_CONVERSION
      SENSORS_Intersection_Status(const std::string &name) : wb_sensors_intersection_status(std::string(name)) {}
#endif // WHITEBOARD_POSTER_STRING_CONVERSION

  };
}


#endif // SENSORS_Intersection_Status_DEFINED
