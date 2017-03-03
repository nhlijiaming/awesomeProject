#include "systemc.h"
#include "server.h"

void server::assignment(){

	struct motionData robot ;
	struct motionData *coordinate;
	bool boundary = robot_is_crossing;
	int nextGrid ;
	//int d = robot.direction,i;
	int next_grid;
	int i;
	bool reached=false;
	bool stop = false;
	bool occupied = false;
	int gridnum[numberOfRobots];
/*	if (robot.location[0] >= 6.5 && robot.location[1] == -0.5){
		d = 1;
		direction = d;
	}
	*/
	if (envir.getGridNumber(&robot) == 10)
	{
		reached = true;

	}



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
			cout << "boundary: " << boundary << endl;
			nextGrid = envir.getRobotNextGridNumber(i);

			cout << "nextGrid: " << nextGrid << endl;
			if (nextGrid == gridnum[i]){
				occupied = true;
			}
			else occupied = false;

			cout << "occupied: " << occupied << endl;
		}
	}
		if (occupied || reached )
		{
			velocity = 0;
		}
		else {
			velocity = 1;

			cout << "velocity: " << velocity << endl;
			envir.moveRobotToNextGrid(0);
		}
	
	/*velocity control*/
 

	velocity = 1.0;
} 
