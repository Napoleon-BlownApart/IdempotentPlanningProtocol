#ifndef _WBSENSORSINTERSECTIONSTATUS_
#define _WBSENSORSINTERSECTIONSTATUS_

#include "wb_goal_message.h"
#include "wb_possible_directions.h"

#include <gu_util.h>

/** wb_sensors_intersection_status Class */
struct wb_sensors_intersection_status {

  /** X Axis */
  PROPERTY(bool,scanComplete)
  PROPERTY(wb_possible_directions, directions)

#ifdef __cplusplus
  /** Default constructor */
  wb_sensors_intersection_status() :
    _scanComplete(false),
    _directions()
    {}

  /** Copy Constructor */
  wb_sensors_intersection_status(const wb_sensors_intersection_status &other) :
    _scanComplete(other.scanComplete()),
    _directions(other.directions())
    {}

  /** Assignment Operator */
  wb_sensors_intersection_status  &operator= (const wb_sensors_intersection_status &other) {
    _scanComplete = other.scanComplete();
    _directions = other.directions();
    return *this;
  }

#ifdef WHITEBOARD_POSTER_STRING_CONVERSION

  const char PROPERTY_SEPARATOR = ':';
  // '|' (Pipe) Property Separator has already been used further in this branch.

  /** String constructor */
  wb_sensors_intersection_status(const std::string &name) {
      from_string(name);
  }

  /** convert from a string */
  void from_string(const std::string &str)
  {
    std::istringstream iss(str);
    std::string token;
    getline(iss, token, PROPERTY_SEPARATOR);
    _scanComplete = (token.compare("T") == 0) ? true : false;
    getline(iss, token, PROPERTY_SEPARATOR);
    _directions.from_string(token);
  }

  /** get string serialisation */
  std::string to_string() {
    using namespace std;
    ostringstream ss;
    ss << ((this->scanComplete()) ? "T" : "F") << PROPERTY_SEPARATOR \
       << this->directions().to_string() << PROPERTY_SEPARATOR;
    return ss.str();
  }

  /** get message description */
  std::string description() {
    using namespace std;
    ostringstream ss;
    ss << ((this->scanComplete()) ? "True" : "False") << PROPERTY_SEPARATOR \
       << "Dir(" << this->directions().description() << ") ";
    return ss.str();
  }
#endif // WHITEBOARD_POSTER_STRING_CONVERSION


#endif // __cplusplus

};
#endif // _WBSENSORSINTERSECTIONSTATUS_
