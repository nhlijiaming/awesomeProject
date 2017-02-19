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
	sc_in_clk clock;
	float x_human0, y_human0 = -0.5, x_human1, y_human1; //human1,2's location
	int n,m;//for human lacation calculation
	float humsp0 = 0.5, humsp1 = 1.5;

	void assignment();
	SC_CTOR(human){
		SC_METHOD(assignment);
		sensitive << clock.pos();
	}
};
#endif
