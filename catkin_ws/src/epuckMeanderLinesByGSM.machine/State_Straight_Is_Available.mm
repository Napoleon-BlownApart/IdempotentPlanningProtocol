//
// State_Straight_Is_Available.mm
//
// Automatically created through MiCASE -- do not change manually!
//
#include "epuckMeanderLinesByGSM_Includes.h"
#include "epuckMeanderLinesByGSM.h"
#include "State_Straight_Is_Available.h"

#include "State_Straight_Is_Available_Includes.h"

using namespace FSM;
using namespace CLM;
using namespace FSMepuckMeanderLinesByGSM;
using namespace State;

Straight_Is_Available::Straight_Is_Available(const char *name): CLState(name, *new Straight_Is_Available::OnEntry, *new Straight_Is_Available::OnExit, *new Straight_Is_Available::Internal)
{
	_transitions[0] = new Transition_0();
	_transitions[1] = new Transition_1();
}

Straight_Is_Available::~Straight_Is_Available()
{
	delete &onEntryAction();
	delete &onExitAction();
	delete &internalAction();

	delete _transitions[0];
	delete _transitions[1];
}

void Straight_Is_Available::OnEntry::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckMeanderLinesByGSM_VarRefs.mm"
#	include "State_Straight_Is_Available_VarRefs.mm"
#	include "State_Straight_Is_Available_OnEntry.mm"
}

void Straight_Is_Available::OnExit::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckMeanderLinesByGSM_VarRefs.mm"
#	include "State_Straight_Is_Available_VarRefs.mm"
#	include "State_Straight_Is_Available_OnExit.mm"
}

void Straight_Is_Available::Internal::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckMeanderLinesByGSM_VarRefs.mm"
#	include "State_Straight_Is_Available_VarRefs.mm"
#	include "State_Straight_Is_Available_Internal.mm"
}

bool Straight_Is_Available::Transition_0::check(CLMachine *_machine, CLState *_state) const
{
#	include "epuckMeanderLinesByGSM_VarRefs.mm"
#	include "State_Straight_Is_Available_VarRefs.mm"

	return
	(
#		include "State_Straight_Is_Available_Transition_0.expr"
	);
}

bool Straight_Is_Available::Transition_1::check(CLMachine *_machine, CLState *_state) const
{
#	include "epuckMeanderLinesByGSM_VarRefs.mm"
#	include "State_Straight_Is_Available_VarRefs.mm"

	return
	(
#		include "State_Straight_Is_Available_Transition_1.expr"
	);
}
