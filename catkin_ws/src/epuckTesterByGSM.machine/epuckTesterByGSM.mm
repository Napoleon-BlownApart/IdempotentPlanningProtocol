//
// epuckTesterByGSM.mm
//
// Automatically created through MiCASE -- do not change manually!
//
#include "epuckTesterByGSM_Includes.h"
#include "epuckTesterByGSM.h"

#include "State_InitialPseudoState.h"
#include "State_Initial.h"
#include "State_observe.h"
#include "State_epuckFollowsLine.h"
#include "State_epuckFollowsLine_Suspend.h"
#include "State_epuckFollowsLine_Resume.h"
#include "State_epuckIntersection.h"
#include "State_epuckIntersection_Suspend.h"
#include "State_epuckIntersection_Resume.h"
#include "State_epuckTurnAway.h"
#include "State_epuckTurnAway_Suspend.h"
#include "State_epuckTurnAway_Resume.h"
#include "State_epuckChooseDirection.h"
#include "State_epuckChooseDirection_Suspend.h"
#include "State_epuckChooseDirection_Resume.h"
#include "State_epuckTurn.h"
#include "State_epuckTurn_Suspend.h"
#include "State_epuckTurn_Resume.h"
#include "State_epuckOrientation.h"
#include "State_epuckOrientation_Suspend.h"
#include "State_epuckOrientation_Resume.h"
#include "State_epuckObstacleOnPath.h"
#include "State_epuckObstacleOnPath_Suspend.h"
#include "State_epuckObstacleOnPath_Resume.h"
#include "State_epuckCoordinates.h"
#include "State_epuckCoordinates_Suspend.h"
#include "State_epuckCoordinates_Resume.h"
#include "State_epuckCourseLeg.h"
#include "State_epuckCourseLeg_Suspend.h"
#include "State_epuckCourseLeg_Resume.h"
#include "State_epuckPlanManager.h"
#include "State_epuckPlanManager_Suspend.h"
#include "State_epuckPlanManager_Resume.h"
#include "State_loop_Back.h"

using namespace FSM;
using namespace CLM;

extern "C"
{
	epuckTesterByGSM *CLM_Create_epuckTesterByGSM(int mid, const char *name)
	{
		return new epuckTesterByGSM(mid, name);
	}
}

epuckTesterByGSM::epuckTesterByGSM(int mid, const char *name): CLMachine(mid, name)
{
	_states[0] = new FSMepuckTesterByGSM::State::InitialPseudoState;
	_states[1] = new FSMepuckTesterByGSM::State::Initial;
	_states[2] = new FSMepuckTesterByGSM::State::observe;
	_states[3] = new FSMepuckTesterByGSM::State::epuckFollowsLine;
	_states[4] = new FSMepuckTesterByGSM::State::epuckFollowsLine_Suspend;
	_states[5] = new FSMepuckTesterByGSM::State::epuckFollowsLine_Resume;
	_states[6] = new FSMepuckTesterByGSM::State::epuckIntersection;
	_states[7] = new FSMepuckTesterByGSM::State::epuckIntersection_Suspend;
	_states[8] = new FSMepuckTesterByGSM::State::epuckIntersection_Resume;
	_states[9] = new FSMepuckTesterByGSM::State::epuckTurnAway;
	_states[10] = new FSMepuckTesterByGSM::State::epuckTurnAway_Suspend;
	_states[11] = new FSMepuckTesterByGSM::State::epuckTurnAway_Resume;
	_states[12] = new FSMepuckTesterByGSM::State::epuckChooseDirection;
	_states[13] = new FSMepuckTesterByGSM::State::epuckChooseDirection_Suspend;
	_states[14] = new FSMepuckTesterByGSM::State::epuckChooseDirection_Resume;
	_states[15] = new FSMepuckTesterByGSM::State::epuckTurn;
	_states[16] = new FSMepuckTesterByGSM::State::epuckTurn_Suspend;
	_states[17] = new FSMepuckTesterByGSM::State::epuckTurn_Resume;
	_states[18] = new FSMepuckTesterByGSM::State::epuckOrientation;
	_states[19] = new FSMepuckTesterByGSM::State::epuckOrientation_Suspend;
	_states[20] = new FSMepuckTesterByGSM::State::epuckOrientation_Resume;
	_states[21] = new FSMepuckTesterByGSM::State::epuckObstacleOnPath;
	_states[22] = new FSMepuckTesterByGSM::State::epuckObstacleOnPath_Suspend;
	_states[23] = new FSMepuckTesterByGSM::State::epuckObstacleOnPath_Resume;
	_states[24] = new FSMepuckTesterByGSM::State::epuckCoordinates;
	_states[25] = new FSMepuckTesterByGSM::State::epuckCoordinates_Suspend;
	_states[26] = new FSMepuckTesterByGSM::State::epuckCoordinates_Resume;
	_states[27] = new FSMepuckTesterByGSM::State::epuckCourseLeg;
	_states[28] = new FSMepuckTesterByGSM::State::epuckCourseLeg_Suspend;
	_states[29] = new FSMepuckTesterByGSM::State::epuckCourseLeg_Resume;
	_states[30] = new FSMepuckTesterByGSM::State::epuckPlanManager;
	_states[31] = new FSMepuckTesterByGSM::State::epuckPlanManager_Suspend;
	_states[32] = new FSMepuckTesterByGSM::State::epuckPlanManager_Resume;
	_states[33] = new FSMepuckTesterByGSM::State::loop_Back;

	setInitialState(_states[0]);            // set initial state
}

epuckTesterByGSM::~epuckTesterByGSM()
{
	delete _states[0];
	delete _states[1];
	delete _states[2];
	delete _states[3];
	delete _states[4];
	delete _states[5];
	delete _states[6];
	delete _states[7];
	delete _states[8];
	delete _states[9];
	delete _states[10];
	delete _states[11];
	delete _states[12];
	delete _states[13];
	delete _states[14];
	delete _states[15];
	delete _states[16];
	delete _states[17];
	delete _states[18];
	delete _states[19];
	delete _states[20];
	delete _states[21];
	delete _states[22];
	delete _states[23];
	delete _states[24];
	delete _states[25];
	delete _states[26];
	delete _states[27];
	delete _states[28];
	delete _states[29];
	delete _states[30];
	delete _states[31];
	delete _states[32];
	delete _states[33];
}
