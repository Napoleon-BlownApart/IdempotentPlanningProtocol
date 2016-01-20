//
// State_VeeringRight.mm
//
// Automatically created through MiCASE -- do not change manually!
//
#include "epuckFollowLineByGSM_Includes.h"
#include "epuckFollowLineByGSM.h"
#include "State_VeeringRight.h"

#include "State_VeeringRight_Includes.h"

using namespace FSM;
using namespace CLM;
using namespace FSMepuckFollowLineByGSM;
using namespace State;

VeeringRight::VeeringRight(const char *name): CLState(name, *new VeeringRight::OnEntry, *new VeeringRight::OnExit, *new VeeringRight::Internal)
{
	_transitions[0] = new Transition_0();
	_transitions[1] = new Transition_1();
}

VeeringRight::~VeeringRight()
{
	delete &onEntryAction();
	delete &onExitAction();
	delete &internalAction();

	delete _transitions[0];
	delete _transitions[1];
}

void VeeringRight::OnEntry::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckFollowLineByGSM_VarRefs.mm"
#	include "State_VeeringRight_VarRefs.mm"
#	include "State_VeeringRight_OnEntry.mm"
}

void VeeringRight::OnExit::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckFollowLineByGSM_VarRefs.mm"
#	include "State_VeeringRight_VarRefs.mm"
#	include "State_VeeringRight_OnExit.mm"
}

void VeeringRight::Internal::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckFollowLineByGSM_VarRefs.mm"
#	include "State_VeeringRight_VarRefs.mm"
#	include "State_VeeringRight_Internal.mm"
}

bool VeeringRight::Transition_0::check(CLMachine *_machine, CLState *_state) const
{
#	include "epuckFollowLineByGSM_VarRefs.mm"
#	include "State_VeeringRight_VarRefs.mm"

	return
	(
#		include "State_VeeringRight_Transition_0.expr"
	);
}

bool VeeringRight::Transition_1::check(CLMachine *_machine, CLState *_state) const
{
#	include "epuckFollowLineByGSM_VarRefs.mm"
#	include "State_VeeringRight_VarRefs.mm"

	return
	(
#		include "State_VeeringRight_Transition_1.expr"
	);
}
