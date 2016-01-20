//
// State_Determine_Direction_Left.mm
//
// Automatically created through MiCASE -- do not change manually!
//
#include "epuckIntersectionByGSM_Includes.h"
#include "epuckIntersectionByGSM.h"
#include "State_Determine_Direction_Left.h"

#include "State_Determine_Direction_Left_Includes.h"

using namespace FSM;
using namespace CLM;
using namespace FSMepuckIntersectionByGSM;
using namespace State;

Determine_Direction_Left::Determine_Direction_Left(const char *name): CLState(name, *new Determine_Direction_Left::OnEntry, *new Determine_Direction_Left::OnExit, *new Determine_Direction_Left::Internal)
{
	_transitions[0] = new Transition_0();
	_transitions[1] = new Transition_1();
}

Determine_Direction_Left::~Determine_Direction_Left()
{
	delete &onEntryAction();
	delete &onExitAction();
	delete &internalAction();

	delete _transitions[0];
	delete _transitions[1];
}

void Determine_Direction_Left::OnEntry::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckIntersectionByGSM_VarRefs.mm"
#	include "State_Determine_Direction_Left_VarRefs.mm"
#	include "State_Determine_Direction_Left_OnEntry.mm"
}

void Determine_Direction_Left::OnExit::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckIntersectionByGSM_VarRefs.mm"
#	include "State_Determine_Direction_Left_VarRefs.mm"
#	include "State_Determine_Direction_Left_OnExit.mm"
}

void Determine_Direction_Left::Internal::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckIntersectionByGSM_VarRefs.mm"
#	include "State_Determine_Direction_Left_VarRefs.mm"
#	include "State_Determine_Direction_Left_Internal.mm"
}

bool Determine_Direction_Left::Transition_0::check(CLMachine *_machine, CLState *_state) const
{
#	include "epuckIntersectionByGSM_VarRefs.mm"
#	include "State_Determine_Direction_Left_VarRefs.mm"

	return
	(
#		include "State_Determine_Direction_Left_Transition_0.expr"
	);
}

bool Determine_Direction_Left::Transition_1::check(CLMachine *_machine, CLState *_state) const
{
#	include "epuckIntersectionByGSM_VarRefs.mm"
#	include "State_Determine_Direction_Left_VarRefs.mm"

	return
	(
#		include "State_Determine_Direction_Left_Transition_1.expr"
	);
}
