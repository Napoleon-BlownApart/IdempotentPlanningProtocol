//
// State_Intersection_Check_LeftGS.mm
//
// Automatically created through MiCASE -- do not change manually!
//
#include "epuckMeanderLinesByGSM_Includes.h"
#include "epuckMeanderLinesByGSM.h"
#include "State_Intersection_Check_LeftGS.h"

#include "State_Intersection_Check_LeftGS_Includes.h"

using namespace FSM;
using namespace CLM;
using namespace FSMepuckMeanderLinesByGSM;
using namespace State;

Intersection_Check_LeftGS::Intersection_Check_LeftGS(const char *name): CLState(name, *new Intersection_Check_LeftGS::OnEntry, *new Intersection_Check_LeftGS::OnExit, *new Intersection_Check_LeftGS::Internal)
{
	_transitions[0] = new Transition_0();
	_transitions[1] = new Transition_1();
	_transitions[2] = new Transition_2();
}

Intersection_Check_LeftGS::~Intersection_Check_LeftGS()
{
	delete &onEntryAction();
	delete &onExitAction();
	delete &internalAction();

	delete _transitions[0];
	delete _transitions[1];
	delete _transitions[2];
}

void Intersection_Check_LeftGS::OnEntry::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckMeanderLinesByGSM_VarRefs.mm"
#	include "State_Intersection_Check_LeftGS_VarRefs.mm"
#	include "State_Intersection_Check_LeftGS_OnEntry.mm"
}

void Intersection_Check_LeftGS::OnExit::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckMeanderLinesByGSM_VarRefs.mm"
#	include "State_Intersection_Check_LeftGS_VarRefs.mm"
#	include "State_Intersection_Check_LeftGS_OnExit.mm"
}

void Intersection_Check_LeftGS::Internal::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckMeanderLinesByGSM_VarRefs.mm"
#	include "State_Intersection_Check_LeftGS_VarRefs.mm"
#	include "State_Intersection_Check_LeftGS_Internal.mm"
}

bool Intersection_Check_LeftGS::Transition_0::check(CLMachine *_machine, CLState *_state) const
{
#	include "epuckMeanderLinesByGSM_VarRefs.mm"
#	include "State_Intersection_Check_LeftGS_VarRefs.mm"

	return
	(
#		include "State_Intersection_Check_LeftGS_Transition_0.expr"
	);
}

bool Intersection_Check_LeftGS::Transition_1::check(CLMachine *_machine, CLState *_state) const
{
#	include "epuckMeanderLinesByGSM_VarRefs.mm"
#	include "State_Intersection_Check_LeftGS_VarRefs.mm"

	return
	(
#		include "State_Intersection_Check_LeftGS_Transition_1.expr"
	);
}

bool Intersection_Check_LeftGS::Transition_2::check(CLMachine *_machine, CLState *_state) const
{
#	include "epuckMeanderLinesByGSM_VarRefs.mm"
#	include "State_Intersection_Check_LeftGS_VarRefs.mm"

	return
	(
#		include "State_Intersection_Check_LeftGS_Transition_2.expr"
	);
}
