#include "systemc.h"

SC_MODULE(robot){
	sc_in_clk clock;
	sc_in<int> direction;
	sc_in<float> velocity;
	sc_in<int> serialNumber;
	float v;
	void assignment();
	SC_CTOR(robot){
		v = 1.0; // velocity of the robot
		SC_METHOD(assignment);
		sensitive << clock.pos();
		dont_initialize();
	}
};
