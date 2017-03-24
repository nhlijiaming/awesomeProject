#ifndef __ROBOT_H
#define __ROBOT_H
#include "systemc.h"
#include "environment.h"

extern environment envir;

SC_MODULE(robot){
	sc_in_clk clock;
	sc_in<int> direction[numberOfRobots];
	sc_in<float> velocity[numberOfRobots];
	sc_in<bool> near_boundary[numberOfRobots];
	sc_in<bool> obstacle[numberOfRobots];
	sc_out<bool> robot_is_crossing[numberOfRobots];

	void motor();
	void comm0();
	void comm1();

	SC_CTOR(robot){
		SC_METHOD(motor);
		sensitive << clock.pos();
		dont_initialize();
		SC_METHOD(comm0);
		sensitive << near_boundary[0].pos();
		sensitive << near_boundary[0].neg();
		dont_initialize();
		SC_METHOD(comm1);
		sensitive << near_boundary[1].pos();
		sensitive << near_boundary[1].neg();
		dont_initialize();
	}
};

#endif
