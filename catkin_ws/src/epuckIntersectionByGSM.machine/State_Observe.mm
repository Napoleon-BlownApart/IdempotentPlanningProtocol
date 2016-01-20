//
// State_Observe.mm
//
// Automatically created through MiCASE -- do not change manually!
//
#include "epuckIntersectionByGSM_Includes.h"
#include "epuckIntersectionByGSM.h"
#include "State_Observe.h"

#include "State_Observe_Includes.h"

using namespace FSM;
using namespace CLM;
using namespace FSMepuckIntersectionByGSM;
using namespace State;

Observe::Observe(const char *name): CLState(name, *new Observe::OnEntry, *new Observe::OnExit, *new Observe::Internal)
{
	_transitions[0] = new Transition_0();
	_transitions[1] = new Transition_1();
	_transitions[2] = new Transition_2();
}

Observe::~Observe()
{
	delete &onEntryAction();
	delete &onExitAction();
	delete &internalAction();

	delete _transitions[0];
	delete _transitions[1];
	delete _transitions[2];
}

void Observe::OnEntry::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckIntersectionByGSM_VarRefs.mm"
#	include "State_Observe_VarRefs.mm"
#	include "State_Observe_OnEntry.mm"
}

void Observe::OnExit::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckIntersectionByGSM_VarRefs.mm"
#	include "State_Observe_VarRefs.mm"
#	include "State_Observe_OnExit.mm"
}

void Observe::Internal::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckIntersectionByGSM_VarRefs.mm"
#	include "State_Observe_VarRefs.mm"
#	include "State_Observe_Internal.mm"
}

bool Observe::Transition_0::check(CLMachine *_machine, CLState *_state) const
{
#	include "epuckIntersectionByGSM_VarRefs.mm"
#	include "State_Observe_VarRefs.mm"

	return
	(
#		include "State_Observe_Transition_0.expr"
	);
}

bool Observe::Transition_1::check(CLMachine *_machine, CLState *_state) const
{
#	include "epuckIntersectionByGSM_VarRefs.mm"
#	include "State_Observe_VarRefs.mm"

	return
	(
#		include "State_Observe_Transition_1.expr"
	);
}

bool Observe::Transition_2::check(CLMachine *_machine, CLState *_state) const
{
#	include "epuckIntersectionByGSM_VarRefs.mm"
#	include "State_Observe_VarRefs.mm"

	return
	(
#		include "State_Observe_Transition_2.expr"
	);
}
