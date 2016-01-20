//
// epuckCourseLegByGSM.mm
//
// Automatically created through MiCASE -- do not change manually!
//
#include "epuckCourseLegByGSM_Includes.h"
#include "epuckCourseLegByGSM.h"

#include "State_InitialPseudoState.h"
#include "State_Initial.h"
#include "State_ChooseDirection.h"
#include "State_Wait_4_Scan.h"
#include "State_SUSPENDED.h"
#include "State_At_Goal.h"
#include "State_Unreachable.h"
#include "State_Stop.h"
#include "State_DirectionChosen.h"
#include "State_Observe.h"
#include "State_Detected_Intersection.h"
#include "State_Not_Detected_Intersection.h"

using namespace FSM;
using namespace CLM;

extern "C"
{
	epuckCourseLegByGSM *CLM_Create_epuckCourseLegByGSM(int mid, const char *name)
	{
		return new epuckCourseLegByGSM(mid, name);
	}
}

epuckCourseLegByGSM::epuckCourseLegByGSM(int mid, const char *name): CLMachine(mid, name)
{
	_states[0] = new FSMepuckCourseLegByGSM::State::InitialPseudoState;
	_states[1] = new FSMepuckCourseLegByGSM::State::Initial;
	_states[2] = new FSMepuckCourseLegByGSM::State::ChooseDirection;
	_states[3] = new FSMepuckCourseLegByGSM::State::Wait_4_Scan;
	_states[4] = new FSMepuckCourseLegByGSM::State::SUSPENDED;
	_states[5] = new FSMepuckCourseLegByGSM::State::At_Goal;
	_states[6] = new FSMepuckCourseLegByGSM::State::Unreachable;
	_states[7] = new FSMepuckCourseLegByGSM::State::Stop;
	_states[8] = new FSMepuckCourseLegByGSM::State::DirectionChosen;
	_states[9] = new FSMepuckCourseLegByGSM::State::Observe;
	_states[10] = new FSMepuckCourseLegByGSM::State::Detected_Intersection;
	_states[11] = new FSMepuckCourseLegByGSM::State::Not_Detected_Intersection;

	setSuspendState(_states[4]);            // set suspend state
	setInitialState(_states[0]);            // set initial state
}

epuckCourseLegByGSM::~epuckCourseLegByGSM()
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
}
