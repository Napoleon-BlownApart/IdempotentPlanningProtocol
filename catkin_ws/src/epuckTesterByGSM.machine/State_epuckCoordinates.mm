//
// State_epuckCoordinates.mm
//
// Automatically created through MiCASE -- do not change manually!
//
#include "epuckTesterByGSM_Includes.h"
#include "epuckTesterByGSM.h"
#include "State_epuckCoordinates.h"

#include "State_epuckCoordinates_Includes.h"

using namespace FSM;
using namespace CLM;
using namespace FSMepuckTesterByGSM;
using namespace State;

epuckCoordinates::epuckCoordinates(const char *name): CLState(name, *new epuckCoordinates::OnEntry, *new epuckCoordinates::OnExit, *new epuckCoordinates::Internal)
{
	_transitions[0] = new Transition_0();
	_transitions[1] = new Transition_1();
	_transitions[2] = new Transition_2();
}

epuckCoordinates::~epuckCoordinates()
{
	delete &onEntryAction();
	delete &onExitAction();
	delete &internalAction();

	delete _transitions[0];
	delete _transitions[1];
	delete _transitions[2];
}

void epuckCoordinates::OnEntry::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckTesterByGSM_VarRefs.mm"
#	include "State_epuckCoordinates_VarRefs.mm"
#	include "State_epuckCoordinates_OnEntry.mm"
}

void epuckCoordinates::OnExit::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckTesterByGSM_VarRefs.mm"
#	include "State_epuckCoordinates_VarRefs.mm"
#	include "State_epuckCoordinates_OnExit.mm"
}

void epuckCoordinates::Internal::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckTesterByGSM_VarRefs.mm"
#	include "State_epuckCoordinates_VarRefs.mm"
#	include "State_epuckCoordinates_Internal.mm"
}

bool epuckCoordinates::Transition_0::check(CLMachine *_machine, CLState *_state) const
{
#	include "epuckTesterByGSM_VarRefs.mm"
#	include "State_epuckCoordinates_VarRefs.mm"

	return
	(
#		include "State_epuckCoordinates_Transition_0.expr"
	);
}

bool epuckCoordinates::Transition_1::check(CLMachine *_machine, CLState *_state) const
{
#	include "epuckTesterByGSM_VarRefs.mm"
#	include "State_epuckCoordinates_VarRefs.mm"

	return
	(
#		include "State_epuckCoordinates_Transition_1.expr"
	);
}

bool epuckCoordinates::Transition_2::check(CLMachine *_machine, CLState *_state) const
{
#	include "epuckTesterByGSM_VarRefs.mm"
#	include "State_epuckCoordinates_VarRefs.mm"

	return
	(
#		include "State_epuckCoordinates_Transition_2.expr"
	);
}
