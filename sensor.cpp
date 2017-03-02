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
	if (r->direction == 0) {
		if (abs(y - gridMap[b - 1][2]) < 2 * period * robsp) robot_is_crossing = true;
	}
	else if (r->direction == 1) {
		if (abs(y - gridMap[b - 1][4]) < 2 * period * robsp) robot_is_crossing = true;
	}
	else if (r->direction == 2) {
		if (abs(x - gridMap[b - 1][1]) < 2 * period * robsp) robot_is_crossing = true;
	}
	else if (abs(x - gridMap[b - 1][3]) < 2 * period * robsp) {robot_is_crossing = true; cout << "heading east.... crossing.... " << endl;}
	else
	{
		robot_is_crossing = false;
	}


	gridNumber = envir.getGridNumber(r);
	thisGrid = envir.getGrid(gridNumber-1);
	centerx = ((float)thisGrid[1] + (float)thisGrid[3]) / 2;
	centery = ((float)thisGrid[2] + (float)thisGrid[4]) / 2;

	cout << "at grid:" << gridNumber;
	cout << " distance to boundary: " << abs(x - gridMap[b - 1][3]);
	cout << "   next grid: " << envir.getRobotNextGridNumber(0) << endl;

	// cout << "at grid " << gridNumber << " === " << x << " " << y << " ====== ";
	// cout << thisGrid[1] << " " << thisGrid[2] << " " << thisGrid[3] << " " << thisGrid[4] << " ";
	// cout << thisGrid[5] << " " << thisGrid[6] << " " << thisGrid[7] << " " << thisGrid[8] << endl;


	if ((x-centerx) * (x-centerx) + (y-centery) * (y-centery) <= 0.2)
	{
		// should turn and ready to move to next objective grid
		nextGridNumber = envir.getRobotNextGridNumber(0);

		// cout << thisGrid[5] << " " << thisGrid[6] << " " << thisGrid[7] << " " << thisGrid[8] << " " << nextGridNumber << endl;
		if (thisGrid[5] == nextGridNumber) // facing west side
			direction = 2;
		if (thisGrid[6] == nextGridNumber) // facing east side
			direction = 3;
		if (thisGrid[7] == nextGridNumber) // facing north side
			direction = 0;
		if (thisGrid[8] == nextGridNumber) // facing south side
			direction = 1;
	}

}



