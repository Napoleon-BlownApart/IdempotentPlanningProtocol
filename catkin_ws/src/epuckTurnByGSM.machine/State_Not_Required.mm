//
// State_Not_Required.mm
//
// Automatically created through MiCASE -- do not change manually!
//
#include "epuckTurnByGSM_Includes.h"
#include "epuckTurnByGSM.h"
#include "State_Not_Required.h"

#include "State_Not_Required_Includes.h"

using namespace FSM;
using namespace CLM;
using namespace FSMepuckTurnByGSM;
using namespace State;

Not_Required::Not_Required(const char *name): CLState(name, *new Not_Required::OnEntry, *new Not_Required::OnExit, *new Not_Required::Internal)
{
	_transitions[0] = new Transition_0();
}

Not_Required::~Not_Required()
{
	delete &onEntryAction();
	delete &onExitAction();
	delete &internalAction();

	delete _transitions[0];
}

void Not_Required::OnEntry::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckTurnByGSM_VarRefs.mm"
#	include "State_Not_Required_VarRefs.mm"
#	include "State_Not_Required_OnEntry.mm"
}

void Not_Required::OnExit::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckTurnByGSM_VarRefs.mm"
#	include "State_Not_Required_VarRefs.mm"
#	include "State_Not_Required_OnExit.mm"
}

void Not_Required::Internal::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckTurnByGSM_VarRefs.mm"
#	include "State_Not_Required_VarRefs.mm"
#	include "State_Not_Required_Internal.mm"
}

bool Not_Required::Transition_0::check(CLMachine *_machine, CLState *_state) const
{
#	include "epuckTurnByGSM_VarRefs.mm"
#	include "State_Not_Required_VarRefs.mm"

	return
	(
#		include "State_Not_Required_Transition_0.expr"
	);
}
