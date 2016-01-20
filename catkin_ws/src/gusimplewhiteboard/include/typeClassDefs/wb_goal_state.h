#ifndef _WBGOALSTATE_
#define _WBGOALSTATE_

#include <gu_util.h>

/** wb_goal_state Class */
struct wb_goal_state {

  /***
    * didFail
    * FALSE = in progress (default)
    * TRUE =  FAILED to attain the goal
   */

  PROPERTY(bool, didFail)

#ifdef __cplusplus
  /** Default constructor */
  wb_goal_state() :
    _didFail(false)
    {}

  /** Copy Constructor */
  wb_goal_state(const wb_goal_state &other) :
    _didFail(other.didFail())
    {}

  /** Assignment Operator */
  wb_goal_state  &operator= (const wb_goal_state &other) {
    _didFail = other.didFail();
    return *this;
  }

#ifdef WHITEBOARD_POSTER_STRING_CONVERSION

  const char PROPERTY_SEPARATOR = '|';

  /** String constructor */
  wb_goal_state(const std::string &name) {
      from_string(name);
  }

  /** convert from a string */
  void from_string(const std::string &str)
  {
    std::istringstream iss(str);
    std::string token;
    getline(iss, token, PROPERTY_SEPARATOR);
    _didFail = (token.compare("T") == 0) ? true : false;
  }

  /** get string serialisation */
  std::string to_string() {
    using namespace std;
    ostringstream ss;
    ss << ((this->didFail()) ? "T" : "F");
    return ss.str();
  }

  /** get message description */
  std::string description() {
    using namespace std;
    ostringstream ss;
    ss << "(" << ((this->didFail()) ? "True" : "False") << ")";
    return ss.str();
  }
#endif // WHITEBOARD_POSTER_STRING_CONVERSION


#endif // __cplusplus

};


#endif // _WBGOALSTATE_
