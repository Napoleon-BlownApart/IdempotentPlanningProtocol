//
// State_Turn_Around.mm
//
// Automatically created through MiCASE -- do not change manually!
//
#include "epuckTurnByGSM_Includes.h"
#include "epuckTurnByGSM.h"
#include "State_Turn_Around.h"

#include "State_Turn_Around_Includes.h"

using namespace FSM;
using namespace CLM;
using namespace FSMepuckTurnByGSM;
using namespace State;

Turn_Around::Turn_Around(const char *name): CLState(name, *new Turn_Around::OnEntry, *new Turn_Around::OnExit, *new Turn_Around::Internal)
{
	_transitions[0] = new Transition_0();
	_transitions[1] = new Transition_1();
}

Turn_Around::~Turn_Around()
{
	delete &onEntryAction();
	delete &onExitAction();
	delete &internalAction();

	delete _transitions[0];
	delete _transitions[1];
}

void Turn_Around::OnEntry::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckTurnByGSM_VarRefs.mm"
#	include "State_Turn_Around_VarRefs.mm"
#	include "State_Turn_Around_OnEntry.mm"
}

void Turn_Around::OnExit::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckTurnByGSM_VarRefs.mm"
#	include "State_Turn_Around_VarRefs.mm"
#	include "State_Turn_Around_OnExit.mm"
}

void Turn_Around::Internal::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckTurnByGSM_VarRefs.mm"
#	include "State_Turn_Around_VarRefs.mm"
#	include "State_Turn_Around_Internal.mm"
}

bool Turn_Around::Transition_0::check(CLMachine *_machine, CLState *_state) const
{
#	include "epuckTurnByGSM_VarRefs.mm"
#	include "State_Turn_Around_VarRefs.mm"

	return
	(
#		include "State_Turn_Around_Transition_0.expr"
	);
}

bool Turn_Around::Transition_1::check(CLMachine *_machine, CLState *_state) const
{
#	include "epuckTurnByGSM_VarRefs.mm"
#	include "State_Turn_Around_VarRefs.mm"

	return
	(
#		include "State_Turn_Around_Transition_1.expr"
	);
}
