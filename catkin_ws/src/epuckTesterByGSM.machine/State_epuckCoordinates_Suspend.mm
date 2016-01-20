//
// State_epuckCoordinates_Suspend.mm
//
// Automatically created through MiCASE -- do not change manually!
//
#include "epuckTesterByGSM_Includes.h"
#include "epuckTesterByGSM.h"
#include "State_epuckCoordinates_Suspend.h"

#include "State_epuckCoordinates_Suspend_Includes.h"

using namespace FSM;
using namespace CLM;
using namespace FSMepuckTesterByGSM;
using namespace State;

epuckCoordinates_Suspend::epuckCoordinates_Suspend(const char *name): CLState(name, *new epuckCoordinates_Suspend::OnEntry, *new epuckCoordinates_Suspend::OnExit, *new epuckCoordinates_Suspend::Internal)
{
	_transitions[0] = new Transition_0();
}

epuckCoordinates_Suspend::~epuckCoordinates_Suspend()
{
	delete &onEntryAction();
	delete &onExitAction();
	delete &internalAction();

	delete _transitions[0];
}

void epuckCoordinates_Suspend::OnEntry::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckTesterByGSM_VarRefs.mm"
#	include "State_epuckCoordinates_Suspend_VarRefs.mm"
#	include "State_epuckCoordinates_Suspend_OnEntry.mm"
}

void epuckCoordinates_Suspend::OnExit::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckTesterByGSM_VarRefs.mm"
#	include "State_epuckCoordinates_Suspend_VarRefs.mm"
#	include "State_epuckCoordinates_Suspend_OnExit.mm"
}

void epuckCoordinates_Suspend::Internal::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckTesterByGSM_VarRefs.mm"
#	include "State_epuckCoordinates_Suspend_VarRefs.mm"
#	include "State_epuckCoordinates_Suspend_Internal.mm"
}

bool epuckCoordinates_Suspend::Transition_0::check(CLMachine *_machine, CLState *_state) const
{
#	include "epuckTesterByGSM_VarRefs.mm"
#	include "State_epuckCoordinates_Suspend_VarRefs.mm"

	return
	(
#		include "State_epuckCoordinates_Suspend_Transition_0.expr"
	);
}
