#ifndef SENSORS_EPuckCamera_ControlStatus_DEFINED
#define SENSORS_EPuckCamera_ControlStatus_DEFINED

#include <cstdlib>
#include <stdlib.h>
#include <cstring>
#include <sstream>
#include <gu_util.h>
#include "gusimplewhiteboard.h"
#include "wb_sensors_epuck_camera.h"

namespace guWhiteboard {

  class SENSORS_EPuckCamera_ControlStatus: public wb_sensors_epuck_camera {

    public:
      SENSORS_EPuckCamera_ControlStatus() : wb_sensors_epuck_camera() {}
#ifdef WHITEBOARD_POSTER_STRING_CONVERSION
      SENSORS_EPuckCamera_ControlStatus(const std::string &name) : wb_sensors_epuck_camera(std::string(name)) {}
#endif // WHITEBOARD_POSTER_STRING_CONVERSION

  };
}
#endif // SENSORS_EPuckCamera_ControlStatus_DEFINED

