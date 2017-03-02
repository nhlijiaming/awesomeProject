#ifndef __ROBOT_H
#define __ROBOT_H
#include "systemc.h"
#include "environment.h"

extern environment envir;

SC_MODULE(robot){
	sc_in_clk clock;
	sc_in<int> direction;
	sc_in<float> velocity;

	sc_in<bool> near_boundary;
	sc_in<bool> obstacle;
	sc_out<bool> robot_is_crossing;

	void motor();
	void comm();
	SC_CTOR(robot){
		SC_METHOD(motor);
		sensitive << clock.pos();
		SC_METHOD(comm);
		sensitive << near_boundary.pos();
		sensitive << near_boundary.neg();
		dont_initialize();
	}
};

#endif
