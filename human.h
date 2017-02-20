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
	float x_human0, y_human0, x_human1, y_human1; //human1,2's location
	int n,m;//for human lacation calculation
	float humsp0, humsp1;

	void assignment();
	SC_CTOR(human){
		x_human0=6.5;
		y_human0 = -0.5;
		x_human1=6.5;
		y_human1=-3.5;
		humsp0 = 0.5;
		humsp1 = 1.5;
		SC_METHOD(assignment);
		sensitive << clock.pos();
		dont_initialize();
	}
};
#endif
