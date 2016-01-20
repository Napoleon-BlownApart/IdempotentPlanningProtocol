#ifndef Epuck_Test_DEFINED
#define Epuck_Test_DEFINED

#include <cstdlib>
#include <stdlib.h>
#include <cstring>
#include <sstream>
#include <gu_util.h>
#include "gusimplewhiteboard.h"
#include "wb_epuck_test.h"

namespace guWhiteboard {

  class Epuck_Test : public wb_epuck_test {

    public:
      Epuck_Test() : wb_epuck_test() {}
#ifdef WHITEBOARD_POSTER_STRING_CONVERSION
      Epuck_Test(const std::string &name) : wb_epuck_test(std::string(name)) {}
#endif // WHITEBOARD_POSTER_STRING_CONVERSION

  };
}
#endif // Epuck_Test_DEFINED
