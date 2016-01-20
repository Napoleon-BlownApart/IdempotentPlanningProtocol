//
// epuckFollowLineByGSM.mm
//
// Automatically created through MiCASE -- do not change manually!
//
#include "epuckFollowLineByGSM_Includes.h"
#include "epuckFollowLineByGSM.h"

#include "State_InitialPseudoState.h"
#include "State_Initial.h"
#include "State_Forward.h"
#include "State_Forward_Feedback.h"
#include "State_Continue_Forward.h"
#include "State_VeeringRight.h"
#include "State_VeeringLeft.h"
#include "State_SUSPENDED.h"

using namespace FSM;
using namespace CLM;

extern "C"
{
	epuckFollowLineByGSM *CLM_Create_epuckFollowLineByGSM(int mid, const char *name)
	{
		return new epuckFollowLineByGSM(mid, name);
	}
}

epuckFollowLineByGSM::epuckFollowLineByGSM(int mid, const char *name): CLMachine(mid, name)
{
	_states[0] = new FSMepuckFollowLineByGSM::State::InitialPseudoState;
	_states[1] = new FSMepuckFollowLineByGSM::State::Initial;
	_states[2] = new FSMepuckFollowLineByGSM::State::Forward;
	_states[3] = new FSMepuckFollowLineByGSM::State::Forward_Feedback;
	_states[4] = new FSMepuckFollowLineByGSM::State::Continue_Forward;
	_states[5] = new FSMepuckFollowLineByGSM::State::VeeringRight;
	_states[6] = new FSMepuckFollowLineByGSM::State::VeeringLeft;
	_states[7] = new FSMepuckFollowLineByGSM::State::SUSPENDED;

	setSuspendState(_states[7]);            // set suspend state
	setInitialState(_states[0]);            // set initial state
}

epuckFollowLineByGSM::~epuckFollowLineByGSM()
{
	delete _states[0];
	delete _states[1];
	delete _states[2];
	delete _states[3];
	delete _states[4];
	delete _states[5];
	delete _states[6];
	delete _states[7];
}
