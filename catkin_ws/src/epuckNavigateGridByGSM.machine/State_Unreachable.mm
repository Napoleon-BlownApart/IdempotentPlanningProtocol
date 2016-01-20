//
// State_Unreachable.mm
//
// Automatically created through MiCASE -- do not change manually!
//
#include "epuckNavigateGridByGSM_Includes.h"
#include "epuckNavigateGridByGSM.h"
#include "State_Unreachable.h"

#include "State_Unreachable_Includes.h"

using namespace FSM;
using namespace CLM;
using namespace FSMepuckNavigateGridByGSM;
using namespace State;

Unreachable::Unreachable(const char *name): CLState(name, *new Unreachable::OnEntry, *new Unreachable::OnExit, *new Unreachable::Internal)
{
	_transitions[0] = new Transition_0();
}

Unreachable::~Unreachable()
{
	delete &onEntryAction();
	delete &onExitAction();
	delete &internalAction();

	delete _transitions[0];
}

void Unreachable::OnEntry::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckNavigateGridByGSM_VarRefs.mm"
#	include "State_Unreachable_VarRefs.mm"
#	include "State_Unreachable_OnEntry.mm"
}

void Unreachable::OnExit::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckNavigateGridByGSM_VarRefs.mm"
#	include "State_Unreachable_VarRefs.mm"
#	include "State_Unreachable_OnExit.mm"
}

void Unreachable::Internal::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckNavigateGridByGSM_VarRefs.mm"
#	include "State_Unreachable_VarRefs.mm"
#	include "State_Unreachable_Internal.mm"
}

bool Unreachable::Transition_0::check(CLMachine *_machine, CLState *_state) const
{
#	include "epuckNavigateGridByGSM_VarRefs.mm"
#	include "State_Unreachable_VarRefs.mm"

	return
	(
#		include "State_Unreachable_Transition_0.expr"
	);
}
