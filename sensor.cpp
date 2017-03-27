#include "systemc.h"
#include "sensor.h"
#include "environment.h"


void sensor::dosens(){
	struct motionData *s, *r;
	float l1;
	int i, n, b;
	int gridNumber, nextGridNumber, *thisGrid;
	float x, y, centerx, centery;
	
	float robsp = 1;

	for(int robotNumber = 0; robotNumber < envir.getNumberOfRobots() ; robotNumber ++)
	{

		/*human detection*/	/*boundary detection*/
		n = envir.getNumberOfHumans();
		r = envir.getRobotLocation(robotNumber);
		x = r->location[0];
		y = r->location[1];
		for (i = 0; i < envir.getNumberOfHumans(); i++){
			s = envir.getHumanLocation(i);
			l1 = sqrt((x - s->location[0]) * (x - s->location[0]) + (y - s->location[1]) * (y - s->location[1]));
			if (l1 < 0.5)
				obstacle[robotNumber] = 1;
			else
				obstacle[robotNumber] = 0;
		}
		b = envir.getGridNumber(r);
		// cout << "(" << x << "," << y << ")" << " distance = " << y - gridMap[b][4] << endl;
		robot_is_crossing[robotNumber] = false;
		if (r->direction == 0) {
			if (((gridMap[b][2] - y) > 0) && ((gridMap[b][2] - y) < (float)2 * period * robsp)) robot_is_crossing[robotNumber] = true;
		}
		else if (r->direction == 1) {
			if (((y - gridMap[b][4]) > 0) && ((y - gridMap[b][4]) < (float)2 * period * robsp)) robot_is_crossing[robotNumber] = true;
		}
		else if (r->direction == 2) {
			if (((x - gridMap[b][1]) > 0) && ((x - gridMap[b][1]) < (float)2 * period * robsp)) robot_is_crossing[robotNumber] = true;
		}
		else if (((gridMap[b][3] - x) > 0) && ((gridMap[b][3] - x) < (float)2 * period * robsp)) robot_is_crossing[robotNumber] = true;


		gridNumber = envir.getGridNumber(r);
		thisGrid = envir.getGrid(gridNumber);
		centerx = ((float)thisGrid[1] + (float)thisGrid[3]) / 2;
		centery = ((float)thisGrid[2] + (float)thisGrid[4]) / 2;



		if ((x-centerx) * (x-centerx) + (y-centery) * (y-centery) <= 0.013)
		{
			// should turn and ready to move to next objective grid
			nextGridNumber = envir.getRobotNextGridNumber(robotNumber);
			//cout << "should turn now:   " << gridNumber << " === (" << centerx << "," << centery << ") ==== (" << x << "," << y << ")" << endl;
			//cout << thisGrid[5] << " " << thisGrid[6] << " " << thisGrid[7] << " " << thisGrid[8] << " " << nextGridNumber << endl;
			if (thisGrid[5] == nextGridNumber) // facing west side
				direction[robotNumber] = 2;
			else if (thisGrid[6] == nextGridNumber) // facing east side
				direction[robotNumber] = 3;
			else if (thisGrid[7] == nextGridNumber) // facing north side
				direction[robotNumber] = 0;
			else if (thisGrid[8] == nextGridNumber) // facing south side
				direction[robotNumber] = 1;
			else {
				cout << "**************************   ERR: grid " << gridNumber << " has no neighbor "<< nextGridNumber << " for robot " << robotNumber << ".  ***************************" << endl;
				envir.stop = true;
			}
		}
	}

}



