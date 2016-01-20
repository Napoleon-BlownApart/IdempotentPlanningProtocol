//
// State_Forward.mm
//
// Automatically created through MiCASE -- do not change manually!
//
#include "epuckFollowLineByGSM_Includes.h"
#include "epuckFollowLineByGSM.h"
#include "State_Forward.h"

#include "State_Forward_Includes.h"

using namespace FSM;
using namespace CLM;
using namespace FSMepuckFollowLineByGSM;
using namespace State;

Forward::Forward(const char *name): CLState(name, *new Forward::OnEntry, *new Forward::OnExit, *new Forward::Internal)
{
	_transitions[0] = new Transition_0();
	_transitions[1] = new Transition_1();
	_transitions[2] = new Transition_2();
}

Forward::~Forward()
{
	delete &onEntryAction();
	delete &onExitAction();
	delete &internalAction();

	delete _transitions[0];
	delete _transitions[1];
	delete _transitions[2];
}

void Forward::OnEntry::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckFollowLineByGSM_VarRefs.mm"
#	include "State_Forward_VarRefs.mm"
#	include "State_Forward_OnEntry.mm"
}

void Forward::OnExit::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckFollowLineByGSM_VarRefs.mm"
#	include "State_Forward_VarRefs.mm"
#	include "State_Forward_OnExit.mm"
}

void Forward::Internal::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckFollowLineByGSM_VarRefs.mm"
#	include "State_Forward_VarRefs.mm"
#	include "State_Forward_Internal.mm"
}

bool Forward::Transition_0::check(CLMachine *_machine, CLState *_state) const
{
#	include "epuckFollowLineByGSM_VarRefs.mm"
#	include "State_Forward_VarRefs.mm"

	return
	(
#		include "State_Forward_Transition_0.expr"
	);
}

bool Forward::Transition_1::check(CLMachine *_machine, CLState *_state) const
{
#	include "epuckFollowLineByGSM_VarRefs.mm"
#	include "State_Forward_VarRefs.mm"

	return
	(
#		include "State_Forward_Transition_1.expr"
	);
}

bool Forward::Transition_2::check(CLMachine *_machine, CLState *_state) const
{
#	include "epuckFollowLineByGSM_VarRefs.mm"
#	include "State_Forward_VarRefs.mm"

	return
	(
#		include "State_Forward_Transition_2.expr"
	);
}
