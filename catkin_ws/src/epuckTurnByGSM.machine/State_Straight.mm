//
// State_Straight.mm
//
// Automatically created through MiCASE -- do not change manually!
//
#include "epuckTurnByGSM_Includes.h"
#include "epuckTurnByGSM.h"
#include "State_Straight.h"

#include "State_Straight_Includes.h"

using namespace FSM;
using namespace CLM;
using namespace FSMepuckTurnByGSM;
using namespace State;

Straight::Straight(const char *name): CLState(name, *new Straight::OnEntry, *new Straight::OnExit, *new Straight::Internal)
{
	_transitions[0] = new Transition_0();
}

Straight::~Straight()
{
	delete &onEntryAction();
	delete &onExitAction();
	delete &internalAction();

	delete _transitions[0];
}

void Straight::OnEntry::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckTurnByGSM_VarRefs.mm"
#	include "State_Straight_VarRefs.mm"
#	include "State_Straight_OnEntry.mm"
}

void Straight::OnExit::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckTurnByGSM_VarRefs.mm"
#	include "State_Straight_VarRefs.mm"
#	include "State_Straight_OnExit.mm"
}

void Straight::Internal::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckTurnByGSM_VarRefs.mm"
#	include "State_Straight_VarRefs.mm"
#	include "State_Straight_Internal.mm"
}

bool Straight::Transition_0::check(CLMachine *_machine, CLState *_state) const
{
#	include "epuckTurnByGSM_VarRefs.mm"
#	include "State_Straight_VarRefs.mm"

	return
	(
#		include "State_Straight_Transition_0.expr"
	);
}
