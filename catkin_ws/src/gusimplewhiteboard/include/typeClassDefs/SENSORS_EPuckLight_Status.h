#ifndef SENSORS_EPuckLight_Status_DEFINED
#define SENSORS_EPuckLight_Status_DEFINED

#include <cstdlib>
#include <stdlib.h>
#include <cstring>
#include <sstream>
#include <gu_util.h>
#include "gusimplewhiteboard.h"
#include "wb_sensors_epuck_light_status.h"

namespace guWhiteboard {

  class SENSORS_EPuckLight_Status: public wb_sensors_epuck_light_status {

    public:
      SENSORS_EPuckLight_Status() : wb_sensors_epuck_light_status() {}
#ifdef WHITEBOARD_POSTER_STRING_CONVERSION
      SENSORS_EPuckLight_Status(const std::string &name) : wb_sensors_epuck_light_status(std::string(name)) {}
#endif // WHITEBOARD_POSTER_STRING_CONVERSION

  };
}
#endif // SENSORS_EPuckLight_Status_DEFINED
