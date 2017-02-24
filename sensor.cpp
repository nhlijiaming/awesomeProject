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
		b = envir.getGridNumber(s);
		if (s->direction = 0) {
			if (abs(s->location[1] - gridMap[b][2]) < 4 * robsp) boundary = 1;
		}
		else if (s->direction = 1) {
			if (abs(s->location[1] - gridMap[b][4]) < 4 * robsp) boundary = 1;
		}
		else if (s->direction = 2) {
			if (abs(s->location[1] - gridMap[b][1]) < 4 * robsp) boundary = 1;
		}
		else {
			if (abs(s->location[1] - gridMap[b][3]) < 4 * robsp) boundary = 1;
		}

	}


}



