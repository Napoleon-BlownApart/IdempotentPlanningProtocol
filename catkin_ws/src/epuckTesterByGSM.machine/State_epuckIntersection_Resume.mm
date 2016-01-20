//
// State_epuckIntersection_Resume.mm
//
// Automatically created through MiCASE -- do not change manually!
//
#include "epuckTesterByGSM_Includes.h"
#include "epuckTesterByGSM.h"
#include "State_epuckIntersection_Resume.h"

#include "State_epuckIntersection_Resume_Includes.h"

using namespace FSM;
using namespace CLM;
using namespace FSMepuckTesterByGSM;
using namespace State;

epuckIntersection_Resume::epuckIntersection_Resume(const char *name): CLState(name, *new epuckIntersection_Resume::OnEntry, *new epuckIntersection_Resume::OnExit, *new epuckIntersection_Resume::Internal)
{
	_transitions[0] = new Transition_0();
}

epuckIntersection_Resume::~epuckIntersection_Resume()
{
	delete &onEntryAction();
	delete &onExitAction();
	delete &internalAction();

	delete _transitions[0];
}

void epuckIntersection_Resume::OnEntry::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckTesterByGSM_VarRefs.mm"
#	include "State_epuckIntersection_Resume_VarRefs.mm"
#	include "State_epuckIntersection_Resume_OnEntry.mm"
}

void epuckIntersection_Resume::OnExit::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckTesterByGSM_VarRefs.mm"
#	include "State_epuckIntersection_Resume_VarRefs.mm"
#	include "State_epuckIntersection_Resume_OnExit.mm"
}

void epuckIntersection_Resume::Internal::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckTesterByGSM_VarRefs.mm"
#	include "State_epuckIntersection_Resume_VarRefs.mm"
#	include "State_epuckIntersection_Resume_Internal.mm"
}

bool epuckIntersection_Resume::Transition_0::check(CLMachine *_machine, CLState *_state) const
{
#	include "epuckTesterByGSM_VarRefs.mm"
#	include "State_epuckIntersection_Resume_VarRefs.mm"

	return
	(
#		include "State_epuckIntersection_Resume_Transition_0.expr"
	);
}
