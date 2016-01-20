//
// epuckTurnAwayByGSM.mm
//
// Automatically created through MiCASE -- do not change manually!
//
#include "epuckTurnAwayByGSM_Includes.h"
#include "epuckTurnAwayByGSM.h"

#include "State_InitialPseudoState.h"
#include "State_Initial.h"
#include "State_TurnLeftAwayFromObstacleOnRight.h"
#include "State_TurnRightAwayFromObstacleOnLeft.h"
#include "State_Observe.h"
#include "State_No_Obstacles.h"
#include "State_SUSPENDED.h"

using namespace FSM;
using namespace CLM;

extern "C"
{
	epuckTurnAwayByGSM *CLM_Create_epuckTurnAwayByGSM(int mid, const char *name)
	{
		return new epuckTurnAwayByGSM(mid, name);
	}
}

epuckTurnAwayByGSM::epuckTurnAwayByGSM(int mid, const char *name): CLMachine(mid, name)
{
	_states[0] = new FSMepuckTurnAwayByGSM::State::InitialPseudoState;
	_states[1] = new FSMepuckTurnAwayByGSM::State::Initial;
	_states[2] = new FSMepuckTurnAwayByGSM::State::TurnLeftAwayFromObstacleOnRight;
	_states[3] = new FSMepuckTurnAwayByGSM::State::TurnRightAwayFromObstacleOnLeft;
	_states[4] = new FSMepuckTurnAwayByGSM::State::Observe;
	_states[5] = new FSMepuckTurnAwayByGSM::State::No_Obstacles;
	_states[6] = new FSMepuckTurnAwayByGSM::State::SUSPENDED;

	setSuspendState(_states[6]);            // set suspend state
	setInitialState(_states[0]);            // set initial state
}

epuckTurnAwayByGSM::~epuckTurnAwayByGSM()
{
	delete _states[0];
	delete _states[1];
	delete _states[2];
	delete _states[3];
	delete _states[4];
	delete _states[5];
	delete _states[6];
}
