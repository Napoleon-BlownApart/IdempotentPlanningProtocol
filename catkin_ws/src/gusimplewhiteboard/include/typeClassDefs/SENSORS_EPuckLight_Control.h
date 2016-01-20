#ifndef SENSORS_EPuckLight_Control_DEFINED
#define SENSORS_EPuckLight_Control_DEFINED

#include <cstdlib>
#include <stdlib.h>
#include <cstring>
#include <sstream>
#include <gu_util.h>
#include "gusimplewhiteboard.h"
#include "wb_sensors_epuck_light_control.h"

namespace guWhiteboard {

  class SENSORS_EPuckLight_Control: public wb_sensors_epuck_light_control {

    public:
      SENSORS_EPuckLight_Control() : wb_sensors_epuck_light_control() {}
#ifdef WHITEBOARD_POSTER_STRING_CONVERSION
      SENSORS_EPuckLight_Control(const std::string &name) : wb_sensors_epuck_light_control(std::string(name)) {}
#endif // WHITEBOARD_POSTER_STRING_CONVERSION

  };
}
#endif // SENSORS_EPuckLight_Control_DEFINED
