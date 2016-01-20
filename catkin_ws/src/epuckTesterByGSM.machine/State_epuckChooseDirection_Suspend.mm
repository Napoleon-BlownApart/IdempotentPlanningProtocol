//
// State_epuckChooseDirection_Suspend.mm
//
// Automatically created through MiCASE -- do not change manually!
//
#include "epuckTesterByGSM_Includes.h"
#include "epuckTesterByGSM.h"
#include "State_epuckChooseDirection_Suspend.h"

#include "State_epuckChooseDirection_Suspend_Includes.h"

using namespace FSM;
using namespace CLM;
using namespace FSMepuckTesterByGSM;
using namespace State;

epuckChooseDirection_Suspend::epuckChooseDirection_Suspend(const char *name): CLState(name, *new epuckChooseDirection_Suspend::OnEntry, *new epuckChooseDirection_Suspend::OnExit, *new epuckChooseDirection_Suspend::Internal)
{
	_transitions[0] = new Transition_0();
}

epuckChooseDirection_Suspend::~epuckChooseDirection_Suspend()
{
	delete &onEntryAction();
	delete &onExitAction();
	delete &internalAction();

	delete _transitions[0];
}

void epuckChooseDirection_Suspend::OnEntry::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckTesterByGSM_VarRefs.mm"
#	include "State_epuckChooseDirection_Suspend_VarRefs.mm"
#	include "State_epuckChooseDirection_Suspend_OnEntry.mm"
}

void epuckChooseDirection_Suspend::OnExit::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckTesterByGSM_VarRefs.mm"
#	include "State_epuckChooseDirection_Suspend_VarRefs.mm"
#	include "State_epuckChooseDirection_Suspend_OnExit.mm"
}

void epuckChooseDirection_Suspend::Internal::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckTesterByGSM_VarRefs.mm"
#	include "State_epuckChooseDirection_Suspend_VarRefs.mm"
#	include "State_epuckChooseDirection_Suspend_Internal.mm"
}

bool epuckChooseDirection_Suspend::Transition_0::check(CLMachine *_machine, CLState *_state) const
{
#	include "epuckTesterByGSM_VarRefs.mm"
#	include "State_epuckChooseDirection_Suspend_VarRefs.mm"

	return
	(
#		include "State_epuckChooseDirection_Suspend_Transition_0.expr"
	);
}
