//
// State_Set_Next_Goal.mm
//
// Automatically created through MiCASE -- do not change manually!
//
#include "epuckPlanManagerByGSM_Includes.h"
#include "epuckPlanManagerByGSM.h"
#include "State_Set_Next_Goal.h"

#include "State_Set_Next_Goal_Includes.h"

using namespace FSM;
using namespace CLM;
using namespace FSMepuckPlanManagerByGSM;
using namespace State;

Set_Next_Goal::Set_Next_Goal(const char *name): CLState(name, *new Set_Next_Goal::OnEntry, *new Set_Next_Goal::OnExit, *new Set_Next_Goal::Internal)
{
	_transitions[0] = new Transition_0();
}

Set_Next_Goal::~Set_Next_Goal()
{
	delete &onEntryAction();
	delete &onExitAction();
	delete &internalAction();

	delete _transitions[0];
}

void Set_Next_Goal::OnEntry::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckPlanManagerByGSM_VarRefs.mm"
#	include "State_Set_Next_Goal_VarRefs.mm"
#	include "State_Set_Next_Goal_OnEntry.mm"
}

void Set_Next_Goal::OnExit::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckPlanManagerByGSM_VarRefs.mm"
#	include "State_Set_Next_Goal_VarRefs.mm"
#	include "State_Set_Next_Goal_OnExit.mm"
}

void Set_Next_Goal::Internal::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckPlanManagerByGSM_VarRefs.mm"
#	include "State_Set_Next_Goal_VarRefs.mm"
#	include "State_Set_Next_Goal_Internal.mm"
}

bool Set_Next_Goal::Transition_0::check(CLMachine *_machine, CLState *_state) const
{
#	include "epuckPlanManagerByGSM_VarRefs.mm"
#	include "State_Set_Next_Goal_VarRefs.mm"

	return
	(
#		include "State_Set_Next_Goal_Transition_0.expr"
	);
}
