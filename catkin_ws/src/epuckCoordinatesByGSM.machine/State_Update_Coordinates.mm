//
// State_Update_Coordinates.mm
//
// Automatically created through MiCASE -- do not change manually!
//
#include "epuckCoordinatesByGSM_Includes.h"
#include "epuckCoordinatesByGSM.h"
#include "State_Update_Coordinates.h"

#include "State_Update_Coordinates_Includes.h"

using namespace FSM;
using namespace CLM;
using namespace FSMepuckCoordinatesByGSM;
using namespace State;

Update_Coordinates::Update_Coordinates(const char *name): CLState(name, *new Update_Coordinates::OnEntry, *new Update_Coordinates::OnExit, *new Update_Coordinates::Internal)
{
	_transitions[0] = new Transition_0();
	_transitions[1] = new Transition_1();
	_transitions[2] = new Transition_2();
	_transitions[3] = new Transition_3();
}

Update_Coordinates::~Update_Coordinates()
{
	delete &onEntryAction();
	delete &onExitAction();
	delete &internalAction();

	delete _transitions[0];
	delete _transitions[1];
	delete _transitions[2];
	delete _transitions[3];
}

void Update_Coordinates::OnEntry::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckCoordinatesByGSM_VarRefs.mm"
#	include "State_Update_Coordinates_VarRefs.mm"
#	include "State_Update_Coordinates_OnEntry.mm"
}

void Update_Coordinates::OnExit::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckCoordinatesByGSM_VarRefs.mm"
#	include "State_Update_Coordinates_VarRefs.mm"
#	include "State_Update_Coordinates_OnExit.mm"
}

void Update_Coordinates::Internal::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckCoordinatesByGSM_VarRefs.mm"
#	include "State_Update_Coordinates_VarRefs.mm"
#	include "State_Update_Coordinates_Internal.mm"
}

bool Update_Coordinates::Transition_0::check(CLMachine *_machine, CLState *_state) const
{
#	include "epuckCoordinatesByGSM_VarRefs.mm"
#	include "State_Update_Coordinates_VarRefs.mm"

	return
	(
#		include "State_Update_Coordinates_Transition_0.expr"
	);
}

bool Update_Coordinates::Transition_1::check(CLMachine *_machine, CLState *_state) const
{
#	include "epuckCoordinatesByGSM_VarRefs.mm"
#	include "State_Update_Coordinates_VarRefs.mm"

	return
	(
#		include "State_Update_Coordinates_Transition_1.expr"
	);
}

bool Update_Coordinates::Transition_2::check(CLMachine *_machine, CLState *_state) const
{
#	include "epuckCoordinatesByGSM_VarRefs.mm"
#	include "State_Update_Coordinates_VarRefs.mm"

	return
	(
#		include "State_Update_Coordinates_Transition_2.expr"
	);
}

bool Update_Coordinates::Transition_3::check(CLMachine *_machine, CLState *_state) const
{
#	include "epuckCoordinatesByGSM_VarRefs.mm"
#	include "State_Update_Coordinates_VarRefs.mm"

	return
	(
#		include "State_Update_Coordinates_Transition_3.expr"
	);
}
