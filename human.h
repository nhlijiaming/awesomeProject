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

	int v;
	void setVelocity(int velocity);
	void assignment();
	SC_CTOR(human){
		SC_METHOD(assignment);
		sensitive << clock.pos();
	}
};
