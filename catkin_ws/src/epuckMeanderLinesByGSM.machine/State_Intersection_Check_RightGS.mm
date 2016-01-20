//
// State_Intersection_Check_RightGS.mm
//
// Automatically created through MiCASE -- do not change manually!
//
#include "epuckMeanderLinesByGSM_Includes.h"
#include "epuckMeanderLinesByGSM.h"
#include "State_Intersection_Check_RightGS.h"

#include "State_Intersection_Check_RightGS_Includes.h"

using namespace FSM;
using namespace CLM;
using namespace FSMepuckMeanderLinesByGSM;
using namespace State;

Intersection_Check_RightGS::Intersection_Check_RightGS(const char *name): CLState(name, *new Intersection_Check_RightGS::OnEntry, *new Intersection_Check_RightGS::OnExit, *new Intersection_Check_RightGS::Internal)
{
	_transitions[0] = new Transition_0();
	_transitions[1] = new Transition_1();
	_transitions[2] = new Transition_2();
}

Intersection_Check_RightGS::~Intersection_Check_RightGS()
{
	delete &onEntryAction();
	delete &onExitAction();
	delete &internalAction();

	delete _transitions[0];
	delete _transitions[1];
	delete _transitions[2];
}

void Intersection_Check_RightGS::OnEntry::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckMeanderLinesByGSM_VarRefs.mm"
#	include "State_Intersection_Check_RightGS_VarRefs.mm"
#	include "State_Intersection_Check_RightGS_OnEntry.mm"
}

void Intersection_Check_RightGS::OnExit::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckMeanderLinesByGSM_VarRefs.mm"
#	include "State_Intersection_Check_RightGS_VarRefs.mm"
#	include "State_Intersection_Check_RightGS_OnExit.mm"
}

void Intersection_Check_RightGS::Internal::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckMeanderLinesByGSM_VarRefs.mm"
#	include "State_Intersection_Check_RightGS_VarRefs.mm"
#	include "State_Intersection_Check_RightGS_Internal.mm"
}

bool Intersection_Check_RightGS::Transition_0::check(CLMachine *_machine, CLState *_state) const
{
#	include "epuckMeanderLinesByGSM_VarRefs.mm"
#	include "State_Intersection_Check_RightGS_VarRefs.mm"

	return
	(
#		include "State_Intersection_Check_RightGS_Transition_0.expr"
	);
}

bool Intersection_Check_RightGS::Transition_1::check(CLMachine *_machine, CLState *_state) const
{
#	include "epuckMeanderLinesByGSM_VarRefs.mm"
#	include "State_Intersection_Check_RightGS_VarRefs.mm"

	return
	(
#		include "State_Intersection_Check_RightGS_Transition_1.expr"
	);
}

bool Intersection_Check_RightGS::Transition_2::check(CLMachine *_machine, CLState *_state) const
{
#	include "epuckMeanderLinesByGSM_VarRefs.mm"
#	include "State_Intersection_Check_RightGS_VarRefs.mm"

	return
	(
#		include "State_Intersection_Check_RightGS_Transition_2.expr"
	);
}
