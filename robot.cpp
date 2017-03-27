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

		if (!obstacle[i])
		{
			thisRobot->direction = direction[i].read();
			envir.move(thisRobot, deltaDistance);
			envir.robotSpeed[i] = velocity[i].read();
		}
		else
			envir.robotSpeed[i] = 0.0;
	}


	return;
}

void robot::comm0() {
	robot_is_crossing[0].write(near_boundary[0].read());
	if (!near_boundary[0])
		{
			envir.moveRobotToNextGrid(0);
			cout << "Robot "<< 0 << " crossed boundary. Now on grid: " << envir.getGridNumber(envir.getRobotLocation(0)) << endl;
		}
	return;
}

void robot::comm1() {
	robot_is_crossing[1].write(near_boundary[1].read());
	if (!near_boundary[1])
		{
			envir.moveRobotToNextGrid(1);
			cout << "Robot "<< 1 << " crossed boundary. Now on grid: " << envir.getGridNumber(envir.getRobotLocation(1)) << endl;
		}
	return;
}

void robot::comm2() {
	robot_is_crossing[2].write(near_boundary[2].read());
	if (!near_boundary[2])
	{
		envir.moveRobotToNextGrid(2);
		cout << "Robot " << 2 << " crossed boundary. Now on grid: " << envir.getGridNumber(envir.getRobotLocation(2)) << endl;
	}
	return;
}

void robot::comm3() {
	robot_is_crossing[3].write(near_boundary[3].read());
	if (!near_boundary[3])
	{
		envir.moveRobotToNextGrid(3);
		cout << "Robot " << 3 << " crossed boundary. Now on grid: " << envir.getGridNumber(envir.getRobotLocation(3)) << endl;
	}
	return;
}

