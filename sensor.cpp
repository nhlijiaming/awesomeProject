#include "systemc.h"
#include "sensor.h"
#include "environment.h"


void sensor::dosens(){
	struct motionData *s, *r;
	extern environment envir;
	float distance;
	int i, n;


	/*human detection*/
	n = envir.getNumberOfHumans();
	r = envir.getRobotLocation(0);
	for (i = 0; i < envir.getNumberOfHumans(); i++){
		s = envir.getHumanLocation(i);
		distance = sqrt((r->location[0] - s->location[0]) * (r->location[0] - s->location[0]) + (r->location[1] - s->location[1]) * (r->location[1] - s->location[1]));
		if (distance < 0.5) obstacle = 1;
		else obstacle = 0;
	}

	xcenterOfThisGrid = 0;
}



