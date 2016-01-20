//
// State_Add_Next_Obstacle.mm
//
// Automatically created through MiCASE -- do not change manually!
//
#include "epuckPlanManagerByGSM_Includes.h"
#include "epuckPlanManagerByGSM.h"
#include "State_Add_Next_Obstacle.h"

#include "State_Add_Next_Obstacle_Includes.h"

using namespace FSM;
using namespace CLM;
using namespace FSMepuckPlanManagerByGSM;
using namespace State;

Add_Next_Obstacle::Add_Next_Obstacle(const char *name): CLState(name, *new Add_Next_Obstacle::OnEntry, *new Add_Next_Obstacle::OnExit, *new Add_Next_Obstacle::Internal)
{
	_transitions[0] = new Transition_0();
}

Add_Next_Obstacle::~Add_Next_Obstacle()
{
	delete &onEntryAction();
	delete &onExitAction();
	delete &internalAction();

	delete _transitions[0];
}

void Add_Next_Obstacle::OnEntry::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckPlanManagerByGSM_VarRefs.mm"
#	include "State_Add_Next_Obstacle_VarRefs.mm"
#	include "State_Add_Next_Obstacle_OnEntry.mm"
}

void Add_Next_Obstacle::OnExit::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckPlanManagerByGSM_VarRefs.mm"
#	include "State_Add_Next_Obstacle_VarRefs.mm"
#	include "State_Add_Next_Obstacle_OnExit.mm"
}

void Add_Next_Obstacle::Internal::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckPlanManagerByGSM_VarRefs.mm"
#	include "State_Add_Next_Obstacle_VarRefs.mm"
#	include "State_Add_Next_Obstacle_Internal.mm"
}

bool Add_Next_Obstacle::Transition_0::check(CLMachine *_machine, CLState *_state) const
{
#	include "epuckPlanManagerByGSM_VarRefs.mm"
#	include "State_Add_Next_Obstacle_VarRefs.mm"

	return
	(
#		include "State_Add_Next_Obstacle_Transition_0.expr"
	);
}
