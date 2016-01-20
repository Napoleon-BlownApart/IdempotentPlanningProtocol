//
// State_loop_Back.mm
//
// Automatically created through MiCASE -- do not change manually!
//
#include "epuckTesterByGSM_Includes.h"
#include "epuckTesterByGSM.h"
#include "State_loop_Back.h"

#include "State_loop_Back_Includes.h"

using namespace FSM;
using namespace CLM;
using namespace FSMepuckTesterByGSM;
using namespace State;

loop_Back::loop_Back(const char *name): CLState(name, *new loop_Back::OnEntry, *new loop_Back::OnExit, *new loop_Back::Internal)
{
	_transitions[0] = new Transition_0();
}

loop_Back::~loop_Back()
{
	delete &onEntryAction();
	delete &onExitAction();
	delete &internalAction();

	delete _transitions[0];
}

void loop_Back::OnEntry::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckTesterByGSM_VarRefs.mm"
#	include "State_loop_Back_VarRefs.mm"
#	include "State_loop_Back_OnEntry.mm"
}

void loop_Back::OnExit::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckTesterByGSM_VarRefs.mm"
#	include "State_loop_Back_VarRefs.mm"
#	include "State_loop_Back_OnExit.mm"
}

void loop_Back::Internal::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckTesterByGSM_VarRefs.mm"
#	include "State_loop_Back_VarRefs.mm"
#	include "State_loop_Back_Internal.mm"
}

bool loop_Back::Transition_0::check(CLMachine *_machine, CLState *_state) const
{
#	include "epuckTesterByGSM_VarRefs.mm"
#	include "State_loop_Back_VarRefs.mm"

	return
	(
#		include "State_loop_Back_Transition_0.expr"
	);
}
