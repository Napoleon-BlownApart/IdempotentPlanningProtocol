//
// State_Continue_Align_Right.mm
//
// Automatically created through MiCASE -- do not change manually!
//
#include "epuckMeanderLinesByGSM_Includes.h"
#include "epuckMeanderLinesByGSM.h"
#include "State_Continue_Align_Right.h"

#include "State_Continue_Align_Right_Includes.h"

using namespace FSM;
using namespace CLM;
using namespace FSMepuckMeanderLinesByGSM;
using namespace State;

Continue_Align_Right::Continue_Align_Right(const char *name): CLState(name, *new Continue_Align_Right::OnEntry, *new Continue_Align_Right::OnExit, *new Continue_Align_Right::Internal)
{
	_transitions[0] = new Transition_0();
}

Continue_Align_Right::~Continue_Align_Right()
{
	delete &onEntryAction();
	delete &onExitAction();
	delete &internalAction();

	delete _transitions[0];
}

void Continue_Align_Right::OnEntry::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckMeanderLinesByGSM_VarRefs.mm"
#	include "State_Continue_Align_Right_VarRefs.mm"
#	include "State_Continue_Align_Right_OnEntry.mm"
}

void Continue_Align_Right::OnExit::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckMeanderLinesByGSM_VarRefs.mm"
#	include "State_Continue_Align_Right_VarRefs.mm"
#	include "State_Continue_Align_Right_OnExit.mm"
}

void Continue_Align_Right::Internal::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckMeanderLinesByGSM_VarRefs.mm"
#	include "State_Continue_Align_Right_VarRefs.mm"
#	include "State_Continue_Align_Right_Internal.mm"
}

bool Continue_Align_Right::Transition_0::check(CLMachine *_machine, CLState *_state) const
{
#	include "epuckMeanderLinesByGSM_VarRefs.mm"
#	include "State_Continue_Align_Right_VarRefs.mm"

	return
	(
#		include "State_Continue_Align_Right_Transition_0.expr"
	);
}
