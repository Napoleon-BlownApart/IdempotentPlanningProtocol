//
// State_Observe_Turn.mm
//
// Automatically created through MiCASE -- do not change manually!
//
#include "epuckOrientationByGSM_Includes.h"
#include "epuckOrientationByGSM.h"
#include "State_Observe_Turn.h"

#include "State_Observe_Turn_Includes.h"

using namespace FSM;
using namespace CLM;
using namespace FSMepuckOrientationByGSM;
using namespace State;

Observe_Turn::Observe_Turn(const char *name): CLState(name, *new Observe_Turn::OnEntry, *new Observe_Turn::OnExit, *new Observe_Turn::Internal)
{
	_transitions[0] = new Transition_0();
	_transitions[1] = new Transition_1();
	_transitions[2] = new Transition_2();
	_transitions[3] = new Transition_3();
}

Observe_Turn::~Observe_Turn()
{
	delete &onEntryAction();
	delete &onExitAction();
	delete &internalAction();

	delete _transitions[0];
	delete _transitions[1];
	delete _transitions[2];
	delete _transitions[3];
}

void Observe_Turn::OnEntry::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckOrientationByGSM_VarRefs.mm"
#	include "State_Observe_Turn_VarRefs.mm"
#	include "State_Observe_Turn_OnEntry.mm"
}

void Observe_Turn::OnExit::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckOrientationByGSM_VarRefs.mm"
#	include "State_Observe_Turn_VarRefs.mm"
#	include "State_Observe_Turn_OnExit.mm"
}

void Observe_Turn::Internal::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckOrientationByGSM_VarRefs.mm"
#	include "State_Observe_Turn_VarRefs.mm"
#	include "State_Observe_Turn_Internal.mm"
}

bool Observe_Turn::Transition_0::check(CLMachine *_machine, CLState *_state) const
{
#	include "epuckOrientationByGSM_VarRefs.mm"
#	include "State_Observe_Turn_VarRefs.mm"

	return
	(
#		include "State_Observe_Turn_Transition_0.expr"
	);
}

bool Observe_Turn::Transition_1::check(CLMachine *_machine, CLState *_state) const
{
#	include "epuckOrientationByGSM_VarRefs.mm"
#	include "State_Observe_Turn_VarRefs.mm"

	return
	(
#		include "State_Observe_Turn_Transition_1.expr"
	);
}

bool Observe_Turn::Transition_2::check(CLMachine *_machine, CLState *_state) const
{
#	include "epuckOrientationByGSM_VarRefs.mm"
#	include "State_Observe_Turn_VarRefs.mm"

	return
	(
#		include "State_Observe_Turn_Transition_2.expr"
	);
}

bool Observe_Turn::Transition_3::check(CLMachine *_machine, CLState *_state) const
{
#	include "epuckOrientationByGSM_VarRefs.mm"
#	include "State_Observe_Turn_VarRefs.mm"

	return
	(
#		include "State_Observe_Turn_Transition_3.expr"
	);
}
