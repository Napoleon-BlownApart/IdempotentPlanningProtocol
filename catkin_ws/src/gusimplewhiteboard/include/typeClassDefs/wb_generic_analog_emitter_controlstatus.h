//#ifndef _DATAVALUETYPES_
//#define _DATAVALUETYPES_
//
//enum data_value_type {
//  REALVALUES,
//  INTEGERVALUES
//};
//#endif // _DATAVALUETYPES_


#ifndef _WBDGENERICANALOGUEEMITTERCONTROLSTATUS_
#define _WBDGENERICANALOGUEEMITTERCONTROLSTATUS_

#include <sys/types.h>
#include <gu_util.h>

#ifdef WHITEBOARD_POSTER_STRING_CONVERSION
#include <sstream>
#include <ctype.h>
#endif

/** Generic Analogue Emitter
 *  This emitter represents a single parameter
 *  that has an analogue range.
 *
 *  The emitter can accept integer or real values,
 *  and care must be taken to use the correct one.
 *
 *  It can also be turned ON/OFF
 *
 *  This emitter does not define any protocol ie.
 *  1) Units,
 *  2) Sample Frequency
 *  3) Tranformation Functions
 *  4) Operational Ranges
 *  5) Duty Cycle or waveforms
 *  etc.
 *  These must be defined within the classes that
 *  use the emitter.
 *
 */

struct wb_generic_analog_emitter_controlstatus {

  PROPERTY(int32_t, value)
  PROPERTY(bool, enabled)

#ifdef __cplusplus
	/** Default constructor */
	wb_generic_analog_emitter_controlstatus() :
    _value(0),
    _enabled(false)
    {}

  /** Copy Constructor */
  wb_generic_analog_emitter_controlstatus (const wb_generic_analog_emitter_controlstatus &other) :
    _value(other._value),
    _enabled(other._enabled)
    {}

    /** assignment operator */
  wb_generic_analog_emitter_controlstatus &operator= (const  wb_generic_analog_emitter_controlstatus &other) {
    _value = other._value;
    _enabled = other._enabled;
    return *this;
  }

#ifdef WHITEBOARD_POSTER_STRING_CONVERSION

  const char PROPERTY_SEPARATOR = '|';

  /** String constructor */
  wb_generic_analog_emitter_controlstatus(const std::string &name) {
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
    ss << "V(" << static_cast<int>(this->value()) << ") " \
       << "On("   << ((this->enabled()) ? "True" : "False") << ")";
    return ss.str();
  }
#endif // WHITEBOARD_POSTER_STRING_CONVERSION


#endif // __cplusplus

};

#endif // _WBDGENERICANALOGUEEMITTERCONTROLSTATUS_
