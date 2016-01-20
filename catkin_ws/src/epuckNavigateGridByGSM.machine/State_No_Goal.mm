//
// State_No_Goal.mm
//
// Automatically created through MiCASE -- do not change manually!
//
#include "epuckNavigateGridByGSM_Includes.h"
#include "epuckNavigateGridByGSM.h"
#include "State_No_Goal.h"

#include "State_No_Goal_Includes.h"

using namespace FSM;
using namespace CLM;
using namespace FSMepuckNavigateGridByGSM;
using namespace State;

No_Goal::No_Goal(const char *name): CLState(name, *new No_Goal::OnEntry, *new No_Goal::OnExit, *new No_Goal::Internal)
{
	_transitions[0] = new Transition_0();
}

No_Goal::~No_Goal()
{
	delete &onEntryAction();
	delete &onExitAction();
	delete &internalAction();

	delete _transitions[0];
}

void No_Goal::OnEntry::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckNavigateGridByGSM_VarRefs.mm"
#	include "State_No_Goal_VarRefs.mm"
#	include "State_No_Goal_OnEntry.mm"
}

void No_Goal::OnExit::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckNavigateGridByGSM_VarRefs.mm"
#	include "State_No_Goal_VarRefs.mm"
#	include "State_No_Goal_OnExit.mm"
}

void No_Goal::Internal::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckNavigateGridByGSM_VarRefs.mm"
#	include "State_No_Goal_VarRefs.mm"
#	include "State_No_Goal_Internal.mm"
}

bool No_Goal::Transition_0::check(CLMachine *_machine, CLState *_state) const
{
#	include "epuckNavigateGridByGSM_VarRefs.mm"
#	include "State_No_Goal_VarRefs.mm"

	return
	(
#		include "State_No_Goal_Transition_0.expr"
	);
}
