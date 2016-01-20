//
// State_Are_We_Travelling.mm
//
// Automatically created through MiCASE -- do not change manually!
//
#include "epuckCoordinatesByGSM_Includes.h"
#include "epuckCoordinatesByGSM.h"
#include "State_Are_We_Travelling.h"

#include "State_Are_We_Travelling_Includes.h"

using namespace FSM;
using namespace CLM;
using namespace FSMepuckCoordinatesByGSM;
using namespace State;

Are_We_Travelling::Are_We_Travelling(const char *name): CLState(name, *new Are_We_Travelling::OnEntry, *new Are_We_Travelling::OnExit, *new Are_We_Travelling::Internal)
{
	_transitions[0] = new Transition_0();
}

Are_We_Travelling::~Are_We_Travelling()
{
	delete &onEntryAction();
	delete &onExitAction();
	delete &internalAction();

	delete _transitions[0];
}

void Are_We_Travelling::OnEntry::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckCoordinatesByGSM_VarRefs.mm"
#	include "State_Are_We_Travelling_VarRefs.mm"
#	include "State_Are_We_Travelling_OnEntry.mm"
}

void Are_We_Travelling::OnExit::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckCoordinatesByGSM_VarRefs.mm"
#	include "State_Are_We_Travelling_VarRefs.mm"
#	include "State_Are_We_Travelling_OnExit.mm"
}

void Are_We_Travelling::Internal::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckCoordinatesByGSM_VarRefs.mm"
#	include "State_Are_We_Travelling_VarRefs.mm"
#	include "State_Are_We_Travelling_Internal.mm"
}

bool Are_We_Travelling::Transition_0::check(CLMachine *_machine, CLState *_state) const
{
#	include "epuckCoordinatesByGSM_VarRefs.mm"
#	include "State_Are_We_Travelling_VarRefs.mm"

	return
	(
#		include "State_Are_We_Travelling_Transition_0.expr"
	);
}
