#ifndef SENSORS_EPuckAccel_Status_DEFINED
#define SENSORS_EPuckAccel_Status_DEFINED

#include <cstdlib>
#include <stdlib.h>
#include <cstring>
#include <sstream>
#include <gu_util.h>
#include "gusimplewhiteboard.h"
#include "wb_sensors_epuck_accel_status.h"

namespace guWhiteboard {

  class SENSORS_EPuckAccel_Status: public wb_sensors_epuck_accel_status {

    public:
      SENSORS_EPuckAccel_Status() : wb_sensors_epuck_accel_status() {}
#ifdef WHITEBOARD_POSTER_STRING_CONVERSION
      SENSORS_EPuckAccel_Status(const std::string &name) : wb_sensors_epuck_accel_status(std::string(name)) {}
#endif // WHITEBOARD_POSTER_STRING_CONVERSION

  };
}
#endif // SENSORS_EPuckAccel_Status_DEFINED

