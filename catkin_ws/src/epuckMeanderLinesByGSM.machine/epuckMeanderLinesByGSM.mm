//
// epuckMeanderLinesByGSM.mm
//
// Automatically created through MiCASE -- do not change manually!
//
#include "epuckMeanderLinesByGSM_Includes.h"
#include "epuckMeanderLinesByGSM.h"

#include "State_InitialPseudoState.h"
#include "State_Initial.h"
#include "State_Forward.h"
#include "State_Intersection_Check_LeftGS.h"
#include "State_Turn_Right.h"
#include "State_Turn_Left.h"
#include "State_Align_After_Left_Turn.h"
#include "State_ChooseDirection.h"
#include "State_Stop.h"
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
#include "State_Align_To_Left_Beyond_Intersection.h"
#include "State_May_Need_Align_Beyond_Intersection.h"
#include "State_TurnLeftAwayFromObstacleOnRight.h"
#include "State_TurnRightAwayFromObstacleOnLeft.h"
#include "State_LeftGS_Detects_Nothing.h"
#include "State_Intersection_Check_CentreGS.h"
#include "State_CentreGS_Detects_Nothing.h"
#include "State_Intersection_Check_RightGS.h"
#include "State_RightGS_Detects_Nothing.h"
#include "State_Intersection_Alignment.h"
#include "State_Determine_Directiion_Left.h"
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

using namespace FSM;
using namespace CLM;

extern "C"
{
	epuckMeanderLinesByGSM *CLM_Create_epuckMeanderLinesByGSM(int mid, const char *name)
	{
		return new epuckMeanderLinesByGSM(mid, name);
	}
}

epuckMeanderLinesByGSM::epuckMeanderLinesByGSM(int mid, const char *name): CLMachine(mid, name)
{
	_states[0] = new FSMepuckMeanderLinesByGSM::State::InitialPseudoState;
	_states[1] = new FSMepuckMeanderLinesByGSM::State::Initial;
	_states[2] = new FSMepuckMeanderLinesByGSM::State::Forward;
	_states[3] = new FSMepuckMeanderLinesByGSM::State::Intersection_Check_LeftGS;
	_states[4] = new FSMepuckMeanderLinesByGSM::State::Turn_Right;
	_states[5] = new FSMepuckMeanderLinesByGSM::State::Turn_Left;
	_states[6] = new FSMepuckMeanderLinesByGSM::State::Align_After_Left_Turn;
	_states[7] = new FSMepuckMeanderLinesByGSM::State::ChooseDirection;
	_states[8] = new FSMepuckMeanderLinesByGSM::State::Stop;
	_states[9] = new FSMepuckMeanderLinesByGSM::State::Entering_Intersection;
	_states[10] = new FSMepuckMeanderLinesByGSM::State::Forward_Feedback;
	_states[11] = new FSMepuckMeanderLinesByGSM::State::LeftGS_Detects_Path;
	_states[12] = new FSMepuckMeanderLinesByGSM::State::LeftGS_Detects_Intersection;
	_states[13] = new FSMepuckMeanderLinesByGSM::State::CentreGS_Detects_Path;
	_states[14] = new FSMepuckMeanderLinesByGSM::State::CentreGS_Detects_Intersection;
	_states[15] = new FSMepuckMeanderLinesByGSM::State::RightGS_Detects_Path;
	_states[16] = new FSMepuckMeanderLinesByGSM::State::RightGS_Detects_Intersection;
	_states[17] = new FSMepuckMeanderLinesByGSM::State::May_Need_Align_In_Intersection;
	_states[18] = new FSMepuckMeanderLinesByGSM::State::Align_In_Intersection;
	_states[19] = new FSMepuckMeanderLinesByGSM::State::Align_To_Left_Beyond_Intersection;
	_states[20] = new FSMepuckMeanderLinesByGSM::State::May_Need_Align_Beyond_Intersection;
	_states[21] = new FSMepuckMeanderLinesByGSM::State::TurnLeftAwayFromObstacleOnRight;
	_states[22] = new FSMepuckMeanderLinesByGSM::State::TurnRightAwayFromObstacleOnLeft;
	_states[23] = new FSMepuckMeanderLinesByGSM::State::LeftGS_Detects_Nothing;
	_states[24] = new FSMepuckMeanderLinesByGSM::State::Intersection_Check_CentreGS;
	_states[25] = new FSMepuckMeanderLinesByGSM::State::CentreGS_Detects_Nothing;
	_states[26] = new FSMepuckMeanderLinesByGSM::State::Intersection_Check_RightGS;
	_states[27] = new FSMepuckMeanderLinesByGSM::State::RightGS_Detects_Nothing;
	_states[28] = new FSMepuckMeanderLinesByGSM::State::Intersection_Alignment;
	_states[29] = new FSMepuckMeanderLinesByGSM::State::Determine_Directiion_Left;
	_states[30] = new FSMepuckMeanderLinesByGSM::State::Align_Beyond_Intersection;
	_states[31] = new FSMepuckMeanderLinesByGSM::State::Left_Is_Available;
	_states[32] = new FSMepuckMeanderLinesByGSM::State::Determine_Direction_Right;
	_states[33] = new FSMepuckMeanderLinesByGSM::State::Right_Is_Available;
	_states[34] = new FSMepuckMeanderLinesByGSM::State::Determine_Direction_Straight;
	_states[35] = new FSMepuckMeanderLinesByGSM::State::Straight_Is_Available;
	_states[36] = new FSMepuckMeanderLinesByGSM::State::Continue_Forward;
	_states[37] = new FSMepuckMeanderLinesByGSM::State::Continue_Align_Left;
	_states[38] = new FSMepuckMeanderLinesByGSM::State::Align_After_Right_Turn;
	_states[39] = new FSMepuckMeanderLinesByGSM::State::Continue_Align_Right;

	setInitialState(_states[0]);            // set initial state
}

epuckMeanderLinesByGSM::~epuckMeanderLinesByGSM()
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
}
