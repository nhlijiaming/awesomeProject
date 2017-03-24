#include "systemc.h"
#include "server.h"

void server::assignment(){
	struct motionData *coordinate;
	int nextGrid[numberOfRobots];
	//int d = robot.direction,i;
	int i, j, n , l;
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
	
			for (n = 0; n < numberOfRobots; n++){
				if (i != n){
					if (nextGrid[i] == nextGrid[n] || nextGrid[i] == gridnum[n]) {
						cout << "Robot" << i << " & Robot " << n << " will be in the same grid" << endl;
						occupied[i] = true;
						cout << "Robot " << i << " will stop " << endl;
						cout << "occupied" << i << "==" << occupied[i] << endl;
					}
					else occupied[i] = false;
				}
			}
		}
	}
	cout << "occupied: ";
	for (j = 0; j < numberOfRobots; j++)
		cout <<  occupied[j] << " " ;
	cout << endl <<"velocity: ";
	for (l = 0; l < numberOfRobots; l++)
	{
		if (occupied[l])
		{
			velocity[l] = 0.0;
			cout << velocity[l] << " ";
		}
		else {
			velocity[l] = 1.0;
			cout << velocity[l] << " ";
		}
	}
	cout << endl;
	
} 

