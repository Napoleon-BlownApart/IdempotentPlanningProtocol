#ifndef _WBGOALMESSAGE_
#define _WBGOALMESSAGE_

#include <gu_util.h>

/** wb_goal_message Class */
struct wb_goal_message {

  /** X Axis */
  PROPERTY(int8_t, x)
  /** Y Axis */
  PROPERTY(int8_t, y)

#ifdef __cplusplus
  /** Default constructor */
  wb_goal_message() :
    _x(0),
    _y(0)
    {}

  /** Copy Constructor */
  wb_goal_message(const wb_goal_message &other) :
    _x(other.x()),
    _y(other.y())
    {}

  /** Assignment Operator */
  wb_goal_message  &operator= (const wb_goal_message &other) {
    _x = other.x();
    _y = other.y();
    return *this;
  }

#ifdef WHITEBOARD_POSTER_STRING_CONVERSION

  const char PROPERTY_SEPARATOR = '|';

  /** String constructor */
  wb_goal_message(const std::string &name) {
      from_string(name);
  }

  /** convert from a string */
  void from_string(const std::string &str)
  {
    std::istringstream iss(str);
    std::string token;
    getline(iss, token, PROPERTY_SEPARATOR);
    _x = static_cast<int8_t>(atoi(token.c_str()));
    getline(iss, token, PROPERTY_SEPARATOR);
    _y = static_cast<int8_t>(atoi(token.c_str()));
  }

  /** get string serialisation */
  std::string to_string() {
    using namespace std;
    ostringstream ss;
    ss << static_cast<int>(this->x()) << PROPERTY_SEPARATOR \
       << static_cast<int>(this->y());
    return ss.str();
  }

  /** get message description */
  std::string description() {
    using namespace std;
    ostringstream ss;
    ss << "("  << static_cast<int>(this->x()) \
       << ", " << static_cast<int>(this->y()) \
       << ")";
    return ss.str();
  }
#endif // WHITEBOARD_POSTER_STRING_CONVERSION


#endif // __cplusplus

};


#endif // _WBGOALMESSAGE_
