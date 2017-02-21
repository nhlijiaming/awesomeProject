#ifndef __HUMAN_H
#define __HUMAN_H
#include "systemc.h"

/*
Functions:
1.
2.
3.
4.
*/

SC_MODULE(human){
	sc_in <bool> clock;
	float x_human0=6.5, y_human0 = -0.5, x_human1=6.5, y_human1=-3.5; //human1,2's location
	bool n = 0 , m = 0 ;//for human lacation calculation
	float humsp0 = 0.5, humsp1 = 1.5;

	void assignment();
	SC_CTOR(human){
		SC_METHOD(assignment);
		sensitive << clock.pos();
	}
};
#endif
