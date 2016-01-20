//
// State_epuckOrientation_Suspend.mm
//
// Automatically created through MiCASE -- do not change manually!
//
#include "epuckTesterByGSM_Includes.h"
#include "epuckTesterByGSM.h"
#include "State_epuckOrientation_Suspend.h"

#include "State_epuckOrientation_Suspend_Includes.h"

using namespace FSM;
using namespace CLM;
using namespace FSMepuckTesterByGSM;
using namespace State;

epuckOrientation_Suspend::epuckOrientation_Suspend(const char *name): CLState(name, *new epuckOrientation_Suspend::OnEntry, *new epuckOrientation_Suspend::OnExit, *new epuckOrientation_Suspend::Internal)
{
	_transitions[0] = new Transition_0();
}

epuckOrientation_Suspend::~epuckOrientation_Suspend()
{
	delete &onEntryAction();
	delete &onExitAction();
	delete &internalAction();

	delete _transitions[0];
}

void epuckOrientation_Suspend::OnEntry::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckTesterByGSM_VarRefs.mm"
#	include "State_epuckOrientation_Suspend_VarRefs.mm"
#	include "State_epuckOrientation_Suspend_OnEntry.mm"
}

void epuckOrientation_Suspend::OnExit::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckTesterByGSM_VarRefs.mm"
#	include "State_epuckOrientation_Suspend_VarRefs.mm"
#	include "State_epuckOrientation_Suspend_OnExit.mm"
}

void epuckOrientation_Suspend::Internal::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckTesterByGSM_VarRefs.mm"
#	include "State_epuckOrientation_Suspend_VarRefs.mm"
#	include "State_epuckOrientation_Suspend_Internal.mm"
}

bool epuckOrientation_Suspend::Transition_0::check(CLMachine *_machine, CLState *_state) const
{
#	include "epuckTesterByGSM_VarRefs.mm"
#	include "State_epuckOrientation_Suspend_VarRefs.mm"

	return
	(
#		include "State_epuckOrientation_Suspend_Transition_0.expr"
	);
}
