#include "systemc.h"

/*The modole Senor includes:
1:the robots and humans position
2:real map(grids ID and position)
4:distance between each robot and obstacle & stop and resume command*/

SC_MODULE(sensor){

	sc_in <bool> clock;
	sc_out <bool> v;

	int r, s;
	float obstacle;
	
	void dosens();
	SC_CTOR(sensor){
		SC_METHOD(dosens);
		sensitive << clock.pos();
	}
};