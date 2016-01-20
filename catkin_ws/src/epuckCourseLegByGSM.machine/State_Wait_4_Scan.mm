//
// State_Wait_4_Scan.mm
//
// Automatically created through MiCASE -- do not change manually!
//
#include "epuckCourseLegByGSM_Includes.h"
#include "epuckCourseLegByGSM.h"
#include "State_Wait_4_Scan.h"

#include "State_Wait_4_Scan_Includes.h"

using namespace FSM;
using namespace CLM;
using namespace FSMepuckCourseLegByGSM;
using namespace State;

Wait_4_Scan::Wait_4_Scan(const char *name): CLState(name, *new Wait_4_Scan::OnEntry, *new Wait_4_Scan::OnExit, *new Wait_4_Scan::Internal)
{
	_transitions[0] = new Transition_0();
}

Wait_4_Scan::~Wait_4_Scan()
{
	delete &onEntryAction();
	delete &onExitAction();
	delete &internalAction();

	delete _transitions[0];
}

void Wait_4_Scan::OnEntry::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckCourseLegByGSM_VarRefs.mm"
#	include "State_Wait_4_Scan_VarRefs.mm"
#	include "State_Wait_4_Scan_OnEntry.mm"
}

void Wait_4_Scan::OnExit::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckCourseLegByGSM_VarRefs.mm"
#	include "State_Wait_4_Scan_VarRefs.mm"
#	include "State_Wait_4_Scan_OnExit.mm"
}

void Wait_4_Scan::Internal::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckCourseLegByGSM_VarRefs.mm"
#	include "State_Wait_4_Scan_VarRefs.mm"
#	include "State_Wait_4_Scan_Internal.mm"
}

bool Wait_4_Scan::Transition_0::check(CLMachine *_machine, CLState *_state) const
{
#	include "epuckCourseLegByGSM_VarRefs.mm"
#	include "State_Wait_4_Scan_VarRefs.mm"

	return
	(
#		include "State_Wait_4_Scan_Transition_0.expr"
	);
}
