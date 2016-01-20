/**                                                                     
 *  /file guwhiteboardtypelist_generated.h                              
 *                                                                      
 *  Created by Carl Lusty in 2013.                                      
 *  Copyright (c) 2013 Carl Lusty                                       
 *  All rights reserved.                                                
 */                                                                     
                                                                        
                                                                        
#ifndef _GUWHITEBOARD_TYPELIST_H_                                       
#define _GUWHITEBOARD_TYPELIST_H_                                       
                                                                        
#include "gugenericwhiteboardobject.h"                                
                                                                        
#pragma clang diagnostic push                                           
#pragma clang diagnostic ignored "-Wpadded"                           
                                                                        
                                                                        
//Generated on: Wed Jan 20 00:03:35 2016
//Generated by user: nap

namespace guWhiteboard                                                  
{                                                                       
                                                                        
extern "C"                                                            
{                                                                       
#include "guwhiteboardtypelist_c_generated.h"                         
}                                                                       
                                                                        
	/** WB Ptr Class: Print @brief print to stdout */ 
        class Print_t: public generic_whiteboard_object<std::string > { 
	public: 
		/** Constructor: Print */ 
		Print_t(gu_simple_whiteboard_descriptor *wbd = NULL): generic_whiteboard_object<std::string >(wbd, kPrint_v, true) {}
		/** Constructor: Print */ 
		Print_t(std::string value, gu_simple_whiteboard_descriptor *wbd = NULL): generic_whiteboard_object<std::string >(value, kPrint_v, wbd, true) {} 
	};

	/** WB Ptr Class: Say @brief speech output message */ 
        class Say_t: public generic_whiteboard_object<std::string > { 
	public: 
		/** Constructor: Say */ 
		Say_t(gu_simple_whiteboard_descriptor *wbd = NULL): generic_whiteboard_object<std::string >(wbd, kSay_v, true) {}
		/** Constructor: Say */ 
		Say_t(std::string value, gu_simple_whiteboard_descriptor *wbd = NULL): generic_whiteboard_object<std::string >(value, kSay_v, wbd, true) {} 
	};

	/** WB Ptr Class: Speech @brief debug speech message */ 
        class Speech_t: public generic_whiteboard_object<std::string > { 
	public: 
		/** Constructor: Speech */ 
		Speech_t(gu_simple_whiteboard_descriptor *wbd = NULL): generic_whiteboard_object<std::string >(wbd, kSpeech_v, true) {}
		/** Constructor: Speech */ 
		Speech_t(std::string value, gu_simple_whiteboard_descriptor *wbd = NULL): generic_whiteboard_object<std::string >(value, kSpeech_v, wbd, true) {} 
	};

	/** WB Ptr Class: QSay @brief speech output message (queued) */ 
        class QSay_t: public generic_whiteboard_object<std::string > { 
	public: 
		/** Constructor: QSay */ 
		QSay_t(gu_simple_whiteboard_descriptor *wbd = NULL): generic_whiteboard_object<std::string >(wbd, kQSay_v, true) {}
		/** Constructor: QSay */ 
		QSay_t(std::string value, gu_simple_whiteboard_descriptor *wbd = NULL): generic_whiteboard_object<std::string >(value, kQSay_v, wbd, true) {} 
	};

	/** WB Ptr Class: QSpeech @brief debug speech message (queued) */ 
        class QSpeech_t: public generic_whiteboard_object<std::string > { 
	public: 
		/** Constructor: QSpeech */ 
		QSpeech_t(gu_simple_whiteboard_descriptor *wbd = NULL): generic_whiteboard_object<std::string >(wbd, kQSpeech_v, true) {}
		/** Constructor: QSpeech */ 
		QSpeech_t(std::string value, gu_simple_whiteboard_descriptor *wbd = NULL): generic_whiteboard_object<std::string >(value, kQSpeech_v, wbd, true) {} 
	};

