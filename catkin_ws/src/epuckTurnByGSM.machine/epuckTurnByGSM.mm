//
// epuckTurnByGSM.mm
//
// Automatically created through MiCASE -- do not change manually!
//
#include "epuckTurnByGSM_Includes.h"
#include "epuckTurnByGSM.h"

#include "State_InitialPseudoState.h"
#include "State_Initial.h"
#include "State_Turn_Right.h"
#include "State_Turn_Left.h"
#include "State_Align_After_Left_Turn.h"
#include "State_Continue_Align_Left.h"
#include "State_Observe.h"
#include "State_Not_Required.h"
#include "State_Turn_Around.h"
#include "State_SUSPENDED.h"
#include "State_Turn_Completed.h"
#include "State_Align_After_Right_Turn.h"
#include "State_Continue_Align_Right.h"
#include "State_Straight.h"

using namespace FSM;
using namespace CLM;

extern "C"
{
	epuckTurnByGSM *CLM_Create_epuckTurnByGSM(int mid, const char *name)
	{
		return new epuckTurnByGSM(mid, name);
	}
}

epuckTurnByGSM::epuckTurnByGSM(int mid, const char *name): CLMachine(mid, name)
{
	_states[0] = new FSMepuckTurnByGSM::State::InitialPseudoState;
	_states[1] = new FSMepuckTurnByGSM::State::Initial;
	_states[2] = new FSMepuckTurnByGSM::State::Turn_Right;
	_states[3] = new FSMepuckTurnByGSM::State::Turn_Left;
	_states[4] = new FSMepuckTurnByGSM::State::Align_After_Left_Turn;
	_states[5] = new FSMepuckTurnByGSM::State::Continue_Align_Left;
	_states[6] = new FSMepuckTurnByGSM::State::Observe;
	_states[7] = new FSMepuckTurnByGSM::State::Not_Required;
	_states[8] = new FSMepuckTurnByGSM::State::Turn_Around;
	_states[9] = new FSMepuckTurnByGSM::State::SUSPENDED;
	_states[10] = new FSMepuckTurnByGSM::State::Turn_Completed;
	_states[11] = new FSMepuckTurnByGSM::State::Align_After_Right_Turn;
	_states[12] = new FSMepuckTurnByGSM::State::Continue_Align_Right;
	_states[13] = new FSMepuckTurnByGSM::State::Straight;

	setSuspendState(_states[9]);            // set suspend state
	setInitialState(_states[0]);            // set initial state
}

epuckTurnByGSM::~epuckTurnByGSM()
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
}
