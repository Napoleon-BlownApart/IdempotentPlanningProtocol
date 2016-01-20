#ifndef GOAL_Status_DEFINED
#define GOAL_Status_DEFINED

#include <cstdlib>
#include <stdlib.h>
#include <cstring>
#include <sstream>
#include <gu_util.h>
#include "gusimplewhiteboard.h"
#include "wb_goal_status.h"

namespace guWhiteboard {

  class GOAL_Status : public wb_goal_status {

    public:
      GOAL_Status() : wb_goal_status() {}
#ifdef WHITEBOARD_POSTER_STRING_CONVERSION
      GOAL_Status(const std::string &name) : wb_goal_status(std::string(name)) {}
#endif // WHITEBOARD_POSTER_STRING_CONVERSION

  };
}
#endif // GOAL_Status_DEFINED

