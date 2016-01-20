#ifndef SENSORS_EPuckAccel_Control_DEFINED
#define SENSORS_EPuckAccel_Control_DEFINED

#include <cstdlib>
#include <stdlib.h>
#include <cstring>
#include <sstream>
#include <gu_util.h>
#include "gusimplewhiteboard.h"
#include "wb_sensors_epuck_accel_control.h"

namespace guWhiteboard {

  class SENSORS_EPuckAccel_Control: public wb_sensors_epuck_accel_control {

    public:
      SENSORS_EPuckAccel_Control() : wb_sensors_epuck_accel_control() {}
#ifdef WHITEBOARD_POSTER_STRING_CONVERSION
      SENSORS_EPuckAccel_Control(const std::string &name) : wb_sensors_epuck_accel_control(std::string(name)) {}
#endif // WHITEBOARD_POSTER_STRING_CONVERSION

  };
}
#endif // SENSORS_EPuckAccel_Control_DEFINED

