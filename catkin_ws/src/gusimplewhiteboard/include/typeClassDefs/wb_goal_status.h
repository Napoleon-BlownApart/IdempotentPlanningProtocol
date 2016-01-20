#ifndef _WBGOALSTATUS_
#define _WBGOALSTATUS_

#include "wb_goal_message.h"
#include "wb_goal_state.h"

#include <gu_util.h>

/** wb_goal_status Class */
struct wb_goal_status {

  /** X Axis */
  PROPERTY(wb_goal_message, goal)
  PROPERTY(wb_goal_message, curPosition)
  /** Y Axis */
  PROPERTY(wb_goal_state, state)

#ifdef __cplusplus
  /** Default constructor */
  wb_goal_status() :
    _goal(),
    _curPosition(),
    _state()
    {}

  /** Copy Constructor */
  wb_goal_status(const wb_goal_status &other) :
    _goal(other.goal()),
    _curPosition(other.curPosition()),
    _state(other.state())
    {}

  /** Assignment Operator */
  wb_goal_status  &operator= (const wb_goal_status &other) {
    _goal = other.goal();
    _curPosition = other.curPosition();
    _state = other.state();
    return *this;
  }

#ifdef WHITEBOARD_POSTER_STRING_CONVERSION

  const char PROPERTY_SEPARATOR = ':';
  // '|' (Pipe) Property Separator has already been used further in this branch.

  /** String constructor */
  wb_goal_status(const std::string &name) {
      from_string(name);
  }

  /** convert from a string */
  void from_string(const std::string &str)
  {
    std::istringstream iss(str);
    std::string token;
    getline(iss, token, PROPERTY_SEPARATOR);
    _goal.from_string(token);
    getline(iss, token, PROPERTY_SEPARATOR);
    _curPosition.from_string(token);
    getline(iss, token, PROPERTY_SEPARATOR);
    _state.from_string(token);
  }

  /** get string serialisation */
  std::string to_string() {
    using namespace std;
    ostringstream ss;
    ss << this->goal().to_string() << PROPERTY_SEPARATOR \
       << this->curPosition().to_string() << PROPERTY_SEPARATOR \
       << this->state().to_string();
    return ss.str();
  }

  /** get message description */
  std::string description() {
    using namespace std;
    ostringstream ss;
    ss << "G" << this->goal().description() \
       << "C" << this->curPosition().description() \
       << "S" << this->state().description();
    return ss.str();
  }
#endif // WHITEBOARD_POSTER_STRING_CONVERSION


#endif // __cplusplus

};


#endif // _WBGOALSTATUS_
