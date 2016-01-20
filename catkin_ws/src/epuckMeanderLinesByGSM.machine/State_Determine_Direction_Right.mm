//
// State_Determine_Direction_Right.mm
//
// Automatically created through MiCASE -- do not change manually!
//
#include "epuckMeanderLinesByGSM_Includes.h"
#include "epuckMeanderLinesByGSM.h"
#include "State_Determine_Direction_Right.h"

#include "State_Determine_Direction_Right_Includes.h"

using namespace FSM;
using namespace CLM;
using namespace FSMepuckMeanderLinesByGSM;
using namespace State;

Determine_Direction_Right::Determine_Direction_Right(const char *name): CLState(name, *new Determine_Direction_Right::OnEntry, *new Determine_Direction_Right::OnExit, *new Determine_Direction_Right::Internal)
{
	_transitions[0] = new Transition_0();
	_transitions[1] = new Transition_1();
}

Determine_Direction_Right::~Determine_Direction_Right()
{
	delete &onEntryAction();
	delete &onExitAction();
	delete &internalAction();

	delete _transitions[0];
	delete _transitions[1];
}

void Determine_Direction_Right::OnEntry::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckMeanderLinesByGSM_VarRefs.mm"
#	include "State_Determine_Direction_Right_VarRefs.mm"
#	include "State_Determine_Direction_Right_OnEntry.mm"
}

void Determine_Direction_Right::OnExit::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckMeanderLinesByGSM_VarRefs.mm"
#	include "State_Determine_Direction_Right_VarRefs.mm"
#	include "State_Determine_Direction_Right_OnExit.mm"
}

void Determine_Direction_Right::Internal::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckMeanderLinesByGSM_VarRefs.mm"
#	include "State_Determine_Direction_Right_VarRefs.mm"
#	include "State_Determine_Direction_Right_Internal.mm"
}

bool Determine_Direction_Right::Transition_0::check(CLMachine *_machine, CLState *_state) const
{
#	include "epuckMeanderLinesByGSM_VarRefs.mm"
#	include "State_Determine_Direction_Right_VarRefs.mm"

	return
	(
#		include "State_Determine_Direction_Right_Transition_0.expr"
	);
}

bool Determine_Direction_Right::Transition_1::check(CLMachine *_machine, CLState *_state) const
{
#	include "epuckMeanderLinesByGSM_VarRefs.mm"
#	include "State_Determine_Direction_Right_VarRefs.mm"

	return
	(
#		include "State_Determine_Direction_Right_Transition_1.expr"
	);
}
