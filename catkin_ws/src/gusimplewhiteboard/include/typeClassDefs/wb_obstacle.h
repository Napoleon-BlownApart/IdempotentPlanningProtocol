#ifndef _WBOBSTACLE_
#define _WBOBSTACLE_

#include <gu_util.h>

/** wb_obstacle Class */
struct wb_obstacle {

  /** AR Drone Land
   *  Set to TRUE by client when a obstacleing is requested
   *  Set to FALSE by ardrone_whiteboard when obstacleing command has been sent to the drone.
   *
   *  Normally FALSE
   */
  PROPERTY(bool,obstacle)

#ifdef __cplusplus
  /** Default constructor */
  wb_obstacle() :
    _obstacle(false)
    {}

  /** Copy Constructor */
  wb_obstacle(const wb_obstacle &other) :
    _obstacle(other.obstacle())
    {}

  /** Assignment Operator */
  wb_obstacle  &operator= (const wb_obstacle &other) {
    _obstacle = other.obstacle();
    return *this;
  }

#ifdef WHITEBOARD_POSTER_STRING_CONVERSION
  const char PROPERTY_SEPARATOR = '|';

  /** String constructor */
  wb_obstacle(const std::string &name) {
      from_string(name);
  }

  /** convert from a string */
  void from_string(const std::string &str)
  {
    std::istringstream iss(str);
    std::string token;
    getline(iss, token, PROPERTY_SEPARATOR);
    _obstacle = (token.compare("T") == 0) ? true : false;
  }

  /** get string serialisation */
  std::string to_string() {
    using namespace std;
    ostringstream ss;
    ss << ((this->obstacle()) ? "T" : "F");
    return ss.str();
  }

  /** get message description */
  std::string description() {
    using namespace std;
    ostringstream ss;
    ss << "O(" << ((this->obstacle()) ? "True" : "False") << ")";
    return ss.str();
  }
#endif // WHITEBOARD_POSTER_STRING_CONVERSION


#endif // __cplusplus

};


#endif // _WBOBSTACLE_
