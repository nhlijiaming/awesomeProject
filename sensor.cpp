#include "systemc.h"
#include "sensor.h"
#include "environment.h"


void sensor::dosens(){
	struct motionData *s, *r;
	float l1,l2;
	int i, n, b, direction;
	
	float robsp = 1;

	/*human detection*/	/*boundary detection*/
	n = envir.getNumberOfHumans();
	r = envir.getRobotLocation(0);
	for (i = 0; i < envir.getNumberOfHumans(); i++){
		s = envir.getHumanLocation(i);
		l1 = sqrt((r->location[0] - s->location[0]) * (r->location[0] - s->location[0]) + (r->location[1] - s->location[1]) * (r->location[1] - s->location[1]));
		if (l1 < 0.5) obstacle = 1;
		else obstacle = 0;
		}
	b = envir.getGridNumber(r);
	if (r->direction == 0) {
		if (abs(r->location[1] - gridMap[b - 1][2]) < 2 * period * robsp) boundary = 1;
	}
	else if (r->direction == 1) {
		if (abs(r->location[1] - gridMap[b - 1][4]) < 2 * period * robsp) boundary = 1;
	}
	else if (r->direction == 2) {
		if (abs(r->location[0] - gridMap[b - 1][1]) < 2 * period * robsp) boundary = 1;
	}
	else {
		if (abs(r->location[0] - gridMap[b - 1][3]) < 2 * period * robsp) boundary = 1;
	}

}



