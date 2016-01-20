//
// State_Turn_Left.mm
//
// Automatically created through MiCASE -- do not change manually!
//
#include "epuckMeanderLinesByGSM_Includes.h"
#include "epuckMeanderLinesByGSM.h"
#include "State_Turn_Left.h"

#include "State_Turn_Left_Includes.h"

using namespace FSM;
using namespace CLM;
using namespace FSMepuckMeanderLinesByGSM;
using namespace State;

Turn_Left::Turn_Left(const char *name): CLState(name, *new Turn_Left::OnEntry, *new Turn_Left::OnExit, *new Turn_Left::Internal)
{
	_transitions[0] = new Transition_0();
}

Turn_Left::~Turn_Left()
{
	delete &onEntryAction();
	delete &onExitAction();
	delete &internalAction();

	delete _transitions[0];
}

void Turn_Left::OnEntry::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckMeanderLinesByGSM_VarRefs.mm"
#	include "State_Turn_Left_VarRefs.mm"
#	include "State_Turn_Left_OnEntry.mm"
}

void Turn_Left::OnExit::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckMeanderLinesByGSM_VarRefs.mm"
#	include "State_Turn_Left_VarRefs.mm"
#	include "State_Turn_Left_OnExit.mm"
}

void Turn_Left::Internal::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckMeanderLinesByGSM_VarRefs.mm"
#	include "State_Turn_Left_VarRefs.mm"
#	include "State_Turn_Left_Internal.mm"
}

bool Turn_Left::Transition_0::check(CLMachine *_machine, CLState *_state) const
{
#	include "epuckMeanderLinesByGSM_VarRefs.mm"
#	include "State_Turn_Left_VarRefs.mm"

	return
	(
#		include "State_Turn_Left_Transition_0.expr"
	);
}
