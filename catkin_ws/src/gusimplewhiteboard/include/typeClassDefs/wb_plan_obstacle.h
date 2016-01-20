#ifndef _WBPLANOBSTACLE_
#define _WBPLANOBSTACLE_

#include "wb_goal_message.h"

#include <gu_util.h>

/** wb_plan_control Class */
struct wb_plan_obstacle {

  PROPERTY(wb_goal_message, intersectionA)
  PROPERTY(wb_goal_message, intersectionB)
//  PROPERTY(bool, isValidLocation)

#ifdef __cplusplus
  /** Default constructor */
  wb_plan_obstacle() :
    _intersectionA(),
    _intersectionB()
//    _isValidLocation(false)
    {}

  /** Copy Constructor */
  wb_plan_obstacle(const wb_plan_obstacle &other) :
    _intersectionA(other.intersectionA()),
    _intersectionB(other.intersectionB())
//    _isValidLocation(other.isValidLocation())
    {}

  /** Assignment Operator */
  wb_plan_obstacle  &operator= (const wb_plan_obstacle &other) {
    _intersectionA = other.intersectionA();
    _intersectionB = other.intersectionB();
//    _isValidLocation = other.isValidLocation();
    return *this;
  }

#ifdef WHITEBOARD_POSTER_STRING_CONVERSION

  const char PROPERTY_SEPARATOR = ':';
  // '|' (Pipe) Property Separator has already been used further in this branch.

  /** String constructor */
  wb_plan_obstacle(const std::string &name) {
      from_string(name);
  }

  /** convert from a string */
  void from_string(const std::string &str)
  {
    std::istringstream iss(str);
    std::string token;
    getline(iss, token, PROPERTY_SEPARATOR);
    _intersectionA.from_string(token);
    getline(iss, token, PROPERTY_SEPARATOR);
    _intersectionB.from_string(token);
//    getline(iss, token, PROPERTY_SEPARATOR);
//    _isValidLocation = (token.compare("T") == 0) ? true : false;
  }

  /** get string serialisation */
  std::string to_string() {
    using namespace std;
    ostringstream ss;
    ss << this->intersectionA().to_string() << PROPERTY_SEPARATOR \
       << this->intersectionB().to_string(); // << PROPERTY_SEPARATOR \
       << ((this->isValidLocation()) ? "T" : "F");
    return ss.str();
  }

  /** get message description */
  std::string description() {
    using namespace std;
    ostringstream ss;
    ss << "A(" << this->intersectionA().description() << ") "\
       << "B(" << this->intersectionB().description(); // << ") "\
       << "v(" << ((this->isValidLocation()) ? "True" : "False") << ")";
    return ss.str();
  }
#endif // WHITEBOARD_POSTER_STRING_CONVERSION


#endif // __cplusplus

};


#endif // _WBPLANOBSTACLE_

