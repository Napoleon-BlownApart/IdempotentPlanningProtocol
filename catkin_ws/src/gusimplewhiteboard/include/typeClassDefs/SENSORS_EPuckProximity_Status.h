#ifndef SENSORS_EPuckProximity_Status_DEFINED
#define SENSORS_EPuckProximity_Status_DEFINED

#include <cstdlib>
#include <stdlib.h>
#include <cstring>
#include <sstream>
#include <gu_util.h>
#include "gusimplewhiteboard.h"
#include "wb_sensors_epuck_proximity_status.h"

namespace guWhiteboard {

  class SENSORS_EPuckProximity_Status: public wb_sensors_epuck_proximity_status {

    public:
      SENSORS_EPuckProximity_Status() : wb_sensors_epuck_proximity_status() {}
#ifdef WHITEBOARD_POSTER_STRING_CONVERSION
      SENSORS_EPuckProximity_Status(const std::string &name) : wb_sensors_epuck_proximity_status(std::string(name)) {}
#endif // WHITEBOARD_POSTER_STRING_CONVERSION

  };
}
#endif // SENSORS_EPuckProximity_Status_DEFINED

