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
/*	if (robot.location[0] >= 6.5 && robot.location[1] == -0.5){
		d = 1;
		direction = d;
	}
*/


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
			cout << "nextGrid: " << nextGrid << endl;

			for (i = 0; i < numberOfRobots; i++)
			{
				if (nextGrid == gridnum[i]){
					occupied = true;
					cout << "occupied: " << occupied << endl;
				}
				else occupied = false;
			}
		}
	}
		if (occupied)
		{
			velocity = 0.0;
			cout << "velocity: " << velocity << endl;
		}
		else {
			velocity = 1.0;
			cout << "velocity: " << velocity << endl;
			// envir.moveRobotToNextGrid(0);
		}
	
	/*velocity control*/
 	// velocity = 1.0;
} 

