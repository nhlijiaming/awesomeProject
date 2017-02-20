#include "systemc.h"
#include "robot.h"
 #include "human.h"
// #include "server.h"
#include "environment.h"

environment envir;
int sc_main(int, char **)
{
	struct motionData a,b,c;
	//extern environment envir;

	
	sc_signal<bool>   clock;
	human human("HUMAN");
	human.clock(clock);


	clock = 0;
	sc_start(50, SC_MS); 
	clock = 1;
	sc_start(50, SC_MS);



	system("pause");
	return 0;
}

