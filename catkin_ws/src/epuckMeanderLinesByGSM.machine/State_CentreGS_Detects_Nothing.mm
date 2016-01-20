//
// State_CentreGS_Detects_Nothing.mm
//
// Automatically created through MiCASE -- do not change manually!
//
#include "epuckMeanderLinesByGSM_Includes.h"
#include "epuckMeanderLinesByGSM.h"
#include "State_CentreGS_Detects_Nothing.h"

#include "State_CentreGS_Detects_Nothing_Includes.h"

using namespace FSM;
using namespace CLM;
using namespace FSMepuckMeanderLinesByGSM;
using namespace State;

CentreGS_Detects_Nothing::CentreGS_Detects_Nothing(const char *name): CLState(name, *new CentreGS_Detects_Nothing::OnEntry, *new CentreGS_Detects_Nothing::OnExit, *new CentreGS_Detects_Nothing::Internal)
{
	_transitions[0] = new Transition_0();
}

CentreGS_Detects_Nothing::~CentreGS_Detects_Nothing()
{
	delete &onEntryAction();
	delete &onExitAction();
	delete &internalAction();

	delete _transitions[0];
}

void CentreGS_Detects_Nothing::OnEntry::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckMeanderLinesByGSM_VarRefs.mm"
#	include "State_CentreGS_Detects_Nothing_VarRefs.mm"
#	include "State_CentreGS_Detects_Nothing_OnEntry.mm"
}

void CentreGS_Detects_Nothing::OnExit::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckMeanderLinesByGSM_VarRefs.mm"
#	include "State_CentreGS_Detects_Nothing_VarRefs.mm"
#	include "State_CentreGS_Detects_Nothing_OnExit.mm"
}

void CentreGS_Detects_Nothing::Internal::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckMeanderLinesByGSM_VarRefs.mm"
#	include "State_CentreGS_Detects_Nothing_VarRefs.mm"
#	include "State_CentreGS_Detects_Nothing_Internal.mm"
}

bool CentreGS_Detects_Nothing::Transition_0::check(CLMachine *_machine, CLState *_state) const
{
#	include "epuckMeanderLinesByGSM_VarRefs.mm"
#	include "State_CentreGS_Detects_Nothing_VarRefs.mm"

	return
	(
#		include "State_CentreGS_Detects_Nothing_Transition_0.expr"
	);
}
