//
// State_Load_Obstacles.mm
//
// Automatically created through MiCASE -- do not change manually!
//
#include "epuckPlanManagerByGSM_Includes.h"
#include "epuckPlanManagerByGSM.h"
#include "State_Load_Obstacles.h"

#include "State_Load_Obstacles_Includes.h"

using namespace FSM;
using namespace CLM;
using namespace FSMepuckPlanManagerByGSM;
using namespace State;

Load_Obstacles::Load_Obstacles(const char *name): CLState(name, *new Load_Obstacles::OnEntry, *new Load_Obstacles::OnExit, *new Load_Obstacles::Internal)
{
	_transitions[0] = new Transition_0();
}

Load_Obstacles::~Load_Obstacles()
{
	delete &onEntryAction();
	delete &onExitAction();
	delete &internalAction();

	delete _transitions[0];
}

void Load_Obstacles::OnEntry::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckPlanManagerByGSM_VarRefs.mm"
#	include "State_Load_Obstacles_VarRefs.mm"
#	include "State_Load_Obstacles_OnEntry.mm"
}

void Load_Obstacles::OnExit::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckPlanManagerByGSM_VarRefs.mm"
#	include "State_Load_Obstacles_VarRefs.mm"
#	include "State_Load_Obstacles_OnExit.mm"
}

void Load_Obstacles::Internal::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckPlanManagerByGSM_VarRefs.mm"
#	include "State_Load_Obstacles_VarRefs.mm"
#	include "State_Load_Obstacles_Internal.mm"
}

bool Load_Obstacles::Transition_0::check(CLMachine *_machine, CLState *_state) const
{
#	include "epuckPlanManagerByGSM_VarRefs.mm"
#	include "State_Load_Obstacles_VarRefs.mm"

	return
	(
#		include "State_Load_Obstacles_Transition_0.expr"
	);
}
