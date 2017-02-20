#include "systemc.h"
#include "server.h"

void server::assignment(){
	struct motionData robot = location;
	bool obs = obstacle;
	int d = robot.direction;

	if (robot.location[0] >= 6.5 && robot.location[1] == -0.5)
		d = 1;
	direction = d;

	if (obs)
	{
		stop = true;
	}
	else
	{
		stop = false;
	}
} 
