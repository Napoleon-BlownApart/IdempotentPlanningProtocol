/** Auto-generated, don't modify! */

#include <string>
#include <vector>
#include <cstdlib>

#define WHITEBOARD_POSTER_STRING_CONVERSION

#include "guwhiteboardtypelist_generated.h"
#include "guwhiteboardposter.h"

using namespace std;
using namespace guWhiteboard;

extern "C"
{
	WBTypes whiteboard_type_for_message_named(const char *message_type)
	{
		return types_map[message_type];
	}


	bool whiteboard_post(const char *message_type, const char *message_content)
	{
		return whiteboard_postmsg(types_map[message_type], message_content);
	}


	bool whiteboard_postmsg(int message_index, const char *message_content)
	{
		return postmsg(WBTypes(message_index), message_content);
	}
} // extern C

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunused-function"

static vector<int> strtointvec(string str)
{
	const char *sep = "|,";
	char *context = NULL;
	vector<int> array;
	for (char *element = strtok_r(const_cast<char *>(str.c_str()), sep, &context); element; element = strtok_r(NULL, sep, &context))
		array.push_back(atoi(element));
	return array;
}

#pragma clang diagnostic pop

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wglobal-constructors"
#pragma clang diagnostic ignored "-Wexit-time-destructors"

whiteboard_types_map guWhiteboard::types_map; ///< global types map

#pragma clang diagnostic pop

bool guWhiteboard::post(string message_type, string message_content)
{
	return postmsg(types_map[message_type], message_content);
}


