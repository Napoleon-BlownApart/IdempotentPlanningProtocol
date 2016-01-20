//
// State_Is_Array_Full.mm
//
// Automatically created through MiCASE -- do not change manually!
//
#include "epuckPlanManagerByGSM_Includes.h"
#include "epuckPlanManagerByGSM.h"
#include "State_Is_Array_Full.h"

#include "State_Is_Array_Full_Includes.h"

using namespace FSM;
using namespace CLM;
using namespace FSMepuckPlanManagerByGSM;
using namespace State;

Is_Array_Full::Is_Array_Full(const char *name): CLState(name, *new Is_Array_Full::OnEntry, *new Is_Array_Full::OnExit, *new Is_Array_Full::Internal)
{
	_transitions[0] = new Transition_0();
	_transitions[1] = new Transition_1();
}

Is_Array_Full::~Is_Array_Full()
{
	delete &onEntryAction();
	delete &onExitAction();
	delete &internalAction();

	delete _transitions[0];
	delete _transitions[1];
}

void Is_Array_Full::OnEntry::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckPlanManagerByGSM_VarRefs.mm"
#	include "State_Is_Array_Full_VarRefs.mm"
#	include "State_Is_Array_Full_OnEntry.mm"
}

void Is_Array_Full::OnExit::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckPlanManagerByGSM_VarRefs.mm"
#	include "State_Is_Array_Full_VarRefs.mm"
#	include "State_Is_Array_Full_OnExit.mm"
}

void Is_Array_Full::Internal::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckPlanManagerByGSM_VarRefs.mm"
#	include "State_Is_Array_Full_VarRefs.mm"
#	include "State_Is_Array_Full_Internal.mm"
}

bool Is_Array_Full::Transition_0::check(CLMachine *_machine, CLState *_state) const
{
#	include "epuckPlanManagerByGSM_VarRefs.mm"
#	include "State_Is_Array_Full_VarRefs.mm"

	return
	(
#		include "State_Is_Array_Full_Transition_0.expr"
	);
}

bool Is_Array_Full::Transition_1::check(CLMachine *_machine, CLState *_state) const
{
#	include "epuckPlanManagerByGSM_VarRefs.mm"
#	include "State_Is_Array_Full_VarRefs.mm"

	return
	(
#		include "State_Is_Array_Full_Transition_1.expr"
	);
}
