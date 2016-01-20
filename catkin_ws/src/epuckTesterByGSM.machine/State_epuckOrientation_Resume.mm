//
// State_epuckOrientation_Resume.mm
//
// Automatically created through MiCASE -- do not change manually!
//
#include "epuckTesterByGSM_Includes.h"
#include "epuckTesterByGSM.h"
#include "State_epuckOrientation_Resume.h"

#include "State_epuckOrientation_Resume_Includes.h"

using namespace FSM;
using namespace CLM;
using namespace FSMepuckTesterByGSM;
using namespace State;

epuckOrientation_Resume::epuckOrientation_Resume(const char *name): CLState(name, *new epuckOrientation_Resume::OnEntry, *new epuckOrientation_Resume::OnExit, *new epuckOrientation_Resume::Internal)
{
	_transitions[0] = new Transition_0();
}

epuckOrientation_Resume::~epuckOrientation_Resume()
{
	delete &onEntryAction();
	delete &onExitAction();
	delete &internalAction();

	delete _transitions[0];
}

void epuckOrientation_Resume::OnEntry::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckTesterByGSM_VarRefs.mm"
#	include "State_epuckOrientation_Resume_VarRefs.mm"
#	include "State_epuckOrientation_Resume_OnEntry.mm"
}

void epuckOrientation_Resume::OnExit::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckTesterByGSM_VarRefs.mm"
#	include "State_epuckOrientation_Resume_VarRefs.mm"
#	include "State_epuckOrientation_Resume_OnExit.mm"
}

void epuckOrientation_Resume::Internal::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckTesterByGSM_VarRefs.mm"
#	include "State_epuckOrientation_Resume_VarRefs.mm"
#	include "State_epuckOrientation_Resume_Internal.mm"
}

bool epuckOrientation_Resume::Transition_0::check(CLMachine *_machine, CLState *_state) const
{
#	include "epuckTesterByGSM_VarRefs.mm"
#	include "State_epuckOrientation_Resume_VarRefs.mm"

	return
	(
#		include "State_epuckOrientation_Resume_Transition_0.expr"
	);
}
