//
// State_Send_Obstacles.mm
//
// Automatically created through MiCASE -- do not change manually!
//
#include "epuckPlanManagerByGSM_Includes.h"
#include "epuckPlanManagerByGSM.h"
#include "State_Send_Obstacles.h"

#include "State_Send_Obstacles_Includes.h"

using namespace FSM;
using namespace CLM;
using namespace FSMepuckPlanManagerByGSM;
using namespace State;

Send_Obstacles::Send_Obstacles(const char *name): CLState(name, *new Send_Obstacles::OnEntry, *new Send_Obstacles::OnExit, *new Send_Obstacles::Internal)
{
	_transitions[0] = new Transition_0();
}

Send_Obstacles::~Send_Obstacles()
{
	delete &onEntryAction();
	delete &onExitAction();
	delete &internalAction();

	delete _transitions[0];
}

void Send_Obstacles::OnEntry::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckPlanManagerByGSM_VarRefs.mm"
#	include "State_Send_Obstacles_VarRefs.mm"
#	include "State_Send_Obstacles_OnEntry.mm"
}

void Send_Obstacles::OnExit::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckPlanManagerByGSM_VarRefs.mm"
#	include "State_Send_Obstacles_VarRefs.mm"
#	include "State_Send_Obstacles_OnExit.mm"
}

void Send_Obstacles::Internal::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckPlanManagerByGSM_VarRefs.mm"
#	include "State_Send_Obstacles_VarRefs.mm"
#	include "State_Send_Obstacles_Internal.mm"
}

bool Send_Obstacles::Transition_0::check(CLMachine *_machine, CLState *_state) const
{
#	include "epuckPlanManagerByGSM_VarRefs.mm"
#	include "State_Send_Obstacles_VarRefs.mm"

	return
	(
#		include "State_Send_Obstacles_Transition_0.expr"
	);
}
