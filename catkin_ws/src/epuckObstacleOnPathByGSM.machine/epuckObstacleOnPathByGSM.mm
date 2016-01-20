//
// epuckObstacleOnPathByGSM.mm
//
// Automatically created through MiCASE -- do not change manually!
//
#include "epuckObstacleOnPathByGSM_Includes.h"
#include "epuckObstacleOnPathByGSM.h"

#include "State_InitialPseudoState.h"
#include "State_Initial.h"
#include "State_Have_Obstacle.h"
#include "State_Observe_Obstacle.h"
#include "State_SUSPENDED.h"
#include "State_Observe_Intersection.h"
#include "State_Entering_Intersection.h"
#include "State_Detected_Intersection.h"
#include "State_Not_Detected_Intersection.h"

using namespace FSM;
using namespace CLM;

extern "C"
{
	epuckObstacleOnPathByGSM *CLM_Create_epuckObstacleOnPathByGSM(int mid, const char *name)
	{
		return new epuckObstacleOnPathByGSM(mid, name);
	}
}

epuckObstacleOnPathByGSM::epuckObstacleOnPathByGSM(int mid, const char *name): CLMachine(mid, name)
{
	_states[0] = new FSMepuckObstacleOnPathByGSM::State::InitialPseudoState;
	_states[1] = new FSMepuckObstacleOnPathByGSM::State::Initial;
	_states[2] = new FSMepuckObstacleOnPathByGSM::State::Have_Obstacle;
	_states[3] = new FSMepuckObstacleOnPathByGSM::State::Observe_Obstacle;
	_states[4] = new FSMepuckObstacleOnPathByGSM::State::SUSPENDED;
	_states[5] = new FSMepuckObstacleOnPathByGSM::State::Observe_Intersection;
	_states[6] = new FSMepuckObstacleOnPathByGSM::State::Entering_Intersection;
	_states[7] = new FSMepuckObstacleOnPathByGSM::State::Detected_Intersection;
	_states[8] = new FSMepuckObstacleOnPathByGSM::State::Not_Detected_Intersection;

	setSuspendState(_states[4]);            // set suspend state
	setInitialState(_states[0]);            // set initial state
}

epuckObstacleOnPathByGSM::~epuckObstacleOnPathByGSM()
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
}
