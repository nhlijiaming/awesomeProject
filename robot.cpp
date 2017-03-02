#include "systemc.h"
#include "robot.h"
#include "environment.h"


void robot::motor(){
	struct motionData* thisRobot = envir.getRobotLocation(0);
	float deltaDistance = period * velocity.read();

	thisRobot->direction = direction.read();
	envir.move(thisRobot, deltaDistance);
	return;
}

void robot::comm() {
	robot_is_crossing = near_boundry;
	grid_num = envir.getGridNumber(0);
	return;
}
