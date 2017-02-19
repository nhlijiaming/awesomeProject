#include "systemc.h"
#include "robot.h"
#include "environment.h"

void robot::assignment(){
	extern environment envir;
	struct motionData* thisRobot = envir.getRobotLocation(serialNumber);
	float deltaDistance = period * velocity;
	
	if (direction == 0)
	{
		thisRobot->location[1] += deltaDistance;
	}
	else if (direction == 1)
	{
		thisRobot->location[1] -= deltaDistance;
	}
	else if (direction == 2)
	{
		thisRobot->location[0] -= deltaDistance;
	}
	else if (direction == 3)
	{
		thisRobot->location[0] += deltaDistance;
	}

	return;
}
