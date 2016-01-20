//
// State_Moved_Down.mm
//
// Automatically created through MiCASE -- do not change manually!
//
#include "epuckCoordinatesByGSM_Includes.h"
#include "epuckCoordinatesByGSM.h"
#include "State_Moved_Down.h"

#include "State_Moved_Down_Includes.h"

using namespace FSM;
using namespace CLM;
using namespace FSMepuckCoordinatesByGSM;
using namespace State;

Moved_Down::Moved_Down(const char *name): CLState(name, *new Moved_Down::OnEntry, *new Moved_Down::OnExit, *new Moved_Down::Internal)
{
	_transitions[0] = new Transition_0();
}

Moved_Down::~Moved_Down()
{
	delete &onEntryAction();
	delete &onExitAction();
	delete &internalAction();

	delete _transitions[0];
}

void Moved_Down::OnEntry::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckCoordinatesByGSM_VarRefs.mm"
#	include "State_Moved_Down_VarRefs.mm"
#	include "State_Moved_Down_OnEntry.mm"
}

void Moved_Down::OnExit::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckCoordinatesByGSM_VarRefs.mm"
#	include "State_Moved_Down_VarRefs.mm"
#	include "State_Moved_Down_OnExit.mm"
}

void Moved_Down::Internal::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckCoordinatesByGSM_VarRefs.mm"
#	include "State_Moved_Down_VarRefs.mm"
#	include "State_Moved_Down_Internal.mm"
}

bool Moved_Down::Transition_0::check(CLMachine *_machine, CLState *_state) const
{
#	include "epuckCoordinatesByGSM_VarRefs.mm"
#	include "State_Moved_Down_VarRefs.mm"

	return
	(
#		include "State_Moved_Down_Transition_0.expr"
	);
}
