#include "systemc.h"
#include "sensor.h"
#include "environment.h"


void sensor::dosens(){
	struct motionData *s, *r;
	extern environment envir;


		/*human detection*/
		r = envir.getRobotLocation(0);
		s = envir.getHuamnLocation(0);
		obstacle = sqrt((r->location[0] - s->location[0]) * (r->location[0] - s->location[0]) + (r->location[1] - s->location[1]) * (r->location[1] - s->location[1]));
		/*obstacle calculation*/
		if (obstacle <= 0.5)	v = 0;
		else v = 1;



			

		

}



