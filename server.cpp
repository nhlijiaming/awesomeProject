#include "systemc.h"
#include "server.h"

void server::assignment(){
	struct motionData *coordinate;
	bool boundary = robot_is_crossing;
	int nextGrid;
	//int d = robot.direction,i;
	int i;
	bool occupied = false;
	int gridnum[numberOfRobots];

	for (i = 0; i < numberOfRobots; i++)
	{
		coordinate = envir.getRobotLocation(i);
		gridnum[i] = envir.getGridNumber(coordinate);
		cout << "gridnum: " << gridnum[i] << endl;
	}

	/*occupied detection*/
	for (i = 0; i < numberOfRobots; i++)
	{
		if (boundary){
			nextGrid = envir.getRobotNextGridNumber(i);
			if (nextGrid == gridnum[i]){
				occupied = true;
			}
			else occupied = false;
		}
	}
	if (occupied)
	{
		velocity = 0.0;
	}
	else {
		velocity = 1.0;
		cout << "velocity: " << velocity << endl;
	}
	
	/*velocity control*/
 	// for
} 

