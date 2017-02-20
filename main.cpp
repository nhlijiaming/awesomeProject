#include "systemc.h"
#include "robot.h"
#include "sensor.h"
#include "server.h"
#include "environment.h"

environment envir;
int sc_main(int, char **)
{
	struct motionData *temp;
	sc_signal<bool> server_clock, robot_clock, sensor_clock;
	sc_signal<motionData> r0;
	sc_signal<bool> obstacle;
	sc_signal<bool> stop;
	sc_signal<int> serialNumber;
	sc_signal<int> direction;

	server hq("SERVER");
	hq.location(r0);
	hq.obstacle(obs);
	hq.clock(server_clock);
	hq.stop(stop);
	hq.direction(direction);

	robot robot0("ROBOT0");
	robot0.direction(direction);
	robot0.stop(stop);
	robot0.serialNumber(serialNumber);
	robot0.clock(robot_clock);
	serialNumber = 0;

	sensor sensor0("SENSOR0");
	sensor0.clock(sensor_clock);
	sensor0.obstacle(obstacle);

	human human0("HUMAN0");
	human0.clock(human_clock);

	for(int i = 0; i <= 10*20; i++)
	{
		temp = envir.getRobotLocation(0);
		r0 = *temp;
		if (i%20 == 0)
		{
			cout << temp->location[0] << ", " << temp->location[1] << endl;
		}

		human_clock = 1;
		sc_start(10, SC_NS);
		human_clock = 0;
		sc_start(10, SC_NS);

		sensor_clock = 1;
		sc_start(10, SC_NS);
		sensor_clock = 0;
		sc_start(10, SC_NS);

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

