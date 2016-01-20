#ifndef SENSORS_EPuckGSM_Control_DEFINED
#define SENSORS_EPuckGSM_Control_DEFINED

#include <cstdlib>
#include <stdlib.h>
#include <cstring>
#include <sstream>
#include <gu_util.h>
#include "gusimplewhiteboard.h"
#include "wb_sensors_epuck_gsm_control.h"

namespace guWhiteboard {

  class SENSORS_EPuckGSM_Control: public wb_sensors_epuck_gsm_control {

    public:
      SENSORS_EPuckGSM_Control() : wb_sensors_epuck_gsm_control() {}
#ifdef WHITEBOARD_POSTER_STRING_CONVERSION
      SENSORS_EPuckGSM_Control(const std::string &name) : wb_sensors_epuck_gsm_control(std::string(name)) {}
#endif // WHITEBOARD_POSTER_STRING_CONVERSION

  };
}
#endif // SENSORSEPUCKGSMCONTROL

