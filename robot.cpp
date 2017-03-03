#include "systemc.h"
#include "robot.h"
#include "environment.h"

void robot::motor(){
	struct motionData* thisRobot = envir.getRobotLocation(0);
	float deltaDistance = period * velocity.read();
	// cout << velocity << " " << obstacle << " direction:" << direction.read() << endl;
	if (!obstacle)
	{
		thisRobot->direction = direction.read();
		envir.move(thisRobot, deltaDistance);
	}
	return;
}

void robot::comm() {
	robot_is_crossing.write(near_boundary.read());

	if (near_boundary)
		robot_is_crossing = near_boundary;
		//cout << "robot_is_crossing: " << robot_is_crossing << " near_boundary: " << near_boundary << endl;
		envir.moveRobotToNextGrid(0);
	return;
}
