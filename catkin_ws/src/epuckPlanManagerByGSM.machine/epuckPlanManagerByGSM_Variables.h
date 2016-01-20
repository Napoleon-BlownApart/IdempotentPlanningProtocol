//
// epuckPlanManagerByGSM_Variables.h
//
// Automatically created through MiCASE -- do not change manually!
//
DifferentialRobotControl_t	wbhDifferentialRobot_Control;	///<
DifferentialRobotStatus_t	wbhDifferentialRobot_Status;	///<
EMITTERS_EPuckLED_Control_t	wbhEPuckLED_Control;	///<
EMITTERS_EPuckLED_Status_t	wbhEPuckLED_Status;	///<
GOAL_Control_t	wbhGoal_Control;	///<
GOAL_Status_t	wbhGoal_Status;	///<
Plan_Domain_Filename_t	wbhDomain_Filename;	///<
Plan_Goal_List_t	wbhGoal_List;	///<
Plan_Manager_Status_t	wbhManager_Status;	///<
Plan_Obstacle_List_t	wbhObstacle_List;	///<
Plan_Obstacles_Filename_t	wbhObstacles_Filename;	///<
Plan_Plan_Filename_t	wbhPlan_Filename;	///<
Plan_Planner_Settings_t	wbhPlanner_Settings;	///<
Plan_Planner_Status_t	wbhPlanner_Status;	///<
Plan_Problem_Filename_t	wbhProblem_Filename;	///<
SENSORS_EPuckGSM_Control_t	wbhEPuckGSM_Control;	///<
SENSORS_EPuckAccel_Control_t	wbhEPuckAccel_Control;	///<
SENSORS_EPuckAccel_Status_t	wbhEPuckAccel_Status;	///<
SENSORS_EPuckCamera_Control_t	wbhEPuckCamera_Control;	///<
SENSORS_EPuckCamera_Status_t	wbhEPuckCamera_Status;	///<
SENSORS_EPuckGSM_Status_t	wbhEPuckGSM_Status;	///<
SENSORS_EPuckLight_Control_t	wbhEPuckLight_Control;	///<
SENSORS_EPuckLight_Status_t	wbhEPuckLight_Status;	///<
SENSORS_EPuckProximity_Control_t	wbhEPuckProximity_Control;	///<
SENSORS_EPuckProximity_Status_t	wbhEPuckProximity_Status;	///<
SENSORS_Intersection_Status_t	wbhIntersection_Status;	///<
SENSORS_Obstacle_On_Path_t	wbhObstacleOnPath;	///<
DifferentialRobotControlStatus	wbcDifferentialRobot_Control;	///<
DifferentialRobotControlStatus	wbcDifferentialRobot_Status;	///<
EMITTERS_EPuckLED_ControlStatus	wbcEPuckLED_Control;	///<
EMITTERS_EPuckLED_ControlStatus	wbcEPuckLED_Status;	///<
GOAL_Control	wbcGoal_Control;	///<
GOAL_Status	wbcGoal_Status;	///<
Plan_Filename	wbcDomain_Filename;	///<
Plan_Filename	wbcObstacles_Filename;	///<
Plan_Filename	wbcPlan_Filename;	///<
Plan_Filename	wbcProblem_Filename;	///<
Plan_Goal_List	wbcGoal_List;	///<
Plan_Obstacle_List	wbcObstacle_List;	///<
Plan_Planner_Settings	wbcPlanner_Settings;	///<
Plan_Control_Status	wbcManager_Status;	///<
Plan_Control_Status	wbcPlanner_Status;	///<
SENSORS_EPuckAccel_Control	wbcEPuckAccel_Control;	///<
SENSORS_EPuckAccel_Status	wbcEPuckAccel_Status;	///<
SENSORS_EPuckCamera_ControlStatus	wbcEPuckCamera_Control;	///<
SENSORS_EPuckCamera_ControlStatus	wbcEPuckCamera_Status;	///<
SENSORS_EPuckGSM_Control	wbcEPuckGSM_Control;	///<
SENSORS_EPuckGSM_Status	wbcEPuckGSM_Status;	///<
SENSORS_EPuckLight_Control	wbcEPuckLight_Control;	///<
SENSORS_EPuckLight_Status	wbcEPuckLight_Status;	///<
SENSORS_EPuckProximity_Control	wbcEPuckProximity_Control;	///<
SENSORS_EPuckProximity_Status	wbcEPuckProximity_Status;	///<
SENSORS_Intersection_Status	wbcIntersection_Status;	///<
SENSORS_Obstacle_On_Path	wbcObstacleOnPath;	///<
size_t	lastPlanHash;	///<
uint8_t	obstacleListElementsFilled;	///<
uint32_t	planElements;	///<
bool	firstPass;	///<
bool	obstacleProcessed;	///<
bool	needNewPlan;	///<
bool	newObstacle;	///<
bool	obstacleListRequested;	///<
std::string	obstacleStr;	///<
bool	needPlan;	///<
bool	planReady;	///<
bool	subGoalAchieved;	///<
bool	unreachable;	///<
bool	atSubGoal;	///<
bool	obstacle;	///<
int	obstacleListMsgCnt;	///<
int	plannerStatusMsgCnt;	///<
bool	notFullwithMoreObstacles;	///<
bool	isFullorDone;	///<
bool	waitingForPlan;	///<
bool	planIsNew;	///<
std::vector<guWhiteboard::GOAL_Control>	pathList;	///<
std::map<std::string, guWhiteboard::Plan_Obstacle>	obstacleMap;	///<
std::map<std::string, guWhiteboard::Plan_Obstacle>::const_iterator obstacleMap_it;	///<;	///<
std::vector<guWhiteboard::Plan_Obstacle>	obstacleList;	///<
std::hash<std::string> str_hash;
