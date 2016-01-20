//
// State_epuckTurn_Resume.mm
//
// Automatically created through MiCASE -- do not change manually!
//
#include "epuckTesterByGSM_Includes.h"
#include "epuckTesterByGSM.h"
#include "State_epuckTurn_Resume.h"

#include "State_epuckTurn_Resume_Includes.h"

using namespace FSM;
using namespace CLM;
using namespace FSMepuckTesterByGSM;
using namespace State;

epuckTurn_Resume::epuckTurn_Resume(const char *name): CLState(name, *new epuckTurn_Resume::OnEntry, *new epuckTurn_Resume::OnExit, *new epuckTurn_Resume::Internal)
{
	_transitions[0] = new Transition_0();
}

epuckTurn_Resume::~epuckTurn_Resume()
{
	delete &onEntryAction();
	delete &onExitAction();
	delete &internalAction();

	delete _transitions[0];
}

void epuckTurn_Resume::OnEntry::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckTesterByGSM_VarRefs.mm"
#	include "State_epuckTurn_Resume_VarRefs.mm"
#	include "State_epuckTurn_Resume_OnEntry.mm"
}

void epuckTurn_Resume::OnExit::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckTesterByGSM_VarRefs.mm"
#	include "State_epuckTurn_Resume_VarRefs.mm"
#	include "State_epuckTurn_Resume_OnExit.mm"
}

void epuckTurn_Resume::Internal::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckTesterByGSM_VarRefs.mm"
#	include "State_epuckTurn_Resume_VarRefs.mm"
#	include "State_epuckTurn_Resume_Internal.mm"
}

bool epuckTurn_Resume::Transition_0::check(CLMachine *_machine, CLState *_state) const
{
#	include "epuckTesterByGSM_VarRefs.mm"
#	include "State_epuckTurn_Resume_VarRefs.mm"

	return
	(
#		include "State_epuckTurn_Resume_Transition_0.expr"
	);
}
