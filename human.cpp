#include "systemc.h"
#include "human.h"
#include "environment.h"

void human::assignment(){
	/*human moving*/

	struct motionData a, b;
	extern environment envir;

	if (n  == 0){
		//human 1 "L"
		if (y_human1 < -0.5 ) 	y_human1 = y_human1 + humsp1 / 20;
		else if (x_human1 >  humsp1 / 20)	x_human1 = x_human1 - humsp1 / 20;
		else  n =  1;
	}
	else {
		if (x_human1 < 6.5) 	x_human1 = x_human1 + humsp1 / 20;
		else if (y_human1 > -4 + humsp1/20 )	y_human1 = y_human1 - humsp1 / 20;
		else n = 0;
	}

	//human 0 "--"
	if (m == 0){
		if (x_human0 > humsp0/20 ) x_human0 = x_human0 - humsp0 / 20;
		else m =  1;
	}
	else {
		if (x_human0 < 7 - humsp0 / 20) x_human0 = x_human0 + humsp0 / 20;
		else m = 0;
	}
	a.location[0] = x_human0;
	a.location[1] = y_human0;
	b.location[0] = x_human1;
	b.location[1] = y_human1;
	envir.setHumanLocation(0, &a);
	envir.setHumanLocation(1, &b);
}


