//
// State_VeeringLeft.mm
//
// Automatically created through MiCASE -- do not change manually!
//
#include "epuckFollowLineByGSM_Includes.h"
#include "epuckFollowLineByGSM.h"
#include "State_VeeringLeft.h"

#include "State_VeeringLeft_Includes.h"

using namespace FSM;
using namespace CLM;
using namespace FSMepuckFollowLineByGSM;
using namespace State;

VeeringLeft::VeeringLeft(const char *name): CLState(name, *new VeeringLeft::OnEntry, *new VeeringLeft::OnExit, *new VeeringLeft::Internal)
{
	_transitions[0] = new Transition_0();
	_transitions[1] = new Transition_1();
}

VeeringLeft::~VeeringLeft()
{
	delete &onEntryAction();
	delete &onExitAction();
	delete &internalAction();

	delete _transitions[0];
	delete _transitions[1];
}

void VeeringLeft::OnEntry::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckFollowLineByGSM_VarRefs.mm"
#	include "State_VeeringLeft_VarRefs.mm"
#	include "State_VeeringLeft_OnEntry.mm"
}

void VeeringLeft::OnExit::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckFollowLineByGSM_VarRefs.mm"
#	include "State_VeeringLeft_VarRefs.mm"
#	include "State_VeeringLeft_OnExit.mm"
}

void VeeringLeft::Internal::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckFollowLineByGSM_VarRefs.mm"
#	include "State_VeeringLeft_VarRefs.mm"
#	include "State_VeeringLeft_Internal.mm"
}

bool VeeringLeft::Transition_0::check(CLMachine *_machine, CLState *_state) const
{
#	include "epuckFollowLineByGSM_VarRefs.mm"
#	include "State_VeeringLeft_VarRefs.mm"

	return
	(
#		include "State_VeeringLeft_Transition_0.expr"
	);
}

bool VeeringLeft::Transition_1::check(CLMachine *_machine, CLState *_state) const
{
#	include "epuckFollowLineByGSM_VarRefs.mm"
#	include "State_VeeringLeft_VarRefs.mm"

	return
	(
#		include "State_VeeringLeft_Transition_1.expr"
	);
}
