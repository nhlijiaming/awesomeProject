#ifndef __SERVER_H
#define __SERVER_H
#include "systemc.h"
#include "environment.h"

extern environment envir;

SC_MODULE(server){
	sc_in_clk clk;
	sc_in<bool> robot_is_crossing[numberOfRobots];
	sc_out<float> velocity[numberOfRobots];

	void assignment();
	SC_CTOR(server){
		velocity[0].initialize(1.0);
		velocity[1].initialize(1.0);
		velocity[2].initialize(1.0);
		velocity[3].initialize(1.0);
		SC_METHOD(assignment);
		sensitive << clk.pos();
		sensitive << robot_is_crossing[0].pos() << robot_is_crossing[0].neg();
		sensitive << robot_is_crossing[1].pos() << robot_is_crossing[1].neg();
		sensitive << robot_is_crossing[2].pos() << robot_is_crossing[2].neg();
		sensitive << robot_is_crossing[3].pos() << robot_is_crossing[3].neg();

		// dont_initialize();
	}
};
#endif
