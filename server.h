#include "systemc.h"

/*
Functions:
1.
2.
3.
4.
*/

SC_MODULE(server){
	sc_in_clk clock;
	void assignment();
	SC_CTOR(server){
		SC_METHOD(assignment);
		sensitive << clock.pos();
	}
};
