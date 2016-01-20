//
// State_DirectionChosen.mm
//
// Automatically created through MiCASE -- do not change manually!
//
#include "epuckCourseLegByGSM_Includes.h"
#include "epuckCourseLegByGSM.h"
#include "State_DirectionChosen.h"

#include "State_DirectionChosen_Includes.h"

using namespace FSM;
using namespace CLM;
using namespace FSMepuckCourseLegByGSM;
using namespace State;

DirectionChosen::DirectionChosen(const char *name): CLState(name, *new DirectionChosen::OnEntry, *new DirectionChosen::OnExit, *new DirectionChosen::Internal)
{
	_transitions[0] = new Transition_0();
}

DirectionChosen::~DirectionChosen()
{
	delete &onEntryAction();
	delete &onExitAction();
	delete &internalAction();

	delete _transitions[0];
}

void DirectionChosen::OnEntry::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckCourseLegByGSM_VarRefs.mm"
#	include "State_DirectionChosen_VarRefs.mm"
#	include "State_DirectionChosen_OnEntry.mm"
}

void DirectionChosen::OnExit::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckCourseLegByGSM_VarRefs.mm"
#	include "State_DirectionChosen_VarRefs.mm"
#	include "State_DirectionChosen_OnExit.mm"
}

void DirectionChosen::Internal::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckCourseLegByGSM_VarRefs.mm"
#	include "State_DirectionChosen_VarRefs.mm"
#	include "State_DirectionChosen_Internal.mm"
}

bool DirectionChosen::Transition_0::check(CLMachine *_machine, CLState *_state) const
{
#	include "epuckCourseLegByGSM_VarRefs.mm"
#	include "State_DirectionChosen_VarRefs.mm"

	return
	(
#		include "State_DirectionChosen_Transition_0.expr"
	);
}
