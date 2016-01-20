//
// State_No_Change.mm
//
// Automatically created through MiCASE -- do not change manually!
//
#include "epuckPlanManagerByGSM_Includes.h"
#include "epuckPlanManagerByGSM.h"
#include "State_No_Change.h"

#include "State_No_Change_Includes.h"

using namespace FSM;
using namespace CLM;
using namespace FSMepuckPlanManagerByGSM;
using namespace State;

No_Change::No_Change(const char *name): CLState(name, *new No_Change::OnEntry, *new No_Change::OnExit, *new No_Change::Internal)
{
	_transitions[0] = new Transition_0();
}

No_Change::~No_Change()
{
	delete &onEntryAction();
	delete &onExitAction();
	delete &internalAction();

	delete _transitions[0];
}

void No_Change::OnEntry::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckPlanManagerByGSM_VarRefs.mm"
#	include "State_No_Change_VarRefs.mm"
#	include "State_No_Change_OnEntry.mm"
}

void No_Change::OnExit::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckPlanManagerByGSM_VarRefs.mm"
#	include "State_No_Change_VarRefs.mm"
#	include "State_No_Change_OnExit.mm"
}

void No_Change::Internal::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckPlanManagerByGSM_VarRefs.mm"
#	include "State_No_Change_VarRefs.mm"
#	include "State_No_Change_Internal.mm"
}

bool No_Change::Transition_0::check(CLMachine *_machine, CLState *_state) const
{
#	include "epuckPlanManagerByGSM_VarRefs.mm"
#	include "State_No_Change_VarRefs.mm"

	return
	(
#		include "State_No_Change_Transition_0.expr"
	);
}
