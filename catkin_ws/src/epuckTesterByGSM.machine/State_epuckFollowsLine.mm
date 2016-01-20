//
// State_epuckFollowsLine.mm
//
// Automatically created through MiCASE -- do not change manually!
//
#include "epuckTesterByGSM_Includes.h"
#include "epuckTesterByGSM.h"
#include "State_epuckFollowsLine.h"

#include "State_epuckFollowsLine_Includes.h"

using namespace FSM;
using namespace CLM;
using namespace FSMepuckTesterByGSM;
using namespace State;

epuckFollowsLine::epuckFollowsLine(const char *name): CLState(name, *new epuckFollowsLine::OnEntry, *new epuckFollowsLine::OnExit, *new epuckFollowsLine::Internal)
{
	_transitions[0] = new Transition_0();
	_transitions[1] = new Transition_1();
	_transitions[2] = new Transition_2();
}

epuckFollowsLine::~epuckFollowsLine()
{
	delete &onEntryAction();
	delete &onExitAction();
	delete &internalAction();

	delete _transitions[0];
	delete _transitions[1];
	delete _transitions[2];
}

void epuckFollowsLine::OnEntry::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckTesterByGSM_VarRefs.mm"
#	include "State_epuckFollowsLine_VarRefs.mm"
#	include "State_epuckFollowsLine_OnEntry.mm"
}

void epuckFollowsLine::OnExit::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckTesterByGSM_VarRefs.mm"
#	include "State_epuckFollowsLine_VarRefs.mm"
#	include "State_epuckFollowsLine_OnExit.mm"
}

void epuckFollowsLine::Internal::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckTesterByGSM_VarRefs.mm"
#	include "State_epuckFollowsLine_VarRefs.mm"
#	include "State_epuckFollowsLine_Internal.mm"
}

bool epuckFollowsLine::Transition_0::check(CLMachine *_machine, CLState *_state) const
{
#	include "epuckTesterByGSM_VarRefs.mm"
#	include "State_epuckFollowsLine_VarRefs.mm"

	return
	(
#		include "State_epuckFollowsLine_Transition_0.expr"
	);
}

bool epuckFollowsLine::Transition_1::check(CLMachine *_machine, CLState *_state) const
{
#	include "epuckTesterByGSM_VarRefs.mm"
#	include "State_epuckFollowsLine_VarRefs.mm"

	return
	(
#		include "State_epuckFollowsLine_Transition_1.expr"
	);
}

bool epuckFollowsLine::Transition_2::check(CLMachine *_machine, CLState *_state) const
{
#	include "epuckTesterByGSM_VarRefs.mm"
#	include "State_epuckFollowsLine_VarRefs.mm"

	return
	(
#		include "State_epuckFollowsLine_Transition_2.expr"
	);
}
