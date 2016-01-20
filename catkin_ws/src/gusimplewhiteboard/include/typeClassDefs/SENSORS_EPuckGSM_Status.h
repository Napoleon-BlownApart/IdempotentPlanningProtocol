#ifndef SENSORS_EPuckGSM_Status_DEFINED
#define SENSORS_EPuckGSM_Status_DEFINED

#include <cstdlib>
#include <stdlib.h>
#include <cstring>
#include <sstream>
#include <gu_util.h>
#include "gusimplewhiteboard.h"
#include "wb_sensors_epuck_gsm_status.h"

namespace guWhiteboard {

  class SENSORS_EPuckGSM_Status: public wb_sensors_epuck_gsm_status {

    public:
      SENSORS_EPuckGSM_Status() : wb_sensors_epuck_gsm_status() {}
#ifdef WHITEBOARD_POSTER_STRING_CONVERSION
      SENSORS_EPuckGSM_Status(const std::string &name) : wb_sensors_epuck_gsm_status(std::string(name)) {}
#endif // WHITEBOARD_POSTER_STRING_CONVERSION

  };
}
#endif // SENSORS_EPuckGSM_Status_DEFINED

