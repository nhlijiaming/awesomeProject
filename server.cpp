#include "systemc.h"
#include "server.h"

void server::assignment(){
	struct motionData robot = location;
	sc_uint<4> obs = obstacle;
	int d = robot.direction;

	if (robot.location[0] >= 6.5 && robot.location[1] == -0.5)
		d = 1;
	direction = d;

	if (obs == 0)
	{
		stop = false;
	}
	else
	{
		stop = true;
	}
} 
