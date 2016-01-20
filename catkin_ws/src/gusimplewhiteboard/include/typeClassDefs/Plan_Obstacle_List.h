#ifndef Plan_Obstacle_List_DEFINED
#define Plan_Obstacle_List_DEFINED

#include <cstdlib>
#include <stdlib.h>
#include <cstring>
#include <sstream>
#include <gu_util.h>
#include "gusimplewhiteboard.h"
#include "wb_plan_obstacle_list.h"

namespace guWhiteboard {

  class Plan_Obstacle_List: public wb_plan_obstacle_list {

    public:
      Plan_Obstacle_List() : wb_plan_obstacle_list() {}
#ifdef WHITEBOARD_POSTER_STRING_CONVERSION
      Plan_Obstacle_List(const std::string &name) : wb_plan_obstacle_list(std::string(name)) {}
#endif // WHITEBOARD_POSTER_STRING_CONVERSION

  };
}
#endif // Plan_Obstacle_List_DEFINED

