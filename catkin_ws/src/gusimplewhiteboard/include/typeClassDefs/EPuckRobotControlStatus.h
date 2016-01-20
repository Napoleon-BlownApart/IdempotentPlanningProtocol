#ifndef EPUCKCONTROLSTATUS
#define EPUCKCONTROLSTATUS

#include <cstdlib>
#include <stdlib.h>
#include <cstring>
#include <sstream>
#include <gu_util.h>
#include "gusimplewhiteboard.h"
#include "wb_epuck_robot.h"

namespace guWhiteboard {

  class EPuckControlStatus: public wb_epuck_robot {

    public:
      EPuckControlStatus() : wb_epuck_robot() {}

//#ifdef WHITEBOARD_POSTER_STRING_CONVERSION
//      /** String constructor */
//      DifferentialRobotControlStatus(const std::string &name) {
//          from_string(name);
//      }
//
//      /** get message description */
//      std::string description() {
//          using namespace std;
//          ostringstream ss;
//          const wb_motor &l = left_motor();
//          const wb_motor &r = right_motor();
//          ss << static_cast<int>(l.speed()) << "," << static_cast<int>(r.speed()) \
//          << ", " << l.odo() << "," << r.odo() << ", " << static_cast<unsigned>(l.accel()) \
//          << "," << static_cast<unsigned>(r.accel());
//          return ss.str();
//      }
//#endif



  };
};
#endif // EPUCKCONTROLSTATUS