	/** WB Ptr Class: SpeechOutput @brief toggle, treat speech messages as silent output unless this is turned on */ 
        class SpeechOutput_t: public generic_whiteboard_object<bool > { 
	public: 
		/** Constructor: SpeechOutput */ 
		SpeechOutput_t(gu_simple_whiteboard_descriptor *wbd = NULL): generic_whiteboard_object<bool >(wbd, kSpeechOutput_v, false) {}
		/** Constructor: SpeechOutput */ 
		SpeechOutput_t(bool value, gu_simple_whiteboard_descriptor *wbd = NULL): generic_whiteboard_object<bool >(value, kSpeechOutput_v, wbd, false) {} 
	};

	/** WB Ptr Class: FSM_Control @brief Suspend, Resume, or Restart a finite state machine (clfsm) */ 

        class FSM_Control_t: public generic_whiteboard_object<class FSMControlStatus > { 
	public: 
		/** Constructor: FSM_Control */ 
		FSM_Control_t(gu_simple_whiteboard_descriptor *wbd = NULL) : generic_whiteboard_object<class FSMControlStatus >(wbd, kFSM_Control_v, true) {} 
	};

	/** WB Ptr Class: FSM_Status @brief Current status indicating the suspended state of all FSMs.  The highest bit that is always set is the number of machines plus one. */ 

        class FSM_Status_t: public generic_whiteboard_object<class FSMControlStatus > { 
	public: 
		/** Constructor: FSM_Status */ 
		FSM_Status_t(gu_simple_whiteboard_descriptor *wbd = NULL) : generic_whiteboard_object<class FSMControlStatus >(wbd, kFSM_Status_v, true) {} 
	};

	/** WB Ptr Class: FSM_Names @brief Request or return the names of the currently loaded FSMs.  End of list is denoted by an empty string.  Requests need to put an empty string into the first FSM name; */ 

        class FSM_Names_t: public generic_whiteboard_object<class FSMNames > { 
	public: 
		/** Constructor: FSM_Names */ 
		FSM_Names_t(gu_simple_whiteboard_descriptor *wbd = NULL) : generic_whiteboard_object<class FSMNames >(wbd, kFSM_Names_v, true) {} 
	};

	/** WB Ptr Class: FSM_States @brief Idempotent Message publicising the state -about to be executed- (0-254) of up-to the first 128 machines (0-127).  State -INVALDMACHINE- (255) is posted for MachineIDs that are not currently loaded. */ 

        class FSM_States_t: public generic_whiteboard_object<class FSMState > { 
	public: 
		/** Constructor: FSM_States */ 
		FSM_States_t(gu_simple_whiteboard_descriptor *wbd = NULL) : generic_whiteboard_object<class FSMState >(wbd, kFSM_States_v, true) {} 
	};

	/** WB Ptr Class: SENSORS_EPuckAccel_Control @brief Controls which accelerometer sensors are on/off */ 

        class SENSORS_EPuckAccel_Control_t: public generic_whiteboard_object<class SENSORS_EPuckAccel_Control > { 
	public: 
		/** Constructor: SENSORS_EPuckAccel_Control */ 
		SENSORS_EPuckAccel_Control_t(gu_simple_whiteboard_descriptor *wbd = NULL) : generic_whiteboard_object<class SENSORS_EPuckAccel_Control >(wbd, kSENSORS_EPuckAccel_Control_v, false) {} 
	};

	/** WB Ptr Class: SENSORS_EPuckAccel_Status @brief Reports status of accelerometers (on/off & value) */ 

        class SENSORS_EPuckAccel_Status_t: public generic_whiteboard_object<class SENSORS_EPuckAccel_Status > { 
	public: 
		/** Constructor: SENSORS_EPuckAccel_Status */ 
		SENSORS_EPuckAccel_Status_t(gu_simple_whiteboard_descriptor *wbd = NULL) : generic_whiteboard_object<class SENSORS_EPuckAccel_Status >(wbd, kSENSORS_EPuckAccel_Status_v, false) {} 
	};

	/** WB Ptr Class: SENSORS_EPuckCamera_Control @brief Controls Camera Settings */ 

        class SENSORS_EPuckCamera_Control_t: public generic_whiteboard_object<class SENSORS_EPuckCamera_ControlStatus > { 
	public: 
		/** Constructor: SENSORS_EPuckCamera_Control */ 
		SENSORS_EPuckCamera_Control_t(gu_simple_whiteboard_descriptor *wbd = NULL) : generic_whiteboard_object<class SENSORS_EPuckCamera_ControlStatus >(wbd, kSENSORS_EPuckCamera_Control_v, false) {} 
	};

