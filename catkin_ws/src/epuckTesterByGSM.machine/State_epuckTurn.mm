//
// State_epuckTurn.mm
//
// Automatically created through MiCASE -- do not change manually!
//
#include "epuckTesterByGSM_Includes.h"
#include "epuckTesterByGSM.h"
#include "State_epuckTurn.h"

#include "State_epuckTurn_Includes.h"

using namespace FSM;
using namespace CLM;
using namespace FSMepuckTesterByGSM;
using namespace State;

epuckTurn::epuckTurn(const char *name): CLState(name, *new epuckTurn::OnEntry, *new epuckTurn::OnExit, *new epuckTurn::Internal)
{
	_transitions[0] = new Transition_0();
	_transitions[1] = new Transition_1();
	_transitions[2] = new Transition_2();
}

epuckTurn::~epuckTurn()
{
	delete &onEntryAction();
	delete &onExitAction();
	delete &internalAction();

	delete _transitions[0];
	delete _transitions[1];
	delete _transitions[2];
}

void epuckTurn::OnEntry::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckTesterByGSM_VarRefs.mm"
#	include "State_epuckTurn_VarRefs.mm"
#	include "State_epuckTurn_OnEntry.mm"
}

void epuckTurn::OnExit::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckTesterByGSM_VarRefs.mm"
#	include "State_epuckTurn_VarRefs.mm"
#	include "State_epuckTurn_OnExit.mm"
}

void epuckTurn::Internal::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckTesterByGSM_VarRefs.mm"
#	include "State_epuckTurn_VarRefs.mm"
#	include "State_epuckTurn_Internal.mm"
}

bool epuckTurn::Transition_0::check(CLMachine *_machine, CLState *_state) const
{
#	include "epuckTesterByGSM_VarRefs.mm"
#	include "State_epuckTurn_VarRefs.mm"

	return
	(
#		include "State_epuckTurn_Transition_0.expr"
	);
}

bool epuckTurn::Transition_1::check(CLMachine *_machine, CLState *_state) const
{
#	include "epuckTesterByGSM_VarRefs.mm"
#	include "State_epuckTurn_VarRefs.mm"

	return
	(
#		include "State_epuckTurn_Transition_1.expr"
	);
}

bool epuckTurn::Transition_2::check(CLMachine *_machine, CLState *_state) const
{
#	include "epuckTesterByGSM_VarRefs.mm"
#	include "State_epuckTurn_VarRefs.mm"

	return
	(
#		include "State_epuckTurn_Transition_2.expr"
	);
}
