//
// State_TurnRightAwayFromObstacleOnLeft.mm
//
// Automatically created through MiCASE -- do not change manually!
//
#include "epuckMeanderLinesByGSM_Includes.h"
#include "epuckMeanderLinesByGSM.h"
#include "State_TurnRightAwayFromObstacleOnLeft.h"

#include "State_TurnRightAwayFromObstacleOnLeft_Includes.h"

using namespace FSM;
using namespace CLM;
using namespace FSMepuckMeanderLinesByGSM;
using namespace State;

TurnRightAwayFromObstacleOnLeft::TurnRightAwayFromObstacleOnLeft(const char *name): CLState(name, *new TurnRightAwayFromObstacleOnLeft::OnEntry, *new TurnRightAwayFromObstacleOnLeft::OnExit, *new TurnRightAwayFromObstacleOnLeft::Internal)
{
	_transitions[0] = new Transition_0();
}

TurnRightAwayFromObstacleOnLeft::~TurnRightAwayFromObstacleOnLeft()
{
	delete &onEntryAction();
	delete &onExitAction();
	delete &internalAction();

	delete _transitions[0];
}

void TurnRightAwayFromObstacleOnLeft::OnEntry::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckMeanderLinesByGSM_VarRefs.mm"
#	include "State_TurnRightAwayFromObstacleOnLeft_VarRefs.mm"
#	include "State_TurnRightAwayFromObstacleOnLeft_OnEntry.mm"
}

void TurnRightAwayFromObstacleOnLeft::OnExit::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckMeanderLinesByGSM_VarRefs.mm"
#	include "State_TurnRightAwayFromObstacleOnLeft_VarRefs.mm"
#	include "State_TurnRightAwayFromObstacleOnLeft_OnExit.mm"
}

void TurnRightAwayFromObstacleOnLeft::Internal::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckMeanderLinesByGSM_VarRefs.mm"
#	include "State_TurnRightAwayFromObstacleOnLeft_VarRefs.mm"
#	include "State_TurnRightAwayFromObstacleOnLeft_Internal.mm"
}

bool TurnRightAwayFromObstacleOnLeft::Transition_0::check(CLMachine *_machine, CLState *_state) const
{
#	include "epuckMeanderLinesByGSM_VarRefs.mm"
#	include "State_TurnRightAwayFromObstacleOnLeft_VarRefs.mm"

	return
	(
#		include "State_TurnRightAwayFromObstacleOnLeft_Transition_0.expr"
	);
}
