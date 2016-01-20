//
// State_epuckCoordinates_Resume.mm
//
// Automatically created through MiCASE -- do not change manually!
//
#include "epuckTesterByGSM_Includes.h"
#include "epuckTesterByGSM.h"
#include "State_epuckCoordinates_Resume.h"

#include "State_epuckCoordinates_Resume_Includes.h"

using namespace FSM;
using namespace CLM;
using namespace FSMepuckTesterByGSM;
using namespace State;

epuckCoordinates_Resume::epuckCoordinates_Resume(const char *name): CLState(name, *new epuckCoordinates_Resume::OnEntry, *new epuckCoordinates_Resume::OnExit, *new epuckCoordinates_Resume::Internal)
{
	_transitions[0] = new Transition_0();
}

epuckCoordinates_Resume::~epuckCoordinates_Resume()
{
	delete &onEntryAction();
	delete &onExitAction();
	delete &internalAction();

	delete _transitions[0];
}

void epuckCoordinates_Resume::OnEntry::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckTesterByGSM_VarRefs.mm"
#	include "State_epuckCoordinates_Resume_VarRefs.mm"
#	include "State_epuckCoordinates_Resume_OnEntry.mm"
}

void epuckCoordinates_Resume::OnExit::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckTesterByGSM_VarRefs.mm"
#	include "State_epuckCoordinates_Resume_VarRefs.mm"
#	include "State_epuckCoordinates_Resume_OnExit.mm"
}

void epuckCoordinates_Resume::Internal::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckTesterByGSM_VarRefs.mm"
#	include "State_epuckCoordinates_Resume_VarRefs.mm"
#	include "State_epuckCoordinates_Resume_Internal.mm"
}

bool epuckCoordinates_Resume::Transition_0::check(CLMachine *_machine, CLState *_state) const
{
#	include "epuckTesterByGSM_VarRefs.mm"
#	include "State_epuckCoordinates_Resume_VarRefs.mm"

	return
	(
#		include "State_epuckCoordinates_Resume_Transition_0.expr"
	);
}
