#include "systemc.h"
#include "robot.h"
#include "sensor.h"
#include "server.h"
#include "human.h"
#include "environment.h"

environment envir;

int sc_main(int, char **)
{
	struct motionData r0, r1, h0, h1;
	sc_signal<bool> robot_clock, sensor_clock, human_clock;
	sc_signal<bool> obstacle[numberOfRobots];
	sc_signal<float> velocity[numberOfRobots];
	sc_signal<int> direction[numberOfRobots];
	sc_signal<bool> near_boundary[numberOfRobots];
	sc_signal<bool> robot_is_crossing[numberOfRobots];
	FILE *stream;

	float time;
	int i;

	server hq("SERVER");
	for(i = 0; i < numberOfRobots ; i ++)
	{
		hq.robot_is_crossing[i](robot_is_crossing[i]);
		hq.velocity[i](velocity[i]);
	}

	robot robot0("ROBOT0");
	robot0.clock(robot_clock);
	for(i = 0; i < numberOfRobots ; i ++)
	{
		robot0.direction[i](direction[i]);
		robot0.velocity[i](velocity[i]);
		robot0.near_boundary[i](near_boundary[i]);
		robot0.obstacle[i](obstacle[i]);	
		robot0.robot_is_crossing[i](robot_is_crossing[i]);
	}

	sensor sensor0("SENSOR0");
	sensor0.clock(sensor_clock);
	for(i = 0; i < numberOfRobots ; i ++)
	{
		sensor0.obstacle[i](obstacle[i]);
		sensor0.robot_is_crossing[i](near_boundary[i]);
		sensor0.direction[i](direction[i]);
	}


	human human0("HUMAN0");
	human0.clock(human_clock);

	sc_trace_file *wf = sc_create_vcd_trace_file("wave");
	sc_trace(wf, time, "time");
	sc_trace(wf, robot_clock, "robot_clock");

	sc_trace(wf, r0, "robot0");
	sc_trace(wf, r1, "robot1");
	sc_trace(wf, h0, "human0");
	sc_trace(wf, h1, "human1");
	// for(i = 0; i < numberOfRobots ; i ++)
	// {
	i=0;
		sc_trace(wf, obstacle[i], "obstacle");
		sc_trace(wf, velocity[i], "velocity");
		sc_trace(wf, direction[i], "direction");
		sc_trace(wf, near_boundary[i], "near_boundary");
		sc_trace(wf, robot_is_crossing[i], "robot_is_crossing");

	// }

	sc_trace(wf, envir.path[0][envir.path_pointer[0]], "path");

	// s.direction = 0;
	// s.location[0] = 6.5;
	// s.location[1] = -1.1;
	// envir.setRobotLocation(0, &s);


	//cout << "boundary" << boundary << endl;


	stream = fopen( "stream.dat", "w" );
	for(int i = 0; i <= 100*20; i++)

	{
		time = envir.getTime();
		h0 = *(envir.getHumanLocation(0));
		h1 = *(envir.getHumanLocation(1));
		r0 = *(envir.getRobotLocation(0));
		r1 = *(envir.getRobotLocation(1));
		if (i%20 == 0)
		{
			cout << "@" << (int)envir.getTime() << "s  Robot0:("<<r0.location[0] << ", " << r0.location[1] << ") on grid "<< envir.getGridNumber(&r0) << endl;
			cout << "     Robot1:("<<r1.location[0] << ", " << r1.location[1] << ") on grid "<< envir.getGridNumber(&r1) << endl;
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

		fprintf(stream, "%.2f,%.2f,%.2f,%.2f,%.2f", time, r0.location[0], r0.location[1], r1.location[0], r1.location[1]);
		fprintf(stream, ",%.2f,%.2f,%.2f,%.2f \n", h0.location[0], h0.location[1], h1.location[0], h1.location[1]);

		envir.timeIncrement();
	}
	fclose(stream);
	sc_close_vcd_trace_file(wf);
	system("pause");
	return 0;
}