	/** WB Ptr Class: SENSORS_EPuckCamera_Status @brief Reports Camera data */ 

        class SENSORS_EPuckCamera_Status_t: public generic_whiteboard_object<class SENSORS_EPuckCamera_ControlStatus > { 
	public: 
		/** Constructor: SENSORS_EPuckCamera_Status */ 
		SENSORS_EPuckCamera_Status_t(gu_simple_whiteboard_descriptor *wbd = NULL) : generic_whiteboard_object<class SENSORS_EPuckCamera_ControlStatus >(wbd, kSENSORS_EPuckCamera_Status_v, false) {} 
	};

	/** WB Ptr Class: SENSORS_EPuckGSM_Control @brief Controls which accelerometer sensors are on/off */ 

        class SENSORS_EPuckGSM_Control_t: public generic_whiteboard_object<class SENSORS_EPuckGSM_Control > { 
	public: 
		/** Constructor: SENSORS_EPuckGSM_Control */ 
		SENSORS_EPuckGSM_Control_t(gu_simple_whiteboard_descriptor *wbd = NULL) : generic_whiteboard_object<class SENSORS_EPuckGSM_Control >(wbd, kSENSORS_EPuckGSM_Control_v, false) {} 
	};

	/** WB Ptr Class: SENSORS_EPuckGSM_Status @brief Reports status of accelerometers (on/off & value) */ 

        class SENSORS_EPuckGSM_Status_t: public generic_whiteboard_object<class SENSORS_EPuckGSM_Status > { 
	public: 
		/** Constructor: SENSORS_EPuckGSM_Status */ 
		SENSORS_EPuckGSM_Status_t(gu_simple_whiteboard_descriptor *wbd = NULL) : generic_whiteboard_object<class SENSORS_EPuckGSM_Status >(wbd, kSENSORS_EPuckGSM_Status_v, false) {} 
	};

	/** WB Ptr Class: SENSORS_EPuckLight_Control @brief Controls which accelerometer sensors are on/off */ 

        class SENSORS_EPuckLight_Control_t: public generic_whiteboard_object<class SENSORS_EPuckLight_Control > { 
	public: 
		/** Constructor: SENSORS_EPuckLight_Control */ 
		SENSORS_EPuckLight_Control_t(gu_simple_whiteboard_descriptor *wbd = NULL) : generic_whiteboard_object<class SENSORS_EPuckLight_Control >(wbd, kSENSORS_EPuckLight_Control_v, false) {} 
	};

	/** WB Ptr Class: SENSORS_EPuckLight_Status @brief Reports status of accelerometers (on/off & value) */ 

        class SENSORS_EPuckLight_Status_t: public generic_whiteboard_object<class SENSORS_EPuckLight_Status > { 
	public: 
		/** Constructor: SENSORS_EPuckLight_Status */ 
		SENSORS_EPuckLight_Status_t(gu_simple_whiteboard_descriptor *wbd = NULL) : generic_whiteboard_object<class SENSORS_EPuckLight_Status >(wbd, kSENSORS_EPuckLight_Status_v, false) {} 
	};

	/** WB Ptr Class: SENSORS_EPuckProximity_Control @brief Controls which accelerometer sensors are on/off */ 

        class SENSORS_EPuckProximity_Control_t: public generic_whiteboard_object<class SENSORS_EPuckProximity_Control > { 
	public: 
		/** Constructor: SENSORS_EPuckProximity_Control */ 
		SENSORS_EPuckProximity_Control_t(gu_simple_whiteboard_descriptor *wbd = NULL) : generic_whiteboard_object<class SENSORS_EPuckProximity_Control >(wbd, kSENSORS_EPuckProximity_Control_v, false) {} 
	};

	/** WB Ptr Class: SENSORS_EPuckProximity_Status @brief Reports status of accelerometers (on/off & value) */ 

