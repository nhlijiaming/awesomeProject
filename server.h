#ifndef __SERVER_H
#define __SERVER_H
#include "systemc.h"
#include "environment.h"

extern environment envir;

SC_MODULE(server){

	//sc_in<int> next_grid;
	sc_in<bool> obstacle;
	sc_in<bool> robot_is_crossing;
	sc_out<float> velocity;
	int gridnum[numberOfRobots];


	void assignment();
	SC_CTOR(server){
		velocity.initialize(0.0);
		
		SC_METHOD(assignment);
		sensitive << robot_is_crossing;

		dont_initialize();
	}
};
#endif