bool guWhiteboard::postmsg(WBTypes message_index, std::string message_content)
{
	switch (message_index)
	{
		case kwb_reserved_SubscribeToAllTypes_v:
			return false;

		case kPrint_v:
		{
/** WB Ptr Class: Print @brief Nil */ 
			class Print_t Print_msg;
			Print_msg.post(std::string(message_content));
			return true;
		}
		case kSay_v:
		{
/** WB Ptr Class: Say @brief Nil */ 
			class Say_t Say_msg;
			Say_msg.post(std::string(message_content));
			return true;
		}
		case kSpeech_v:
		{
/** WB Ptr Class: Speech @brief Nil */ 
			class Speech_t Speech_msg;
			Speech_msg.post(std::string(message_content));
			return true;
		}
		case kQSay_v:
		{
/** WB Ptr Class: QSay @brief Nil */ 
			class QSay_t QSay_msg;
			QSay_msg.post(std::string(message_content));
			return true;
		}
		case kQSpeech_v:
		{
/** WB Ptr Class: QSpeech @brief Nil */ 
			class QSpeech_t QSpeech_msg;
			QSpeech_msg.post(std::string(message_content));
			return true;
		}
		case kSpeechOutput_v:
		{
/** WB Ptr Class: SpeechOutput @brief Nil */ 
			class SpeechOutput_t SpeechOutput_msg;
			SpeechOutput_msg.post(atoi(message_content.c_str()));
			return true;
		}

		case kFSM_Control_v:
#ifdef FSMControlStatus_DEFINED
		{
/** WB Ptr Class: FSM_Control @brief Nil */ 
			class FSM_Control_t FSM_Control_msg;
			FSM_Control_msg.post(FSMControlStatus(message_content));
			return true;
		}
#else
			return false;
#endif // !FSMControlStatus_DEFINED

		case kFSM_Status_v:
#ifdef FSMControlStatus_DEFINED
		{
/** WB Ptr Class: FSM_Status @brief Nil */ 
			class FSM_Status_t FSM_Status_msg;
			FSM_Status_msg.post(FSMControlStatus(message_content));
			return true;
		}
#else
			return false;
#endif // !FSMControlStatus_DEFINED

		case kFSM_Names_v:
#ifdef FSMNames_DEFINED
		{
/** WB Ptr Class: FSM_Names @brief Nil */ 
			class FSM_Names_t FSM_Names_msg;
			FSM_Names_msg.post(FSMNames(message_content));
			return true;
		}
#else
			return false;
#endif // !FSMNames_DEFINED

		case kFSM_States_v:
#ifdef FSMState_DEFINED
		{
/** WB Ptr Class: FSM_States @brief Nil */ 
			class FSM_States_t FSM_States_msg;
			FSM_States_msg.post(FSMState(message_content));
			return true;
		}
#else
			return false;
#endif // !FSMState_DEFINED

		case kSENSORS_EPuckAccel_Control_v:
#ifdef SENSORS_EPuckAccel_Control_DEFINED
		{
/** WB Ptr Class: SENSORS_EPuckAccel_Control @brief Nil */ 
			class SENSORS_EPuckAccel_Control_t SENSORS_EPuckAccel_Control_msg;
			SENSORS_EPuckAccel_Control_msg.post(SENSORS_EPuckAccel_Control(message_content));
			return true;
		}
#else
			return false;
#endif // !SENSORS_EPuckAccel_Control_DEFINED

		case kSENSORS_EPuckAccel_Status_v:
#ifdef SENSORS_EPuckAccel_Status_DEFINED
		{
/** WB Ptr Class: SENSORS_EPuckAccel_Status @brief Nil */ 
			class SENSORS_EPuckAccel_Status_t SENSORS_EPuckAccel_Status_msg;
			SENSORS_EPuckAccel_Status_msg.post(SENSORS_EPuckAccel_Status(message_content));
			return true;
		}
#else
			return false;
#endif // !SENSORS_EPuckAccel_Status_DEFINED

		case kSENSORS_EPuckCamera_Control_v:
#ifdef SENSORS_EPuckCamera_ControlStatus_DEFINED
		{
/** WB Ptr Class: SENSORS_EPuckCamera_Control @brief Nil */ 
			class SENSORS_EPuckCamera_Control_t SENSORS_EPuckCamera_Control_msg;
			SENSORS_EPuckCamera_Control_msg.post(SENSORS_EPuckCamera_ControlStatus(message_content));
			return true;
		}
#else
			return false;
#endif // !SENSORS_EPuckCamera_ControlStatus_DEFINED

		case kSENSORS_EPuckCamera_Status_v:
#ifdef SENSORS_EPuckCamera_ControlStatus_DEFINED
		{
/** WB Ptr Class: SENSORS_EPuckCamera_Status @brief Nil */ 
			class SENSORS_EPuckCamera_Status_t SENSORS_EPuckCamera_Status_msg;
			SENSORS_EPuckCamera_Status_msg.post(SENSORS_EPuckCamera_ControlStatus(message_content));
			return true;
		}
#else
			return false;
#endif // !SENSORS_EPuckCamera_ControlStatus_DEFINED

		case kSENSORS_EPuckGSM_Control_v:
#ifdef SENSORS_EPuckGSM_Control_DEFINED
		{
/** WB Ptr Class: SENSORS_EPuckGSM_Control @brief Nil */ 
			class SENSORS_EPuckGSM_Control_t SENSORS_EPuckGSM_Control_msg;
			SENSORS_EPuckGSM_Control_msg.post(SENSORS_EPuckGSM_Control(message_content));
			return true;
		}
#else
			return false;
#endif // !SENSORS_EPuckGSM_Control_DEFINED

		case kSENSORS_EPuckGSM_Status_v:
#ifdef SENSORS_EPuckGSM_Status_DEFINED
		{
/** WB Ptr Class: SENSORS_EPuckGSM_Status @brief Nil */ 
			class SENSORS_EPuckGSM_Status_t SENSORS_EPuckGSM_Status_msg;
			SENSORS_EPuckGSM_Status_msg.post(SENSORS_EPuckGSM_Status(message_content));
			return true;
		}
#else
			return false;
#endif // !SENSORS_EPuckGSM_Status_DEFINED

		case kSENSORS_EPuckLight_Control_v:
#ifdef SENSORS_EPuckLight_Control_DEFINED
		{
/** WB Ptr Class: SENSORS_EPuckLight_Control @brief Nil */ 
			class SENSORS_EPuckLight_Control_t SENSORS_EPuckLight_Control_msg;
			SENSORS_EPuckLight_Control_msg.post(SENSORS_EPuckLight_Control(message_content));
			return true;
		}
#else
			return false;
#endif // !SENSORS_EPuckLight_Control_DEFINED

		case kSENSORS_EPuckLight_Status_v:
#ifdef SENSORS_EPuckLight_Status_DEFINED
		{
/** WB Ptr Class: SENSORS_EPuckLight_Status @brief Nil */ 
			class SENSORS_EPuckLight_Status_t SENSORS_EPuckLight_Status_msg;
			SENSORS_EPuckLight_Status_msg.post(SENSORS_EPuckLight_Status(message_content));
			return true;
		}
#else
			return false;
#endif // !SENSORS_EPuckLight_Status_DEFINED

		case kSENSORS_EPuckProximity_Control_v:
#ifdef SENSORS_EPuckProximity_Control_DEFINED
		{
/** WB Ptr Class: SENSORS_EPuckProximity_Control @brief Nil */ 
			class SENSORS_EPuckProximity_Control_t SENSORS_EPuckProximity_Control_msg;
			SENSORS_EPuckProximity_Control_msg.post(SENSORS_EPuckProximity_Control(message_content));
			return true;
		}
#else
			return false;
#endif // !SENSORS_EPuckProximity_Control_DEFINED

		case kSENSORS_EPuckProximity_Status_v:
#ifdef SENSORS_EPuckProximity_Status_DEFINED
		{
/** WB Ptr Class: SENSORS_EPuckProximity_Status @brief Nil */ 
			class SENSORS_EPuckProximity_Status_t SENSORS_EPuckProximity_Status_msg;
			SENSORS_EPuckProximity_Status_msg.post(SENSORS_EPuckProximity_Status(message_content));
			return true;
		}
#else
			return false;
#endif // !SENSORS_EPuckProximity_Status_DEFINED

		case kDifferentialRobotControl_v:
#ifdef DifferentialRobotControlStatus_DEFINED
		{
/** WB Ptr Class: DifferentialRobotControl @brief Nil */ 
			class DifferentialRobotControl_t DifferentialRobotControl_msg;
			DifferentialRobotControl_msg.post(DifferentialRobotControlStatus(message_content));
			return true;
		}
#else
			return false;
#endif // !DifferentialRobotControlStatus_DEFINED

		case kDifferentialRobotStatus_v:
#ifdef DifferentialRobotControlStatus_DEFINED
		{
/** WB Ptr Class: DifferentialRobotStatus @brief Nil */ 
			class DifferentialRobotStatus_t DifferentialRobotStatus_msg;
			DifferentialRobotStatus_msg.post(DifferentialRobotControlStatus(message_content));
			return true;
		}
#else
			return false;
#endif // !DifferentialRobotControlStatus_DEFINED

		case kEMITTERS_EPuckLED_Control_v:
#ifdef EMITTERS_EPuckLED_ControlStatus_DEFINED
		{
/** WB Ptr Class: EMITTERS_EPuckLED_Control @brief Nil */ 
			class EMITTERS_EPuckLED_Control_t EMITTERS_EPuckLED_Control_msg;
			EMITTERS_EPuckLED_Control_msg.post(EMITTERS_EPuckLED_ControlStatus(message_content));
			return true;
		}
#else
			return false;
#endif // !EMITTERS_EPuckLED_ControlStatus_DEFINED

		case kEMITTERS_EPuckLED_Status_v:
#ifdef EMITTERS_EPuckLED_ControlStatus_DEFINED
		{
/** WB Ptr Class: EMITTERS_EPuckLED_Status @brief Nil */ 
			class EMITTERS_EPuckLED_Status_t EMITTERS_EPuckLED_Status_msg;
			EMITTERS_EPuckLED_Status_msg.post(EMITTERS_EPuckLED_ControlStatus(message_content));
			return true;
		}
#else
			return false;
#endif // !EMITTERS_EPuckLED_ControlStatus_DEFINED

		case kGOAL_Control_v:
#ifdef GOAL_Control_DEFINED
		{
/** WB Ptr Class: GOAL_Control @brief Nil */ 
			class GOAL_Control_t GOAL_Control_msg;
			GOAL_Control_msg.post(GOAL_Control(message_content));
			return true;
		}
#else
			return false;
#endif // !GOAL_Control_DEFINED

		case kGOAL_Status_v:
#ifdef GOAL_Status_DEFINED
		{
/** WB Ptr Class: GOAL_Status @brief Nil */ 
			class GOAL_Status_t GOAL_Status_msg;
			GOAL_Status_msg.post(GOAL_Status(message_content));
			return true;
		}
#else
			return false;
#endif // !GOAL_Status_DEFINED

		case kSENSORS_Intersection_Status_v:
#ifdef SENSORS_Intersection_Status_DEFINED
		{
/** WB Ptr Class: SENSORS_Intersection_Status @brief Nil */ 
			class SENSORS_Intersection_Status_t SENSORS_Intersection_Status_msg;
			SENSORS_Intersection_Status_msg.post(SENSORS_Intersection_Status(message_content));
			return true;
		}
#else
			return false;
#endif // !SENSORS_Intersection_Status_DEFINED

		case kDirection_Control_v:
#ifdef Direction_Control_DEFINED
		{
/** WB Ptr Class: Direction_Control @brief Nil */ 
			class Direction_Control_t Direction_Control_msg;
			Direction_Control_msg.post(Direction_Control(message_content));
			return true;
		}
#else
			return false;
#endif // !Direction_Control_DEFINED

		case kSENSORS_Obstacle_On_Path_v:
#ifdef SENSORS_Obstacle_On_Path_DEFINED
		{
/** WB Ptr Class: SENSORS_Obstacle_On_Path @brief Nil */ 
			class SENSORS_Obstacle_On_Path_t SENSORS_Obstacle_On_Path_msg;
			SENSORS_Obstacle_On_Path_msg.post(SENSORS_Obstacle_On_Path(message_content));
			return true;
		}
#else
			return false;
#endif // !SENSORS_Obstacle_On_Path_DEFINED

		case kAngle_v:
#ifdef Angle_DEFINED
		{
/** WB Ptr Class: Angle @brief Nil */ 
			class Angle_t Angle_msg;
			Angle_msg.post(Angle(message_content));
			return true;
		}
#else
			return false;
#endif // !Angle_DEFINED

		case kSENSORS_Obstacle_v:
#ifdef SENSORS_Obstacle_DEFINED
		{
/** WB Ptr Class: SENSORS_Obstacle @brief Nil */ 
			class SENSORS_Obstacle_t SENSORS_Obstacle_msg;
			SENSORS_Obstacle_msg.post(SENSORS_Obstacle(message_content));
			return true;
		}
#else
			return false;
#endif // !SENSORS_Obstacle_DEFINED

		case kCurrent_Position_v:
#ifdef Current_Position_DEFINED
		{
/** WB Ptr Class: Current_Position @brief Nil */ 
			class Current_Position_t Current_Position_msg;
			Current_Position_msg.post(Current_Position(message_content));
			return true;
		}
#else
			return false;
#endif // !Current_Position_DEFINED

		case kPlan_Planner_Settings_v:
#ifdef Plan_Planner_Settings_DEFINED
		{
/** WB Ptr Class: Plan_Planner_Settings @brief Nil */ 
			class Plan_Planner_Settings_t Plan_Planner_Settings_msg;
			Plan_Planner_Settings_msg.post(Plan_Planner_Settings(message_content));
			return true;
		}
#else
			return false;
#endif // !Plan_Planner_Settings_DEFINED

		case kPlan_Domain_Filename_v:
#ifdef Plan_Filename_DEFINED
		{
/** WB Ptr Class: Plan_Domain_Filename @brief Nil */ 
			class Plan_Domain_Filename_t Plan_Domain_Filename_msg;
			Plan_Domain_Filename_msg.post(Plan_Filename(message_content));
			return true;
		}
#else
			return false;
#endif // !Plan_Filename_DEFINED

		case kPlan_Problem_Filename_v:
#ifdef Plan_Filename_DEFINED
		{
/** WB Ptr Class: Plan_Problem_Filename @brief Nil */ 
			class Plan_Problem_Filename_t Plan_Problem_Filename_msg;
			Plan_Problem_Filename_msg.post(Plan_Filename(message_content));
			return true;
		}
#else
			return false;
#endif // !Plan_Filename_DEFINED

		case kPlan_Obstacles_Filename_v:
#ifdef Plan_Filename_DEFINED
		{
/** WB Ptr Class: Plan_Obstacles_Filename @brief Nil */ 
			class Plan_Obstacles_Filename_t Plan_Obstacles_Filename_msg;
			Plan_Obstacles_Filename_msg.post(Plan_Filename(message_content));
			return true;
		}
#else
			return false;
#endif // !Plan_Filename_DEFINED

		case kPlan_Plan_Filename_v:
#ifdef Plan_Filename_DEFINED
		{
/** WB Ptr Class: Plan_Plan_Filename @brief Nil */ 
			class Plan_Plan_Filename_t Plan_Plan_Filename_msg;
			Plan_Plan_Filename_msg.post(Plan_Filename(message_content));
			return true;
		}
#else
			return false;
#endif // !Plan_Filename_DEFINED

		case kPlan_Manager_Status_v:
#ifdef Plan_Control_Status_DEFINED
		{
/** WB Ptr Class: Plan_Manager_Status @brief Nil */ 
			class Plan_Manager_Status_t Plan_Manager_Status_msg;
			Plan_Manager_Status_msg.post(Plan_Control_Status(message_content));
			return true;
		}
#else
			return false;
#endif // !Plan_Control_Status_DEFINED

		case kPlan_Planner_Status_v:
#ifdef Plan_Control_Status_DEFINED
		{
/** WB Ptr Class: Plan_Planner_Status @brief Nil */ 
			class Plan_Planner_Status_t Plan_Planner_Status_msg;
			Plan_Planner_Status_msg.post(Plan_Control_Status(message_content));
			return true;
		}
#else
			return false;
#endif // !Plan_Control_Status_DEFINED

		case kPlan_Goal_List_v:
#ifdef Plan_Goal_List_DEFINED
		{
/** WB Ptr Class: Plan_Goal_List @brief Nil */ 
			class Plan_Goal_List_t Plan_Goal_List_msg;
			Plan_Goal_List_msg.post(Plan_Goal_List(message_content));
			return true;
		}
#else
			return false;
#endif // !Plan_Goal_List_DEFINED

		case kPlan_Obstacle_List_v:
#ifdef Plan_Obstacle_List_DEFINED
		{
/** WB Ptr Class: Plan_Obstacle_List @brief Nil */ 
			class Plan_Obstacle_List_t Plan_Obstacle_List_msg;
			Plan_Obstacle_List_msg.post(Plan_Obstacle_List(message_content));
			return true;
		}
#else
			return false;
#endif // !Plan_Obstacle_List_DEFINED

		case kEpuck_Test_Control_v:
#ifdef Epuck_Test_DEFINED
		{
/** WB Ptr Class: Epuck_Test_Control @brief Nil */ 
			class Epuck_Test_Control_t Epuck_Test_Control_msg;
			Epuck_Test_Control_msg.post(Epuck_Test(message_content));
			return true;
		}
#else
			return false;
#endif // !Epuck_Test_DEFINED

		case kEpuck_Test_Status_v:
#ifdef Epuck_Test_DEFINED
		{
/** WB Ptr Class: Epuck_Test_Status @brief Nil */ 
			class Epuck_Test_Status_t Epuck_Test_Status_msg;
			Epuck_Test_Status_msg.post(Epuck_Test(message_content));
			return true;
		}
#else
			return false;
#endif // !Epuck_Test_DEFINED

		case kEpuck_Test_Start_Up_v:
#ifdef Epuck_Test_DEFINED
		{
/** WB Ptr Class: Epuck_Test_Start_Up @brief Nil */ 
			class Epuck_Test_Start_Up_t Epuck_Test_Start_Up_msg;
			Epuck_Test_Start_Up_msg.post(Epuck_Test(message_content));
			return true;
		}
#else
			return false;
#endif // !Epuck_Test_DEFINED

	}
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunreachable-code"

	return false;
#pragma clang diagnostic pop
}

