#ifndef DifferentialRobotControlStatus_DEFINED
#define DifferentialRobotControlStatus_DEFINED

#include <cstdlib>
#include <stdlib.h>
#include <cstring>
#include <sstream>
#include <gu_util.h>
#include "gusimplewhiteboard.h"
#include "wb_differential_robot.h"

namespace guWhiteboard {
    /**
    *   Class for controlling differential robots
    *   Defines whiteboard message
    */
    class DifferentialRobotControlStatus: public wb_differential_robot {
        public:
            /** Designated constructor */
            DifferentialRobotControlStatus(): wb_differential_robot() {}

#ifdef WHITEBOARD_POSTER_STRING_CONVERSION
            /** String constructor */
            DifferentialRobotControlStatus(const std::string &name) {
                from_string(name);
            }

            /** get message description */
            std::string description() {
                using namespace std;
                ostringstream ss;
                const wb_kinematic_motor &l = left_motor();
                const wb_kinematic_motor &r = right_motor();
                ss << static_cast<int>(l.speed()) << "," << static_cast<int>(r.speed()) \
                << ", " << l.odo() << "," << r.odo() << ", " << static_cast<int>(l.accel()) \
                << "," << static_cast<int>(r.accel());
                return ss.str();
            }

            /** string conversion */
            void from_string (std::string str) {
                using namespace std;
                vector<string> elements = components_of_string_separated(str, ',', true);
                wb_kinematic_motor &l = left_motor();
                wb_kinematic_motor &r = right_motor();
                if (elements.size() == 0) return;
                l.set_speed(static_cast<int16_t>(atoi(elements[0].c_str())));
                if (elements.size() < 2) return;
                r.set_speed(static_cast<int16_t>(atoi(elements[1].c_str())));
                if (elements.size() < 3) return;
                l.set_odo(static_cast<int32_t>(atoi(elements[2].c_str())));
                if (elements.size() < 4) return;
                r.set_odo(static_cast<int32_t>(atoi(elements[3].c_str())));
                if (elements.size() < 5) return;
                l.set_accel(static_cast<uint16_t>(atoi(elements[4].c_str())));
                if (elements.size() < 6) return;
                r.set_accel(static_cast<uint16_t>(atoi(elements[5].c_str())));
            }
#endif
            /** override equality operator so we can compare instances */
            bool operator == (const DifferentialRobotControlStatus &s) {
                wb_kinematic_motor &l = left_motor();
                wb_kinematic_motor &r = right_motor();
                const wb_kinematic_motor &sl = s.left_motor();
                const wb_kinematic_motor &sr = s.right_motor();

                if (l.speed() == sl.speed()
                    && l.accel() == sl.accel()
                    && l.odo() == sl.odo()
                    && r.speed() == sr.speed()
                    && r.accel() == sr.accel()
                    && r.odo() == sr.odo()) {
                    return true;
                } else {
                    return false;
                }
            }

            /** Abstraction for a stop */
            void stop() {
                wb_kinematic_motor &l = left_motor();
                wb_kinematic_motor &r = right_motor();

                l.set_speed (static_cast<int16_t> (0));
                r.set_speed (static_cast<int16_t> (0));
                l.set_accel (static_cast<int16_t> (0));
                r.set_accel (static_cast<int16_t> (0));
            }
    };
}
#endif //DifferentialRobotControlStatus_DEFINED
