//
// State_epuckTurn_Suspend.mm
//
// Automatically created through MiCASE -- do not change manually!
//
#include "epuckTesterByGSM_Includes.h"
#include "epuckTesterByGSM.h"
#include "State_epuckTurn_Suspend.h"

#include "State_epuckTurn_Suspend_Includes.h"

using namespace FSM;
using namespace CLM;
using namespace FSMepuckTesterByGSM;
using namespace State;

epuckTurn_Suspend::epuckTurn_Suspend(const char *name): CLState(name, *new epuckTurn_Suspend::OnEntry, *new epuckTurn_Suspend::OnExit, *new epuckTurn_Suspend::Internal)
{
	_transitions[0] = new Transition_0();
}

epuckTurn_Suspend::~epuckTurn_Suspend()
{
	delete &onEntryAction();
	delete &onExitAction();
	delete &internalAction();

	delete _transitions[0];
}

void epuckTurn_Suspend::OnEntry::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckTesterByGSM_VarRefs.mm"
#	include "State_epuckTurn_Suspend_VarRefs.mm"
#	include "State_epuckTurn_Suspend_OnEntry.mm"
}

void epuckTurn_Suspend::OnExit::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckTesterByGSM_VarRefs.mm"
#	include "State_epuckTurn_Suspend_VarRefs.mm"
#	include "State_epuckTurn_Suspend_OnExit.mm"
}

void epuckTurn_Suspend::Internal::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckTesterByGSM_VarRefs.mm"
#	include "State_epuckTurn_Suspend_VarRefs.mm"
#	include "State_epuckTurn_Suspend_Internal.mm"
}

bool epuckTurn_Suspend::Transition_0::check(CLMachine *_machine, CLState *_state) const
{
#	include "epuckTesterByGSM_VarRefs.mm"
#	include "State_epuckTurn_Suspend_VarRefs.mm"

	return
	(
#		include "State_epuckTurn_Suspend_Transition_0.expr"
	);
}
