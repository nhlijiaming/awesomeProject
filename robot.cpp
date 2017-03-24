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

void robot::comm0() {
	robot_is_crossing[0].write(near_boundary[0].read());
	if (!near_boundary[0])
		{
			envir.moveRobotToNextGrid(0);
			cout << "Robot "<< 0 << " crossed boundary."<<near_boundary[0]<<endl;
		}
	return;
}

void robot::comm1() {
	robot_is_crossing[1].write(near_boundary[1].read());
	if (!near_boundary[1])
		{
			envir.moveRobotToNextGrid(1);
			cout << "Robot "<< 1 << " crossed boundary. Next boundary: " << envir.getRobotNextGridNumber(1) << endl;
		}
	return;
}

