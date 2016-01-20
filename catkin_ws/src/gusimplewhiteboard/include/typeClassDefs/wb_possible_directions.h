#ifndef _WBPOSSIBLEDIRECTIONS_
#define _WBPOSSIBLEDIRECTIONS_

#ifndef EPUCK_POSSIBLE_DIRECTIONS_LIST
#define EPUCK_POSSIBLE_DIRECTIONS_LIST

/** e-Puck Light Sensors
 *  The e-Puck has eight (8) LightSensors (ls0 - ls7)
 *  They are mounted (approximately):
 *  0:  18 degrees
 *  1:  45 degrees
 *  2:  90 degrees
 *  3   150 degrees
 *  4:  210 degrees
 *  5:  270 degrees
 *  6:  315 degrees
 *  7:  342 degrees
 */
//#pragma GCC diagnostic push
//#pragma GCC diagnostic ignored "-Wduplicate-enum"
enum Direction {
  BACK          = 0x00,
  STRAIGHT      = 0x01,
  RIGHT         = 0x02,
  LEFT          = 0x04,
  AROUNDRIGHT   = 0x08,
  AROUNDLEFT    = 0x10,
};
//#pragma GCC diagnostic pop
#endif // EPUCK_POSSIBLE_DIRECTIONS_LIST

/** wb_possible_directions Class */
struct wb_possible_directions {

  PROPERTY(Direction, direction)

#ifdef __cplusplus
  /** Default constructor */
  wb_possible_directions() :
    _direction()
    {}

  /** Copy Constructor */
  wb_possible_directions(const wb_possible_directions &other) :
    _direction(other.direction())
    {}

  /** Assignment Operator */
  wb_possible_directions  &operator= (const wb_possible_directions &other) {
    _direction = other.direction();
    return *this;
  }

#ifdef WHITEBOARD_POSTER_STRING_CONVERSION

  const char PROPERTY_SEPARATOR = '|';

  /** String constructor */
  wb_possible_directions(const std::string &name) {
      from_string(name);
  }

  /** convert from a string */
  void from_string(const std::string &str)
  {
    std::istringstream iss(str);
    std::string token;
    getline(iss, token, PROPERTY_SEPARATOR);
    _direction = static_cast<Direction>(atoi(token.c_str()));
  }

  /** get string serialisation */
  std::string to_string() {
    using namespace std;
    ostringstream ss;
    ss << static_cast<int>(this->direction());
    return ss.str();
  }

  /** get message description */
  std::string description() {
    using namespace std;
    ostringstream ss;
    ss << "(" << static_cast<int>(this->direction()) << ")";
    return ss.str();
  }
#endif // WHITEBOARD_POSTER_STRING_CONVERSION

#endif // __cplusplus
};
#endif // _WBPOSSIBLEDIRECTIONS_
