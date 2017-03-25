#include "systemc.h"
#include "human.h"
#include "environment.h"

void human::assignment(){
	/*human moving*/

	struct motionData a, b, c, d;
	extern environment envir;
	//human 0 
	if (y_human0 == 3  && x_human0 < 66) {
		x_human0 = x_human0 + humsp0 / 20;
	}
	else if (y_human0 < 49 && x_human0 == 66) {
		y_human0 = y_human0 + humsp0 / 20;
	}
	else if (x_human0 > 4 && y_human0 == 49) {
		x_human0 = x_human0 - humsp0 / 20;
	}
	else if (y_human0 >= 3 && x_human0 ==4 ) {
		y_human0 = y_human0 - humsp0 / 20;
	}
	//human 1 
	if (x_human1 == 66 && y_human1<24) {
		y_human1 = y_human1 + humsp1 / 20;
	}
	else if (x_human1 > 20 && y_human1==24 ) {
		x_human1 = x_human1 - humsp1 / 20;
	}
	else if (y_human1 > 3 && x_human1==20 ) {
		y_human1 = y_human1 - humsp1 / 20;
	}
	else if (x_human1 < 66.0  && y_human1 == 3){
		x_human1 = x_human1 + humsp1 / 20;
	}

	//human 2 
	if (y_human2 == 36 && x_human2 > 39) {
		x_human2 = x_human2 - humsp2 / 20;
	}
	else if (y_human2 > 24 && x_human2 == 39) {
		y_human2 = y_human2 - humsp2 / 20;
	}
	else if (x_human2 < 66 && y_human2 == 24) {
		x_human2 = x_human2 + humsp2 / 20;
	}
	else if (y_human2 <= 36 && x_human2 == 66) {
		y_human2 = y_human2 + humsp2 / 20;
	}

	//human 3 
	if (x_human3 == 4 && y_human3 > 36) {
		y_human3 = y_human3 - humsp3 / 20;
	}
	else if (x_human3 < 66 && y_human3 == 36) {
		x_human3 = x_human3 + humsp3 / 20;
	}
	else if (y_human3 < 49 && x_human3 == 66) {
		y_human3 = y_human3 + humsp3 / 20;
	}
	else if (x_human3 > 4 && y_human3 == 49){
		x_human3 = x_human3 - humsp3 / 20;
	}


	a.location[0] = x_human0;
	a.location[1] = y_human0;
	b.location[0] = x_human1;
	b.location[1] = y_human1;
	c.location[0] = x_human2;
	c.location[1] = y_human2;
	d.location[0] = x_human3;
	d.location[1] = y_human3;

	envir.setHumanLocation(0, &a);
	envir.setHumanLocation(1, &b);
	envir.setHumanLocation(2, &c);
	envir.setHumanLocation(3, &d);
}


