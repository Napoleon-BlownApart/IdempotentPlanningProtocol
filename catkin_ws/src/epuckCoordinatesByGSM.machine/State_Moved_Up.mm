//
// State_Moved_Up.mm
//
// Automatically created through MiCASE -- do not change manually!
//
#include "epuckCoordinatesByGSM_Includes.h"
#include "epuckCoordinatesByGSM.h"
#include "State_Moved_Up.h"

#include "State_Moved_Up_Includes.h"

using namespace FSM;
using namespace CLM;
using namespace FSMepuckCoordinatesByGSM;
using namespace State;

Moved_Up::Moved_Up(const char *name): CLState(name, *new Moved_Up::OnEntry, *new Moved_Up::OnExit, *new Moved_Up::Internal)
{
	_transitions[0] = new Transition_0();
}

Moved_Up::~Moved_Up()
{
	delete &onEntryAction();
	delete &onExitAction();
	delete &internalAction();

	delete _transitions[0];
}

void Moved_Up::OnEntry::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckCoordinatesByGSM_VarRefs.mm"
#	include "State_Moved_Up_VarRefs.mm"
#	include "State_Moved_Up_OnEntry.mm"
}

void Moved_Up::OnExit::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckCoordinatesByGSM_VarRefs.mm"
#	include "State_Moved_Up_VarRefs.mm"
#	include "State_Moved_Up_OnExit.mm"
}

void Moved_Up::Internal::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckCoordinatesByGSM_VarRefs.mm"
#	include "State_Moved_Up_VarRefs.mm"
#	include "State_Moved_Up_Internal.mm"
}

bool Moved_Up::Transition_0::check(CLMachine *_machine, CLState *_state) const
{
#	include "epuckCoordinatesByGSM_VarRefs.mm"
#	include "State_Moved_Up_VarRefs.mm"

	return
	(
#		include "State_Moved_Up_Transition_0.expr"
	);
}
