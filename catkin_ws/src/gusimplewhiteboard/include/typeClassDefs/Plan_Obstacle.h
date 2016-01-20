#ifndef Plan_Obstacle_DEFINED
#define Plan_Obstacle_DEFINED

#include <cstdlib>
#include <stdlib.h>
#include <cstring>
#include <sstream>
#include <gu_util.h>
#include "gusimplewhiteboard.h"
#include "wb_plan_obstacle.h"

namespace guWhiteboard {

  class Plan_Obstacle: public wb_plan_obstacle {

    public:
      Plan_Obstacle() : wb_plan_obstacle() {}
#ifdef WHITEBOARD_POSTER_STRING_CONVERSION
      Plan_Obstacle(const std::string &name) : wb_plan_obstacle(std::string(name)) {}
#endif // WHITEBOARD_POSTER_STRING_CONVERSION

  };
}
#endif // Plan_Obstacle_DEFINED

