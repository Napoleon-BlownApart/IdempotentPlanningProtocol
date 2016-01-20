#ifndef _WBPLANFILENAME_
#define _WBPLANFILENAME_

#include <gu_util.h>

#define MAX_FILEPATH_LENGTH GU_SIMPLE_WHITEBOARD_BUFSIZE-1
/** wb_plan_filename Class */
struct wb_plan_filename {

  /** Filename
    *
    * String that fills the whole width
    * of the Whiteboard Message size.
    *
    * NOTE: last character is reserved for the string terminator '\0'
    *
    */
  STRING_PROPERTY(filename, MAX_FILEPATH_LENGTH-1) // See gusimplewhiteboard.h for definition

#ifdef __cplusplus
  /** Default constructor */
  wb_plan_filename()
   {}

  /** Copy Constructor */
  wb_plan_filename(const wb_plan_filename &other)
    { *this = other;}

  /** Assignment Operator */
  wb_plan_filename  &operator= (const wb_plan_filename &other) {
    strncpy(_filename,other.filename(),(MAX_FILEPATH_LENGTH-1)); // Allow 1 byte for \0
    return *this;
  }

#ifdef WHITEBOARD_POSTER_STRING_CONVERSION

  const char PROPERTY_SEPARATOR = '|';

  /** String constructor */
  wb_plan_filename(const std::string &name) {
      from_string(name);
  }

  /** convert from a string */
  void from_string(const std::string &str)
  {
    std::istringstream iss(str);
    std::string token;
    getline(iss, token, PROPERTY_SEPARATOR);
    strncpy(_filename,token.c_str(),(MAX_FILEPATH_LENGTH-1)); // Allow 1 byte for \0
  }

  /** get string serialisation */
  std::string to_string() {
    using namespace std;
    ostringstream ss;
    ss << this->filename();
    return ss.str();
  }

  /** get message description */
  std::string description() {
    using namespace std;
    ostringstream ss;
    ss << "FN(" << this->filename() << ") ";
    return ss.str();
  }
#endif // WHITEBOARD_POSTER_STRING_CONVERSION


#endif // __cplusplus

};


#endif // _WBPLANFILENAME_
