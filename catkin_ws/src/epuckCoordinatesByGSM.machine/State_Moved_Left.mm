//
// State_Moved_Left.mm
//
// Automatically created through MiCASE -- do not change manually!
//
#include "epuckCoordinatesByGSM_Includes.h"
#include "epuckCoordinatesByGSM.h"
#include "State_Moved_Left.h"

#include "State_Moved_Left_Includes.h"

using namespace FSM;
using namespace CLM;
using namespace FSMepuckCoordinatesByGSM;
using namespace State;

Moved_Left::Moved_Left(const char *name): CLState(name, *new Moved_Left::OnEntry, *new Moved_Left::OnExit, *new Moved_Left::Internal)
{
	_transitions[0] = new Transition_0();
}

Moved_Left::~Moved_Left()
{
	delete &onEntryAction();
	delete &onExitAction();
	delete &internalAction();

	delete _transitions[0];
}

void Moved_Left::OnEntry::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckCoordinatesByGSM_VarRefs.mm"
#	include "State_Moved_Left_VarRefs.mm"
#	include "State_Moved_Left_OnEntry.mm"
}

void Moved_Left::OnExit::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckCoordinatesByGSM_VarRefs.mm"
#	include "State_Moved_Left_VarRefs.mm"
#	include "State_Moved_Left_OnExit.mm"
}

void Moved_Left::Internal::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckCoordinatesByGSM_VarRefs.mm"
#	include "State_Moved_Left_VarRefs.mm"
#	include "State_Moved_Left_Internal.mm"
}

bool Moved_Left::Transition_0::check(CLMachine *_machine, CLState *_state) const
{
#	include "epuckCoordinatesByGSM_VarRefs.mm"
#	include "State_Moved_Left_VarRefs.mm"

	return
	(
#		include "State_Moved_Left_Transition_0.expr"
	);
}
