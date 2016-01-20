//#ifndef _DATAVALUETYPES_
//#define _DATAVALUETYPES_
//
//enum data_value_type {
//  REALVALUES,
//  INTEGERVALUES
//};
//#endif // _DATAVALUETYPES_


#ifndef _WBDGENERICANALOGUESENSORSTATUS_
#define _WBDGENERICANALOGUESENSORSTATUS_

#include <sys/types.h>
#include <gu_util.h>

#ifdef WHITEBOARD_POSTER_STRING_CONVERSION
#include <sstream>
#include <ctype.h>
#endif

/** Generic Analogue Sensor
 *  This sensor only reports on one measured parameter
 *  that has an analogue range.
 *
 *  The sensor can report integer or real values,
 *  and care must be taken to use the correct one.
 *
 *  It can also be turned ON/OFF
 *
 *  This sensor does not specify:
 *  1) Units Measured,
 *  2) Sample Frequency
 *  3) Tranformation Functions
 *  4) Operational Ranges
 *  etc
 *
 */


struct wb_generic_analog_sensor_status {

  PROPERTY(int32_t, value)
  PROPERTY(bool, enabled)

#ifdef __cplusplus
	/** Default Constructor */
	wb_generic_analog_sensor_status() :
    _value(0),
    _enabled(false)
    {}

  /** Copy Constructor */
  wb_generic_analog_sensor_status (const wb_generic_analog_sensor_status &other) :
    _value(other._value),
    _enabled(other._enabled)
    {}

  /** Assignment Operator */
  wb_generic_analog_sensor_status &operator= (const  wb_generic_analog_sensor_status &other) {
    _value = other._value;
    _enabled = other._enabled;
    return *this;
  }

#ifdef WHITEBOARD_POSTER_STRING_CONVERSION

  const char PROPERTY_SEPARATOR = '|';

  /** String constructor */
  wb_generic_analog_sensor_status(const std::string &name) {
      from_string(name);
  }

  /** convert from a string */
  void from_string(const std::string &str)
  {
    std::istringstream iss(str);
    std::string token;
    getline(iss, token, PROPERTY_SEPARATOR);
    _value = static_cast<int32_t>(atoi(token.c_str()));
    getline(iss, token, PROPERTY_SEPARATOR);
    _enabled = (token.compare("T") == 0) ? true : false;
  }

  /** get string serialisation */
  std::string to_string() {
    using namespace std;
    ostringstream ss;
    ss << static_cast<int>(this->value()) << PROPERTY_SEPARATOR \
       << ((this->enabled()) ? "T" : "F");
    return ss.str();
  }

  /** get message description */
  std::string description() {
    using namespace std;
    ostringstream ss;
    ss << "v(" << static_cast<int>(this->value()) << ") " \
       << "On("   << ((this->enabled()) ? "True" : "False") << ")";
    return ss.str();
  }
#endif // WHITEBOARD_POSTER_STRING_CONVERSION

#endif // __cplusplus

};

#endif // _WBDGENERICANALOGUESENSORSTATUS_
