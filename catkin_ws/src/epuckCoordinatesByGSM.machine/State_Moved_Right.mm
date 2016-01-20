//
// State_Moved_Right.mm
//
// Automatically created through MiCASE -- do not change manually!
//
#include "epuckCoordinatesByGSM_Includes.h"
#include "epuckCoordinatesByGSM.h"
#include "State_Moved_Right.h"

#include "State_Moved_Right_Includes.h"

using namespace FSM;
using namespace CLM;
using namespace FSMepuckCoordinatesByGSM;
using namespace State;

Moved_Right::Moved_Right(const char *name): CLState(name, *new Moved_Right::OnEntry, *new Moved_Right::OnExit, *new Moved_Right::Internal)
{
	_transitions[0] = new Transition_0();
}

Moved_Right::~Moved_Right()
{
	delete &onEntryAction();
	delete &onExitAction();
	delete &internalAction();

	delete _transitions[0];
}

void Moved_Right::OnEntry::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckCoordinatesByGSM_VarRefs.mm"
#	include "State_Moved_Right_VarRefs.mm"
#	include "State_Moved_Right_OnEntry.mm"
}

void Moved_Right::OnExit::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckCoordinatesByGSM_VarRefs.mm"
#	include "State_Moved_Right_VarRefs.mm"
#	include "State_Moved_Right_OnExit.mm"
}

void Moved_Right::Internal::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckCoordinatesByGSM_VarRefs.mm"
#	include "State_Moved_Right_VarRefs.mm"
#	include "State_Moved_Right_Internal.mm"
}

bool Moved_Right::Transition_0::check(CLMachine *_machine, CLState *_state) const
{
#	include "epuckCoordinatesByGSM_VarRefs.mm"
#	include "State_Moved_Right_VarRefs.mm"

	return
	(
#		include "State_Moved_Right_Transition_0.expr"
	);
}
