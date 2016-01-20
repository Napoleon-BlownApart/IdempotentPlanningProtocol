//
// State_Determine_Direction_Straight.mm
//
// Automatically created through MiCASE -- do not change manually!
//
#include "epuckMeanderLinesByGSM_Includes.h"
#include "epuckMeanderLinesByGSM.h"
#include "State_Determine_Direction_Straight.h"

#include "State_Determine_Direction_Straight_Includes.h"

using namespace FSM;
using namespace CLM;
using namespace FSMepuckMeanderLinesByGSM;
using namespace State;

Determine_Direction_Straight::Determine_Direction_Straight(const char *name): CLState(name, *new Determine_Direction_Straight::OnEntry, *new Determine_Direction_Straight::OnExit, *new Determine_Direction_Straight::Internal)
{
	_transitions[0] = new Transition_0();
	_transitions[1] = new Transition_1();
	_transitions[2] = new Transition_2();
}

Determine_Direction_Straight::~Determine_Direction_Straight()
{
	delete &onEntryAction();
	delete &onExitAction();
	delete &internalAction();

	delete _transitions[0];
	delete _transitions[1];
	delete _transitions[2];
}

void Determine_Direction_Straight::OnEntry::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckMeanderLinesByGSM_VarRefs.mm"
#	include "State_Determine_Direction_Straight_VarRefs.mm"
#	include "State_Determine_Direction_Straight_OnEntry.mm"
}

void Determine_Direction_Straight::OnExit::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckMeanderLinesByGSM_VarRefs.mm"
#	include "State_Determine_Direction_Straight_VarRefs.mm"
#	include "State_Determine_Direction_Straight_OnExit.mm"
}

void Determine_Direction_Straight::Internal::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckMeanderLinesByGSM_VarRefs.mm"
#	include "State_Determine_Direction_Straight_VarRefs.mm"
#	include "State_Determine_Direction_Straight_Internal.mm"
}

bool Determine_Direction_Straight::Transition_0::check(CLMachine *_machine, CLState *_state) const
{
#	include "epuckMeanderLinesByGSM_VarRefs.mm"
#	include "State_Determine_Direction_Straight_VarRefs.mm"

	return
	(
#		include "State_Determine_Direction_Straight_Transition_0.expr"
	);
}

bool Determine_Direction_Straight::Transition_1::check(CLMachine *_machine, CLState *_state) const
{
#	include "epuckMeanderLinesByGSM_VarRefs.mm"
#	include "State_Determine_Direction_Straight_VarRefs.mm"

	return
	(
#		include "State_Determine_Direction_Straight_Transition_1.expr"
	);
}

bool Determine_Direction_Straight::Transition_2::check(CLMachine *_machine, CLState *_state) const
{
#	include "epuckMeanderLinesByGSM_VarRefs.mm"
#	include "State_Determine_Direction_Straight_VarRefs.mm"

	return
	(
#		include "State_Determine_Direction_Straight_Transition_2.expr"
	);
}
