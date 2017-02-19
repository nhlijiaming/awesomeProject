#ifndef __ROBOT_H
#define __ROBOT_H
#include "systemc.h"
#include "environment.h"

extern environment envir;

SC_MODULE(robot){
	sc_in_clk clock;
	sc_in<int> direction;
	sc_in<float> velocity;
	sc_in<int> serialNumber;
	float v;
	int n;

	void assignment();
	SC_CTOR(robot){
		v = 1.0; // velocity of the robot
		SC_METHOD(assignment);
		sensitive << clock.pos();
		dont_initialize();
	}
};

#endif
