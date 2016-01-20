//
// State_epuckChooseDirection.mm
//
// Automatically created through MiCASE -- do not change manually!
//
#include "epuckTesterByGSM_Includes.h"
#include "epuckTesterByGSM.h"
#include "State_epuckChooseDirection.h"

#include "State_epuckChooseDirection_Includes.h"

using namespace FSM;
using namespace CLM;
using namespace FSMepuckTesterByGSM;
using namespace State;

epuckChooseDirection::epuckChooseDirection(const char *name): CLState(name, *new epuckChooseDirection::OnEntry, *new epuckChooseDirection::OnExit, *new epuckChooseDirection::Internal)
{
	_transitions[0] = new Transition_0();
	_transitions[1] = new Transition_1();
	_transitions[2] = new Transition_2();
}

epuckChooseDirection::~epuckChooseDirection()
{
	delete &onEntryAction();
	delete &onExitAction();
	delete &internalAction();

	delete _transitions[0];
	delete _transitions[1];
	delete _transitions[2];
}

void epuckChooseDirection::OnEntry::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckTesterByGSM_VarRefs.mm"
#	include "State_epuckChooseDirection_VarRefs.mm"
#	include "State_epuckChooseDirection_OnEntry.mm"
}

void epuckChooseDirection::OnExit::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckTesterByGSM_VarRefs.mm"
#	include "State_epuckChooseDirection_VarRefs.mm"
#	include "State_epuckChooseDirection_OnExit.mm"
}

void epuckChooseDirection::Internal::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckTesterByGSM_VarRefs.mm"
#	include "State_epuckChooseDirection_VarRefs.mm"
#	include "State_epuckChooseDirection_Internal.mm"
}

bool epuckChooseDirection::Transition_0::check(CLMachine *_machine, CLState *_state) const
{
#	include "epuckTesterByGSM_VarRefs.mm"
#	include "State_epuckChooseDirection_VarRefs.mm"

	return
	(
#		include "State_epuckChooseDirection_Transition_0.expr"
	);
}

bool epuckChooseDirection::Transition_1::check(CLMachine *_machine, CLState *_state) const
{
#	include "epuckTesterByGSM_VarRefs.mm"
#	include "State_epuckChooseDirection_VarRefs.mm"

	return
	(
#		include "State_epuckChooseDirection_Transition_1.expr"
	);
}

bool epuckChooseDirection::Transition_2::check(CLMachine *_machine, CLState *_state) const
{
#	include "epuckTesterByGSM_VarRefs.mm"
#	include "State_epuckChooseDirection_VarRefs.mm"

	return
	(
#		include "State_epuckChooseDirection_Transition_2.expr"
	);
}
