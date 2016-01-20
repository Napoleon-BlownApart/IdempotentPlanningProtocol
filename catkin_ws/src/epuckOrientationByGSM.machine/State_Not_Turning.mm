//
// State_Not_Turning.mm
//
// Automatically created through MiCASE -- do not change manually!
//
#include "epuckOrientationByGSM_Includes.h"
#include "epuckOrientationByGSM.h"
#include "State_Not_Turning.h"

#include "State_Not_Turning_Includes.h"

using namespace FSM;
using namespace CLM;
using namespace FSMepuckOrientationByGSM;
using namespace State;

Not_Turning::Not_Turning(const char *name): CLState(name, *new Not_Turning::OnEntry, *new Not_Turning::OnExit, *new Not_Turning::Internal)
{
	_transitions[0] = new Transition_0();
}

Not_Turning::~Not_Turning()
{
	delete &onEntryAction();
	delete &onExitAction();
	delete &internalAction();

	delete _transitions[0];
}

void Not_Turning::OnEntry::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckOrientationByGSM_VarRefs.mm"
#	include "State_Not_Turning_VarRefs.mm"
#	include "State_Not_Turning_OnEntry.mm"
}

void Not_Turning::OnExit::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckOrientationByGSM_VarRefs.mm"
#	include "State_Not_Turning_VarRefs.mm"
#	include "State_Not_Turning_OnExit.mm"
}

void Not_Turning::Internal::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckOrientationByGSM_VarRefs.mm"
#	include "State_Not_Turning_VarRefs.mm"
#	include "State_Not_Turning_Internal.mm"
}

bool Not_Turning::Transition_0::check(CLMachine *_machine, CLState *_state) const
{
#	include "epuckOrientationByGSM_VarRefs.mm"
#	include "State_Not_Turning_VarRefs.mm"

	return
	(
#		include "State_Not_Turning_Transition_0.expr"
	);
}
