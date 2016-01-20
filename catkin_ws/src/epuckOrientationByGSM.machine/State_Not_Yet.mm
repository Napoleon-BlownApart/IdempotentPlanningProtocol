//
// State_Not_Yet.mm
//
// Automatically created through MiCASE -- do not change manually!
//
#include "epuckOrientationByGSM_Includes.h"
#include "epuckOrientationByGSM.h"
#include "State_Not_Yet.h"

#include "State_Not_Yet_Includes.h"

using namespace FSM;
using namespace CLM;
using namespace FSMepuckOrientationByGSM;
using namespace State;

Not_Yet::Not_Yet(const char *name): CLState(name, *new Not_Yet::OnEntry, *new Not_Yet::OnExit, *new Not_Yet::Internal)
{
	_transitions[0] = new Transition_0();
}

Not_Yet::~Not_Yet()
{
	delete &onEntryAction();
	delete &onExitAction();
	delete &internalAction();

	delete _transitions[0];
}

void Not_Yet::OnEntry::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckOrientationByGSM_VarRefs.mm"
#	include "State_Not_Yet_VarRefs.mm"
#	include "State_Not_Yet_OnEntry.mm"
}

void Not_Yet::OnExit::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckOrientationByGSM_VarRefs.mm"
#	include "State_Not_Yet_VarRefs.mm"
#	include "State_Not_Yet_OnExit.mm"
}

void Not_Yet::Internal::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckOrientationByGSM_VarRefs.mm"
#	include "State_Not_Yet_VarRefs.mm"
#	include "State_Not_Yet_Internal.mm"
}

bool Not_Yet::Transition_0::check(CLMachine *_machine, CLState *_state) const
{
#	include "epuckOrientationByGSM_VarRefs.mm"
#	include "State_Not_Yet_VarRefs.mm"

	return
	(
#		include "State_Not_Yet_Transition_0.expr"
	);
}
