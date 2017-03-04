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
	sc_signal<bool> robot_clock, sensor_clock, human_clock;
	sc_signal<motionData> r0;
	sc_signal<bool> obstacle, boundary;
	sc_signal<float> velocity;
	sc_signal<bool> stop;
	sc_signal<int> grid_num;
	sc_signal<int> direction;
	sc_signal<bool> near_boundary;
	sc_signal<bool> robot_is_crossing;

	float time;

	server hq("SERVER");
	hq.robot_is_crossing(robot_is_crossing);
	hq.velocity(velocity);

	robot robot0("ROBOT0");
	robot0.direction(direction);
	robot0.velocity(velocity);
	robot0.near_boundary(near_boundary);
	robot0.obstacle(obstacle);
	robot0.robot_is_crossing(robot_is_crossing);
	robot0.clock(robot_clock);

	sensor sensor0("SENSOR0");
	sensor0.clock(sensor_clock);
	sensor0.obstacle(obstacle);
	sensor0.robot_is_crossing(near_boundary);
	sensor0.direction(direction);


	human human0("HUMAN0");
	human0.clock(human_clock);

	sc_trace_file *wf = sc_create_vcd_trace_file("wave");
	sc_trace(wf, time, "time");
	sc_trace(wf, robot_clock, "robot_clock");
	sc_trace(wf, r0, "robot0");
	// sc_trace(wf, h0, "human0");
	// sc_trace(wf, h1, "human1");
	sc_trace(wf, obstacle, "obstacle");
	sc_trace(wf, velocity, "velocity");
	sc_trace(wf, stop, "stop");
	sc_trace(wf, direction, "direction");
	sc_trace(wf, near_boundary, "near_boundary");
	sc_trace(wf, robot_is_crossing, "robot_is_crossing");
	sc_trace(wf, envir.path_pointer[0], "path");


	// s.direction = 0;
	// s.location[0] = 6.5;
	// s.location[1] = -1.1;
	// envir.setRobotLocation(0, &s);


	//cout << "boundary" << boundary << endl;


	for(int i = 0; i <= 10*20; i++)

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

