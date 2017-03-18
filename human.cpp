#include "systemc.h"
#include "human.h"
#include "environment.h"

void human::assignment(){
	/*human moving*/

	struct motionData a, b;
	extern environment envir;

	//human 0 
	if (y_human0< 3 + humsp0 / 20 && x_human0<66 - humsp0 / 20) {
		x_human0 = x_human0 + humsp0 / 20;
		cout << "human0_x" << x_human0 << "human0_y" << y_human0 << endl;
	}
	else if (y_human0 < 49 - humsp0 / 20) {
		y_human0 = y_human0 + humsp0 / 20;
		cout << "human0_x" << x_human0 << "human0_y" << y_human0 << endl;
	}
	else if (x_human0 > 4 + humsp0 / 20) {
		x_human0 = x_human0 - humsp0 / 20;
		cout << "human0_x" << x_human0 << "human0_y" << y_human0 << endl;
	}
	else  {
		y_human0 = y_human0 - humsp0 / 20;
		cout << "human0_x" << x_human0 << "human0_y" << y_human0 << endl;
	}
	
	//human 1 
	if (x_human1> 66 - humsp1 / 20 && y_human1<24 - humsp1 / 20) {
		y_human1 = y_human1 + humsp1 / 20;
		cout << "human1_x" << x_human1 << "human1_y" << y_human1 << endl;
	}
	else if (x_human1 > 20 + humsp1 / 20) {
		x_human1 = x_human1 - humsp1 / 20;
		cout << "human1_x" << x_human1 << "human1_y" << y_human1 << endl;
	}
	else if (y_human1 > 3 + humsp1 / 20) {
		y_human1 = y_human1 - humsp1 / 20;
		cout << "human1_x" << x_human1 << "human1_y" << y_human1 << endl;
	}
	else {
		x_human1 = x_human1 + humsp1 / 20;
		cout << "human1_x" << x_human1 << "human1_y" << y_human1 << endl;
	}


	a.location[0] = x_human0;
	a.location[1] = y_human0;
	b.location[0] = x_human1;
	b.location[1] = y_human1;
	envir.setHumanLocation(0, &a);
	envir.setHumanLocation(1, &b);
}


