//
// epuckCoordinatesByGSM.mm
//
// Automatically created through MiCASE -- do not change manually!
//
#include "epuckCoordinatesByGSM_Includes.h"
#include "epuckCoordinatesByGSM.h"

#include "State_InitialPseudoState.h"
#include "State_Initial.h"
#include "State_Observe.h"
#include "State_Detected_Intersection.h"
#include "State_Not_Detected_Intersection.h"
#include "State_Entering_Intersection.h"
#include "State_Update_Coordinates.h"
#include "State_Moved_Up.h"
#include "State_Moved_Right.h"
#include "State_Moved_Down.h"
#include "State_Moved_Left.h"
#include "State_SUSPENDED.h"
#include "State_Are_We_Travelling.h"

using namespace FSM;
using namespace CLM;

extern "C"
{
	epuckCoordinatesByGSM *CLM_Create_epuckCoordinatesByGSM(int mid, const char *name)
	{
		return new epuckCoordinatesByGSM(mid, name);
	}
}

epuckCoordinatesByGSM::epuckCoordinatesByGSM(int mid, const char *name): CLMachine(mid, name)
{
	_states[0] = new FSMepuckCoordinatesByGSM::State::InitialPseudoState;
	_states[1] = new FSMepuckCoordinatesByGSM::State::Initial;
	_states[2] = new FSMepuckCoordinatesByGSM::State::Observe;
	_states[3] = new FSMepuckCoordinatesByGSM::State::Detected_Intersection;
	_states[4] = new FSMepuckCoordinatesByGSM::State::Not_Detected_Intersection;
	_states[5] = new FSMepuckCoordinatesByGSM::State::Entering_Intersection;
	_states[6] = new FSMepuckCoordinatesByGSM::State::Update_Coordinates;
	_states[7] = new FSMepuckCoordinatesByGSM::State::Moved_Up;
	_states[8] = new FSMepuckCoordinatesByGSM::State::Moved_Right;
	_states[9] = new FSMepuckCoordinatesByGSM::State::Moved_Down;
	_states[10] = new FSMepuckCoordinatesByGSM::State::Moved_Left;
	_states[11] = new FSMepuckCoordinatesByGSM::State::SUSPENDED;
	_states[12] = new FSMepuckCoordinatesByGSM::State::Are_We_Travelling;

	setSuspendState(_states[11]);            // set suspend state
	setInitialState(_states[0]);            // set initial state
}

epuckCoordinatesByGSM::~epuckCoordinatesByGSM()
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
}
