//
// State_observe.mm
//
// Automatically created through MiCASE -- do not change manually!
//
#include "epuckTesterByGSM_Includes.h"
#include "epuckTesterByGSM.h"
#include "State_observe.h"

#include "State_observe_Includes.h"

using namespace FSM;
using namespace CLM;
using namespace FSMepuckTesterByGSM;
using namespace State;

observe::observe(const char *name): CLState(name, *new observe::OnEntry, *new observe::OnExit, *new observe::Internal)
{
	_transitions[0] = new Transition_0();
}

observe::~observe()
{
	delete &onEntryAction();
	delete &onExitAction();
	delete &internalAction();

	delete _transitions[0];
}

void observe::OnEntry::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckTesterByGSM_VarRefs.mm"
#	include "State_observe_VarRefs.mm"
#	include "State_observe_OnEntry.mm"
}

void observe::OnExit::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckTesterByGSM_VarRefs.mm"
#	include "State_observe_VarRefs.mm"
#	include "State_observe_OnExit.mm"
}

void observe::Internal::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckTesterByGSM_VarRefs.mm"
#	include "State_observe_VarRefs.mm"
#	include "State_observe_Internal.mm"
}

bool observe::Transition_0::check(CLMachine *_machine, CLState *_state) const
{
#	include "epuckTesterByGSM_VarRefs.mm"
#	include "State_observe_VarRefs.mm"

	return
	(
#		include "State_observe_Transition_0.expr"
	);
}
