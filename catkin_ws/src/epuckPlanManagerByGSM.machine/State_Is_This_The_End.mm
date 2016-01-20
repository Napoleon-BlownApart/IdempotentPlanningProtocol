//
// State_Is_This_The_End.mm
//
// Automatically created through MiCASE -- do not change manually!
//
#include "epuckPlanManagerByGSM_Includes.h"
#include "epuckPlanManagerByGSM.h"
#include "State_Is_This_The_End.h"

#include "State_Is_This_The_End_Includes.h"

using namespace FSM;
using namespace CLM;
using namespace FSMepuckPlanManagerByGSM;
using namespace State;

Is_This_The_End::Is_This_The_End(const char *name): CLState(name, *new Is_This_The_End::OnEntry, *new Is_This_The_End::OnExit, *new Is_This_The_End::Internal)
{
	_transitions[0] = new Transition_0();
	_transitions[1] = new Transition_1();
}

Is_This_The_End::~Is_This_The_End()
{
	delete &onEntryAction();
	delete &onExitAction();
	delete &internalAction();

	delete _transitions[0];
	delete _transitions[1];
}

void Is_This_The_End::OnEntry::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckPlanManagerByGSM_VarRefs.mm"
#	include "State_Is_This_The_End_VarRefs.mm"
#	include "State_Is_This_The_End_OnEntry.mm"
}

void Is_This_The_End::OnExit::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckPlanManagerByGSM_VarRefs.mm"
#	include "State_Is_This_The_End_VarRefs.mm"
#	include "State_Is_This_The_End_OnExit.mm"
}

void Is_This_The_End::Internal::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckPlanManagerByGSM_VarRefs.mm"
#	include "State_Is_This_The_End_VarRefs.mm"
#	include "State_Is_This_The_End_Internal.mm"
}

bool Is_This_The_End::Transition_0::check(CLMachine *_machine, CLState *_state) const
{
#	include "epuckPlanManagerByGSM_VarRefs.mm"
#	include "State_Is_This_The_End_VarRefs.mm"

	return
	(
#		include "State_Is_This_The_End_Transition_0.expr"
	);
}

bool Is_This_The_End::Transition_1::check(CLMachine *_machine, CLState *_state) const
{
#	include "epuckPlanManagerByGSM_VarRefs.mm"
#	include "State_Is_This_The_End_VarRefs.mm"

	return
	(
#		include "State_Is_This_The_End_Transition_1.expr"
	);
}
