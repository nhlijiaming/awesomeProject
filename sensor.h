#include "systemc.h"
#include "environment.h"

extern environment envir;


/*The modole Senor includes:
1:the robots and humans position
2:real map(grids ID and position)
4:distance between each robot and obstacle & stop and resume command*/

SC_MODULE(sensor){
	sc_in <bool> clock;
	sc_out <bool> obstacle,boundary;
	int (*gridMap)[9];

	sc_out <bool> obstacle;
	sc_out <bool> robot_is_crossing;
	sc_out <int> direction;

	void dosens();
	SC_CTOR(sensor){
		SC_METHOD(dosens);
		gridMap = envir.getMap();
		sensitive << clock.pos();
		dont_initialize();
	}
};
