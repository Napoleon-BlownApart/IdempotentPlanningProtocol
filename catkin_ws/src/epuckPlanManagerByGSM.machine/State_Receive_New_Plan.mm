//
// State_Receive_New_Plan.mm
//
// Automatically created through MiCASE -- do not change manually!
//
#include "epuckPlanManagerByGSM_Includes.h"
#include "epuckPlanManagerByGSM.h"
#include "State_Receive_New_Plan.h"

#include "State_Receive_New_Plan_Includes.h"

using namespace FSM;
using namespace CLM;
using namespace FSMepuckPlanManagerByGSM;
using namespace State;

Receive_New_Plan::Receive_New_Plan(const char *name): CLState(name, *new Receive_New_Plan::OnEntry, *new Receive_New_Plan::OnExit, *new Receive_New_Plan::Internal)
{
	_transitions[0] = new Transition_0();
}

Receive_New_Plan::~Receive_New_Plan()
{
	delete &onEntryAction();
	delete &onExitAction();
	delete &internalAction();

	delete _transitions[0];
}

void Receive_New_Plan::OnEntry::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckPlanManagerByGSM_VarRefs.mm"
#	include "State_Receive_New_Plan_VarRefs.mm"
#	include "State_Receive_New_Plan_OnEntry.mm"
}

void Receive_New_Plan::OnExit::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckPlanManagerByGSM_VarRefs.mm"
#	include "State_Receive_New_Plan_VarRefs.mm"
#	include "State_Receive_New_Plan_OnExit.mm"
}

void Receive_New_Plan::Internal::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckPlanManagerByGSM_VarRefs.mm"
#	include "State_Receive_New_Plan_VarRefs.mm"
#	include "State_Receive_New_Plan_Internal.mm"
}

bool Receive_New_Plan::Transition_0::check(CLMachine *_machine, CLState *_state) const
{
#	include "epuckPlanManagerByGSM_VarRefs.mm"
#	include "State_Receive_New_Plan_VarRefs.mm"

	return
	(
#		include "State_Receive_New_Plan_Transition_0.expr"
	);
}
