#ifndef Plan_Filename_DEFINED
#define Plan_Filename_DEFINED

#include <cstdlib>
#include <stdlib.h>
#include <cstring>
#include <sstream>
#include <gu_util.h>
#include "gusimplewhiteboard.h"
#include "wb_plan_filename.h"

namespace guWhiteboard {

  class Plan_Filename: public wb_plan_filename {

    public:
      Plan_Filename() : wb_plan_filename() {}
#ifdef WHITEBOARD_POSTER_STRING_CONVERSION
      Plan_Filename(const std::string &name) : wb_plan_filename(std::string(name)) {}
#endif // WHITEBOARD_POSTER_STRING_CONVERSION

  };
}
#endif // Plan_Filename_DEFINED

