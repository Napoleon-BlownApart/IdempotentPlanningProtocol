//
// State_epuckCourseLeg_Resume.mm
//
// Automatically created through MiCASE -- do not change manually!
//
#include "epuckTesterByGSM_Includes.h"
#include "epuckTesterByGSM.h"
#include "State_epuckCourseLeg_Resume.h"

#include "State_epuckCourseLeg_Resume_Includes.h"

using namespace FSM;
using namespace CLM;
using namespace FSMepuckTesterByGSM;
using namespace State;

epuckCourseLeg_Resume::epuckCourseLeg_Resume(const char *name): CLState(name, *new epuckCourseLeg_Resume::OnEntry, *new epuckCourseLeg_Resume::OnExit, *new epuckCourseLeg_Resume::Internal)
{
	_transitions[0] = new Transition_0();
}

epuckCourseLeg_Resume::~epuckCourseLeg_Resume()
{
	delete &onEntryAction();
	delete &onExitAction();
	delete &internalAction();

	delete _transitions[0];
}

void epuckCourseLeg_Resume::OnEntry::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckTesterByGSM_VarRefs.mm"
#	include "State_epuckCourseLeg_Resume_VarRefs.mm"
#	include "State_epuckCourseLeg_Resume_OnEntry.mm"
}

void epuckCourseLeg_Resume::OnExit::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckTesterByGSM_VarRefs.mm"
#	include "State_epuckCourseLeg_Resume_VarRefs.mm"
#	include "State_epuckCourseLeg_Resume_OnExit.mm"
}

void epuckCourseLeg_Resume::Internal::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckTesterByGSM_VarRefs.mm"
#	include "State_epuckCourseLeg_Resume_VarRefs.mm"
#	include "State_epuckCourseLeg_Resume_Internal.mm"
}

bool epuckCourseLeg_Resume::Transition_0::check(CLMachine *_machine, CLState *_state) const
{
#	include "epuckTesterByGSM_VarRefs.mm"
#	include "State_epuckCourseLeg_Resume_VarRefs.mm"

	return
	(
#		include "State_epuckCourseLeg_Resume_Transition_0.expr"
	);
}
