//
// State_Determine_Directiion_Left.mm
//
// Automatically created through MiCASE -- do not change manually!
//
#include "epuckMeanderLinesByGSM_Includes.h"
#include "epuckMeanderLinesByGSM.h"
#include "State_Determine_Directiion_Left.h"

#include "State_Determine_Directiion_Left_Includes.h"

using namespace FSM;
using namespace CLM;
using namespace FSMepuckMeanderLinesByGSM;
using namespace State;

Determine_Directiion_Left::Determine_Directiion_Left(const char *name): CLState(name, *new Determine_Directiion_Left::OnEntry, *new Determine_Directiion_Left::OnExit, *new Determine_Directiion_Left::Internal)
{
	_transitions[0] = new Transition_0();
	_transitions[1] = new Transition_1();
}

Determine_Directiion_Left::~Determine_Directiion_Left()
{
	delete &onEntryAction();
	delete &onExitAction();
	delete &internalAction();

	delete _transitions[0];
	delete _transitions[1];
}

void Determine_Directiion_Left::OnEntry::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckMeanderLinesByGSM_VarRefs.mm"
#	include "State_Determine_Directiion_Left_VarRefs.mm"
#	include "State_Determine_Directiion_Left_OnEntry.mm"
}

void Determine_Directiion_Left::OnExit::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckMeanderLinesByGSM_VarRefs.mm"
#	include "State_Determine_Directiion_Left_VarRefs.mm"
#	include "State_Determine_Directiion_Left_OnExit.mm"
}

void Determine_Directiion_Left::Internal::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckMeanderLinesByGSM_VarRefs.mm"
#	include "State_Determine_Directiion_Left_VarRefs.mm"
#	include "State_Determine_Directiion_Left_Internal.mm"
}

bool Determine_Directiion_Left::Transition_0::check(CLMachine *_machine, CLState *_state) const
{
#	include "epuckMeanderLinesByGSM_VarRefs.mm"
#	include "State_Determine_Directiion_Left_VarRefs.mm"

	return
	(
#		include "State_Determine_Directiion_Left_Transition_0.expr"
	);
}

bool Determine_Directiion_Left::Transition_1::check(CLMachine *_machine, CLState *_state) const
{
#	include "epuckMeanderLinesByGSM_VarRefs.mm"
#	include "State_Determine_Directiion_Left_VarRefs.mm"

	return
	(
#		include "State_Determine_Directiion_Left_Transition_1.expr"
	);
}
