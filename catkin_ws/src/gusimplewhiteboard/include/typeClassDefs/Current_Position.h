#ifndef Current_Position_DEFINED
#define Current_Position_DEFINED

#include <cstdlib>
#include <stdlib.h>
#include <cstring>
#include <sstream>
#include <gu_util.h>
#include "gusimplewhiteboard.h"
#include "wb_goal_control.h"

namespace guWhiteboard {

  class Current_Position: public wb_goal_control {

    public:
      Current_Position() : wb_goal_control() {}
      Current_Position(const std::string &name) : wb_goal_control(std::string(name)) {}

  };
}
#endif // Current_Position_DEFINED

