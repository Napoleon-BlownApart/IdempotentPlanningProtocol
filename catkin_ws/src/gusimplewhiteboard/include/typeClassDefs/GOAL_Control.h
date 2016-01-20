#ifndef GOAL_Control_DEFINED
#define GOAL_Control_DEFINED

#include <cstdlib>
#include <stdlib.h>
#include <cstring>
#include <sstream>
#include <gu_util.h>
#include "gusimplewhiteboard.h"
#include "wb_goal_control.h"

namespace guWhiteboard {

  class GOAL_Control: public wb_goal_control {

    public:
      GOAL_Control() : wb_goal_control() {}
#ifdef WHITEBOARD_POSTER_STRING_CONVERSION
      GOAL_Control(const std::string &name) : wb_goal_control(std::string(name)) {}
#endif // WHITEBOARD_POSTER_STRING_CONVERSION

  };
}
#endif // GOAL_Control_DEFINED

