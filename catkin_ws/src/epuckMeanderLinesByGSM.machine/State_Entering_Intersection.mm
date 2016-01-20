//
// State_Entering_Intersection.mm
//
// Automatically created through MiCASE -- do not change manually!
//
#include "epuckMeanderLinesByGSM_Includes.h"
#include "epuckMeanderLinesByGSM.h"
#include "State_Entering_Intersection.h"

#include "State_Entering_Intersection_Includes.h"

using namespace FSM;
using namespace CLM;
using namespace FSMepuckMeanderLinesByGSM;
using namespace State;

Entering_Intersection::Entering_Intersection(const char *name): CLState(name, *new Entering_Intersection::OnEntry, *new Entering_Intersection::OnExit, *new Entering_Intersection::Internal)
{
	_transitions[0] = new Transition_0();
}

Entering_Intersection::~Entering_Intersection()
{
	delete &onEntryAction();
	delete &onExitAction();
	delete &internalAction();

	delete _transitions[0];
}

void Entering_Intersection::OnEntry::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckMeanderLinesByGSM_VarRefs.mm"
#	include "State_Entering_Intersection_VarRefs.mm"
#	include "State_Entering_Intersection_OnEntry.mm"
}

void Entering_Intersection::OnExit::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckMeanderLinesByGSM_VarRefs.mm"
#	include "State_Entering_Intersection_VarRefs.mm"
#	include "State_Entering_Intersection_OnExit.mm"
}

void Entering_Intersection::Internal::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckMeanderLinesByGSM_VarRefs.mm"
#	include "State_Entering_Intersection_VarRefs.mm"
#	include "State_Entering_Intersection_Internal.mm"
}

bool Entering_Intersection::Transition_0::check(CLMachine *_machine, CLState *_state) const
{
#	include "epuckMeanderLinesByGSM_VarRefs.mm"
#	include "State_Entering_Intersection_VarRefs.mm"

	return
	(
#		include "State_Entering_Intersection_Transition_0.expr"
	);
}
