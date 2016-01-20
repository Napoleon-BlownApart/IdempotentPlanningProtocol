//
// State_Forward_Feedback.mm
//
// Automatically created through MiCASE -- do not change manually!
//
#include "epuckMeanderLinesByGSM_Includes.h"
#include "epuckMeanderLinesByGSM.h"
#include "State_Forward_Feedback.h"

#include "State_Forward_Feedback_Includes.h"

using namespace FSM;
using namespace CLM;
using namespace FSMepuckMeanderLinesByGSM;
using namespace State;

Forward_Feedback::Forward_Feedback(const char *name): CLState(name, *new Forward_Feedback::OnEntry, *new Forward_Feedback::OnExit, *new Forward_Feedback::Internal)
{
	_transitions[0] = new Transition_0();
}

Forward_Feedback::~Forward_Feedback()
{
	delete &onEntryAction();
	delete &onExitAction();
	delete &internalAction();

	delete _transitions[0];
}

void Forward_Feedback::OnEntry::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckMeanderLinesByGSM_VarRefs.mm"
#	include "State_Forward_Feedback_VarRefs.mm"
#	include "State_Forward_Feedback_OnEntry.mm"
}

void Forward_Feedback::OnExit::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckMeanderLinesByGSM_VarRefs.mm"
#	include "State_Forward_Feedback_VarRefs.mm"
#	include "State_Forward_Feedback_OnExit.mm"
}

void Forward_Feedback::Internal::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckMeanderLinesByGSM_VarRefs.mm"
#	include "State_Forward_Feedback_VarRefs.mm"
#	include "State_Forward_Feedback_Internal.mm"
}

bool Forward_Feedback::Transition_0::check(CLMachine *_machine, CLState *_state) const
{
#	include "epuckMeanderLinesByGSM_VarRefs.mm"
#	include "State_Forward_Feedback_VarRefs.mm"

	return
	(
#		include "State_Forward_Feedback_Transition_0.expr"
	);
}
