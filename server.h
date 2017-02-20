#ifndef __SERVER_H
#define __SERVER_H
#include "systemc.h"
#include "environment.h"

SC_MODULE(server){
	sc_in_clk clock;
	sc_in<motionData> location;
	sc_in<bool> obstacle;
	sc_out<bool> stop;
	sc_out<int> direction;

	void assignment();
	SC_CTOR(server){
		stop.initialize(true);
		SC_METHOD(assignment);
		sensitive << clock.pos();
		dont_initialize();
	}
};
#endif
