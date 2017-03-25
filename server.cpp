#include "systemc.h"
#include "server.h"

void server::assignment(){
	int i, j, k;
	double v[numberOfRobots];
	double distanceToMeetingPoint, distanceToLeaveMeetingPoint;
	bool changed, printout;

	printout = false;
	for(i = 0; i < numberOfRobots ; i ++)
		v[i] = 1.0;

	for(i = 0 ; i < numberOfRobots ; i ++)
	{
		changed = false;
		for(j = envir.path_pointer[i]-1 ; j <= envir.path[i][0] ; j ++)
		{
			if (envir.isMeetingPoint(envir.path[i][j]))
			{
				for(k = i + 1 ; k < numberOfRobots ; k ++)
				if (i != k)
				{
					distanceToMeetingPoint = envir.distanceToGrid(k, envir.path[i][j]);
					if (distanceToMeetingPoint < 99999)
					{
						distanceToLeaveMeetingPoint = envir.distanceToGrid(i, envir.path[i][j+1]);
						if (distanceToLeaveMeetingPoint > distanceToMeetingPoint && distanceToMeetingPoint > 0.01)
						{
							changed = true;
							printout = true;
							cout << "meetingpoint: " << envir.path[i][j] << endl;
							v[i] = distanceToLeaveMeetingPoint / (distanceToMeetingPoint / v[k]); // assume that the kth-Robot is move at 1.0m/s
							if (v[i] > 2.0 && distanceToLeaveMeetingPoint > 0.01) //even ith-Robot speed up as it can, it still not fast enough. Needs to slow down kth-Robot
							{
								v[i] = 2.0;
								v[k] = distanceToMeetingPoint / (distanceToLeaveMeetingPoint / 2.0);
							} 
							cout << "distanceToLeaveMeetingPoint: " << distanceToLeaveMeetingPoint << " distanceToMeetingPoint:" << distanceToMeetingPoint << endl;
							cout << "velocity: " << v[0] << " " << v[1] << endl;
						}
					}
				}
			}
			if (changed)
				break;
		}
	}
	// cout << " ---------- " << endl;

	if (printout)
	{
		cout <<"velocity: ";
		for (i = 0; i < numberOfRobots; i++)
			cout << v[i] << " ";
		cout << endl;
	}

	for (i = 0; i < numberOfRobots; i++)
		velocity[i] = (float)v[i];
	
} 

