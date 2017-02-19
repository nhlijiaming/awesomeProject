#ifndef __SERVER_H
#define __SERVER_H
#include "systemc.h"

SC_MODULE(server){
	sc_in_clk clock;
	sc_in<struct motionData* >
	void assignment();
	SC_CTOR(server){
		SC_METHOD(assignment);
		sensitive << clock.pos();
	}
};
#endif
