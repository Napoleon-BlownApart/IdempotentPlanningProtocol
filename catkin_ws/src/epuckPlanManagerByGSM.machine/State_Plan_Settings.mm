//
// State_Plan_Settings.mm
//
// Automatically created through MiCASE -- do not change manually!
//
#include "epuckPlanManagerByGSM_Includes.h"
#include "epuckPlanManagerByGSM.h"
#include "State_Plan_Settings.h"

#include "State_Plan_Settings_Includes.h"

using namespace FSM;
using namespace CLM;
using namespace FSMepuckPlanManagerByGSM;
using namespace State;

Plan_Settings::Plan_Settings(const char *name): CLState(name, *new Plan_Settings::OnEntry, *new Plan_Settings::OnExit, *new Plan_Settings::Internal)
{
	_transitions[0] = new Transition_0();
}

Plan_Settings::~Plan_Settings()
{
	delete &onEntryAction();
	delete &onExitAction();
	delete &internalAction();

	delete _transitions[0];
}

void Plan_Settings::OnEntry::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckPlanManagerByGSM_VarRefs.mm"
#	include "State_Plan_Settings_VarRefs.mm"
#	include "State_Plan_Settings_OnEntry.mm"
}

void Plan_Settings::OnExit::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckPlanManagerByGSM_VarRefs.mm"
#	include "State_Plan_Settings_VarRefs.mm"
#	include "State_Plan_Settings_OnExit.mm"
}

void Plan_Settings::Internal::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckPlanManagerByGSM_VarRefs.mm"
#	include "State_Plan_Settings_VarRefs.mm"
#	include "State_Plan_Settings_Internal.mm"
}

bool Plan_Settings::Transition_0::check(CLMachine *_machine, CLState *_state) const
{
#	include "epuckPlanManagerByGSM_VarRefs.mm"
#	include "State_Plan_Settings_VarRefs.mm"

	return
	(
#		include "State_Plan_Settings_Transition_0.expr"
	);
}
