#ifndef __ROBOT_H
#define __ROBOT_H
#include "systemc.h"
#include "environment.h"

extern environment envir;

SC_MODULE(robot){
	sc_in_clk clock;
	sc_in<int> direction;
	sc_in<bool> stop;
	sc_in<int> serialNumber;
	float velocity;

	void assignment();
	SC_CTOR(robot){
		velocity = 1.0;
		SC_METHOD(assignment);
		sensitive << clock.pos();
		dont_initialize();
	}
};

#endif
