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
<<<<<<< HEAD
	robot_is_crossing = near_boundry;
	obstacle=near_human;
=======
	cout << "comm..." << endl;
	robot_is_crossing.write(near_boundary.read());
	// grid_num = envir.getGridNumber(0);
	if (near_boundary)
		envir.moveRobotToNextGrid(0);
>>>>>>> origin/jeff
	return;
}
