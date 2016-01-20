//
// State_Observe_Obstacle.mm
//
// Automatically created through MiCASE -- do not change manually!
//
#include "epuckObstacleOnPathByGSM_Includes.h"
#include "epuckObstacleOnPathByGSM.h"
#include "State_Observe_Obstacle.h"

#include "State_Observe_Obstacle_Includes.h"

using namespace FSM;
using namespace CLM;
using namespace FSMepuckObstacleOnPathByGSM;
using namespace State;

Observe_Obstacle::Observe_Obstacle(const char *name): CLState(name, *new Observe_Obstacle::OnEntry, *new Observe_Obstacle::OnExit, *new Observe_Obstacle::Internal)
{
	_transitions[0] = new Transition_0();
}

Observe_Obstacle::~Observe_Obstacle()
{
	delete &onEntryAction();
	delete &onExitAction();
	delete &internalAction();

	delete _transitions[0];
}

void Observe_Obstacle::OnEntry::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckObstacleOnPathByGSM_VarRefs.mm"
#	include "State_Observe_Obstacle_VarRefs.mm"
#	include "State_Observe_Obstacle_OnEntry.mm"
}

void Observe_Obstacle::OnExit::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckObstacleOnPathByGSM_VarRefs.mm"
#	include "State_Observe_Obstacle_VarRefs.mm"
#	include "State_Observe_Obstacle_OnExit.mm"
}

void Observe_Obstacle::Internal::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckObstacleOnPathByGSM_VarRefs.mm"
#	include "State_Observe_Obstacle_VarRefs.mm"
#	include "State_Observe_Obstacle_Internal.mm"
}

bool Observe_Obstacle::Transition_0::check(CLMachine *_machine, CLState *_state) const
{
#	include "epuckObstacleOnPathByGSM_VarRefs.mm"
#	include "State_Observe_Obstacle_VarRefs.mm"

	return
	(
#		include "State_Observe_Obstacle_Transition_0.expr"
	);
}
