//
// State_Intersection_Alignment.mm
//
// Automatically created through MiCASE -- do not change manually!
//
#include "epuckMeanderLinesByGSM_Includes.h"
#include "epuckMeanderLinesByGSM.h"
#include "State_Intersection_Alignment.h"

#include "State_Intersection_Alignment_Includes.h"

using namespace FSM;
using namespace CLM;
using namespace FSMepuckMeanderLinesByGSM;
using namespace State;

Intersection_Alignment::Intersection_Alignment(const char *name): CLState(name, *new Intersection_Alignment::OnEntry, *new Intersection_Alignment::OnExit, *new Intersection_Alignment::Internal)
{
	_transitions[0] = new Transition_0();
	_transitions[1] = new Transition_1();
}

Intersection_Alignment::~Intersection_Alignment()
{
	delete &onEntryAction();
	delete &onExitAction();
	delete &internalAction();

	delete _transitions[0];
	delete _transitions[1];
}

void Intersection_Alignment::OnEntry::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckMeanderLinesByGSM_VarRefs.mm"
#	include "State_Intersection_Alignment_VarRefs.mm"
#	include "State_Intersection_Alignment_OnEntry.mm"
}

void Intersection_Alignment::OnExit::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckMeanderLinesByGSM_VarRefs.mm"
#	include "State_Intersection_Alignment_VarRefs.mm"
#	include "State_Intersection_Alignment_OnExit.mm"
}

void Intersection_Alignment::Internal::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckMeanderLinesByGSM_VarRefs.mm"
#	include "State_Intersection_Alignment_VarRefs.mm"
#	include "State_Intersection_Alignment_Internal.mm"
}

bool Intersection_Alignment::Transition_0::check(CLMachine *_machine, CLState *_state) const
{
#	include "epuckMeanderLinesByGSM_VarRefs.mm"
#	include "State_Intersection_Alignment_VarRefs.mm"

	return
	(
#		include "State_Intersection_Alignment_Transition_0.expr"
	);
}

bool Intersection_Alignment::Transition_1::check(CLMachine *_machine, CLState *_state) const
{
#	include "epuckMeanderLinesByGSM_VarRefs.mm"
#	include "State_Intersection_Alignment_VarRefs.mm"

	return
	(
#		include "State_Intersection_Alignment_Transition_1.expr"
	);
}
