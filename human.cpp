#include "systemc.h"
#include "human.h"

void human::assignment(){
	/*human moving*/
	if (n % 2 == 0){
		//human 1 "L"
		if (y_human1 < -0.5) 	y_human1 = y_human1 + humsp1 / 20;
		else if (x_human1 > humsp1/20)	x_human1 = x_human1 + humsp1 / 20;
		else  n = n + 1;
	}
	else {
		if (x_human1 < 6.5) 	x_human1 = x_human1 + humsp1 / 20;
		else if (y_human1 > -4)	y_human1 = y_human1 - humsp1 / 20;
		else n = n + 1;
	}
	//human 0 "--"
	if (m % 2 == 0){
		if (x_human0 > 0) x_human0 = x_human0 - humsp0 / 20;
		else m = m + 1;
	}
	else {
		if (x_human0 < 7) x_human0 = x_human0 + humsp0 / 20;
		else m = m + 1;
	}

}


