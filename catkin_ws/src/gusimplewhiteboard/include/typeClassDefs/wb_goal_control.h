#ifndef _WBGOALCONTROL_
#define _WBGOALCONTROL_

#include "wb_goal_message.h"

#include <gu_util.h>

/** wb_goal_control Class */
struct wb_goal_control {

  /** X Axis */
  PROPERTY(wb_goal_message, goal)

#ifdef __cplusplus
  /** Default constructor */
  wb_goal_control() :
    _goal()
    {}

  /** Copy Constructor */
  wb_goal_control(const wb_goal_control &other) :
    _goal(other.goal())
    {}

  /** Assignment Operator */
  wb_goal_control  &operator= (const wb_goal_control &other) {
    _goal = other.goal();
    return *this;
  }

#ifdef WHITEBOARD_POSTER_STRING_CONVERSION

  const char PROPERTY_SEPARATOR = ':';
  // '|' (Pipe) Property Separator has already been used further in this branch.

  /** String constructor */
  wb_goal_control(const std::string &name) {
      from_string(name);
  }

  /** convert from a string */
  void from_string(const std::string &str)
  {
    std::istringstream iss(str);
    std::string token;
    getline(iss, token, PROPERTY_SEPARATOR);
    _goal.from_string(token);
  }

  /** get string serialisation */
  std::string to_string() {
    using namespace std;
    ostringstream ss;
    ss << this->goal().to_string();
    return ss.str();
  }

  /** get message description */
  std::string description() {
    using namespace std;
    ostringstream ss;
    ss << "G" << this->goal().description();
    return ss.str();
  }
#endif // WHITEBOARD_POSTER_STRING_CONVERSION


#endif // __cplusplus

};


#endif // _WBARDRONEVECTOR21F_
