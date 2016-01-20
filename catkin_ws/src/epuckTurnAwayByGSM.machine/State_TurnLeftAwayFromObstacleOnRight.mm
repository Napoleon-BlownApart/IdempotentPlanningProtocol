//
// State_TurnLeftAwayFromObstacleOnRight.mm
//
// Automatically created through MiCASE -- do not change manually!
//
#include "epuckTurnAwayByGSM_Includes.h"
#include "epuckTurnAwayByGSM.h"
#include "State_TurnLeftAwayFromObstacleOnRight.h"

#include "State_TurnLeftAwayFromObstacleOnRight_Includes.h"

using namespace FSM;
using namespace CLM;
using namespace FSMepuckTurnAwayByGSM;
using namespace State;

TurnLeftAwayFromObstacleOnRight::TurnLeftAwayFromObstacleOnRight(const char *name): CLState(name, *new TurnLeftAwayFromObstacleOnRight::OnEntry, *new TurnLeftAwayFromObstacleOnRight::OnExit, *new TurnLeftAwayFromObstacleOnRight::Internal)
{
	_transitions[0] = new Transition_0();
}

TurnLeftAwayFromObstacleOnRight::~TurnLeftAwayFromObstacleOnRight()
{
	delete &onEntryAction();
	delete &onExitAction();
	delete &internalAction();

	delete _transitions[0];
}

void TurnLeftAwayFromObstacleOnRight::OnEntry::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckTurnAwayByGSM_VarRefs.mm"
#	include "State_TurnLeftAwayFromObstacleOnRight_VarRefs.mm"
#	include "State_TurnLeftAwayFromObstacleOnRight_OnEntry.mm"
}

void TurnLeftAwayFromObstacleOnRight::OnExit::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckTurnAwayByGSM_VarRefs.mm"
#	include "State_TurnLeftAwayFromObstacleOnRight_VarRefs.mm"
#	include "State_TurnLeftAwayFromObstacleOnRight_OnExit.mm"
}

void TurnLeftAwayFromObstacleOnRight::Internal::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckTurnAwayByGSM_VarRefs.mm"
#	include "State_TurnLeftAwayFromObstacleOnRight_VarRefs.mm"
#	include "State_TurnLeftAwayFromObstacleOnRight_Internal.mm"
}

bool TurnLeftAwayFromObstacleOnRight::Transition_0::check(CLMachine *_machine, CLState *_state) const
{
#	include "epuckTurnAwayByGSM_VarRefs.mm"
#	include "State_TurnLeftAwayFromObstacleOnRight_VarRefs.mm"

	return
	(
#		include "State_TurnLeftAwayFromObstacleOnRight_Transition_0.expr"
	);
}
