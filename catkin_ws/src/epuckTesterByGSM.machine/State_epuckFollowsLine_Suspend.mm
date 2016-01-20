//
// State_epuckFollowsLine_Suspend.mm
//
// Automatically created through MiCASE -- do not change manually!
//
#include "epuckTesterByGSM_Includes.h"
#include "epuckTesterByGSM.h"
#include "State_epuckFollowsLine_Suspend.h"

#include "State_epuckFollowsLine_Suspend_Includes.h"

using namespace FSM;
using namespace CLM;
using namespace FSMepuckTesterByGSM;
using namespace State;

epuckFollowsLine_Suspend::epuckFollowsLine_Suspend(const char *name): CLState(name, *new epuckFollowsLine_Suspend::OnEntry, *new epuckFollowsLine_Suspend::OnExit, *new epuckFollowsLine_Suspend::Internal)
{
	_transitions[0] = new Transition_0();
}

epuckFollowsLine_Suspend::~epuckFollowsLine_Suspend()
{
	delete &onEntryAction();
	delete &onExitAction();
	delete &internalAction();

	delete _transitions[0];
}

void epuckFollowsLine_Suspend::OnEntry::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckTesterByGSM_VarRefs.mm"
#	include "State_epuckFollowsLine_Suspend_VarRefs.mm"
#	include "State_epuckFollowsLine_Suspend_OnEntry.mm"
}

void epuckFollowsLine_Suspend::OnExit::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckTesterByGSM_VarRefs.mm"
#	include "State_epuckFollowsLine_Suspend_VarRefs.mm"
#	include "State_epuckFollowsLine_Suspend_OnExit.mm"
}

void epuckFollowsLine_Suspend::Internal::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckTesterByGSM_VarRefs.mm"
#	include "State_epuckFollowsLine_Suspend_VarRefs.mm"
#	include "State_epuckFollowsLine_Suspend_Internal.mm"
}

bool epuckFollowsLine_Suspend::Transition_0::check(CLMachine *_machine, CLState *_state) const
{
#	include "epuckTesterByGSM_VarRefs.mm"
#	include "State_epuckFollowsLine_Suspend_VarRefs.mm"

	return
	(
#		include "State_epuckFollowsLine_Suspend_Transition_0.expr"
	);
}
