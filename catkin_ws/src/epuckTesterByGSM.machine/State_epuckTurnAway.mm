//
// State_epuckTurnAway.mm
//
// Automatically created through MiCASE -- do not change manually!
//
#include "epuckTesterByGSM_Includes.h"
#include "epuckTesterByGSM.h"
#include "State_epuckTurnAway.h"

#include "State_epuckTurnAway_Includes.h"

using namespace FSM;
using namespace CLM;
using namespace FSMepuckTesterByGSM;
using namespace State;

epuckTurnAway::epuckTurnAway(const char *name): CLState(name, *new epuckTurnAway::OnEntry, *new epuckTurnAway::OnExit, *new epuckTurnAway::Internal)
{
	_transitions[0] = new Transition_0();
	_transitions[1] = new Transition_1();
	_transitions[2] = new Transition_2();
}

epuckTurnAway::~epuckTurnAway()
{
	delete &onEntryAction();
	delete &onExitAction();
	delete &internalAction();

	delete _transitions[0];
	delete _transitions[1];
	delete _transitions[2];
}

void epuckTurnAway::OnEntry::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckTesterByGSM_VarRefs.mm"
#	include "State_epuckTurnAway_VarRefs.mm"
#	include "State_epuckTurnAway_OnEntry.mm"
}

void epuckTurnAway::OnExit::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckTesterByGSM_VarRefs.mm"
#	include "State_epuckTurnAway_VarRefs.mm"
#	include "State_epuckTurnAway_OnExit.mm"
}

void epuckTurnAway::Internal::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckTesterByGSM_VarRefs.mm"
#	include "State_epuckTurnAway_VarRefs.mm"
#	include "State_epuckTurnAway_Internal.mm"
}

bool epuckTurnAway::Transition_0::check(CLMachine *_machine, CLState *_state) const
{
#	include "epuckTesterByGSM_VarRefs.mm"
#	include "State_epuckTurnAway_VarRefs.mm"

	return
	(
#		include "State_epuckTurnAway_Transition_0.expr"
	);
}

bool epuckTurnAway::Transition_1::check(CLMachine *_machine, CLState *_state) const
{
#	include "epuckTesterByGSM_VarRefs.mm"
#	include "State_epuckTurnAway_VarRefs.mm"

	return
	(
#		include "State_epuckTurnAway_Transition_1.expr"
	);
}

bool epuckTurnAway::Transition_2::check(CLMachine *_machine, CLState *_state) const
{
#	include "epuckTesterByGSM_VarRefs.mm"
#	include "State_epuckTurnAway_VarRefs.mm"

	return
	(
#		include "State_epuckTurnAway_Transition_2.expr"
	);
}
