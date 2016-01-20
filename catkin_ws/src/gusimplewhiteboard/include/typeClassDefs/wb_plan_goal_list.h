#ifndef _WBPLANGOALLIST_
#define _WBPLANGOALLIST_

#include "wb_goal_message.h"

#include <gu_util.h>

#define GOAL_ENVELOPE_SIZE ((GU_SIMPLE_WHITEBOARD_BUFSIZE-(2*sizeof(uint32_t)))/sizeof(wb_goal_message))

/** wb_plan_goal_list Class
  *
  * This class is used to transmit the list of sub-goals from the Planner
  * to the Plan Manager.
  *
  * It is designed using the same principles as the FSMNames class that is
  * already in use by CLFSM and the Whiteboard.
  *
  */
struct wb_plan_goal_list {

  PROPERTY(uint32_t,startoff)
  ARRAY_PROPERTY(wb_goal_message, subGoal, GOAL_ENVELOPE_SIZE)

#ifdef __cplusplus
  /** Default constructor */
  wb_plan_goal_list() :
    _startoff(),
    _subGoal()
    {}

  /** Copy Constructor */
  wb_plan_goal_list(const wb_plan_goal_list &other)
   { *this = other; }

  /** Assignment Operator */
  wb_plan_goal_list  &operator= (const wb_plan_goal_list &other) {
    _startoff = other.startoff();
    std::copy(std::begin(other._subGoal), std::end(other._subGoal), std::begin(_subGoal));
    return *this;
  }

#ifdef WHITEBOARD_POSTER_STRING_CONVERSION

  const char PROPERTY_SEPARATOR = '~'; // Tilda
  // '|' (Pipe) Property Separator has already been used further in this branch.
  // ':' (Colon) Property Separator has already been used further in this branch.

  const char FIELD_SERPARATOR = ',';

  /** String constructor */
  wb_plan_goal_list(const std::string &name) {
      from_string(name);
  }

  /** convert from a string */
  void from_string(const std::string &str)
  {
    std::istringstream iss(str);
    std::string token;
    getline(iss, token, PROPERTY_SEPARATOR);
    _startoff = static_cast<uint32_t>(atoi(token.c_str()));
    getline(iss, token, PROPERTY_SEPARATOR);
    std::istringstream iss__subGoal(token);
    {
      int i = 0;
      std::string subtoken;
      while (getline(iss__subGoal, subtoken, FIELD_SERPARATOR)) {
        _subGoal[i++].from_string(subtoken);
      }
    }
  }

  /** get string serialisation */
  std::string to_string() {
    using namespace std;
    ostringstream ss;
    ss << static_cast<int>(this->startoff()) << PROPERTY_SEPARATOR;
    for(int i=0; i<GOAL_ENVELOPE_SIZE-1; i++) ss << this->subGoal(i).to_string() << FIELD_SERPARATOR;
    ss << this->subGoal(GOAL_ENVELOPE_SIZE-1).to_string() << PROPERTY_SEPARATOR;
    return ss.str();
  }

  /** get message description */
  std::string description() {
    using namespace std;
    ostringstream ss;
    ss << "s(" << static_cast<int>(this->startoff()) << ") ";
    ss << "G(";
    for(int i=0; i<GOAL_ENVELOPE_SIZE-1; i++) ss << this->subGoal(i).description() << ", ";
    ss << this->subGoal(GOAL_ENVELOPE_SIZE-1).description() << ")";
    return ss.str();
  }
#endif // WHITEBOARD_POSTER_STRING_CONVERSION


#endif // __cplusplus

};


#endif // _WBPLANGOALLIST_

