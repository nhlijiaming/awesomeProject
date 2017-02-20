#include "systemc.h"
#include "robot.h"
#include "sensor.h"
#include "server.h"
#include "environment.h"

environment envir;
int sc_main(int, char **)
{

	// sc_signal<int> direction, serialNumber0, serialNumber1;
	// sc_signal<float> velocity0, velocity1;
	// sc_signal<bool> clock;

	// robot robot0("0");
	// robot0.direction(direction);
	// robot0.velocity(velocity0);
	// robot0.serialNumber(serialNumber0);
	// robot0.clock(clock);	

	// direction = 3;
	// velocity0 = 1.5;
	// serialNumber0 = 0;

	// for(int i = 0; i < 20 ; i ++)
	// {
	// 	clock = 0;
	// 	sc_start(10, SC_NS);
	// 	clock = 1;
	// 	sc_start(10, SC_NS);
	// }
	// cout << "robot0 location (x,y): (" << (envir.getRobotLocation(0))->location[0] << "," << (envir.getRobotLocation(0))->location[1] << ")" << endl;

	struct motionData *temp;
	sc_signal<bool> server_clock, robot_clock;
	sc_signal<motionData> r0;
	sc_signal<sc_uint<4> > obs;
	sc_signal<bool> stop;
	sc_signal<int> serialNumber;
	sc_signal<int> direction;
	serialNumber = 0;

	server hq("SERVER");
	// temp = envir.getRobotLocation(0);
	// r0 = *temp;
	hq.location(r0);
	hq.obstacle(obs);
	hq.clock(server_clock);
	hq.stop(stop);
	hq.direction(direction);

	robot robot0("ROBOT");
	robot0.direction(direction);
	robot0.stop(stop);
	robot0.serialNumber(serialNumber);
	robot0.clock(robot_clock);

	obs = 0;

	for(int i = 0; i <= 10*20; i++)
	{
		temp = envir.getRobotLocation(0);
		r0 = *temp;
		if (i%20 == 0)
		{
			cout << temp->location[0] << ", " << temp->location[1] << endl;
		}

		server_clock = 1;
		sc_start(10, SC_NS);
		server_clock = 0;
		sc_start(10, SC_NS);

		robot_clock = 1;
		sc_start(10, SC_NS);
		robot_clock = 0;
		sc_start(10, SC_NS);


	}

	system("pause");
	return 0;
}

