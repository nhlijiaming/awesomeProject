#include "systemc.h"
#include "server.h"

void server::assignment(){
	struct motionData robot ;
	bool obs = obstacle;
	bool boundary = robot_is_crossing;
	int nextGrid ;
	int d = robot.direction,i;
	int next_grid;
	bool reached=false;
	bool stop = false;
	bool occupied = false;
	/*if (robot.location[0] >= 6.5 && robot.location[1] == -0.5)
		d = 1;
	direction = d;

	if (envir.getGridNumber(&robot) == 10)
	{
		reached = true;
	}
*/
		/*occupied detection*/
for (i = 0; i < numberOfRobots; i++)
{
	if (boundary[i]){
		nextGrid = envir.getRobotNextGridNumber(i);
		if (nextGrid == gridnum[i]){
			occupied = true;
		}
		else occupied = false;
		}
	if (occupied || obs || reached)
	{
		velocity[i] = 0;
	}
}
	/*velocity control*/
	


} 
