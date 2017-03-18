#include "systemc.h"
#include "server.h"

void server::assignment(){
	struct motionData *coordinate;
	int nextGrid;
	//int d = robot.direction,i;
	int i, j;
	bool occupied[numberOfRobots] = {false};
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
		if (robot_is_crossing[i]){
			nextGrid = envir.getRobotNextGridNumber(i);
			cout << "nextGrid: " << nextGrid << endl;

			for (j = 0; j < numberOfRobots; j++)
			{
				if (nextGrid == gridnum[j]){
					occupied[i] = true;
					cout << "occupied: " << occupied[i] << endl;
				}
				else occupied[i] = false;
			}
		}
	}
	
	for (i = 0; i < numberOfRobots; i++)
	{
		if (occupied[i])
		{
			velocity[i] = 0.0;
		}
		else {
			velocity[i] = 1.0;
			cout << "velocity: " << velocity[i] << endl;
		}
	}
	
	/*velocity control*/
 	// for
} 

