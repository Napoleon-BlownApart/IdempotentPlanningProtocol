//
// epuckChooseDirectionByGSM_Variables.h
//
// Automatically created through MiCASE -- do not change manually!
//
DifferentialRobotControl_t	wbhDifferentialRobot_Control;	///<
DifferentialRobotStatus_t	wbhDifferentialRobot_Status;	///<
Direction_Control_t	wbhDirection_Control;	///<
EMITTERS_EPuckLED_Control_t	wbhEPuckLED_Control;	///<
EMITTERS_EPuckLED_Status_t	wbhEPuckLED_Status;	///<
GOAL_Control_t	wbhGoal_Control;	///<
GOAL_Status_t	wbhGoal_Status;	///<
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
DifferentialRobotControlStatus	wbcDifferentialRobot_Control;	///<
DifferentialRobotControlStatus	wbcDifferentialRobot_Status;	///<
Direction_Control	wbcDirection_Control;	///<
EMITTERS_EPuckLED_ControlStatus	wbcEPuckLED_Control;	///<
EMITTERS_EPuckLED_ControlStatus	wbcEPuckLED_Status;	///<
GOAL_Control	wbcGoal_Control;	///<
GOAL_Status	wbcGoal_Status;	///<
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
int	gsLeftPathTrigger;	///<
int	gsCenterPathTrigger;	///<
int	gsRightPathTrigger;	///<
int	gsLeftIntersectionTrigger;	///<
int	gsCenterIntersectionTrigger;	///<
int	gsRightIntersectionTrigger;	///<
double	leftPS;	///<
double	rightPS;	///<
double	leftGS;	///<
double	centerGS;	///<
double	rightGS;	///<
bool	scanCompleted;	///<
bool	scanCompletedNoOptions;	///<
bool	running;	///<
bool	returning;	///<
rotationalEncoders	encStateB4Maneuver;	///<
position	curPosition;	///<
Direction	whichWay;	///<
Direction	possibleDirections;	///<
