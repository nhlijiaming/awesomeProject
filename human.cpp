#include "systemc.h"
#include "human.h"
#include "environment.h"

void human::assignment(){
	/*human moving*/

	struct motionData a, b;
	extern environment envir;

	//human 0 
	if (y_human0 == 3  && x_human0 < 66) {
		x_human0 = x_human0 + humsp0 / 20;
		//cout << "human0_x£º" << x_human0 << "   human0_y£º" << y_human0 << endl;
	}
	else if (y_human0 < 49 && x_human0 == 66) {
		y_human0 = y_human0 + humsp0 / 20;
		//cout << "human0_x£º" << x_human0 << "   human0_y£º" << y_human0 << endl;
	}
	else if (x_human0 > 4 && y_human0 == 49) {
		x_human0 = x_human0 - humsp0 / 20;
		//cout << "human0_x£º" << x_human0 << "   human0_y£º" << y_human0 << endl;
	}
	else if (y_human0 >= 3 && x_human0 ==4 ) {
		y_human0 = y_human0 - humsp0 / 20;
		//cout << "-----------human0_is in the last section------------" << endl;
	}
	if (y_human0 == 3 && x_human0 == 66) cout << "human0 is in grid 4 --" << y_human0 << endl;
	if (y_human0 == 49 && x_human0 == 66) cout << "human0 is in grid 47----" << y_human0 << endl;
	if (y_human0 == 49 && x_human0 == 4) cout << "human0 is in grid 41----" << y_human0 << endl;
	if (y_human0 == 3 && x_human0 == 4) cout << "human0 is in grid 0----" << y_human0 << endl;
	
	//human 1 
	if (x_human1 == 66 && y_human1<24) {
		y_human1 = y_human1 + humsp1 / 20;
		//cout << "human1_x£º" << x_human1 << "  human1_y£º" << y_human1 << endl;
	}
	else if (x_human1 > 20 && y_human1==24 ) {
		x_human1 = x_human1 - humsp1 / 20;
		//cout << "human1_x£º" << x_human1 << "  human1_y£º" << y_human1 << endl;
	}
	else if (y_human1 > 3 && x_human1==20 ) {
		y_human1 = y_human1 - humsp1 / 20;
		//cout << "human1_x£º" << x_human1 << "  human1_y£º" << y_human1 << endl;
	}
	else if (x_human1 < 66.0  && y_human1 == 3){
		x_human1 = x_human1 + humsp1 / 20;
		//cout << "x_human1:" << x_human1 << "      y_human1:" << y_human1 << endl;
	}

	if (y_human1 == 3 && x_human1 == 66) cout << "human1 is in grid 4@@@@@" << y_human0 << endl;
	if (y_human1 == 24 && x_human1 == 66) cout << "human1 is in grid 24@@@@@" << y_human0 << endl;
	if (y_human1 == 24 && x_human1 == 20) cout << "human1 is in grid 18@@@@@" << y_human0 << endl;
	if (y_human1 == 3.0 && x_human1 == 20.0) cout << "human1 is in grid 2@@@@@" << y_human0 << endl;

	a.location[0] = x_human0;
	a.location[1] = y_human0;
	b.location[0] = x_human1;
	b.location[1] = y_human1;
	envir.setHumanLocation(0, &a);
	envir.setHumanLocation(1, &b);
}


