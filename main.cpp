#include "systemc.h"
#include "robot.h"
#include "sensor.h"
#include "server.h"
#include "human.h"
#include "environment.h"

environment envir;
int sc_main(int, char **)
{
	struct motionData *temp;
	struct motionData h0, h1;
	sc_signal<bool> server_clock, robot_clock, sensor_clock, human_clock;
	sc_signal<motionData> r0;
	sc_signal<bool> obstacle;
	sc_signal<bool> stop;
	sc_signal<int> serialNumber;
	sc_signal<int> direction;
	float time;

	server hq("SERVER");
	hq.location(r0);
	hq.obstacle(obstacle);
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

	sc_trace_file *wf = sc_create_vcd_trace_file("wave");
	sc_trace(wf, time, "time");
	sc_trace(wf, server_clock, "server_clock");
	sc_trace(wf, robot_clock, "robot_clock");
	sc_trace(wf, sensor_clock, "sensor_clock");
	sc_trace(wf, human_clock, "human_clock");
	sc_trace(wf, r0, "robot0");
	sc_trace(wf, h0, "human0");
	sc_trace(wf, h1, "human1");
	sc_trace(wf, obstacle, "obstacle");
	sc_trace(wf, stop, "stop");
	sc_trace(wf, direction, "direction");

	for(int i = 0; i <= 20*20; i++)
	{
		time = envir.getTime();
		temp = envir.getRobotLocation(0);
		h0 = *(envir.getHumanLocation(0));
		h1 = *(envir.getHumanLocation(1));

		r0 = *temp;
		if (i%20 == 0)
		{
			cout << "@" << envir.getTime() << "s  Robot0:("<<temp->location[0] << ", " << temp->location[1] << ") on grid "<< envir.getGridNumber(temp) << endl;

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

		envir.timeIncrement();
	}
	sc_close_vcd_trace_file(wf);
	 system("pause");
	return 0;
}

