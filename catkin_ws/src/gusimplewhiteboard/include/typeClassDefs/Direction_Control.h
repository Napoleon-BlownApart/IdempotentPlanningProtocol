#ifndef Direction_Control_DEFINED
#define Direction_Control_DEFINED

#include <cstdlib>
#include <stdlib.h>
#include <cstring>
#include <sstream>
#include <gu_util.h>
#include "gusimplewhiteboard.h"
#include "wb_possible_directions.h"

namespace guWhiteboard {

  class Direction_Control: public wb_possible_directions {

    public:
      Direction_Control() : wb_possible_directions() {}
#ifdef WHITEBOARD_POSTER_STRING_CONVERSION
      Direction_Control(const std::string &name) : wb_possible_directions(std::string(name)) {}
#endif // WHITEBOARD_POSTER_STRING_CONVERSION

  };
}


#endif // Direction_Control_DEFINED
