//
// State_epuckPlanManager_Resume.mm
//
// Automatically created through MiCASE -- do not change manually!
//
#include "epuckTesterByGSM_Includes.h"
#include "epuckTesterByGSM.h"
#include "State_epuckPlanManager_Resume.h"

#include "State_epuckPlanManager_Resume_Includes.h"

using namespace FSM;
using namespace CLM;
using namespace FSMepuckTesterByGSM;
using namespace State;

epuckPlanManager_Resume::epuckPlanManager_Resume(const char *name): CLState(name, *new epuckPlanManager_Resume::OnEntry, *new epuckPlanManager_Resume::OnExit, *new epuckPlanManager_Resume::Internal)
{
	_transitions[0] = new Transition_0();
}

epuckPlanManager_Resume::~epuckPlanManager_Resume()
{
	delete &onEntryAction();
	delete &onExitAction();
	delete &internalAction();

	delete _transitions[0];
}

void epuckPlanManager_Resume::OnEntry::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckTesterByGSM_VarRefs.mm"
#	include "State_epuckPlanManager_Resume_VarRefs.mm"
#	include "State_epuckPlanManager_Resume_OnEntry.mm"
}

void epuckPlanManager_Resume::OnExit::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckTesterByGSM_VarRefs.mm"
#	include "State_epuckPlanManager_Resume_VarRefs.mm"
#	include "State_epuckPlanManager_Resume_OnExit.mm"
}

void epuckPlanManager_Resume::Internal::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckTesterByGSM_VarRefs.mm"
#	include "State_epuckPlanManager_Resume_VarRefs.mm"
#	include "State_epuckPlanManager_Resume_Internal.mm"
}

bool epuckPlanManager_Resume::Transition_0::check(CLMachine *_machine, CLState *_state) const
{
#	include "epuckTesterByGSM_VarRefs.mm"
#	include "State_epuckPlanManager_Resume_VarRefs.mm"

	return
	(
#		include "State_epuckPlanManager_Resume_Transition_0.expr"
	);
}
