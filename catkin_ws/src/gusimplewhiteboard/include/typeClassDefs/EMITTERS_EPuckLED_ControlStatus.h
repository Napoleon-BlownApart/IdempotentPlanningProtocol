#ifndef EMITTERS_EPuckLED_ControlStatus_DEFINED
#define EMITTERS_EPuckLED_ControlStatus_DEFINED

#include <cstdlib>
#include <stdlib.h>
#include <cstring>
#include <sstream>
#include <gu_util.h>
#include "gusimplewhiteboard.h"
#include "wb_emitters_epuck_led.h"

namespace guWhiteboard {

  class EMITTERS_EPuckLED_ControlStatus: public wb_emitters_epuck_led {

    public:
      EMITTERS_EPuckLED_ControlStatus() : wb_emitters_epuck_led() {}
#ifdef WHITEBOARD_POSTER_STRING_CONVERSION
      EMITTERS_EPuckLED_ControlStatus(const std::string &name) : wb_emitters_epuck_led(std::string(name)) {}
#endif // WHITEBOARD_POSTER_STRING_CONVERSION

  };
}
#endif // EMITTERS_EPuckLED_ControlStatus_DEFINED