        class SENSORS_EPuckProximity_Status_t: public generic_whiteboard_object<class SENSORS_EPuckProximity_Status > { 
	public: 
		/** Constructor: SENSORS_EPuckProximity_Status */ 
		SENSORS_EPuckProximity_Status_t(gu_simple_whiteboard_descriptor *wbd = NULL) : generic_whiteboard_object<class SENSORS_EPuckProximity_Status >(wbd, kSENSORS_EPuckProximity_Status_v, false) {} 
	};

	/** WB Ptr Class: DifferentialRobotControl @brief Controls Differential Motors */ 

        class DifferentialRobotControl_t: public generic_whiteboard_object<class DifferentialRobotControlStatus > { 
	public: 
		/** Constructor: DifferentialRobotControl */ 
		DifferentialRobotControl_t(gu_simple_whiteboard_descriptor *wbd = NULL) : generic_whiteboard_object<class DifferentialRobotControlStatus >(wbd, kDifferentialRobotControl_v, false) {} 
	};

	/** WB Ptr Class: DifferentialRobotStatus @brief Reports status of Differential Motors */ 

        class DifferentialRobotStatus_t: public generic_whiteboard_object<class DifferentialRobotControlStatus > { 
	public: 
		/** Constructor: DifferentialRobotStatus */ 
		DifferentialRobotStatus_t(gu_simple_whiteboard_descriptor *wbd = NULL) : generic_whiteboard_object<class DifferentialRobotControlStatus >(wbd, kDifferentialRobotStatus_v, false) {} 
	};

	/** WB Ptr Class: EMITTERS_EPuckLED_Control @brief Controls which LED Emitters are on/off and what intensity */ 

        class EMITTERS_EPuckLED_Control_t: public generic_whiteboard_object<class EMITTERS_EPuckLED_ControlStatus > { 
	public: 
		/** Constructor: EMITTERS_EPuckLED_Control */ 
		EMITTERS_EPuckLED_Control_t(gu_simple_whiteboard_descriptor *wbd = NULL) : generic_whiteboard_object<class EMITTERS_EPuckLED_ControlStatus >(wbd, kEMITTERS_EPuckLED_Control_v, false) {} 
	};

	/** WB Ptr Class: EMITTERS_EPuckLED_Status @brief Reports status of LED Emitters (on/off & intensity) */ 

        class EMITTERS_EPuckLED_Status_t: public generic_whiteboard_object<class EMITTERS_EPuckLED_ControlStatus > { 
	public: 
		/** Constructor: EMITTERS_EPuckLED_Status */ 
		EMITTERS_EPuckLED_Status_t(gu_simple_whiteboard_descriptor *wbd = NULL) : generic_whiteboard_object<class EMITTERS_EPuckLED_ControlStatus >(wbd, kEMITTERS_EPuckLED_Status_v, false) {} 
	};

	/** WB Ptr Class: GOAL_Control @brief GOAL Control Message */ 

        class GOAL_Control_t: public generic_whiteboard_object<class GOAL_Control > { 
	public: 
		/** Constructor: GOAL_Control */ 
		GOAL_Control_t(gu_simple_whiteboard_descriptor *wbd = NULL) : generic_whiteboard_object<class GOAL_Control >(wbd, kGOAL_Control_v, false) {} 
	};

	/** WB Ptr Class: GOAL_Status @brief GOAL Status Message */ 

        class GOAL_Status_t: public generic_whiteboard_object<class GOAL_Status > { 
	public: 
		/** Constructor: GOAL_Status */ 
		GOAL_Status_t(gu_simple_whiteboard_descriptor *wbd = NULL) : generic_whiteboard_object<class GOAL_Status >(wbd, kGOAL_Status_v, false) {} 
	};

	/** WB Ptr Class: SENSORS_Intersection_Status @brief Intersection Status Message */ 

        class SENSORS_Intersection_Status_t: public generic_whiteboard_object<class SENSORS_Intersection_Status > { 
	public: 
		/** Constructor: SENSORS_Intersection_Status */ 
		SENSORS_Intersection_Status_t(gu_simple_whiteboard_descriptor *wbd = NULL) : generic_whiteboard_object<class SENSORS_Intersection_Status >(wbd, kSENSORS_Intersection_Status_v, false) {} 
	};

	/** WB Ptr Class: Direction_Control @brief Direction Control (which way to go F/L/R/AR/AL) */ 

