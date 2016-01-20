//
// State_ChooseDirection.mm
//
// Automatically created through MiCASE -- do not change manually!
//
#include "epuckMeanderLinesByGSM_Includes.h"
#include "epuckMeanderLinesByGSM.h"
#include "State_ChooseDirection.h"

#include "State_ChooseDirection_Includes.h"

using namespace FSM;
using namespace CLM;
using namespace FSMepuckMeanderLinesByGSM;
using namespace State;

ChooseDirection::ChooseDirection(const char *name): CLState(name, *new ChooseDirection::OnEntry, *new ChooseDirection::OnExit, *new ChooseDirection::Internal)
{
	_transitions[0] = new Transition_0();
	_transitions[1] = new Transition_1();
	_transitions[2] = new Transition_2();
	_transitions[3] = new Transition_3();
}

ChooseDirection::~ChooseDirection()
{
	delete &onEntryAction();
	delete &onExitAction();
	delete &internalAction();

	delete _transitions[0];
	delete _transitions[1];
	delete _transitions[2];
	delete _transitions[3];
}

void ChooseDirection::OnEntry::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckMeanderLinesByGSM_VarRefs.mm"
#	include "State_ChooseDirection_VarRefs.mm"
#	include "State_ChooseDirection_OnEntry.mm"
}

void ChooseDirection::OnExit::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckMeanderLinesByGSM_VarRefs.mm"
#	include "State_ChooseDirection_VarRefs.mm"
#	include "State_ChooseDirection_OnExit.mm"
}

void ChooseDirection::Internal::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckMeanderLinesByGSM_VarRefs.mm"
#	include "State_ChooseDirection_VarRefs.mm"
#	include "State_ChooseDirection_Internal.mm"
}

bool ChooseDirection::Transition_0::check(CLMachine *_machine, CLState *_state) const
{
#	include "epuckMeanderLinesByGSM_VarRefs.mm"
#	include "State_ChooseDirection_VarRefs.mm"

	return
	(
#		include "State_ChooseDirection_Transition_0.expr"
	);
}

bool ChooseDirection::Transition_1::check(CLMachine *_machine, CLState *_state) const
{
#	include "epuckMeanderLinesByGSM_VarRefs.mm"
#	include "State_ChooseDirection_VarRefs.mm"

	return
	(
#		include "State_ChooseDirection_Transition_1.expr"
	);
}

bool ChooseDirection::Transition_2::check(CLMachine *_machine, CLState *_state) const
{
#	include "epuckMeanderLinesByGSM_VarRefs.mm"
#	include "State_ChooseDirection_VarRefs.mm"

	return
	(
#		include "State_ChooseDirection_Transition_2.expr"
	);
}

bool ChooseDirection::Transition_3::check(CLMachine *_machine, CLState *_state) const
{
#	include "epuckMeanderLinesByGSM_VarRefs.mm"
#	include "State_ChooseDirection_VarRefs.mm"

	return
	(
#		include "State_ChooseDirection_Transition_3.expr"
	);
}
