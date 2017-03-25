#include "systemc.h"
#include "server.h"

void server::assignment(){
	struct motionData *coordinate;
	int nextGrid[numberOfRobots];
	//int d = robot.direction,i;
	int i, j;
	bool occupied[numberOfRobots] = {false};
	int gridnum[numberOfRobots];
	

	cout << "gridnum: ";
	for (i = 0; i < numberOfRobots; i++)
	{
		coordinate = envir.getRobotLocation(i);
		gridnum[i] = envir.getGridNumber(coordinate);
		cout << gridnum[i] << " ";
	}
	cout << endl;

	/*occupied detection*/
	for (i = 0; i < numberOfRobots; i++)
	{
		if (robot_is_crossing[i]){
			nextGrid[i] = envir.getRobotNextGridNumber(i);
			cout << "Robot " << i << " is crossing. Next Grid: " << nextGrid[i] << endl;
			for (j = 0; j < numberOfRobots; j++)
			{
				if (i != j)
				{
					if (nextGrid[i] == nextGrid[j] || nextGrid[i] == gridnum[j]) {
						cout << "Robot" << i << " & Robot" << j << " will be in the same grid" << endl;
						occupied[i] = true;
						cout << "Robot" << i << " will stop " << endl;
						cout << "occupied[" << i << "] = " << occupied[i] << endl;
						break;
					}
					else occupied[i] = false;
				}
			}
		}
	}

	cout << "occupied: ";
	for (i = 0; i < numberOfRobots; i++)
		cout <<  occupied[i] << " " ;
	cout << endl <<"velocity: ";
	for (i = 0; i < numberOfRobots; i++)
	{
		if (occupied[i])
		{
			velocity[i] = 0.0;
			cout << velocity[i] << " ";
		}
		else {
			velocity[i] = 1.0;
			cout << velocity[i] << " ";
		}
	}
	cout << endl;
	
} 

