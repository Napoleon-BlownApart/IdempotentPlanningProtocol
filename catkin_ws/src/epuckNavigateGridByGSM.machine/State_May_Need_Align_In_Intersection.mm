//
// State_May_Need_Align_In_Intersection.mm
//
// Automatically created through MiCASE -- do not change manually!
//
#include "epuckNavigateGridByGSM_Includes.h"
#include "epuckNavigateGridByGSM.h"
#include "State_May_Need_Align_In_Intersection.h"

#include "State_May_Need_Align_In_Intersection_Includes.h"

using namespace FSM;
using namespace CLM;
using namespace FSMepuckNavigateGridByGSM;
using namespace State;

May_Need_Align_In_Intersection::May_Need_Align_In_Intersection(const char *name): CLState(name, *new May_Need_Align_In_Intersection::OnEntry, *new May_Need_Align_In_Intersection::OnExit, *new May_Need_Align_In_Intersection::Internal)
{
	_transitions[0] = new Transition_0();
	_transitions[1] = new Transition_1();
}

May_Need_Align_In_Intersection::~May_Need_Align_In_Intersection()
{
	delete &onEntryAction();
	delete &onExitAction();
	delete &internalAction();

	delete _transitions[0];
	delete _transitions[1];
}

void May_Need_Align_In_Intersection::OnEntry::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckNavigateGridByGSM_VarRefs.mm"
#	include "State_May_Need_Align_In_Intersection_VarRefs.mm"
#	include "State_May_Need_Align_In_Intersection_OnEntry.mm"
}

void May_Need_Align_In_Intersection::OnExit::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckNavigateGridByGSM_VarRefs.mm"
#	include "State_May_Need_Align_In_Intersection_VarRefs.mm"
#	include "State_May_Need_Align_In_Intersection_OnExit.mm"
}

void May_Need_Align_In_Intersection::Internal::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckNavigateGridByGSM_VarRefs.mm"
#	include "State_May_Need_Align_In_Intersection_VarRefs.mm"
#	include "State_May_Need_Align_In_Intersection_Internal.mm"
}

bool May_Need_Align_In_Intersection::Transition_0::check(CLMachine *_machine, CLState *_state) const
{
#	include "epuckNavigateGridByGSM_VarRefs.mm"
#	include "State_May_Need_Align_In_Intersection_VarRefs.mm"

	return
	(
#		include "State_May_Need_Align_In_Intersection_Transition_0.expr"
	);
}

bool May_Need_Align_In_Intersection::Transition_1::check(CLMachine *_machine, CLState *_state) const
{
#	include "epuckNavigateGridByGSM_VarRefs.mm"
#	include "State_May_Need_Align_In_Intersection_VarRefs.mm"

	return
	(
#		include "State_May_Need_Align_In_Intersection_Transition_1.expr"
	);
}
