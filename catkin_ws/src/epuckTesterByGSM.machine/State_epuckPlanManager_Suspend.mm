//
// State_epuckPlanManager_Suspend.mm
//
// Automatically created through MiCASE -- do not change manually!
//
#include "epuckTesterByGSM_Includes.h"
#include "epuckTesterByGSM.h"
#include "State_epuckPlanManager_Suspend.h"

#include "State_epuckPlanManager_Suspend_Includes.h"

using namespace FSM;
using namespace CLM;
using namespace FSMepuckTesterByGSM;
using namespace State;

epuckPlanManager_Suspend::epuckPlanManager_Suspend(const char *name): CLState(name, *new epuckPlanManager_Suspend::OnEntry, *new epuckPlanManager_Suspend::OnExit, *new epuckPlanManager_Suspend::Internal)
{
	_transitions[0] = new Transition_0();
}

epuckPlanManager_Suspend::~epuckPlanManager_Suspend()
{
	delete &onEntryAction();
	delete &onExitAction();
	delete &internalAction();

	delete _transitions[0];
}

void epuckPlanManager_Suspend::OnEntry::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckTesterByGSM_VarRefs.mm"
#	include "State_epuckPlanManager_Suspend_VarRefs.mm"
#	include "State_epuckPlanManager_Suspend_OnEntry.mm"
}

void epuckPlanManager_Suspend::OnExit::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckTesterByGSM_VarRefs.mm"
#	include "State_epuckPlanManager_Suspend_VarRefs.mm"
#	include "State_epuckPlanManager_Suspend_OnExit.mm"
}

void epuckPlanManager_Suspend::Internal::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckTesterByGSM_VarRefs.mm"
#	include "State_epuckPlanManager_Suspend_VarRefs.mm"
#	include "State_epuckPlanManager_Suspend_Internal.mm"
}

bool epuckPlanManager_Suspend::Transition_0::check(CLMachine *_machine, CLState *_state) const
{
#	include "epuckTesterByGSM_VarRefs.mm"
#	include "State_epuckPlanManager_Suspend_VarRefs.mm"

	return
	(
#		include "State_epuckPlanManager_Suspend_Transition_0.expr"
	);
}
