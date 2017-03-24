#include "systemc.h"
#include "robot.h"
#include "environment.h"

void robot::motor(){
	struct motionData* thisRobot;
	float deltaDistance;

	for(int i = 0; i < numberOfRobots ; i ++)
	{
		thisRobot = envir.getRobotLocation(i);
		deltaDistance = period * velocity[i].read();
		if (envir.checkRobotIfArrived(i))
			return;

		if (!obstacle[i])
		{
			thisRobot->direction = direction[i].read();
			envir.move(thisRobot, deltaDistance);
		}
	}


	return;
}

void robot::comm() {
	for(int i = 0; i < numberOfRobots ; i ++)
	{
		robot_is_crossing[i].write(near_boundary[i].read());
		if (!near_boundary[i])
			envir.moveRobotToNextGrid(i);
	}
	return;
}
