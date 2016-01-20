//
// State_Turn_Completed.mm
//
// Automatically created through MiCASE -- do not change manually!
//
#include "epuckOrientationByGSM_Includes.h"
#include "epuckOrientationByGSM.h"
#include "State_Turn_Completed.h"

#include "State_Turn_Completed_Includes.h"

using namespace FSM;
using namespace CLM;
using namespace FSMepuckOrientationByGSM;
using namespace State;

Turn_Completed::Turn_Completed(const char *name): CLState(name, *new Turn_Completed::OnEntry, *new Turn_Completed::OnExit, *new Turn_Completed::Internal)
{
	_transitions[0] = new Transition_0();
	_transitions[1] = new Transition_1();
}

Turn_Completed::~Turn_Completed()
{
	delete &onEntryAction();
	delete &onExitAction();
	delete &internalAction();

	delete _transitions[0];
	delete _transitions[1];
}

void Turn_Completed::OnEntry::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckOrientationByGSM_VarRefs.mm"
#	include "State_Turn_Completed_VarRefs.mm"
#	include "State_Turn_Completed_OnEntry.mm"
}

void Turn_Completed::OnExit::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckOrientationByGSM_VarRefs.mm"
#	include "State_Turn_Completed_VarRefs.mm"
#	include "State_Turn_Completed_OnExit.mm"
}

void Turn_Completed::Internal::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckOrientationByGSM_VarRefs.mm"
#	include "State_Turn_Completed_VarRefs.mm"
#	include "State_Turn_Completed_Internal.mm"
}

bool Turn_Completed::Transition_0::check(CLMachine *_machine, CLState *_state) const
{
#	include "epuckOrientationByGSM_VarRefs.mm"
#	include "State_Turn_Completed_VarRefs.mm"

	return
	(
#		include "State_Turn_Completed_Transition_0.expr"
	);
}

bool Turn_Completed::Transition_1::check(CLMachine *_machine, CLState *_state) const
{
#	include "epuckOrientationByGSM_VarRefs.mm"
#	include "State_Turn_Completed_VarRefs.mm"

	return
	(
#		include "State_Turn_Completed_Transition_1.expr"
	);
}
