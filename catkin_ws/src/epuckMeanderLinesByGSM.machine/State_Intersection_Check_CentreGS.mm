//
// State_Intersection_Check_CentreGS.mm
//
// Automatically created through MiCASE -- do not change manually!
//
#include "epuckMeanderLinesByGSM_Includes.h"
#include "epuckMeanderLinesByGSM.h"
#include "State_Intersection_Check_CentreGS.h"

#include "State_Intersection_Check_CentreGS_Includes.h"

using namespace FSM;
using namespace CLM;
using namespace FSMepuckMeanderLinesByGSM;
using namespace State;

Intersection_Check_CentreGS::Intersection_Check_CentreGS(const char *name): CLState(name, *new Intersection_Check_CentreGS::OnEntry, *new Intersection_Check_CentreGS::OnExit, *new Intersection_Check_CentreGS::Internal)
{
	_transitions[0] = new Transition_0();
	_transitions[1] = new Transition_1();
	_transitions[2] = new Transition_2();
}

Intersection_Check_CentreGS::~Intersection_Check_CentreGS()
{
	delete &onEntryAction();
	delete &onExitAction();
	delete &internalAction();

	delete _transitions[0];
	delete _transitions[1];
	delete _transitions[2];
}

void Intersection_Check_CentreGS::OnEntry::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckMeanderLinesByGSM_VarRefs.mm"
#	include "State_Intersection_Check_CentreGS_VarRefs.mm"
#	include "State_Intersection_Check_CentreGS_OnEntry.mm"
}

void Intersection_Check_CentreGS::OnExit::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckMeanderLinesByGSM_VarRefs.mm"
#	include "State_Intersection_Check_CentreGS_VarRefs.mm"
#	include "State_Intersection_Check_CentreGS_OnExit.mm"
}

void Intersection_Check_CentreGS::Internal::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckMeanderLinesByGSM_VarRefs.mm"
#	include "State_Intersection_Check_CentreGS_VarRefs.mm"
#	include "State_Intersection_Check_CentreGS_Internal.mm"
}

bool Intersection_Check_CentreGS::Transition_0::check(CLMachine *_machine, CLState *_state) const
{
#	include "epuckMeanderLinesByGSM_VarRefs.mm"
#	include "State_Intersection_Check_CentreGS_VarRefs.mm"

	return
	(
#		include "State_Intersection_Check_CentreGS_Transition_0.expr"
	);
}

bool Intersection_Check_CentreGS::Transition_1::check(CLMachine *_machine, CLState *_state) const
{
#	include "epuckMeanderLinesByGSM_VarRefs.mm"
#	include "State_Intersection_Check_CentreGS_VarRefs.mm"

	return
	(
#		include "State_Intersection_Check_CentreGS_Transition_1.expr"
	);
}

bool Intersection_Check_CentreGS::Transition_2::check(CLMachine *_machine, CLState *_state) const
{
#	include "epuckMeanderLinesByGSM_VarRefs.mm"
#	include "State_Intersection_Check_CentreGS_VarRefs.mm"

	return
	(
#		include "State_Intersection_Check_CentreGS_Transition_2.expr"
	);
}
