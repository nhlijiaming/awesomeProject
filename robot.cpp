#include "systemc.h"
#include "robot.h"
#include "environment.h"

void robot::motor(){
	struct motionData* thisRobot = envir.getRobotLocation(0);
	float deltaDistance = period * velocity.read();

	if (envir.checkRobotIfArrived(0))
		return;

	if (!obstacle)
	{
		thisRobot->direction = direction.read();
		envir.move(thisRobot, deltaDistance);
	}

	return;
}

void robot::comm() {
	robot_is_crossing.write(near_boundary.read());
	// grid_num = envir.getGridNumber(0);
	if (near_boundary)
		envir.moveRobotToNextGrid(0);
	return;
}
