#ifndef Plan_Goal_List_DEFINED
#define Plan_Goal_List_DEFINED

#include <cstdlib>
#include <stdlib.h>
#include <cstring>
#include <sstream>
#include <gu_util.h>
#include "gusimplewhiteboard.h"
#include "wb_plan_goal_list.h"

namespace guWhiteboard {

  class Plan_Goal_List: public wb_plan_goal_list {

    public:
      Plan_Goal_List() : wb_plan_goal_list() {}
#ifdef WHITEBOARD_POSTER_STRING_CONVERSION
      Plan_Goal_List(const std::string &name) : wb_plan_goal_list(std::string(name)) {}
#endif // WHITEBOARD_POSTER_STRING_CONVERSION

  };
}
#endif // Plan_Goal_List_DEFINED

