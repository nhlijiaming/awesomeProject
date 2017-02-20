#include "systemc.h"
#include "robot.h"
 #include "sensor.h"
// #include "server.h"
#include "environment.h"

environment envir;
int sc_main(int, char **)
{
	struct motionData a,b,c;
	a.location[0] = 5.4;
	a.location[1] = -0.4;
	b.location[0] = 3;
	b.location[1] = -0.4;
	c.location[0] = 3.2;
	c.location[1] = -0.4;
	envir.setHumanLocation(0, &a);
	envir.setHumanLocation(1, &b);
	envir.setRobotLocation(0, &c);

	sc_signal<bool>   clock;
	sc_signal <bool>	v;

	sensor sensor("sensor");
	sensor.clock(clock);
	sensor.v(v);
	
	sc_start(5, SC_NS);
	cout << v << endl;
	system("pause");
	return 0;
}

