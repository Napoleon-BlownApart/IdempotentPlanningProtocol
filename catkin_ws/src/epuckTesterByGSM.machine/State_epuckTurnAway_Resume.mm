//
// State_epuckTurnAway_Resume.mm
//
// Automatically created through MiCASE -- do not change manually!
//
#include "epuckTesterByGSM_Includes.h"
#include "epuckTesterByGSM.h"
#include "State_epuckTurnAway_Resume.h"

#include "State_epuckTurnAway_Resume_Includes.h"

using namespace FSM;
using namespace CLM;
using namespace FSMepuckTesterByGSM;
using namespace State;

epuckTurnAway_Resume::epuckTurnAway_Resume(const char *name): CLState(name, *new epuckTurnAway_Resume::OnEntry, *new epuckTurnAway_Resume::OnExit, *new epuckTurnAway_Resume::Internal)
{
	_transitions[0] = new Transition_0();
}

epuckTurnAway_Resume::~epuckTurnAway_Resume()
{
	delete &onEntryAction();
	delete &onExitAction();
	delete &internalAction();

	delete _transitions[0];
}

void epuckTurnAway_Resume::OnEntry::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckTesterByGSM_VarRefs.mm"
#	include "State_epuckTurnAway_Resume_VarRefs.mm"
#	include "State_epuckTurnAway_Resume_OnEntry.mm"
}

void epuckTurnAway_Resume::OnExit::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckTesterByGSM_VarRefs.mm"
#	include "State_epuckTurnAway_Resume_VarRefs.mm"
#	include "State_epuckTurnAway_Resume_OnExit.mm"
}

void epuckTurnAway_Resume::Internal::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckTesterByGSM_VarRefs.mm"
#	include "State_epuckTurnAway_Resume_VarRefs.mm"
#	include "State_epuckTurnAway_Resume_Internal.mm"
}

bool epuckTurnAway_Resume::Transition_0::check(CLMachine *_machine, CLState *_state) const
{
#	include "epuckTesterByGSM_VarRefs.mm"
#	include "State_epuckTurnAway_Resume_VarRefs.mm"

	return
	(
#		include "State_epuckTurnAway_Resume_Transition_0.expr"
	);
}
