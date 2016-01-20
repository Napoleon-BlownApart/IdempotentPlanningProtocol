//
// State_Align_Beyond_Intersection.mm
//
// Automatically created through MiCASE -- do not change manually!
//
#include "epuckMeanderLinesByGSM_Includes.h"
#include "epuckMeanderLinesByGSM.h"
#include "State_Align_Beyond_Intersection.h"

#include "State_Align_Beyond_Intersection_Includes.h"

using namespace FSM;
using namespace CLM;
using namespace FSMepuckMeanderLinesByGSM;
using namespace State;

Align_Beyond_Intersection::Align_Beyond_Intersection(const char *name): CLState(name, *new Align_Beyond_Intersection::OnEntry, *new Align_Beyond_Intersection::OnExit, *new Align_Beyond_Intersection::Internal)
{
	_transitions[0] = new Transition_0();
}

Align_Beyond_Intersection::~Align_Beyond_Intersection()
{
	delete &onEntryAction();
	delete &onExitAction();
	delete &internalAction();

	delete _transitions[0];
}

void Align_Beyond_Intersection::OnEntry::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckMeanderLinesByGSM_VarRefs.mm"
#	include "State_Align_Beyond_Intersection_VarRefs.mm"
#	include "State_Align_Beyond_Intersection_OnEntry.mm"
}

void Align_Beyond_Intersection::OnExit::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckMeanderLinesByGSM_VarRefs.mm"
#	include "State_Align_Beyond_Intersection_VarRefs.mm"
#	include "State_Align_Beyond_Intersection_OnExit.mm"
}

void Align_Beyond_Intersection::Internal::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckMeanderLinesByGSM_VarRefs.mm"
#	include "State_Align_Beyond_Intersection_VarRefs.mm"
#	include "State_Align_Beyond_Intersection_Internal.mm"
}

bool Align_Beyond_Intersection::Transition_0::check(CLMachine *_machine, CLState *_state) const
{
#	include "epuckMeanderLinesByGSM_VarRefs.mm"
#	include "State_Align_Beyond_Intersection_VarRefs.mm"

	return
	(
#		include "State_Align_Beyond_Intersection_Transition_0.expr"
	);
}
