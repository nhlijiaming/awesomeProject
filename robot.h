#include "systemc.h"

/*
Functions:
1.
2.
3.
4.
*/

SC_MODULE(robot){
	sc_in_clk clock;
	//sc_in<int> direction;
	sc_in<int> velocity;
	float v;
	int n;

	void assignment();
	SC_CTOR(robot){
		v = 1.0; // velocity of the robot
		SC_METHOD(assignment);
		sensitive << clock.pos();
		dont_initilization();
	}
};