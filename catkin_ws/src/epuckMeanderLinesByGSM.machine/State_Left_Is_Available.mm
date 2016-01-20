//
// State_Left_Is_Available.mm
//
// Automatically created through MiCASE -- do not change manually!
//
#include "epuckMeanderLinesByGSM_Includes.h"
#include "epuckMeanderLinesByGSM.h"
#include "State_Left_Is_Available.h"

#include "State_Left_Is_Available_Includes.h"

using namespace FSM;
using namespace CLM;
using namespace FSMepuckMeanderLinesByGSM;
using namespace State;

Left_Is_Available::Left_Is_Available(const char *name): CLState(name, *new Left_Is_Available::OnEntry, *new Left_Is_Available::OnExit, *new Left_Is_Available::Internal)
{
	_transitions[0] = new Transition_0();
}

Left_Is_Available::~Left_Is_Available()
{
	delete &onEntryAction();
	delete &onExitAction();
	delete &internalAction();

	delete _transitions[0];
}

void Left_Is_Available::OnEntry::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckMeanderLinesByGSM_VarRefs.mm"
#	include "State_Left_Is_Available_VarRefs.mm"
#	include "State_Left_Is_Available_OnEntry.mm"
}

void Left_Is_Available::OnExit::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckMeanderLinesByGSM_VarRefs.mm"
#	include "State_Left_Is_Available_VarRefs.mm"
#	include "State_Left_Is_Available_OnExit.mm"
}

void Left_Is_Available::Internal::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckMeanderLinesByGSM_VarRefs.mm"
#	include "State_Left_Is_Available_VarRefs.mm"
#	include "State_Left_Is_Available_Internal.mm"
}

bool Left_Is_Available::Transition_0::check(CLMachine *_machine, CLState *_state) const
{
#	include "epuckMeanderLinesByGSM_VarRefs.mm"
#	include "State_Left_Is_Available_VarRefs.mm"

	return
	(
#		include "State_Left_Is_Available_Transition_0.expr"
	);
}
