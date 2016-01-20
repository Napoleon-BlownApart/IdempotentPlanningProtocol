#ifndef _WBPLANPLANNERSETTINGS_
#define _WBPLANPLANNERSETTINGS_

#include <gu_util.h>


#define PLANNING_ENGINE_SELECTOR_STR_LEN 21 // Allow 1 byte for \0

/** wb_plan_planner_settings Class
  * Planner Settings
  * The Plan Manager uses this message to choose
  * which Planning Engine from LAPKT to use.
  * The following have been implemented.
  * The plan manager uses this message to select/set
  * planning parameters to be used.
  */
struct wb_plan_planner_settings {

  /** max_novelty
    *
    * Use by the 'bfs_f-ffparser' planner in LAPKT
    * TODO (DRJ)  MEANING TO BE DEFINED
    *
    * Not used with the planners implemented thus far.
    *
    */
  PROPERTY(float, max_novelty)
  PROPERTY(float, cost)
  PROPERTY(float, bound)

  /** budget
    * The time limit for the planner to find a solution.
    * [TODO: time budget is fixed in the epuck example.
    *        This will be implemented later]
    *
    */
  PROPERTY(float, budget)

  /** heuristic
    *
    *   Used in lapkt/planners/generic-best_first-ffparser
  	*   1)  H_add:
	  *   2)  H_add_Rp:
    *   3)  H_max_Rp:
    *   4)  FF's GBFS with H_add_rp:
    *   5)  FF's GBFS with H_max_rp:
    *
    */
  PROPERTY(uint8_t, heuristic)
  PROPERTY(bool, anytime)
  PROPERTY(bool, delayed)
  PROPERTY(bool, greedy)

  /** engine
    *
    * The string tells the Planning Engine
    * which Search Engine from LAPKT to use.
    * The following have been implemented:
    *   BFS_HMAX  bfs (delayed/greedy/anytime) + h_max
    *   BRFS      BrFS
    *   DAS       Deadline_Aware_Search
    *
    */
  STRING_PROPERTY(engine, 20)


#ifdef __cplusplus
  /** Default constructor */
  wb_plan_planner_settings() :
    _max_novelty(),
    _cost(),
    _bound(),
    _budget(),
    _heuristic(),
    _anytime(),
    _delayed(),
    _greedy()
    {}

  /** Copy Constructor */
  wb_plan_planner_settings(const wb_plan_planner_settings &other)
    { *this = other; }

  /** Assignment Operator */
  wb_plan_planner_settings  &operator= (const wb_plan_planner_settings &other) {
    _max_novelty = other.max_novelty();
    _cost = other.cost();
    _bound = other.bound();
    _budget = other.budget();
    _heuristic = other.heuristic();
    _anytime = other.anytime();
    _delayed = other.delayed();
    _greedy = other.greedy();
    strncpy(_engine,other.engine(),(PLANNING_ENGINE_SELECTOR_STR_LEN-1)); // Allow 1 byte for \0
    return *this;
  }

#ifdef WHITEBOARD_POSTER_STRING_CONVERSION

  const char PROPERTY_SEPARATOR = '|';

  /** String constructor */
  wb_plan_planner_settings(const std::string &name) {
      from_string(name);
  }

  /** convert from a string */
  void from_string(const std::string &str)
  {
    std::istringstream iss(str);
    std::string token;
    getline(iss, token, PROPERTY_SEPARATOR);
    _max_novelty = static_cast<float>(atof(token.c_str()));
    getline(iss, token, PROPERTY_SEPARATOR);
    _cost = static_cast<float>(atof(token.c_str()));
    getline(iss, token, PROPERTY_SEPARATOR);
    _bound = static_cast<float>(atof(token.c_str()));
    getline(iss, token, PROPERTY_SEPARATOR);
    _budget = static_cast<float>(atof(token.c_str()));
    getline(iss, token, PROPERTY_SEPARATOR);
    _heuristic = static_cast<uint8_t>(atoi(token.c_str()));
    getline(iss, token, PROPERTY_SEPARATOR);
    _anytime = (token.compare("T") == 0) ? true : false;
    getline(iss, token, PROPERTY_SEPARATOR);
    _delayed = (token.compare("T") == 0) ? true : false;
    getline(iss, token, PROPERTY_SEPARATOR);
    _greedy = (token.compare("T") == 0) ? true : false;
    getline(iss, token, PROPERTY_SEPARATOR);
    strncpy(_engine,token.c_str(),(PLANNING_ENGINE_SELECTOR_STR_LEN-1)); // Allow 1 byte for \0
  }

  /** get string serialisation */
  std::string to_string() {
    using namespace std;
    ostringstream ss;
    ss << static_cast<float>(this->max_novelty()) << PROPERTY_SEPARATOR \
       << static_cast<float>(this->cost()) << PROPERTY_SEPARATOR \
       << static_cast<float>(this->bound()) << PROPERTY_SEPARATOR \
       << static_cast<float>(this->budget()) << PROPERTY_SEPARATOR \
       << static_cast<int>(this->heuristic()) << PROPERTY_SEPARATOR \
       << ((this->anytime()) ? "T" : "F") << PROPERTY_SEPARATOR \
       << ((this->delayed()) ? "T" : "F") << PROPERTY_SEPARATOR \
       << ((this->greedy()) ? "T" : "F") << PROPERTY_SEPARATOR \
       << this->engine();
    return ss.str();
  }

  /** get message description */
  std::string description() {
    using namespace std;
    ostringstream ss;
    ss << "N("   << static_cast<float>(this->max_novelty()) << ") " \
       << "C("   << static_cast<float>(this->cost()) << ") " \
       << "Bnd(" << static_cast<float>(this->bound()) << ") " \
       << "Bud(" << static_cast<float>(this->budget()) << ") " \
       << "H("   << static_cast<int>(this->heuristic()) << ") " \
       << "a("   << ((this->anytime()) ? "T" : "F") << ") " \
       << "d("   << ((this->delayed()) ? "T" : "F") << ") " \
       << "g("   << ((this->greedy()) ? "T" : "F") << ") " \
       << "Eng(" << this->engine() << ") ";
    return ss.str();
  }
#endif // WHITEBOARD_POSTER_STRING_CONVERSION


#endif // __cplusplus

};


#endif // _WBPLANPLANNERSETTINGS_
