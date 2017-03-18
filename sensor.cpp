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

	/*human detection*/	/*boundary detection*/
	n = envir.getNumberOfHumans();
	r = envir.getRobotLocation(0);
	x = r->location[0];
	y = r->location[1];
	for (i = 0; i < envir.getNumberOfHumans(); i++){
		s = envir.getHumanLocation(i);
		l1 = sqrt((x - s->location[0]) * (x - s->location[0]) + (y - s->location[1]) * (y - s->location[1]));
		if (l1 < 0.5) obstacle = 1;
		else obstacle = 0;
	}
	b = envir.getGridNumber(r);
	// cout << "(" << x << "," << y << ")" << " distance = " << y - gridMap[b][4] << endl;
	robot_is_crossing = false;
	if (r->direction == 0) {
		if (((gridMap[b][2] - y) > 0) && ((gridMap[b][2] - y) < (float)2 * period * robsp)) robot_is_crossing = true;
	}
	else if (r->direction == 1) {
		if (((y - gridMap[b][4]) > 0) && ((y - gridMap[b][4]) < (float)2 * period * robsp)) robot_is_crossing = true;
	}
	else if (r->direction == 2) {
		if (((x - gridMap[b][1]) > 0) && ((x - gridMap[b][1]) < (float)2 * period * robsp)) robot_is_crossing = true;
	}
	else if (((gridMap[b][3] - x) > 0) && ((gridMap[b][3] - x) < (float)2 * period * robsp)) robot_is_crossing = true;

			


	gridNumber = envir.getGridNumber(r);
	thisGrid = envir.getGrid(gridNumber);
	centerx = ((float)thisGrid[1] + (float)thisGrid[3]) / 2;
	centery = ((float)thisGrid[2] + (float)thisGrid[4]) / 2;



	if ((x-centerx) * (x-centerx) + (y-centery) * (y-centery) <= 0.002)
	{
		// should turn and ready to move to next objective grid
		nextGridNumber = envir.getRobotNextGridNumber(0);
		//cout << "should turn now:   " << gridNumber << " === (" << centerx << "," << centery << ") ==== (" << x << "," << y << ")" << endl;
		//cout << thisGrid[5] << " " << thisGrid[6] << " " << thisGrid[7] << " " << thisGrid[8] << " " << nextGridNumber << endl;
		if (thisGrid[5] == nextGridNumber) // facing west side
			direction = 2;
		else if (thisGrid[6] == nextGridNumber) // facing east side
			direction = 3;
		else if (thisGrid[7] == nextGridNumber) // facing north side
			direction = 0;
		else if (thisGrid[8] == nextGridNumber) // facing south side
			direction = 1;
		else cout << "**************************   ERR: grid " << gridNumber << " has no neighbor "<< nextGridNumber <<".  ***************************" << endl;
	}

}



