//
// epuckChooseDirectionByGSM.mm
//
// Automatically created through MiCASE -- do not change manually!
//
#include "epuckChooseDirectionByGSM_Includes.h"
#include "epuckChooseDirectionByGSM.h"

#include "State_InitialPseudoState.h"
#include "State_Initial.h"
#include "State_ChooseDirection.h"
#include "State_Stop.h"
#include "State_Check_If_Ready.h"
#include "State_Not_Ready.h"
#include "State_SUSPENDED.h"

using namespace FSM;
using namespace CLM;

extern "C"
{
	epuckChooseDirectionByGSM *CLM_Create_epuckChooseDirectionByGSM(int mid, const char *name)
	{
		return new epuckChooseDirectionByGSM(mid, name);
	}
}

epuckChooseDirectionByGSM::epuckChooseDirectionByGSM(int mid, const char *name): CLMachine(mid, name)
{
	_states[0] = new FSMepuckChooseDirectionByGSM::State::InitialPseudoState;
	_states[1] = new FSMepuckChooseDirectionByGSM::State::Initial;
	_states[2] = new FSMepuckChooseDirectionByGSM::State::ChooseDirection;
	_states[3] = new FSMepuckChooseDirectionByGSM::State::Stop;
	_states[4] = new FSMepuckChooseDirectionByGSM::State::Check_If_Ready;
	_states[5] = new FSMepuckChooseDirectionByGSM::State::Not_Ready;
	_states[6] = new FSMepuckChooseDirectionByGSM::State::SUSPENDED;

	setSuspendState(_states[6]);            // set suspend state
	setInitialState(_states[0]);            // set initial state
}

epuckChooseDirectionByGSM::~epuckChooseDirectionByGSM()
{
	delete _states[0];
	delete _states[1];
	delete _states[2];
	delete _states[3];
	delete _states[4];
	delete _states[5];
	delete _states[6];
}