        class Direction_Control_t: public generic_whiteboard_object<class Direction_Control > { 
	public: 
		/** Constructor: Direction_Control */ 
		Direction_Control_t(gu_simple_whiteboard_descriptor *wbd = NULL) : generic_whiteboard_object<class Direction_Control >(wbd, kDirection_Control_v, false) {} 
	};

	/** WB Ptr Class: SENSORS_Obstacle_On_Path @brief Obstacle On Path (true between detecting it and returning to intersection) */ 

        class SENSORS_Obstacle_On_Path_t: public generic_whiteboard_object<class SENSORS_Obstacle_On_Path > { 
	public: 
		/** Constructor: SENSORS_Obstacle_On_Path */ 
		SENSORS_Obstacle_On_Path_t(gu_simple_whiteboard_descriptor *wbd = NULL) : generic_whiteboard_object<class SENSORS_Obstacle_On_Path >(wbd, kSENSORS_Obstacle_On_Path_v, false) {} 
	};

	/** WB Ptr Class: Angle @brief Angle of the epuck (0 = North) */ 

        class Angle_t: public generic_whiteboard_object<class Angle > { 
	public: 
		/** Constructor: Angle */ 
		Angle_t(gu_simple_whiteboard_descriptor *wbd = NULL) : generic_whiteboard_object<class Angle >(wbd, kAngle_v, false) {} 
	};

	/** WB Ptr Class: SENSORS_Obstacle @brief Obstacle (true only while the obstacle is there) */ 

        class SENSORS_Obstacle_t: public generic_whiteboard_object<class SENSORS_Obstacle > { 
	public: 
		/** Constructor: SENSORS_Obstacle */ 
		SENSORS_Obstacle_t(gu_simple_whiteboard_descriptor *wbd = NULL) : generic_whiteboard_object<class SENSORS_Obstacle >(wbd, kSENSORS_Obstacle_v, false) {} 
	};

	/** WB Ptr Class: Current_Position @brief Current Position */ 

        class Current_Position_t: public generic_whiteboard_object<class Current_Position > { 
	public: 
		/** Constructor: Current_Position */ 
		Current_Position_t(gu_simple_whiteboard_descriptor *wbd = NULL) : generic_whiteboard_object<class Current_Position >(wbd, kCurrent_Position_v, false) {} 
	};

	/** WB Ptr Class: Plan_Planner_Settings @brief Planner Settings */ 

        class Plan_Planner_Settings_t: public generic_whiteboard_object<class Plan_Planner_Settings > { 
	public: 
		/** Constructor: Plan_Planner_Settings */ 
		Plan_Planner_Settings_t(gu_simple_whiteboard_descriptor *wbd = NULL) : generic_whiteboard_object<class Plan_Planner_Settings >(wbd, kPlan_Planner_Settings_v, false) {} 
	};

	/** WB Ptr Class: Plan_Domain_Filename @brief Filename of the PDDL Domain the Planner will try to solve */ 

        class Plan_Domain_Filename_t: public generic_whiteboard_object<class Plan_Filename > { 
	public: 
		/** Constructor: Plan_Domain_Filename */ 
		Plan_Domain_Filename_t(gu_simple_whiteboard_descriptor *wbd = NULL) : generic_whiteboard_object<class Plan_Filename >(wbd, kPlan_Domain_Filename_v, false) {} 
	};

	/** WB Ptr Class: Plan_Problem_Filename @brief Filename of the PDDL Problem the Planner will try to solve */ 

        class Plan_Problem_Filename_t: public generic_whiteboard_object<class Plan_Filename > { 
	public: 
		/** Constructor: Plan_Problem_Filename */ 
		Plan_Problem_Filename_t(gu_simple_whiteboard_descriptor *wbd = NULL) : generic_whiteboard_object<class Plan_Filename >(wbd, kPlan_Problem_Filename_v, false) {} 
	};

	/** WB Ptr Class: Plan_Obstacles_Filename @brief Filename of the Obstacle List */ 

        class Plan_Obstacles_Filename_t: public generic_whiteboard_object<class Plan_Filename > { 
	public: 
		/** Constructor: Plan_Obstacles_Filename */ 
		Plan_Obstacles_Filename_t(gu_simple_whiteboard_descriptor *wbd = NULL) : generic_whiteboard_object<class Plan_Filename >(wbd, kPlan_Obstacles_Filename_v, false) {} 
	};

