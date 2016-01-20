//
// State_Get_A_Portion.mm
//
// Automatically created through MiCASE -- do not change manually!
//
#include "epuckPlanManagerByGSM_Includes.h"
#include "epuckPlanManagerByGSM.h"
#include "State_Get_A_Portion.h"

#include "State_Get_A_Portion_Includes.h"

using namespace FSM;
using namespace CLM;
using namespace FSMepuckPlanManagerByGSM;
using namespace State;

Get_A_Portion::Get_A_Portion(const char *name): CLState(name, *new Get_A_Portion::OnEntry, *new Get_A_Portion::OnExit, *new Get_A_Portion::Internal)
{
	_transitions[0] = new Transition_0();
}

Get_A_Portion::~Get_A_Portion()
{
	delete &onEntryAction();
	delete &onExitAction();
	delete &internalAction();

	delete _transitions[0];
}

void Get_A_Portion::OnEntry::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckPlanManagerByGSM_VarRefs.mm"
#	include "State_Get_A_Portion_VarRefs.mm"
#	include "State_Get_A_Portion_OnEntry.mm"
}

void Get_A_Portion::OnExit::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckPlanManagerByGSM_VarRefs.mm"
#	include "State_Get_A_Portion_VarRefs.mm"
#	include "State_Get_A_Portion_OnExit.mm"
}

void Get_A_Portion::Internal::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckPlanManagerByGSM_VarRefs.mm"
#	include "State_Get_A_Portion_VarRefs.mm"
#	include "State_Get_A_Portion_Internal.mm"
}

bool Get_A_Portion::Transition_0::check(CLMachine *_machine, CLState *_state) const
{
#	include "epuckPlanManagerByGSM_VarRefs.mm"
#	include "State_Get_A_Portion_VarRefs.mm"

	return
	(
#		include "State_Get_A_Portion_Transition_0.expr"
	);
}
