/** Auto-generated, don't modify! */

#include <string>
#include <vector>
#include <cstdlib>

#define WHITEBOARD_POSTER_STRING_CONVERSION

#include "guwhiteboardtypelist_generated.h"
#include "guwhiteboardgetter.h"

using namespace std;
using namespace guWhiteboard;

extern "C"
{
	char *whiteboard_get(const char *message_type, gu_simple_message *msg)
	{
		return whiteboard_getmsg(types_map[message_type], msg);
	}


	char *whiteboard_getmsg(int message_index, gu_simple_message *msg)
	{
		return gu_strdup(getmsg(WBTypes(message_index), msg).c_str());
	}
} // extern C

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunused-function"
static string intvectostring(const vector<int> &vec)
{
	stringstream ss;
	
	for (vector<int>::const_iterator it = vec.begin(); it != vec.end(); it++)
	{
		if (it != vec.begin()) ss << ",";
		ss << *it;
	}

	return ss.str();
}
#pragma clang diagnostic pop

string guWhiteboard::getmsg(string message_type, gu_simple_message *msg)
{
	return getmsg(types_map[message_type], msg);
}


string guWhiteboard::getmsg(WBTypes message_index, gu_simple_message *msg)
{
	switch (message_index)
	{
		case kwb_reserved_SubscribeToAllTypes_v:
			return "##unsupported##";

		case kPrint_v:
		{
/** WB Ptr Class: Print @brief Nil */ 
			class Print_t m;
			return msg ? m.get_from(msg) : m.get();
		}
		case kSay_v:
		{
/** WB Ptr Class: Say @brief Nil */ 
			class Say_t m;
			return msg ? m.get_from(msg) : m.get();
		}
		case kSpeech_v:
		{
/** WB Ptr Class: Speech @brief Nil */ 
			class Speech_t m;
			return msg ? m.get_from(msg) : m.get();
		}
		case kQSay_v:
		{
/** WB Ptr Class: QSay @brief Nil */ 
			class QSay_t m;
			return msg ? m.get_from(msg) : m.get();
		}
		case kQSpeech_v:
		{
/** WB Ptr Class: QSpeech @brief Nil */ 
			class QSpeech_t m;
			return msg ? m.get_from(msg) : m.get();
		}
		case kSpeechOutput_v:
		{
/** WB Ptr Class: SpeechOutput @brief Nil */ 
			class SpeechOutput_t m;
			return msg ? gu_ltos(long(m.get_from(msg))) : gu_ltos(long(m.get()));
		}
		case kFSM_Control_v:
#ifdef FSMControlStatus_DEFINED
		{
/** WB Ptr Class: FSM_Control @brief Nil */ 
			class FSM_Control_t m;
			return msg ? m.get_from(msg).description() : m.get().description();
		}
#else
			return "##unsupported##";

#endif // !FSMControlStatus_DEFINED

		case kFSM_Status_v:
#ifdef FSMControlStatus_DEFINED
		{
/** WB Ptr Class: FSM_Status @brief Nil */ 
			class FSM_Status_t m;
			return msg ? m.get_from(msg).description() : m.get().description();
		}
#else
			return "##unsupported##";

#endif // !FSMControlStatus_DEFINED

		case kFSM_Names_v:
#ifdef FSMNames_DEFINED
		{
/** WB Ptr Class: FSM_Names @brief Nil */ 
			class FSM_Names_t m;
			return msg ? m.get_from(msg).description() : m.get().description();
		}
#else
			return "##unsupported##";

#endif // !FSMNames_DEFINED

		case kFSM_States_v:
#ifdef FSMState_DEFINED
		{
/** WB Ptr Class: FSM_States @brief Nil */ 
			class FSM_States_t m;
			return msg ? m.get_from(msg).description() : m.get().description();
		}
#else
			return "##unsupported##";

#endif // !FSMState_DEFINED

		case kSENSORS_EPuckAccel_Control_v:
#ifdef SENSORS_EPuckAccel_Control_DEFINED
		{
/** WB Ptr Class: SENSORS_EPuckAccel_Control @brief Nil */ 
			class SENSORS_EPuckAccel_Control_t m;
			return msg ? m.get_from(msg).description() : m.get().description();
		}
#else
			return "##unsupported##";

#endif // !SENSORS_EPuckAccel_Control_DEFINED

		case kSENSORS_EPuckAccel_Status_v:
#ifdef SENSORS_EPuckAccel_Status_DEFINED
		{
/** WB Ptr Class: SENSORS_EPuckAccel_Status @brief Nil */ 
			class SENSORS_EPuckAccel_Status_t m;
			return msg ? m.get_from(msg).description() : m.get().description();
		}
#else
			return "##unsupported##";

#endif // !SENSORS_EPuckAccel_Status_DEFINED

		case kSENSORS_EPuckCamera_Control_v:
#ifdef SENSORS_EPuckCamera_ControlStatus_DEFINED
		{
/** WB Ptr Class: SENSORS_EPuckCamera_Control @brief Nil */ 
			class SENSORS_EPuckCamera_Control_t m;
			return msg ? m.get_from(msg).description() : m.get().description();
		}
#else
			return "##unsupported##";

#endif // !SENSORS_EPuckCamera_ControlStatus_DEFINED

		case kSENSORS_EPuckCamera_Status_v:
#ifdef SENSORS_EPuckCamera_ControlStatus_DEFINED
		{
/** WB Ptr Class: SENSORS_EPuckCamera_Status @brief Nil */ 
			class SENSORS_EPuckCamera_Status_t m;
			return msg ? m.get_from(msg).description() : m.get().description();
		}
#else
			return "##unsupported##";

#endif // !SENSORS_EPuckCamera_ControlStatus_DEFINED

		case kSENSORS_EPuckGSM_Control_v:
#ifdef SENSORS_EPuckGSM_Control_DEFINED
		{
/** WB Ptr Class: SENSORS_EPuckGSM_Control @brief Nil */ 
			class SENSORS_EPuckGSM_Control_t m;
			return msg ? m.get_from(msg).description() : m.get().description();
		}
#else
			return "##unsupported##";

#endif // !SENSORS_EPuckGSM_Control_DEFINED

		case kSENSORS_EPuckGSM_Status_v:
#ifdef SENSORS_EPuckGSM_Status_DEFINED
		{
/** WB Ptr Class: SENSORS_EPuckGSM_Status @brief Nil */ 
			class SENSORS_EPuckGSM_Status_t m;
			return msg ? m.get_from(msg).description() : m.get().description();
		}
#else
			return "##unsupported##";

#endif // !SENSORS_EPuckGSM_Status_DEFINED

		case kSENSORS_EPuckLight_Control_v:
#ifdef SENSORS_EPuckLight_Control_DEFINED
		{
/** WB Ptr Class: SENSORS_EPuckLight_Control @brief Nil */ 
			class SENSORS_EPuckLight_Control_t m;
			return msg ? m.get_from(msg).description() : m.get().description();
		}
#else
			return "##unsupported##";

#endif // !SENSORS_EPuckLight_Control_DEFINED

		case kSENSORS_EPuckLight_Status_v:
#ifdef SENSORS_EPuckLight_Status_DEFINED
		{
/** WB Ptr Class: SENSORS_EPuckLight_Status @brief Nil */ 
			class SENSORS_EPuckLight_Status_t m;
			return msg ? m.get_from(msg).description() : m.get().description();
		}
#else
			return "##unsupported##";

#endif // !SENSORS_EPuckLight_Status_DEFINED

		case kSENSORS_EPuckProximity_Control_v:
#ifdef SENSORS_EPuckProximity_Control_DEFINED
		{
/** WB Ptr Class: SENSORS_EPuckProximity_Control @brief Nil */ 
			class SENSORS_EPuckProximity_Control_t m;
			return msg ? m.get_from(msg).description() : m.get().description();
		}
#else
			return "##unsupported##";

#endif // !SENSORS_EPuckProximity_Control_DEFINED

		case kSENSORS_EPuckProximity_Status_v:
#ifdef SENSORS_EPuckProximity_Status_DEFINED
		{
/** WB Ptr Class: SENSORS_EPuckProximity_Status @brief Nil */ 
			class SENSORS_EPuckProximity_Status_t m;
			return msg ? m.get_from(msg).description() : m.get().description();
		}
#else
			return "##unsupported##";

#endif // !SENSORS_EPuckProximity_Status_DEFINED

		case kDifferentialRobotControl_v:
#ifdef DifferentialRobotControlStatus_DEFINED
		{
/** WB Ptr Class: DifferentialRobotControl @brief Nil */ 
			class DifferentialRobotControl_t m;
			return msg ? m.get_from(msg).description() : m.get().description();
		}
#else
			return "##unsupported##";

#endif // !DifferentialRobotControlStatus_DEFINED

		case kDifferentialRobotStatus_v:
#ifdef DifferentialRobotControlStatus_DEFINED
		{
/** WB Ptr Class: DifferentialRobotStatus @brief Nil */ 
			class DifferentialRobotStatus_t m;
			return msg ? m.get_from(msg).description() : m.get().description();
		}
#else
			return "##unsupported##";

#endif // !DifferentialRobotControlStatus_DEFINED

		case kEMITTERS_EPuckLED_Control_v:
#ifdef EMITTERS_EPuckLED_ControlStatus_DEFINED
		{
/** WB Ptr Class: EMITTERS_EPuckLED_Control @brief Nil */ 
			class EMITTERS_EPuckLED_Control_t m;
			return msg ? m.get_from(msg).description() : m.get().description();
		}
#else
			return "##unsupported##";

#endif // !EMITTERS_EPuckLED_ControlStatus_DEFINED

		case kEMITTERS_EPuckLED_Status_v:
#ifdef EMITTERS_EPuckLED_ControlStatus_DEFINED
		{
/** WB Ptr Class: EMITTERS_EPuckLED_Status @brief Nil */ 
			class EMITTERS_EPuckLED_Status_t m;
			return msg ? m.get_from(msg).description() : m.get().description();
		}
#else
			return "##unsupported##";

#endif // !EMITTERS_EPuckLED_ControlStatus_DEFINED

		case kGOAL_Control_v:
#ifdef GOAL_Control_DEFINED
		{
/** WB Ptr Class: GOAL_Control @brief Nil */ 
			class GOAL_Control_t m;
			return msg ? m.get_from(msg).description() : m.get().description();
		}
#else
			return "##unsupported##";

#endif // !GOAL_Control_DEFINED

		case kGOAL_Status_v:
#ifdef GOAL_Status_DEFINED
		{
/** WB Ptr Class: GOAL_Status @brief Nil */ 
			class GOAL_Status_t m;
			return msg ? m.get_from(msg).description() : m.get().description();
		}
#else
			return "##unsupported##";

#endif // !GOAL_Status_DEFINED

		case kSENSORS_Intersection_Status_v:
#ifdef SENSORS_Intersection_Status_DEFINED
		{
/** WB Ptr Class: SENSORS_Intersection_Status @brief Nil */ 
			class SENSORS_Intersection_Status_t m;
			return msg ? m.get_from(msg).description() : m.get().description();
		}
#else
			return "##unsupported##";

#endif // !SENSORS_Intersection_Status_DEFINED

		case kDirection_Control_v:
#ifdef Direction_Control_DEFINED
		{
/** WB Ptr Class: Direction_Control @brief Nil */ 
			class Direction_Control_t m;
			return msg ? m.get_from(msg).description() : m.get().description();
		}
#else
			return "##unsupported##";

#endif // !Direction_Control_DEFINED

		case kSENSORS_Obstacle_On_Path_v:
#ifdef SENSORS_Obstacle_On_Path_DEFINED
		{
/** WB Ptr Class: SENSORS_Obstacle_On_Path @brief Nil */ 
			class SENSORS_Obstacle_On_Path_t m;
			return msg ? m.get_from(msg).description() : m.get().description();
		}
#else
			return "##unsupported##";

#endif // !SENSORS_Obstacle_On_Path_DEFINED

		case kAngle_v:
#ifdef Angle_DEFINED
		{
/** WB Ptr Class: Angle @brief Nil */ 
			class Angle_t m;
			return msg ? m.get_from(msg).description() : m.get().description();
		}
#else
			return "##unsupported##";

#endif // !Angle_DEFINED

		case kSENSORS_Obstacle_v:
#ifdef SENSORS_Obstacle_DEFINED
		{
/** WB Ptr Class: SENSORS_Obstacle @brief Nil */ 
			class SENSORS_Obstacle_t m;
			return msg ? m.get_from(msg).description() : m.get().description();
		}
#else
			return "##unsupported##";

#endif // !SENSORS_Obstacle_DEFINED

		case kCurrent_Position_v:
#ifdef Current_Position_DEFINED
		{
/** WB Ptr Class: Current_Position @brief Nil */ 
			class Current_Position_t m;
			return msg ? m.get_from(msg).description() : m.get().description();
		}
#else
			return "##unsupported##";

#endif // !Current_Position_DEFINED

		case kPlan_Planner_Settings_v:
#ifdef Plan_Planner_Settings_DEFINED
		{
/** WB Ptr Class: Plan_Planner_Settings @brief Nil */ 
			class Plan_Planner_Settings_t m;
			return msg ? m.get_from(msg).description() : m.get().description();
		}
#else
			return "##unsupported##";

#endif // !Plan_Planner_Settings_DEFINED

		case kPlan_Domain_Filename_v:
#ifdef Plan_Filename_DEFINED
		{
/** WB Ptr Class: Plan_Domain_Filename @brief Nil */ 
			class Plan_Domain_Filename_t m;
			return msg ? m.get_from(msg).description() : m.get().description();
		}
#else
			return "##unsupported##";

#endif // !Plan_Filename_DEFINED

		case kPlan_Problem_Filename_v:
#ifdef Plan_Filename_DEFINED
		{
/** WB Ptr Class: Plan_Problem_Filename @brief Nil */ 
			class Plan_Problem_Filename_t m;
			return msg ? m.get_from(msg).description() : m.get().description();
		}
#else
			return "##unsupported##";

#endif // !Plan_Filename_DEFINED

		case kPlan_Obstacles_Filename_v:
#ifdef Plan_Filename_DEFINED
		{
/** WB Ptr Class: Plan_Obstacles_Filename @brief Nil */ 
			class Plan_Obstacles_Filename_t m;
			return msg ? m.get_from(msg).description() : m.get().description();
		}
#else
			return "##unsupported##";

#endif // !Plan_Filename_DEFINED

		case kPlan_Plan_Filename_v:
#ifdef Plan_Filename_DEFINED
		{
/** WB Ptr Class: Plan_Plan_Filename @brief Nil */ 
			class Plan_Plan_Filename_t m;
			return msg ? m.get_from(msg).description() : m.get().description();
		}
#else
			return "##unsupported##";

#endif // !Plan_Filename_DEFINED

		case kPlan_Manager_Status_v:
#ifdef Plan_Control_Status_DEFINED
		{
/** WB Ptr Class: Plan_Manager_Status @brief Nil */ 
			class Plan_Manager_Status_t m;
			return msg ? m.get_from(msg).description() : m.get().description();
		}
#else
			return "##unsupported##";

#endif // !Plan_Control_Status_DEFINED

		case kPlan_Planner_Status_v:
#ifdef Plan_Control_Status_DEFINED
		{
/** WB Ptr Class: Plan_Planner_Status @brief Nil */ 
			class Plan_Planner_Status_t m;
			return msg ? m.get_from(msg).description() : m.get().description();
		}
#else
			return "##unsupported##";

#endif // !Plan_Control_Status_DEFINED

		case kPlan_Goal_List_v:
#ifdef Plan_Goal_List_DEFINED
		{
/** WB Ptr Class: Plan_Goal_List @brief Nil */ 
			class Plan_Goal_List_t m;
			return msg ? m.get_from(msg).description() : m.get().description();
		}
#else
			return "##unsupported##";

#endif // !Plan_Goal_List_DEFINED

		case kPlan_Obstacle_List_v:
#ifdef Plan_Obstacle_List_DEFINED
		{
/** WB Ptr Class: Plan_Obstacle_List @brief Nil */ 
			class Plan_Obstacle_List_t m;
			return msg ? m.get_from(msg).description() : m.get().description();
		}
#else
			return "##unsupported##";

#endif // !Plan_Obstacle_List_DEFINED

		case kEpuck_Test_Control_v:
#ifdef Epuck_Test_DEFINED
		{
/** WB Ptr Class: Epuck_Test_Control @brief Nil */ 
			class Epuck_Test_Control_t m;
			return msg ? m.get_from(msg).description() : m.get().description();
		}
#else
			return "##unsupported##";

#endif // !Epuck_Test_DEFINED

		case kEpuck_Test_Status_v:
#ifdef Epuck_Test_DEFINED
		{
/** WB Ptr Class: Epuck_Test_Status @brief Nil */ 
			class Epuck_Test_Status_t m;
			return msg ? m.get_from(msg).description() : m.get().description();
		}
#else
			return "##unsupported##";

#endif // !Epuck_Test_DEFINED

		case kEpuck_Test_Start_Up_v:
#ifdef Epuck_Test_DEFINED
		{
/** WB Ptr Class: Epuck_Test_Start_Up @brief Nil */ 
			class Epuck_Test_Start_Up_t m;
			return msg ? m.get_from(msg).description() : m.get().description();
		}
#else
			return "##unsupported##";

#endif // !Epuck_Test_DEFINED

	}
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunreachable-code"

	return "##unsupported##";
#pragma clang diagnostic pop
}