	/** WB Ptr Class: Plan_Plan_Filename @brief Filename of the Plan */ 

        class Plan_Plan_Filename_t: public generic_whiteboard_object<class Plan_Filename > { 
	public: 
		/** Constructor: Plan_Plan_Filename */ 
		Plan_Plan_Filename_t(gu_simple_whiteboard_descriptor *wbd = NULL) : generic_whiteboard_object<class Plan_Filename >(wbd, kPlan_Plan_Filename_v, false) {} 
	};

	/** WB Ptr Class: Plan_Manager_Status @brief Plan Manager Status */ 

        class Plan_Manager_Status_t: public generic_whiteboard_object<class Plan_Control_Status > { 
	public: 
		/** Constructor: Plan_Manager_Status */ 
		Plan_Manager_Status_t(gu_simple_whiteboard_descriptor *wbd = NULL) : generic_whiteboard_object<class Plan_Control_Status >(wbd, kPlan_Manager_Status_v, false) {} 
	};

	/** WB Ptr Class: Plan_Planner_Status @brief Planner Status */ 

        class Plan_Planner_Status_t: public generic_whiteboard_object<class Plan_Control_Status > { 
	public: 
		/** Constructor: Plan_Planner_Status */ 
		Plan_Planner_Status_t(gu_simple_whiteboard_descriptor *wbd = NULL) : generic_whiteboard_object<class Plan_Control_Status >(wbd, kPlan_Planner_Status_v, false) {} 
	};

	/** WB Ptr Class: Plan_Goal_List @brief List of sub-goals (works like FSMNames) */ 

        class Plan_Goal_List_t: public generic_whiteboard_object<class Plan_Goal_List > { 
	public: 
		/** Constructor: Plan_Goal_List */ 
		Plan_Goal_List_t(gu_simple_whiteboard_descriptor *wbd = NULL) : generic_whiteboard_object<class Plan_Goal_List >(wbd, kPlan_Goal_List_v, false) {} 
	};

	/** WB Ptr Class: Plan_Obstacle_List @brief List of obstacles (works like FSMNames) */ 

        class Plan_Obstacle_List_t: public generic_whiteboard_object<class Plan_Obstacle_List > { 
	public: 
		/** Constructor: Plan_Obstacle_List */ 
		Plan_Obstacle_List_t(gu_simple_whiteboard_descriptor *wbd = NULL) : generic_whiteboard_object<class Plan_Obstacle_List >(wbd, kPlan_Obstacle_List_v, false) {} 
	};

	/** WB Ptr Class: Epuck_Test_Control @brief Epuck Test Control Message */ 

        class Epuck_Test_Control_t: public generic_whiteboard_object<class Epuck_Test > { 
	public: 
		/** Constructor: Epuck_Test_Control */ 
		Epuck_Test_Control_t(gu_simple_whiteboard_descriptor *wbd = NULL) : generic_whiteboard_object<class Epuck_Test >(wbd, kEpuck_Test_Control_v, false) {} 
	};

	/** WB Ptr Class: Epuck_Test_Status @brief Epuck Test Status Message */ 

        class Epuck_Test_Status_t: public generic_whiteboard_object<class Epuck_Test > { 
	public: 
		/** Constructor: Epuck_Test_Status */ 
		Epuck_Test_Status_t(gu_simple_whiteboard_descriptor *wbd = NULL) : generic_whiteboard_object<class Epuck_Test >(wbd, kEpuck_Test_Status_v, false) {} 
	};

	/** WB Ptr Class: Epuck_Test_Start_Up @brief Epuck Test Start Up State Message */ 

        class Epuck_Test_Start_Up_t: public generic_whiteboard_object<class Epuck_Test > { 
	public: 
		/** Constructor: Epuck_Test_Start_Up */ 
		Epuck_Test_Start_Up_t(gu_simple_whiteboard_descriptor *wbd = NULL) : generic_whiteboard_object<class Epuck_Test >(wbd, kEpuck_Test_Start_Up_v, false) {} 
	};

}

#pragma clang diagnostic pop

#endif                          
