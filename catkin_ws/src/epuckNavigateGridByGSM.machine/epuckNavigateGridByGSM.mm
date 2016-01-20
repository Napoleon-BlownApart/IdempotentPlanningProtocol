//
// epuckNavigateGridByGSM.mm
//
// Automatically created through MiCASE -- do not change manually!
//
#include "epuckNavigateGridByGSM_Includes.h"
#include "epuckNavigateGridByGSM.h"

#include "State_InitialPseudoState.h"
#include "State_Initial.h"
#include "State_Forward.h"
#include "State_Intersection_Check_LeftGS.h"
#include "State_Turn_Right.h"
#include "State_Turn_Left.h"
#include "State_Align_After_Left_Turn.h"
#include "State_ChooseDirection.h"
#include "State_At_Goal.h"
#include "State_Entering_Intersection.h"
#include "State_Forward_Feedback.h"
#include "State_LeftGS_Detects_Path.h"
#include "State_LeftGS_Detects_Intersection.h"
#include "State_CentreGS_Detects_Path.h"
#include "State_CentreGS_Detects_Intersection.h"
#include "State_RightGS_Detects_Path.h"
#include "State_RightGS_Detects_Intersection.h"
#include "State_May_Need_Align_In_Intersection.h"
#include "State_Align_In_Intersection.h"
#include "State_May_Need_Align_Beyond_Intersection.h"
#include "State_TurnLeftAwayFromObstacleOnRight.h"
#include "State_TurnRightAwayFromObstacleOnLeft.h"
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
#include "State_Continue_Forward.h"
#include "State_Continue_Align_Left.h"
#include "State_Align_After_Right_Turn.h"
#include "State_Continue_Align_Right.h"
#include "State_No_Goal.h"
#include "State_Stop.h"
#include "State_Unreachable.h"

using namespace FSM;
using namespace CLM;

extern "C"
{
	epuckNavigateGridByGSM *CLM_Create_epuckNavigateGridByGSM(int mid, const char *name)
	{
		return new epuckNavigateGridByGSM(mid, name);
	}
}

epuckNavigateGridByGSM::epuckNavigateGridByGSM(int mid, const char *name): CLMachine(mid, name)
{
	_states[0] = new FSMepuckNavigateGridByGSM::State::InitialPseudoState;
	_states[1] = new FSMepuckNavigateGridByGSM::State::Initial;
	_states[2] = new FSMepuckNavigateGridByGSM::State::Forward;
	_states[3] = new FSMepuckNavigateGridByGSM::State::Intersection_Check_LeftGS;
	_states[4] = new FSMepuckNavigateGridByGSM::State::Turn_Right;
	_states[5] = new FSMepuckNavigateGridByGSM::State::Turn_Left;
	_states[6] = new FSMepuckNavigateGridByGSM::State::Align_After_Left_Turn;
	_states[7] = new FSMepuckNavigateGridByGSM::State::ChooseDirection;
	_states[8] = new FSMepuckNavigateGridByGSM::State::At_Goal;
	_states[9] = new FSMepuckNavigateGridByGSM::State::Entering_Intersection;
	_states[10] = new FSMepuckNavigateGridByGSM::State::Forward_Feedback;
	_states[11] = new FSMepuckNavigateGridByGSM::State::LeftGS_Detects_Path;
	_states[12] = new FSMepuckNavigateGridByGSM::State::LeftGS_Detects_Intersection;
	_states[13] = new FSMepuckNavigateGridByGSM::State::CentreGS_Detects_Path;
	_states[14] = new FSMepuckNavigateGridByGSM::State::CentreGS_Detects_Intersection;
	_states[15] = new FSMepuckNavigateGridByGSM::State::RightGS_Detects_Path;
	_states[16] = new FSMepuckNavigateGridByGSM::State::RightGS_Detects_Intersection;
	_states[17] = new FSMepuckNavigateGridByGSM::State::May_Need_Align_In_Intersection;
	_states[18] = new FSMepuckNavigateGridByGSM::State::Align_In_Intersection;
	_states[19] = new FSMepuckNavigateGridByGSM::State::May_Need_Align_Beyond_Intersection;
	_states[20] = new FSMepuckNavigateGridByGSM::State::TurnLeftAwayFromObstacleOnRight;
	_states[21] = new FSMepuckNavigateGridByGSM::State::TurnRightAwayFromObstacleOnLeft;
	_states[22] = new FSMepuckNavigateGridByGSM::State::LeftGS_Detects_Nothing;
	_states[23] = new FSMepuckNavigateGridByGSM::State::Intersection_Check_CentreGS;
	_states[24] = new FSMepuckNavigateGridByGSM::State::CentreGS_Detects_Nothing;
	_states[25] = new FSMepuckNavigateGridByGSM::State::Intersection_Check_RightGS;
	_states[26] = new FSMepuckNavigateGridByGSM::State::RightGS_Detects_Nothing;
	_states[27] = new FSMepuckNavigateGridByGSM::State::Intersection_Alignment;
	_states[28] = new FSMepuckNavigateGridByGSM::State::Determine_Direction_Left;
	_states[29] = new FSMepuckNavigateGridByGSM::State::Align_Beyond_Intersection;
	_states[30] = new FSMepuckNavigateGridByGSM::State::Left_Is_Available;
	_states[31] = new FSMepuckNavigateGridByGSM::State::Determine_Direction_Right;
	_states[32] = new FSMepuckNavigateGridByGSM::State::Right_Is_Available;
	_states[33] = new FSMepuckNavigateGridByGSM::State::Determine_Direction_Straight;
	_states[34] = new FSMepuckNavigateGridByGSM::State::Straight_Is_Available;
	_states[35] = new FSMepuckNavigateGridByGSM::State::Continue_Forward;
	_states[36] = new FSMepuckNavigateGridByGSM::State::Continue_Align_Left;
	_states[37] = new FSMepuckNavigateGridByGSM::State::Align_After_Right_Turn;
	_states[38] = new FSMepuckNavigateGridByGSM::State::Continue_Align_Right;
	_states[39] = new FSMepuckNavigateGridByGSM::State::No_Goal;
	_states[40] = new FSMepuckNavigateGridByGSM::State::Stop;
	_states[41] = new FSMepuckNavigateGridByGSM::State::Unreachable;

	setInitialState(_states[0]);            // set initial state
}

epuckNavigateGridByGSM::~epuckNavigateGridByGSM()
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
	delete _states[31];
	delete _states[32];
	delete _states[33];
	delete _states[34];
	delete _states[35];
	delete _states[36];
	delete _states[37];
	delete _states[38];
	delete _states[39];
	delete _states[40];
	delete _states[41];
}
