//
// State_Right_Is_Available.mm
//
// Automatically created through MiCASE -- do not change manually!
//
#include "epuckMeanderLinesByGSM_Includes.h"
#include "epuckMeanderLinesByGSM.h"
#include "State_Right_Is_Available.h"

#include "State_Right_Is_Available_Includes.h"

using namespace FSM;
using namespace CLM;
using namespace FSMepuckMeanderLinesByGSM;
using namespace State;

Right_Is_Available::Right_Is_Available(const char *name): CLState(name, *new Right_Is_Available::OnEntry, *new Right_Is_Available::OnExit, *new Right_Is_Available::Internal)
{
	_transitions[0] = new Transition_0();
}

Right_Is_Available::~Right_Is_Available()
{
	delete &onEntryAction();
	delete &onExitAction();
	delete &internalAction();

	delete _transitions[0];
}

void Right_Is_Available::OnEntry::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckMeanderLinesByGSM_VarRefs.mm"
#	include "State_Right_Is_Available_VarRefs.mm"
#	include "State_Right_Is_Available_OnEntry.mm"
}

void Right_Is_Available::OnExit::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckMeanderLinesByGSM_VarRefs.mm"
#	include "State_Right_Is_Available_VarRefs.mm"
#	include "State_Right_Is_Available_OnExit.mm"
}

void Right_Is_Available::Internal::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckMeanderLinesByGSM_VarRefs.mm"
#	include "State_Right_Is_Available_VarRefs.mm"
#	include "State_Right_Is_Available_Internal.mm"
}

bool Right_Is_Available::Transition_0::check(CLMachine *_machine, CLState *_state) const
{
#	include "epuckMeanderLinesByGSM_VarRefs.mm"
#	include "State_Right_Is_Available_VarRefs.mm"

	return
	(
#		include "State_Right_Is_Available_Transition_0.expr"
	);
}
