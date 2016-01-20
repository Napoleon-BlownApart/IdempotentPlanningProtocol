#ifndef WBDIFFERENTIALROBOT_
#define WBDIFFERENTIALROBOT_

#include <sys/types.h>
#include <gu_util.h>
#include "wb_kinematic_motor.h"

/** Differential, kinematic robot model */
struct wb_differential_robot {
        /** kinematic settings for the left motor */
	PROPERTY(struct wb_kinematic_motor, left_motor)
        /** kinematic settings for the right motor */
	PROPERTY(struct wb_kinematic_motor, right_motor)
#ifdef __cplusplus
        /** Default constructor */
	wb_differential_robot() : _left_motor(), _right_motor() {}
#endif
};

#endif
