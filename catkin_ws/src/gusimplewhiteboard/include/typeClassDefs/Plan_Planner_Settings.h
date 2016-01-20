#ifndef Plan_Planner_Settings_DEFINED
#define Plan_Planner_Settings_DEFINED

#include <cstdlib>
#include <stdlib.h>
#include <cstring>
#include <sstream>
#include <gu_util.h>
#include "gusimplewhiteboard.h"
#include "wb_plan_planner_settings.h"

namespace guWhiteboard {

  class Plan_Planner_Settings: public wb_plan_planner_settings {

    public:
      Plan_Planner_Settings() : wb_plan_planner_settings() {}
      Plan_Planner_Settings(const std::string &name) : wb_plan_planner_settings(std::string(name)) {}

  };
}
#endif // Plan_Settings_DEFINED

