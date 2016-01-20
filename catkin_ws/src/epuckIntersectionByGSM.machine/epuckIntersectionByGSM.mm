//
// epuckIntersectionByGSM.mm
//
// Automatically created through MiCASE -- do not change manually!
//
#include "epuckIntersectionByGSM_Includes.h"
#include "epuckIntersectionByGSM.h"

#include "State_InitialPseudoState.h"
#include "State_Initial.h"
#include "State_Observe.h"
#include "State_Intersection_Check_LeftGS.h"
#include "State_In_Intersection_Aligned.h"
#include "State_Entering_Intersection.h"
#include "State_LeftGS_Detects_Path.h"
#include "State_CentreGS_Detects_Path.h"
#include "State_CentreGS_Detects_Intersection.h"
#include "State_RightGS_Detects_Path.h"
#include "State_RightGS_Detects_Intersection.h"
#include "State_May_Need_Align_In_Intersection.h"
#include "State_Align_In_Intersection.h"
#include "State_May_Need_Align_Beyond_Intersection.h"
#include "State_LeftGS_Detects_Nothing.h"
#include "State_Intersection_Check_CentreGS.h"
#include "State_CentreGS_Detects_Nothing.h"
#include "State_Intersection_Check_RightGS.h"
#include "State_RightGS_Detects_Nothing.h"
#include "State_Intersection_Alignment.h"
#include "State_Determine_Direction_Left.h"
#include "State_Align_Beyond_Intersection.h"
#include "State_Left_Is_Available.h"
#include "State_Determine_Direction_Right.h"
#include "State_Right_Is_Available.h"
#include "State_Determine_Direction_Straight.h"
#include "State_Straight_Is_Available.h"
#include "State_Detected_Intersection.h"
#include "State_Not_Detected_Intersection.h"
#include "State_LeftGS_Detects_Intersection.h"
#include "State_SUSPENDED.h"

using namespace FSM;
using namespace CLM;

extern "C"
{
	epuckIntersectionByGSM *CLM_Create_epuckIntersectionByGSM(int mid, const char *name)
	{
		return new epuckIntersectionByGSM(mid, name);
	}
}

epuckIntersectionByGSM::epuckIntersectionByGSM(int mid, const char *name): CLMachine(mid, name)
{
	_states[0] = new FSMepuckIntersectionByGSM::State::InitialPseudoState;
	_states[1] = new FSMepuckIntersectionByGSM::State::Initial;
	_states[2] = new FSMepuckIntersectionByGSM::State::Observe;
	_states[3] = new FSMepuckIntersectionByGSM::State::Intersection_Check_LeftGS;
	_states[4] = new FSMepuckIntersectionByGSM::State::In_Intersection_Aligned;
	_states[5] = new FSMepuckIntersectionByGSM::State::Entering_Intersection;
	_states[6] = new FSMepuckIntersectionByGSM::State::LeftGS_Detects_Path;
	_states[7] = new FSMepuckIntersectionByGSM::State::CentreGS_Detects_Path;
	_states[8] = new FSMepuckIntersectionByGSM::State::CentreGS_Detects_Intersection;
	_states[9] = new FSMepuckIntersectionByGSM::State::RightGS_Detects_Path;
	_states[10] = new FSMepuckIntersectionByGSM::State::RightGS_Detects_Intersection;
	_states[11] = new FSMepuckIntersectionByGSM::State::May_Need_Align_In_Intersection;
	_states[12] = new FSMepuckIntersectionByGSM::State::Align_In_Intersection;
	_states[13] = new FSMepuckIntersectionByGSM::State::May_Need_Align_Beyond_Intersection;
	_states[14] = new FSMepuckIntersectionByGSM::State::LeftGS_Detects_Nothing;
	_states[15] = new FSMepuckIntersectionByGSM::State::Intersection_Check_CentreGS;
	_states[16] = new FSMepuckIntersectionByGSM::State::CentreGS_Detects_Nothing;
	_states[17] = new FSMepuckIntersectionByGSM::State::Intersection_Check_RightGS;
	_states[18] = new FSMepuckIntersectionByGSM::State::RightGS_Detects_Nothing;
	_states[19] = new FSMepuckIntersectionByGSM::State::Intersection_Alignment;
	_states[20] = new FSMepuckIntersectionByGSM::State::Determine_Direction_Left;
	_states[21] = new FSMepuckIntersectionByGSM::State::Align_Beyond_Intersection;
	_states[22] = new FSMepuckIntersectionByGSM::State::Left_Is_Available;
	_states[23] = new FSMepuckIntersectionByGSM::State::Determine_Direction_Right;
	_states[24] = new FSMepuckIntersectionByGSM::State::Right_Is_Available;
	_states[25] = new FSMepuckIntersectionByGSM::State::Determine_Direction_Straight;
	_states[26] = new FSMepuckIntersectionByGSM::State::Straight_Is_Available;
	_states[27] = new FSMepuckIntersectionByGSM::State::Detected_Intersection;
	_states[28] = new FSMepuckIntersectionByGSM::State::Not_Detected_Intersection;
	_states[29] = new FSMepuckIntersectionByGSM::State::LeftGS_Detects_Intersection;
	_states[30] = new FSMepuckIntersectionByGSM::State::SUSPENDED;

	setSuspendState(_states[30]);            // set suspend state
	setInitialState(_states[0]);            // set initial state
}

epuckIntersectionByGSM::~epuckIntersectionByGSM()
{
	delete _states[0];
	delete _states[1];
	delete _states[2];
	delete _states[3];
	delete _states[4];
	delete _states[5];
	delete _states[6];
	delete _states[7];
	delete _states[8];
	delete _states[9];
	delete _states[10];
	delete _states[11];
	delete _states[12];
	delete _states[13];
	delete _states[14];
	delete _states[15];
	delete _states[16];
	delete _states[17];
	delete _states[18];
	delete _states[19];
	delete _states[20];
	delete _states[21];
	delete _states[22];
	delete _states[23];
	delete _states[24];
	delete _states[25];
	delete _states[26];
	delete _states[27];
	delete _states[28];
	delete _states[29];
	delete _states[30];
}
