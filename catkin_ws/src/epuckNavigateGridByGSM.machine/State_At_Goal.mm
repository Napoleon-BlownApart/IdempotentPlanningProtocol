//
// State_At_Goal.mm
//
// Automatically created through MiCASE -- do not change manually!
//
#include "epuckNavigateGridByGSM_Includes.h"
#include "epuckNavigateGridByGSM.h"
#include "State_At_Goal.h"

#include "State_At_Goal_Includes.h"

using namespace FSM;
using namespace CLM;
using namespace FSMepuckNavigateGridByGSM;
using namespace State;

At_Goal::At_Goal(const char *name): CLState(name, *new At_Goal::OnEntry, *new At_Goal::OnExit, *new At_Goal::Internal)
{
	_transitions[0] = new Transition_0();
}

At_Goal::~At_Goal()
{
	delete &onEntryAction();
	delete &onExitAction();
	delete &internalAction();

	delete _transitions[0];
}

void At_Goal::OnEntry::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckNavigateGridByGSM_VarRefs.mm"
#	include "State_At_Goal_VarRefs.mm"
#	include "State_At_Goal_OnEntry.mm"
}

void At_Goal::OnExit::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckNavigateGridByGSM_VarRefs.mm"
#	include "State_At_Goal_VarRefs.mm"
#	include "State_At_Goal_OnExit.mm"
}

void At_Goal::Internal::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckNavigateGridByGSM_VarRefs.mm"
#	include "State_At_Goal_VarRefs.mm"
#	include "State_At_Goal_Internal.mm"
}

bool At_Goal::Transition_0::check(CLMachine *_machine, CLState *_state) const
{
#	include "epuckNavigateGridByGSM_VarRefs.mm"
#	include "State_At_Goal_VarRefs.mm"

	return
	(
#		include "State_At_Goal_Transition_0.expr"
	);
}
