//
// State_Continue_Align_Left.mm
//
// Automatically created through MiCASE -- do not change manually!
//
#include "epuckMeanderLinesByGSM_Includes.h"
#include "epuckMeanderLinesByGSM.h"
#include "State_Continue_Align_Left.h"

#include "State_Continue_Align_Left_Includes.h"

using namespace FSM;
using namespace CLM;
using namespace FSMepuckMeanderLinesByGSM;
using namespace State;

Continue_Align_Left::Continue_Align_Left(const char *name): CLState(name, *new Continue_Align_Left::OnEntry, *new Continue_Align_Left::OnExit, *new Continue_Align_Left::Internal)
{
	_transitions[0] = new Transition_0();
}

Continue_Align_Left::~Continue_Align_Left()
{
	delete &onEntryAction();
	delete &onExitAction();
	delete &internalAction();

	delete _transitions[0];
}

void Continue_Align_Left::OnEntry::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckMeanderLinesByGSM_VarRefs.mm"
#	include "State_Continue_Align_Left_VarRefs.mm"
#	include "State_Continue_Align_Left_OnEntry.mm"
}

void Continue_Align_Left::OnExit::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckMeanderLinesByGSM_VarRefs.mm"
#	include "State_Continue_Align_Left_VarRefs.mm"
#	include "State_Continue_Align_Left_OnExit.mm"
}

void Continue_Align_Left::Internal::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckMeanderLinesByGSM_VarRefs.mm"
#	include "State_Continue_Align_Left_VarRefs.mm"
#	include "State_Continue_Align_Left_Internal.mm"
}

bool Continue_Align_Left::Transition_0::check(CLMachine *_machine, CLState *_state) const
{
#	include "epuckMeanderLinesByGSM_VarRefs.mm"
#	include "State_Continue_Align_Left_VarRefs.mm"

	return
	(
#		include "State_Continue_Align_Left_Transition_0.expr"
	);
}
