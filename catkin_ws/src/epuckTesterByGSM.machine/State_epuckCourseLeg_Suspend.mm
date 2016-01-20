//
// State_epuckCourseLeg_Suspend.mm
//
// Automatically created through MiCASE -- do not change manually!
//
#include "epuckTesterByGSM_Includes.h"
#include "epuckTesterByGSM.h"
#include "State_epuckCourseLeg_Suspend.h"

#include "State_epuckCourseLeg_Suspend_Includes.h"

using namespace FSM;
using namespace CLM;
using namespace FSMepuckTesterByGSM;
using namespace State;

epuckCourseLeg_Suspend::epuckCourseLeg_Suspend(const char *name): CLState(name, *new epuckCourseLeg_Suspend::OnEntry, *new epuckCourseLeg_Suspend::OnExit, *new epuckCourseLeg_Suspend::Internal)
{
	_transitions[0] = new Transition_0();
}

epuckCourseLeg_Suspend::~epuckCourseLeg_Suspend()
{
	delete &onEntryAction();
	delete &onExitAction();
	delete &internalAction();

	delete _transitions[0];
}

void epuckCourseLeg_Suspend::OnEntry::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckTesterByGSM_VarRefs.mm"
#	include "State_epuckCourseLeg_Suspend_VarRefs.mm"
#	include "State_epuckCourseLeg_Suspend_OnEntry.mm"
}

void epuckCourseLeg_Suspend::OnExit::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckTesterByGSM_VarRefs.mm"
#	include "State_epuckCourseLeg_Suspend_VarRefs.mm"
#	include "State_epuckCourseLeg_Suspend_OnExit.mm"
}

void epuckCourseLeg_Suspend::Internal::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckTesterByGSM_VarRefs.mm"
#	include "State_epuckCourseLeg_Suspend_VarRefs.mm"
#	include "State_epuckCourseLeg_Suspend_Internal.mm"
}

bool epuckCourseLeg_Suspend::Transition_0::check(CLMachine *_machine, CLState *_state) const
{
#	include "epuckTesterByGSM_VarRefs.mm"
#	include "State_epuckCourseLeg_Suspend_VarRefs.mm"

	return
	(
#		include "State_epuckCourseLeg_Suspend_Transition_0.expr"
	);
}
