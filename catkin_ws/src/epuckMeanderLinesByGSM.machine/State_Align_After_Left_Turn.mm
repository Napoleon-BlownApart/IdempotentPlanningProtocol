//
// State_Align_After_Left_Turn.mm
//
// Automatically created through MiCASE -- do not change manually!
//
#include "epuckMeanderLinesByGSM_Includes.h"
#include "epuckMeanderLinesByGSM.h"
#include "State_Align_After_Left_Turn.h"

#include "State_Align_After_Left_Turn_Includes.h"

using namespace FSM;
using namespace CLM;
using namespace FSMepuckMeanderLinesByGSM;
using namespace State;

Align_After_Left_Turn::Align_After_Left_Turn(const char *name): CLState(name, *new Align_After_Left_Turn::OnEntry, *new Align_After_Left_Turn::OnExit, *new Align_After_Left_Turn::Internal)
{
	_transitions[0] = new Transition_0();
	_transitions[1] = new Transition_1();
}

Align_After_Left_Turn::~Align_After_Left_Turn()
{
	delete &onEntryAction();
	delete &onExitAction();
	delete &internalAction();

	delete _transitions[0];
	delete _transitions[1];
}

void Align_After_Left_Turn::OnEntry::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckMeanderLinesByGSM_VarRefs.mm"
#	include "State_Align_After_Left_Turn_VarRefs.mm"
#	include "State_Align_After_Left_Turn_OnEntry.mm"
}

void Align_After_Left_Turn::OnExit::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckMeanderLinesByGSM_VarRefs.mm"
#	include "State_Align_After_Left_Turn_VarRefs.mm"
#	include "State_Align_After_Left_Turn_OnExit.mm"
}

void Align_After_Left_Turn::Internal::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckMeanderLinesByGSM_VarRefs.mm"
#	include "State_Align_After_Left_Turn_VarRefs.mm"
#	include "State_Align_After_Left_Turn_Internal.mm"
}

bool Align_After_Left_Turn::Transition_0::check(CLMachine *_machine, CLState *_state) const
{
#	include "epuckMeanderLinesByGSM_VarRefs.mm"
#	include "State_Align_After_Left_Turn_VarRefs.mm"

	return
	(
#		include "State_Align_After_Left_Turn_Transition_0.expr"
	);
}

bool Align_After_Left_Turn::Transition_1::check(CLMachine *_machine, CLState *_state) const
{
#	include "epuckMeanderLinesByGSM_VarRefs.mm"
#	include "State_Align_After_Left_Turn_VarRefs.mm"

	return
	(
#		include "State_Align_After_Left_Turn_Transition_1.expr"
	);
}
