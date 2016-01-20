#ifndef _WBPLANOBSTACLELIST_
#define _WBPLANOBSTACLELIST_

#include "wb_plan_obstacle.h"

#include <gu_util.h>

#define OBSTACLE_ENVELOPE_SIZE ((GU_SIMPLE_WHITEBOARD_BUFSIZE-(2*sizeof(uint32_t)))/sizeof(wb_plan_obstacle))

/** wb_plan_obstacle_list Class
  *
  * This class is used to transmit the list of obstacles encountered from
  * the Plan Manager to the Planner.  The Planner them amends the base
  * plan with the new information before re-planning.
  *
  * Under normal circumstances, this list is only transmitted when a new
  * obstacle is encountered, and only the new data is sent.  However,
  * if there is a need to retransmit the whole plan, this class is able to
  * facilitate it.
  *
  *
  * It is designed using the same principles as the FSMNames class that is
  * already in use by CLFSM and the Whiteboard.
  *
  */
struct wb_plan_obstacle_list {

  PROPERTY(uint32_t,startoff)
  ARRAY_PROPERTY(wb_plan_obstacle, obstacle, OBSTACLE_ENVELOPE_SIZE)

#ifdef __cplusplus
  /** Default constructor */
  wb_plan_obstacle_list() :
    _startoff(),
    _obstacle()
    {}

  /** Copy Constructor */
  wb_plan_obstacle_list(const wb_plan_obstacle_list &other)
   { *this = other; }

  /** Assignment Operator */
  wb_plan_obstacle_list  &operator= (const wb_plan_obstacle_list &other) {
    _startoff = other.startoff();
    std::copy(std::begin(other._obstacle), std::end(other._obstacle), std::begin(_obstacle));
    return *this;
  }

#ifdef WHITEBOARD_POSTER_STRING_CONVERSION

  const char PROPERTY_SEPARATOR = '~'; // Tilda
  // '|' (Pipe) Property Separator has already been used further in this branch.
  // ':' (Colon) Property Separator has already been used further in this branch.

  const char FIELD_SERPARATOR = ',';

  /** String constructor */
  wb_plan_obstacle_list(const std::string &name) {
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
    std::istringstream iss__obstacle(token);
    {
      int i = 0;
      std::string subtoken;
      while (getline(iss__obstacle, subtoken, FIELD_SERPARATOR)) {
        _obstacle[i++].from_string(subtoken);
      }
    }
  }

  /** get string serialisation */
  std::string to_string() {
    using namespace std;
    ostringstream ss;
    ss << static_cast<int>(this->startoff()) << PROPERTY_SEPARATOR;
    for(int i=0; i<OBSTACLE_ENVELOPE_SIZE-1; i++) ss << this->obstacle(i).to_string() << FIELD_SERPARATOR;
    ss << this->obstacle(OBSTACLE_ENVELOPE_SIZE-1).to_string() << PROPERTY_SEPARATOR;
    return ss.str();
  }

  /** get message description */
  std::string description() {
    using namespace std;
    ostringstream ss;
    ss << "s(" << static_cast<int>(this->startoff()) << ") ";
    ss << "O(";
    for(int i=0; i<OBSTACLE_ENVELOPE_SIZE-1; i++) ss << this->obstacle(i).description() << ", ";
    ss << this->obstacle(OBSTACLE_ENVELOPE_SIZE-1).description() << ")";
    return ss.str();
  }
#endif // WHITEBOARD_POSTER_STRING_CONVERSION


#endif // __cplusplus

};


#endif // _WBPLANOBSTACLELIST_

