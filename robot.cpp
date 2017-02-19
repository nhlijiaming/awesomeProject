#include "systemc.h"
#include "robot.h"
#include "environment.h"

void robot::assignment(){
	struct motionData* thisRobot = envir.getRobotLocation(serialNumber);
	float deltaDistance = period * velocity;
	thisRobot->direction = direction;
	envir.move(thisRobot, deltaDistance);
	return;
}
