#ifndef _WBEPUCKTEST_
#define _WBEPUCKTEST_

#include <gu_util.h>

/** wb_epuck_test Class */
struct wb_epuck_test {


  PROPERTY(bool, epuckFollowsLineSuspended)
  PROPERTY(bool, epuckIntersectionSuspended)
  PROPERTY(bool, epuckTurnAwaySuspended)
  PROPERTY(bool, epuckChooseDirectionSuspended)
  PROPERTY(bool, epuckTurnSuspended)
  PROPERTY(bool, epuckOrientationSuspended)
  PROPERTY(bool, epuckObstacleOnPathSuspended)
  PROPERTY(bool, epuckCoordinatesSuspended)
  PROPERTY(bool, epuckCourseLegSuspended)
  PROPERTY(bool, epuckPlanManagerSuspended)

#ifdef __cplusplus
  /** Default constructor */
  wb_epuck_test() :
    _epuckFollowsLineSuspended(false),
    _epuckIntersectionSuspended(false),
    _epuckTurnAwaySuspended(false),
    _epuckChooseDirectionSuspended(false),
    _epuckTurnSuspended(false),
    _epuckOrientationSuspended(false),
    _epuckObstacleOnPathSuspended(false),
    _epuckCoordinatesSuspended(false),
    _epuckCourseLegSuspended(false),
    _epuckPlanManagerSuspended(false)
    {}

  /** Copy Constructor */
  wb_epuck_test(const wb_epuck_test &other) :
    _epuckFollowsLineSuspended(other.epuckFollowsLineSuspended()),
    _epuckIntersectionSuspended(other.epuckIntersectionSuspended()),
    _epuckTurnAwaySuspended(other.epuckTurnAwaySuspended()),
    _epuckChooseDirectionSuspended(other.epuckChooseDirectionSuspended()),
    _epuckTurnSuspended(other.epuckTurnSuspended()),
    _epuckOrientationSuspended(other.epuckOrientationSuspended()),
    _epuckObstacleOnPathSuspended(other.epuckObstacleOnPathSuspended()),
    _epuckCoordinatesSuspended(other.epuckCoordinatesSuspended()),
    _epuckCourseLegSuspended(other.epuckCourseLegSuspended()),
    _epuckPlanManagerSuspended(other.epuckPlanManagerSuspended())
    {}

  /** Assignment Operator */
  wb_epuck_test  &operator= (const wb_epuck_test &other) {
    _epuckFollowsLineSuspended = other.epuckFollowsLineSuspended();
    _epuckIntersectionSuspended = other.epuckIntersectionSuspended();
    _epuckTurnAwaySuspended = other.epuckTurnAwaySuspended();
    _epuckChooseDirectionSuspended = other.epuckChooseDirectionSuspended();
    _epuckTurnSuspended = other.epuckTurnSuspended();
    _epuckOrientationSuspended = other.epuckOrientationSuspended();
    _epuckObstacleOnPathSuspended = other.epuckObstacleOnPathSuspended();
    _epuckCoordinatesSuspended = other.epuckCoordinatesSuspended();
    _epuckCourseLegSuspended = other.epuckCourseLegSuspended();
    _epuckPlanManagerSuspended = other.epuckPlanManagerSuspended();
    return *this;
  }

#ifdef WHITEBOARD_POSTER_STRING_CONVERSION

  const char PROPERTY_SEPARATOR = '|';

  /** String constructor */
  wb_epuck_test(const std::string &name) {
      from_string(name);
  }

  /** convert from a string */
  void from_string(const std::string &str)
  {
    std::istringstream iss(str);
    std::string token;
    getline(iss, token, PROPERTY_SEPARATOR);
    _epuckFollowsLineSuspended = (token.compare("T") == 0) ? true : false;
    getline(iss, token, PROPERTY_SEPARATOR);
    _epuckIntersectionSuspended = (token.compare("T") == 0) ? true : false;
    getline(iss, token, PROPERTY_SEPARATOR);
    _epuckTurnAwaySuspended = (token.compare("T") == 0) ? true : false;
    getline(iss, token, PROPERTY_SEPARATOR);
    _epuckChooseDirectionSuspended = (token.compare("T") == 0) ? true : false;
    getline(iss, token, PROPERTY_SEPARATOR);
    _epuckTurnSuspended = (token.compare("T") == 0) ? true : false;
    getline(iss, token, PROPERTY_SEPARATOR);
    _epuckOrientationSuspended = (token.compare("T") == 0) ? true : false;
    getline(iss, token, PROPERTY_SEPARATOR);
    _epuckObstacleOnPathSuspended = (token.compare("T") == 0) ? true : false;
    getline(iss, token, PROPERTY_SEPARATOR);
    _epuckCoordinatesSuspended = (token.compare("T") == 0) ? true : false;
    getline(iss, token, PROPERTY_SEPARATOR);
    _epuckCourseLegSuspended = (token.compare("T") == 0) ? true : false;
    getline(iss, token, PROPERTY_SEPARATOR);
    _epuckPlanManagerSuspended = (token.compare("T") == 0) ? true : false;
  }

  /** get string serialisation */
  std::string to_string() {
    using namespace std;
    ostringstream ss;
    ss << ((this->epuckFollowsLineSuspended()) ? "T" : "F") << PROPERTY_SEPARATOR \
       << ((this->epuckIntersectionSuspended()) ? "T" : "F") << PROPERTY_SEPARATOR \
       << ((this->epuckTurnAwaySuspended()) ? "T" : "F") << PROPERTY_SEPARATOR \
       << ((this->epuckChooseDirectionSuspended()) ? "T" : "F") << PROPERTY_SEPARATOR \
       << ((this->epuckTurnSuspended()) ? "T" : "F") << PROPERTY_SEPARATOR \
       << ((this->epuckOrientationSuspended()) ? "T" : "F") << PROPERTY_SEPARATOR \
       << ((this->epuckObstacleOnPathSuspended()) ? "T" : "F") << PROPERTY_SEPARATOR \
       << ((this->epuckCoordinatesSuspended()) ? "T" : "F") << PROPERTY_SEPARATOR \
       << ((this->epuckCourseLegSuspended()) ? "T" : "F") << PROPERTY_SEPARATOR \
       << ((this->epuckPlanManagerSuspended()) ? "T" : "F");
    return ss.str();
  }

  /** get message description */
  std::string description() {
    using namespace std;
    ostringstream ss;
    ss << "F("  << ((this->epuckFollowsLineSuspended()) ? "True" : "False") << ") " \
       << "I("  << ((this->epuckIntersectionSuspended()) ? "True" : "False") << ") " \
       << "TA(" << ((this->epuckTurnAwaySuspended()) ? "True" : "False") << ") " \
       << "Ch(" << ((this->epuckChooseDirectionSuspended()) ? "True" : "False") << ") " \
       << "T("  << ((this->epuckTurnSuspended()) ? "True" : "False") << ") " \
       << "Or(" << ((this->epuckOrientationSuspended()) ? "True" : "False") << ") " \
       << "Ob(" << ((this->epuckObstacleOnPathSuspended()) ? "True" : "False") << ") " \
       << "Co(" << ((this->epuckCoordinatesSuspended()) ? "True" : "False") << ") " \
       << "Cr(" << ((this->epuckCourseLegSuspended()) ? "True" : "False") << ") " \
       << "PM(" << ((this->epuckPlanManagerSuspended()) ? "True" : "False") << ")";
    return ss.str();
  }
#endif // WHITEBOARD_POSTER_STRING_CONVERSION


#endif // __cplusplus

};


#endif // _WBEPUCKTEST_
