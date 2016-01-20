#ifndef _WBANGLE_
#define _WBANGLE_

#include <gu_util.h>

/** wb_angle Class */
struct wb_angle {

  /** AR Drone Land
   *  Set to TRUE by client when a angleing is requested
   *  Set to FALSE by ardrone_whiteboard when angleing command has been sent to the drone.
   *
   *  Normally FALSE
   */
  PROPERTY(uint16_t,angle)

#ifdef __cplusplus
  /** Default constructor */
  wb_angle() : _angle(false) {}

  /** Copy Constructor */
  wb_angle(const wb_angle &other) :
    _angle(other.angle())
    {}

  /** Assignment Operator */
  wb_angle  &operator= (const wb_angle &other) {
    _angle = other.angle();
    return *this;
  }

#ifdef WHITEBOARD_POSTER_STRING_CONVERSION

  const char PROPERTY_SEPARATOR = '|';

  /** String constructor */
  wb_angle(const std::string &name) {
      from_string(name);
  }

  /** convert from a string */
  void from_string(const std::string &str)
  {
    std::istringstream iss(str);
    std::string token;
    getline(iss, token, PROPERTY_SEPARATOR);
    _angle = static_cast<uint16_t>(atoi(token.c_str()));
  }

  /** get string serialisation */
  std::string to_string() {
    using namespace std;
    ostringstream ss;
    ss << this->angle();
    return ss.str();
  }

  /** get message description */
  std::string description() {
    using namespace std;
    ostringstream ss;
    ss << "A(" << this->angle() << ")";
    return ss.str();
  }
#endif // WHITEBOARD_POSTER_STRING_CONVERSION


#endif // __cplusplus

};


#endif // _WBANGLE_
