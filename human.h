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

	void assignment();
	SC_CTOR(human){
		SC_METHOD(assignment);
		sensitive << clock.pos();
	}
};
#endif
