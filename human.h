#ifndef __HUMAN_H
#define __HUMAN_H
#include "systemc.h"

SC_MODULE(human){
	sc_in <bool> clock;

	float x_human0, y_human0, x_human1, y_human1, x_human2, y_human2, x_human3, y_human3; //human1,2's location
	bool n, m;//for human location calculation
	float humsp0, humsp1, humsp2, humsp3;


	void assignment();
	SC_CTOR(human){
		x_human0= 4 ;
		y_human0 = 3;
		x_human1 = 66;
		y_human1 = 3;
		x_human2 = 66;
		y_human2 = 36;
		x_human3 = 4;
		y_human3 = 49;
		humsp0 = 10;
		humsp1 = 10;
		humsp2 = 10;
		humsp3 = 10;
		n = 0;
		m = 0;
		SC_METHOD(assignment);
		sensitive << clock.pos();
		dont_initialize();
	}
};
#endif
