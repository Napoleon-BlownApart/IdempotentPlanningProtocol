//
// State_epuckTurnAway_Suspend.mm
//
// Automatically created through MiCASE -- do not change manually!
//
#include "epuckTesterByGSM_Includes.h"
#include "epuckTesterByGSM.h"
#include "State_epuckTurnAway_Suspend.h"

#include "State_epuckTurnAway_Suspend_Includes.h"

using namespace FSM;
using namespace CLM;
using namespace FSMepuckTesterByGSM;
using namespace State;

epuckTurnAway_Suspend::epuckTurnAway_Suspend(const char *name): CLState(name, *new epuckTurnAway_Suspend::OnEntry, *new epuckTurnAway_Suspend::OnExit, *new epuckTurnAway_Suspend::Internal)
{
	_transitions[0] = new Transition_0();
}

epuckTurnAway_Suspend::~epuckTurnAway_Suspend()
{
	delete &onEntryAction();
	delete &onExitAction();
	delete &internalAction();

	delete _transitions[0];
}

void epuckTurnAway_Suspend::OnEntry::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckTesterByGSM_VarRefs.mm"
#	include "State_epuckTurnAway_Suspend_VarRefs.mm"
#	include "State_epuckTurnAway_Suspend_OnEntry.mm"
}

void epuckTurnAway_Suspend::OnExit::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckTesterByGSM_VarRefs.mm"
#	include "State_epuckTurnAway_Suspend_VarRefs.mm"
#	include "State_epuckTurnAway_Suspend_OnExit.mm"
}

void epuckTurnAway_Suspend::Internal::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckTesterByGSM_VarRefs.mm"
#	include "State_epuckTurnAway_Suspend_VarRefs.mm"
#	include "State_epuckTurnAway_Suspend_Internal.mm"
}

bool epuckTurnAway_Suspend::Transition_0::check(CLMachine *_machine, CLState *_state) const
{
#	include "epuckTesterByGSM_VarRefs.mm"
#	include "State_epuckTurnAway_Suspend_VarRefs.mm"

	return
	(
#		include "State_epuckTurnAway_Suspend_Transition_0.expr"
	);
}
