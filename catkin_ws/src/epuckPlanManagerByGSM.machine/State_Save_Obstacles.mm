//
// State_Save_Obstacles.mm
//
// Automatically created through MiCASE -- do not change manually!
//
#include "epuckPlanManagerByGSM_Includes.h"
#include "epuckPlanManagerByGSM.h"
#include "State_Save_Obstacles.h"

#include "State_Save_Obstacles_Includes.h"

using namespace FSM;
using namespace CLM;
using namespace FSMepuckPlanManagerByGSM;
using namespace State;

Save_Obstacles::Save_Obstacles(const char *name): CLState(name, *new Save_Obstacles::OnEntry, *new Save_Obstacles::OnExit, *new Save_Obstacles::Internal)
{
	_transitions[0] = new Transition_0();
}

Save_Obstacles::~Save_Obstacles()
{
	delete &onEntryAction();
	delete &onExitAction();
	delete &internalAction();

	delete _transitions[0];
}

void Save_Obstacles::OnEntry::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckPlanManagerByGSM_VarRefs.mm"
#	include "State_Save_Obstacles_VarRefs.mm"
#	include "State_Save_Obstacles_OnEntry.mm"
}

void Save_Obstacles::OnExit::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckPlanManagerByGSM_VarRefs.mm"
#	include "State_Save_Obstacles_VarRefs.mm"
#	include "State_Save_Obstacles_OnExit.mm"
}

void Save_Obstacles::Internal::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckPlanManagerByGSM_VarRefs.mm"
#	include "State_Save_Obstacles_VarRefs.mm"
#	include "State_Save_Obstacles_Internal.mm"
}

bool Save_Obstacles::Transition_0::check(CLMachine *_machine, CLState *_state) const
{
#	include "epuckPlanManagerByGSM_VarRefs.mm"
#	include "State_Save_Obstacles_VarRefs.mm"

	return
	(
#		include "State_Save_Obstacles_Transition_0.expr"
	);
}
