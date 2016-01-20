//
// State_May_Need_Align_Beyond_Intersection.mm
//
// Automatically created through MiCASE -- do not change manually!
//
#include "epuckMeanderLinesByGSM_Includes.h"
#include "epuckMeanderLinesByGSM.h"
#include "State_May_Need_Align_Beyond_Intersection.h"

#include "State_May_Need_Align_Beyond_Intersection_Includes.h"

using namespace FSM;
using namespace CLM;
using namespace FSMepuckMeanderLinesByGSM;
using namespace State;

May_Need_Align_Beyond_Intersection::May_Need_Align_Beyond_Intersection(const char *name): CLState(name, *new May_Need_Align_Beyond_Intersection::OnEntry, *new May_Need_Align_Beyond_Intersection::OnExit, *new May_Need_Align_Beyond_Intersection::Internal)
{
	_transitions[0] = new Transition_0();
	_transitions[1] = new Transition_1();
}

May_Need_Align_Beyond_Intersection::~May_Need_Align_Beyond_Intersection()
{
	delete &onEntryAction();
	delete &onExitAction();
	delete &internalAction();

	delete _transitions[0];
	delete _transitions[1];
}

void May_Need_Align_Beyond_Intersection::OnEntry::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckMeanderLinesByGSM_VarRefs.mm"
#	include "State_May_Need_Align_Beyond_Intersection_VarRefs.mm"
#	include "State_May_Need_Align_Beyond_Intersection_OnEntry.mm"
}

void May_Need_Align_Beyond_Intersection::OnExit::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckMeanderLinesByGSM_VarRefs.mm"
#	include "State_May_Need_Align_Beyond_Intersection_VarRefs.mm"
#	include "State_May_Need_Align_Beyond_Intersection_OnExit.mm"
}

void May_Need_Align_Beyond_Intersection::Internal::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckMeanderLinesByGSM_VarRefs.mm"
#	include "State_May_Need_Align_Beyond_Intersection_VarRefs.mm"
#	include "State_May_Need_Align_Beyond_Intersection_Internal.mm"
}

bool May_Need_Align_Beyond_Intersection::Transition_0::check(CLMachine *_machine, CLState *_state) const
{
#	include "epuckMeanderLinesByGSM_VarRefs.mm"
#	include "State_May_Need_Align_Beyond_Intersection_VarRefs.mm"

	return
	(
#		include "State_May_Need_Align_Beyond_Intersection_Transition_0.expr"
	);
}

bool May_Need_Align_Beyond_Intersection::Transition_1::check(CLMachine *_machine, CLState *_state) const
{
#	include "epuckMeanderLinesByGSM_VarRefs.mm"
#	include "State_May_Need_Align_Beyond_Intersection_VarRefs.mm"

	return
	(
#		include "State_May_Need_Align_Beyond_Intersection_Transition_1.expr"
	);
}
