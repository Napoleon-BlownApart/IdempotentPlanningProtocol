#ifndef Plan_Control_Status_DEFINED
#define Plan_Control_Status_DEFINED

#include <cstdlib>
#include <stdlib.h>
#include <cstring>
#include <sstream>
#include <gu_util.h>
#include "gusimplewhiteboard.h"
#include "wb_plan_control_status.h"

namespace guWhiteboard {

  class Plan_Control_Status : public wb_plan_control_status {

    public:
      Plan_Control_Status() : wb_plan_control_status() {}
#ifdef WHITEBOARD_POSTER_STRING_CONVERSION
      Plan_Control_Status(const std::string &name) : wb_plan_control_status(std::string(name)) {}
#endif // WHITEBOARD_POSTER_STRING_CONVERSION

  };
}
#endif // Plan_Status_DEFINED

