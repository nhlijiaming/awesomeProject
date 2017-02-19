#include "systemc.h"

/*
Functions:
1.
2.
3.
4.
*/

SC_MODULE(robot){
	sc_in_clk clock;

	int v;
	void assignment();
	SC_CTOR(robot){
		SC_METHOD(assignment);
		sensitive << clock.pos();
	}
};