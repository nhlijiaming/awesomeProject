#include "systemc.h"
#include "robot.h"
// #include "sensor.h"
// #include "server.h"
#include "environment.h"

environment envir;
int sc_main(int, char **)
{

	sc_signal<int> direction, serialNumber0, serialNumber1;
	sc_signal<float> velocity0, velocity1;
	sc_signal<bool> clock;

	robot robot0("0");
	robot0.direction(direction);
	robot0.velocity(velocity0);
	robot0.serialNumber(serialNumber0);
	robot0.clock(clock);	

	direction = 3;
	velocity0 = 1.5;
	serialNumber0 = 0;

	for(int i = 0; i < 20 ; i ++)
	{
		clock = 0;
		sc_start(10, SC_NS);
		clock = 1;
		sc_start(10, SC_NS);
	}
	cout << "robot0 location (x,y): (" << (envir.getRobotLocation(0))->location[0] << "," << (envir.getRobotLocation(0))->location[1] << ")" << endl;


	return 0;
}

