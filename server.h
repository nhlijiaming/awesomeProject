#ifndef __SERVER_H
#define __SERVER_H
#include "systemc.h"
#include "environment.h"

extern environment envir;

SC_MODULE(server){

<<<<<<< HEAD
	sc_in<bool> obstacle;
=======
	// sc_in<int> next_grid;
>>>>>>> origin/jeff
	sc_in<bool> robot_is_crossing;
	sc_out<float> velocity;
	

	void assignment();
	SC_CTOR(server){
		velocity.initialize(1.0);
		SC_METHOD(assignment);
		sensitive << robot_is_crossing;

		dont_initialize();
	}
};
#endif
