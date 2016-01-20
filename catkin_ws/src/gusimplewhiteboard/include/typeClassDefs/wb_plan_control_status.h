#ifndef _WBPLANCONTROLSTATUS_
#define _WBPLANCONTROLSTATUS_

#include <gu_util.h>

/** wb_plan_control_status Class

  */
struct wb_plan_control_status {



  /** planHash
    *
    * Hash of all the inputs to the current plan.
    *
    */
  PROPERTY(size_t, planHash)

  /** plan
    *
    * As a state in the Plan Manager:
    * TRUE:   Indicates a new plan is required
    * FALSE:  Current plan is ok
    *
    * As a state in the Planner:
    * TRUE:   Indicates there is a new plan available.
    * FALSE:  Current plan is ok or no plan.
    *
    *   *****  SEE EXPLANATION ABOVE  *****
    *
    */
//  PROPERTY(bool, plan)

#ifdef __cplusplus
  /** Default constructor */
  wb_plan_control_status() :
    _planHash()
//    _plan()
    {}

  /** Copy Constructor */
  wb_plan_control_status(const wb_plan_control_status &other) :
    _planHash(other.planHash())
//    _plan(other.plan())
    {}

  /** Assignment Operator */
  wb_plan_control_status  &operator= (const wb_plan_control_status &other) {
    _planHash = other.planHash();
//    _plan = other.plan();
    return *this;
  }

#ifdef WHITEBOARD_POSTER_STRING_CONVERSION

  const char PROPERTY_SEPARATOR = '|';

  /** String constructor */
  wb_plan_control_status(const std::string &name) {
      from_string(name);
  }

  /** convert from a string */
  void from_string(const std::string &str)
  {
    std::istringstream iss(str);
    std::string token;
    getline(iss, token, PROPERTY_SEPARATOR);
    _planHash = static_cast<size_t>(atoi(token.c_str()));
//    getline(iss, token, PROPERTY_SEPARATOR);
//    _plan = (token.compare("T") == 0) ? true : false;
  }

  /** get string serialisation */
  std::string to_string() {
    using namespace std;
    ostringstream ss;
    ss << this->planHash();
//    ss << static_cast<int>(this->numUnits()) << PROPERTY_SEPARATOR \
//       << ((this->plan()) ? "T" : "F");
    return ss.str();
  }

  /** get message description */
  std::string description() {
    using namespace std;
    ostringstream ss;
    ss << "Hash(" << this->planHash() << ")";
//    ss << "Num(" << static_cast<int>(this->numUnits()) << ") " \
//       << "Plan(" << ((this->plan()) ? "T" : "F") << ")";
    return ss.str();
  }
#endif // WHITEBOARD_POSTER_STRING_CONVERSION


#endif // __cplusplus

};


#endif // _WBPLANSTATUS_
