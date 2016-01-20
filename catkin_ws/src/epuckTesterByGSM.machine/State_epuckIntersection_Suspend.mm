//
// State_epuckIntersection_Suspend.mm
//
// Automatically created through MiCASE -- do not change manually!
//
#include "epuckTesterByGSM_Includes.h"
#include "epuckTesterByGSM.h"
#include "State_epuckIntersection_Suspend.h"

#include "State_epuckIntersection_Suspend_Includes.h"

using namespace FSM;
using namespace CLM;
using namespace FSMepuckTesterByGSM;
using namespace State;

epuckIntersection_Suspend::epuckIntersection_Suspend(const char *name): CLState(name, *new epuckIntersection_Suspend::OnEntry, *new epuckIntersection_Suspend::OnExit, *new epuckIntersection_Suspend::Internal)
{
	_transitions[0] = new Transition_0();
}

epuckIntersection_Suspend::~epuckIntersection_Suspend()
{
	delete &onEntryAction();
	delete &onExitAction();
	delete &internalAction();

	delete _transitions[0];
}

void epuckIntersection_Suspend::OnEntry::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckTesterByGSM_VarRefs.mm"
#	include "State_epuckIntersection_Suspend_VarRefs.mm"
#	include "State_epuckIntersection_Suspend_OnEntry.mm"
}

void epuckIntersection_Suspend::OnExit::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckTesterByGSM_VarRefs.mm"
#	include "State_epuckIntersection_Suspend_VarRefs.mm"
#	include "State_epuckIntersection_Suspend_OnExit.mm"
}

void epuckIntersection_Suspend::Internal::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckTesterByGSM_VarRefs.mm"
#	include "State_epuckIntersection_Suspend_VarRefs.mm"
#	include "State_epuckIntersection_Suspend_Internal.mm"
}

bool epuckIntersection_Suspend::Transition_0::check(CLMachine *_machine, CLState *_state) const
{
#	include "epuckTesterByGSM_VarRefs.mm"
#	include "State_epuckIntersection_Suspend_VarRefs.mm"

	return
	(
#		include "State_epuckIntersection_Suspend_Transition_0.expr"
	);
}
