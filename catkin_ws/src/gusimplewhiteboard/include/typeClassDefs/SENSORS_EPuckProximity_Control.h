#ifndef SENSORS_EPuckProximity_Control_DEFINED
#define SENSORS_EPuckProximity_Control_DEFINED

#include <cstdlib>
#include <stdlib.h>
#include <cstring>
#include <sstream>
#include <gu_util.h>
#include "gusimplewhiteboard.h"
#include "wb_sensors_epuck_proximity_control.h"

namespace guWhiteboard {

  class SENSORS_EPuckProximity_Control: public wb_sensors_epuck_proximity_control {

    public:
      SENSORS_EPuckProximity_Control() : wb_sensors_epuck_proximity_control() {}
#ifdef WHITEBOARD_POSTER_STRING_CONVERSION
      SENSORS_EPuckProximity_Control(const std::string &name) : wb_sensors_epuck_proximity_control(std::string(name)) {}
#endif // WHITEBOARD_POSTER_STRING_CONVERSION

  };
}
#endif // SENSORS_EPuckProximity_Control_DEFINED

