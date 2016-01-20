//
// epuckOrientationByGSM.mm
//
// Automatically created through MiCASE -- do not change manually!
//
#include "epuckOrientationByGSM_Includes.h"
#include "epuckOrientationByGSM.h"

#include "State_InitialPseudoState.h"
#include "State_Initial.h"
#include "State_Observe_Turn.h"
#include "State_Not_Turning.h"
#include "State_Turn_Completed.h"
#include "State_Not_Yet.h"
#include "State_Turn_Right.h"
#include "State_Turn_Left.h"
#include "State_Turn_Around.h"
#include "State_SUSPENDED.h"

using namespace FSM;
using namespace CLM;

extern "C"
{
	epuckOrientationByGSM *CLM_Create_epuckOrientationByGSM(int mid, const char *name)
	{
		return new epuckOrientationByGSM(mid, name);
	}
}

epuckOrientationByGSM::epuckOrientationByGSM(int mid, const char *name): CLMachine(mid, name)
{
	_states[0] = new FSMepuckOrientationByGSM::State::InitialPseudoState;
	_states[1] = new FSMepuckOrientationByGSM::State::Initial;
	_states[2] = new FSMepuckOrientationByGSM::State::Observe_Turn;
	_states[3] = new FSMepuckOrientationByGSM::State::Not_Turning;
	_states[4] = new FSMepuckOrientationByGSM::State::Turn_Completed;
	_states[5] = new FSMepuckOrientationByGSM::State::Not_Yet;
	_states[6] = new FSMepuckOrientationByGSM::State::Turn_Right;
	_states[7] = new FSMepuckOrientationByGSM::State::Turn_Left;
	_states[8] = new FSMepuckOrientationByGSM::State::Turn_Around;
	_states[9] = new FSMepuckOrientationByGSM::State::SUSPENDED;

	setSuspendState(_states[9]);            // set suspend state
	setInitialState(_states[0]);            // set initial state
}

epuckOrientationByGSM::~epuckOrientationByGSM()
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
}
