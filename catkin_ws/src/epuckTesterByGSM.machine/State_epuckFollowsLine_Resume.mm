//
// State_epuckFollowsLine_Resume.mm
//
// Automatically created through MiCASE -- do not change manually!
//
#include "epuckTesterByGSM_Includes.h"
#include "epuckTesterByGSM.h"
#include "State_epuckFollowsLine_Resume.h"

#include "State_epuckFollowsLine_Resume_Includes.h"

using namespace FSM;
using namespace CLM;
using namespace FSMepuckTesterByGSM;
using namespace State;

epuckFollowsLine_Resume::epuckFollowsLine_Resume(const char *name): CLState(name, *new epuckFollowsLine_Resume::OnEntry, *new epuckFollowsLine_Resume::OnExit, *new epuckFollowsLine_Resume::Internal)
{
	_transitions[0] = new Transition_0();
}

epuckFollowsLine_Resume::~epuckFollowsLine_Resume()
{
	delete &onEntryAction();
	delete &onExitAction();
	delete &internalAction();

	delete _transitions[0];
}

void epuckFollowsLine_Resume::OnEntry::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckTesterByGSM_VarRefs.mm"
#	include "State_epuckFollowsLine_Resume_VarRefs.mm"
#	include "State_epuckFollowsLine_Resume_OnEntry.mm"
}

void epuckFollowsLine_Resume::OnExit::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckTesterByGSM_VarRefs.mm"
#	include "State_epuckFollowsLine_Resume_VarRefs.mm"
#	include "State_epuckFollowsLine_Resume_OnExit.mm"
}

void epuckFollowsLine_Resume::Internal::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckTesterByGSM_VarRefs.mm"
#	include "State_epuckFollowsLine_Resume_VarRefs.mm"
#	include "State_epuckFollowsLine_Resume_Internal.mm"
}

bool epuckFollowsLine_Resume::Transition_0::check(CLMachine *_machine, CLState *_state) const
{
#	include "epuckTesterByGSM_VarRefs.mm"
#	include "State_epuckFollowsLine_Resume_VarRefs.mm"

	return
	(
#		include "State_epuckFollowsLine_Resume_Transition_0.expr"
	);
}
