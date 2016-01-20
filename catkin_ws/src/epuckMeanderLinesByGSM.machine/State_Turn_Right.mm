//
// State_Turn_Right.mm
//
// Automatically created through MiCASE -- do not change manually!
//
#include "epuckMeanderLinesByGSM_Includes.h"
#include "epuckMeanderLinesByGSM.h"
#include "State_Turn_Right.h"

#include "State_Turn_Right_Includes.h"

using namespace FSM;
using namespace CLM;
using namespace FSMepuckMeanderLinesByGSM;
using namespace State;

Turn_Right::Turn_Right(const char *name): CLState(name, *new Turn_Right::OnEntry, *new Turn_Right::OnExit, *new Turn_Right::Internal)
{
	_transitions[0] = new Transition_0();
}

Turn_Right::~Turn_Right()
{
	delete &onEntryAction();
	delete &onExitAction();
	delete &internalAction();

	delete _transitions[0];
}

void Turn_Right::OnEntry::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckMeanderLinesByGSM_VarRefs.mm"
#	include "State_Turn_Right_VarRefs.mm"
#	include "State_Turn_Right_OnEntry.mm"
}

void Turn_Right::OnExit::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckMeanderLinesByGSM_VarRefs.mm"
#	include "State_Turn_Right_VarRefs.mm"
#	include "State_Turn_Right_OnExit.mm"
}

void Turn_Right::Internal::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckMeanderLinesByGSM_VarRefs.mm"
#	include "State_Turn_Right_VarRefs.mm"
#	include "State_Turn_Right_Internal.mm"
}

bool Turn_Right::Transition_0::check(CLMachine *_machine, CLState *_state) const
{
#	include "epuckMeanderLinesByGSM_VarRefs.mm"
#	include "State_Turn_Right_VarRefs.mm"

	return
	(
#		include "State_Turn_Right_Transition_0.expr"
	);
}
