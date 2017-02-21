#include "systemc.h"
#include "robot.h"
#include "environment.h"

void robot::assignment(){
	struct motionData* thisRobot = envir.getRobotLocation(serialNumber);
	float deltaDistance = period * velocity;
	if (!stop)
	{
		thisRobot->direction = direction.read();
		envir.move(thisRobot, deltaDistance);
	}
	return;
}
