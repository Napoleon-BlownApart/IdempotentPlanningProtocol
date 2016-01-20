//
// State_Request_New_Plan.mm
//
// Automatically created through MiCASE -- do not change manually!
//
#include "epuckPlanManagerByGSM_Includes.h"
#include "epuckPlanManagerByGSM.h"
#include "State_Request_New_Plan.h"

#include "State_Request_New_Plan_Includes.h"

using namespace FSM;
using namespace CLM;
using namespace FSMepuckPlanManagerByGSM;
using namespace State;

Request_New_Plan::Request_New_Plan(const char *name): CLState(name, *new Request_New_Plan::OnEntry, *new Request_New_Plan::OnExit, *new Request_New_Plan::Internal)
{
	_transitions[0] = new Transition_0();
}

Request_New_Plan::~Request_New_Plan()
{
	delete &onEntryAction();
	delete &onExitAction();
	delete &internalAction();

	delete _transitions[0];
}

void Request_New_Plan::OnEntry::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckPlanManagerByGSM_VarRefs.mm"
#	include "State_Request_New_Plan_VarRefs.mm"
#	include "State_Request_New_Plan_OnEntry.mm"
}

void Request_New_Plan::OnExit::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckPlanManagerByGSM_VarRefs.mm"
#	include "State_Request_New_Plan_VarRefs.mm"
#	include "State_Request_New_Plan_OnExit.mm"
}

void Request_New_Plan::Internal::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckPlanManagerByGSM_VarRefs.mm"
#	include "State_Request_New_Plan_VarRefs.mm"
#	include "State_Request_New_Plan_Internal.mm"
}

bool Request_New_Plan::Transition_0::check(CLMachine *_machine, CLState *_state) const
{
#	include "epuckPlanManagerByGSM_VarRefs.mm"
#	include "State_Request_New_Plan_VarRefs.mm"

	return
	(
#		include "State_Request_New_Plan_Transition_0.expr"
	);
}