whiteboard_types_map::whiteboard_types_map(): map<string, WBTypes>()
{
	whiteboard_types_map &self = *this;
	// self.reserve(45);

	self["*"] = kwb_reserved_SubscribeToAllTypes_v;
	self["Print"] = kPrint_v;
	self["Say"] = kSay_v;
	self["Speech"] = kSpeech_v;
	self["QSay"] = kQSay_v;
	self["QSpeech"] = kQSpeech_v;
	self["SpeechOutput"] = kSpeechOutput_v;
	self["fsm_control"] = kFSM_Control_v;
	self["fsm_status"] = kFSM_Status_v;
	self["fsm_names"] = kFSM_Names_v;
	self["fsm_states"] = kFSM_States_v;
	self["EPuckAccel_Control"] = kSENSORS_EPuckAccel_Control_v;
	self["EPuckAccel_Status"] = kSENSORS_EPuckAccel_Status_v;
	self["EPuckCamera_Control"] = kSENSORS_EPuckCamera_Control_v;
	self["EPuckCamera_Status"] = kSENSORS_EPuckCamera_Status_v;
	self["EPuckGSM_Control"] = kSENSORS_EPuckGSM_Control_v;
	self["EPuckGSM_Status"] = kSENSORS_EPuckGSM_Status_v;
	self["EPuckLight_Control"] = kSENSORS_EPuckLight_Control_v;
	self["EPuckLight_Status"] = kSENSORS_EPuckLight_Status_v;
	self["EPuckProximity_Control"] = kSENSORS_EPuckProximity_Control_v;
	self["EPuckProximity_Status"] = kSENSORS_EPuckProximity_Status_v;
	self["DifferentialRobotControl"] = kDifferentialRobotControl_v;
	self["DifferentialRobotStatus"] = kDifferentialRobotStatus_v;
	self["EPuckLED_Control"] = kEMITTERS_EPuckLED_Control_v;
	self["EPuckLED_Status"] = kEMITTERS_EPuckLED_Status_v;
	self["GOAL_Control"] = kGOAL_Control_v;
	self["GOAL_Status"] = kGOAL_Status_v;
	self["Intersection_Status"] = kSENSORS_Intersection_Status_v;
	self["Direction_Control"] = kDirection_Control_v;
	self["Obstacle_On_Path"] = kSENSORS_Obstacle_On_Path_v;
	self["Angle"] = kAngle_v;
	self["Obstacle"] = kSENSORS_Obstacle_v;
	self["Current_Position"] = kCurrent_Position_v;
	self["Plan_Planner_Settings"] = kPlan_Planner_Settings_v;
	self["Plan_Domain_Filename"] = kPlan_Domain_Filename_v;
	self["Plan_Problem_Filename"] = kPlan_Problem_Filename_v;
	self["Plan_Obstacles_Filename"] = kPlan_Obstacles_Filename_v;
	self["Plan_Plan_Filename"] = kPlan_Plan_Filename_v;
	self["Manager_Status"] = kPlan_Manager_Status_v;
	self["Planner_Status"] = kPlan_Planner_Status_v;
	self["Plan_Goal_List"] = kPlan_Goal_List_v;
	self["Plan_Obstacle_List"] = kPlan_Obstacle_List_v;
	self["Epuck_Test_Control"] = kEpuck_Test_Control_v;
	self["Epuck_Test_Status"] = kEpuck_Test_Status_v;
	self["Epuck_Test_Start_Up"] = kEpuck_Test_Start_Up_v;
}

