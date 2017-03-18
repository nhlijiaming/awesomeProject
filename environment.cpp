#include "systemc.h"
#include "environment.h"

// Constructor
environment::environment(void)
{
	/*Grid Map*/
	// gridMap[][0] number, starting from 1
	// gridMap[][1] x of up-left conner coordinate
	// gridMap[][2] y of up-left conner coordinate
	// gridMap[][3] x of down-right conner coordinate
	// gridMap[][4] y of down-right conner coordinate
	// gridMap[][5] grid number of the left side
	// gridMap[][6] grid number of the right side
	// gridMap[][7] grid number of the above
	// gridMap[][8] grid number of the below

	gridMap[0][0] = 0;
	gridMap[0][1] = 0;
	gridMap[0][2] = 0;
	gridMap[0][3] = 1;
	gridMap[0][4] = -1;
	gridMap[0][5] = 0;
	gridMap[0][6] = 1;
	gridMap[0][7] = 0;
	gridMap[0][8] = 0;
	gridMap[1][0] = 1;
	gridMap[1][1] = 1;
	gridMap[1][2] = 0;
	gridMap[1][3] = 2;
	gridMap[1][4] = -1;
	gridMap[1][5] = 0;
	gridMap[1][6] = 2;
	gridMap[1][7] = 0;
	gridMap[1][8] = 0;
	gridMap[2][0] = 2;
	gridMap[2][1] = 2;
	gridMap[2][2] = 0;
	gridMap[2][3] = 3;
	gridMap[2][4] = -1;
	gridMap[2][5] = 1;
	gridMap[2][6] = 3;
	gridMap[2][7] = 0;
	gridMap[2][8] = 0;
	gridMap[3][0] = 3;
	gridMap[3][1] = 3;
	gridMap[3][2] = 0;
	gridMap[3][3] = 4;
	gridMap[3][4] = -1;
	gridMap[3][5] = 2;
	gridMap[3][6] = 4;
	gridMap[3][7] = 0;
	gridMap[3][8] = 0;
	gridMap[4][0] = 4;
	gridMap[4][1] = 4;
	gridMap[4][2] = 0;
	gridMap[4][3] = 5;
	gridMap[4][4] = -1;
	gridMap[4][5] = 3;
	gridMap[4][6] = 5;
	gridMap[4][7] = 0;
	gridMap[4][8] = 0;
	gridMap[5][0] = 5;
	gridMap[5][1] = 5;
	gridMap[5][2] = 0;
	gridMap[5][3] = 6;
	gridMap[5][4] = -1;
	gridMap[5][5] = 4;
	gridMap[5][6] = 6;
	gridMap[5][7] = 0;
	gridMap[5][8] = 0;
	gridMap[6][0] = 6;
	gridMap[6][1] = 6;
	gridMap[6][2] = 0;
	gridMap[6][3] = 7;
	gridMap[6][4] = -1;
	gridMap[6][5] = 5;
	gridMap[6][6] = 0;
	gridMap[6][7] = 0;
	gridMap[6][8] = 7;
	gridMap[7][0] = 7;
	gridMap[7][1] = 6;
	gridMap[7][2] = -1;
	gridMap[7][3] = 7;
	gridMap[7][4] = -2;
	gridMap[7][5] = 0;
	gridMap[7][6] = 0;
	gridMap[7][7] = 6;
	gridMap[7][8] = 8;
	gridMap[8][0] = 8;
	gridMap[8][1] = 6;
	gridMap[8][2] = -2;
	gridMap[8][3] = 7;
	gridMap[8][4] = -3;
	gridMap[8][5] = 0;
	gridMap[8][6] = 0;
	gridMap[8][7] = 7;
	gridMap[8][8] = 9;
	gridMap[9][0] = 9;
	gridMap[9][1] = 9;
	gridMap[9][2] = -3;
	gridMap[9][3] = 7;
	gridMap[9][4] = -4;
	gridMap[9][5] = 0;
	gridMap[9][6] = 0;
	gridMap[9][7] = 8;
	gridMap[9][8] = 0;



	/*gridMap[][0] = 1;
	gridMap[][1] = 0;
	gridMap[][2] = 0;
	gridMap[][3] = 1;
	gridMap[][4] = -1;
	gridMap[][5] = 0;
	gridMap[][6] = 2;
	gridMap[][7] = 0;
	gridMap[][8] = 0;
	*/

	time = 0.0;

	human[0].direction = 0;
	human[0].location[0] = 6.5;
	human[0].location[1] = -0.5;

	human[1].direction = 0;
	human[1].location[0] = 6.5;
	human[1].location[1] = -3.5;

	robot[0].direction = 3;
	robot[0].location[0] = 0.5;
	robot[0].location[1] = -0.5;

	// robot[1].direction = 3;
	// robot[1].location[0] = 5.5;
	// robot[1].location[1] = -0.5;

	// robot[1].location[0] = 0.5;
	// robot[1].location[1] = -0.5;

	path_pointer[0] = 2;
	path[0][0] = 10;
	path[0][1] = 0;
	path[0][2] = 1;
	path[0][3] = 2;
	path[0][4] = 3;
	path[0][5] = 4;
	path[0][6] = 5;
	path[0][7] = 6;
	path[0][8] = 7;
	path[0][9] = 8;
	path[0][10] = 9;
}

int (*environment::getMap(void))[9]{
	return gridMap;
}

int *environment::getGrid(int gridNumber)
{
	return gridMap[gridNumber];
}

int environment::getNumberOfHumans(void)
{
	return numberOfHumans;
}

int environment::getNumberOfRobots(void)
{
	return numberOfRobots;
}

struct motionData* environment::getHumanLocation(int n)
{
	return &human[n];
}

void environment::setHumanLocation(int n, struct motionData* motionData)
{
	human[n].direction = motionData->direction;
	human[n].location[0] = motionData->location[0];
	human[n].location[1] = motionData->location[1];
	return;
}

struct motionData* environment::getRobotLocation(int n)
{
	return &robot[n];
}

void environment::setRobotLocation(int n, struct motionData* motionData)
{
	robot[n].direction = motionData->direction;
	robot[n].location[0] = motionData->location[0];
	robot[n].location[1] = motionData->location[1];
	return;
}

void environment::move(struct motionData* object, float deltaDistance)
{
	int direction = object->direction;

	if (direction == 0) // go north
	{
		object->location[1] += deltaDistance;
	}
	else if (direction == 1) // go south
	{
		object->location[1] -= deltaDistance;
	}
	else if (direction == 2) // go west
	{
		object->location[0] -= deltaDistance;
	}
	else if (direction == 3) // go east
	{
		object->location[0] += deltaDistance;
	}
	return;
}

int environment::getGridNumber(struct motionData* coordinate)
{
	extern environment envir;
	float x, y;
	int i;
	x = coordinate->location[0];
	y = coordinate->location[1];
	for (i = 0; i < 10; i++){
		if (y >= gridMap[0][4]){
			if (x>=gridMap[i][1] && x<gridMap[i][3]) return gridMap[i][0];
		}
		else {
			if (y<gridMap[i][2] && y>=gridMap[i][4]) return gridMap[i][0];
		}
	}
	return 0;
}

void environment::timeIncrement()
{
	time = time + period;
	return;
}

void environment::timeIncrement(float deltaTime)
{
	time = time + deltaTime;
	return;
}

float environment::getTime()
{
	return time;
}

int environment::getRobotNextGridNumber(int robotNumber)
{
	return path[robotNumber][path_pointer[robotNumber]];
}

void environment::moveRobotToNextGrid(int robotNumber)
{
	if (path_pointer[robotNumber] < numberOfGrids)
		path_pointer[robotNumber] ++;
	// cout << "@time " << time << " path= " << path_pointer[robotNumber] <<endl;
	return;
}

bool environment::checkRobotIfArrived(int robotNumber)
{
	if (getGridNumber(&robot[robotNumber]) == path[robotNumber][path[robotNumber][0]])
		return true;
	return false;
}

float environment::distanceToGrid(int robotNumber,int targetGridNumber)
{
	float distance;
	struct motionData *r;
	int gridNumber, nextGridNumber, *thisGrid;
	int direction, currentDirection;
	int pointer, n;
	float centerx, centery;
	// cout <<"==============" << endl;

	r = getRobotLocation(robotNumber);
	gridNumber = getGridNumber(r);
	if (gridNumber == targetGridNumber)
		return 0.0;

	n = 0;
	for(int i = 1; i <= path[robotNumber][0] ; i ++)
		if (path[robotNumber][i] == targetGridNumber)
		{
			n = i;
			break;
		}
	if (n < path_pointer[0])
		return 9999999;	//has passed or will never arrive the targer grid


	pointer = path_pointer[robotNumber];
	nextGridNumber = path[robotNumber][pointer];

	thisGrid = getGrid(gridNumber);
	centerx = ((float)thisGrid[1] + (float)thisGrid[3]) / 2;
	centery = ((float)thisGrid[2] + (float)thisGrid[4]) / 2;
	direction = 0;
	if (thisGrid[5] == nextGridNumber) // facing west side
		direction = 2;
	else if (thisGrid[6] == nextGridNumber) // facing east side
		direction = 3;
	else if (thisGrid[7] == nextGridNumber) // facing north side
		direction = 0;
	else if (thisGrid[8] == nextGridNumber) // facing south side
		direction = 1;
	else cout << "**************************   ERR @ environment::distanceToGrid : grid " << gridNumber << " has no neighbor "<< nextGridNumber <<".  ***************************" << endl;

	distance = 0.0;
	currentDirection = r->direction;
	if (direction == currentDirection)
	{
		if (direction == 0) // going up
			distance += thisGrid[2] - r->location[1];
		else if (direction == 1) // going down
			distance += r->location[1] - thisGrid[4];
		else if (direction == 2) // going left
			distance += r->location[0] - thisGrid[1];
		else if (direction == 3) // going right
			distance += thisGrid[3] - r->location[0];
	}
	else
	{
		distance += sqrt((r->location[0] - centerx) * (r->location[0] - centerx) + (r->location[1] - centery) * (r->location[1] - centery));
		if (direction == 0) // going up
			distance += 0.5 * (thisGrid[2] - r->location[1]);
		else if (direction == 1) // going down
			distance += 0.5 * (r->location[1] - thisGrid[4]);
		else if (direction == 2) // going left
			distance += 0.5 * (r->location[0] - thisGrid[1]);
		else if (direction == 3) // going right
			distance += 0.5 * (thisGrid[3] - r->location[0]);
	}
	currentDirection = direction;

	while (nextGridNumber != targetGridNumber)
	{
		gridNumber = nextGridNumber;
		pointer ++;
		nextGridNumber = path[robotNumber][pointer];
		thisGrid = getGrid(gridNumber);

		// cout << "at grid "<<gridNumber << " -- "<< distance << endl;
		if (thisGrid[5] == nextGridNumber) // facing west side
			direction = 2;
		else if (thisGrid[6] == nextGridNumber) // facing east side
			direction = 3;
		else if (thisGrid[7] == nextGridNumber) // facing north side
			direction = 0;
		else if (thisGrid[8] == nextGridNumber) // facing south side
			direction = 1;
		else cout << "**************************   ERR @ environment::distanceToGrid : grid " << gridNumber << " has no neighbor "<< nextGridNumber <<".  ***************************" << endl;

		if (direction == currentDirection)
		{
			if (direction == 0 || direction == 1) // going up or down
				distance += thisGrid[2] - thisGrid[4];
			else if (direction == 2 || direction == 3) // going left or right
				distance += thisGrid[3] - thisGrid[1];
		}
		else
		{
			distance += 0.5 * (thisGrid[2] - thisGrid[4] + thisGrid[3] - thisGrid[1]);
		}
		currentDirection = direction;
	}
	// cout << "==============" << endl;
	return distance;
}

bool environment::isMeetingPoint(int gridNumber)
{
	return meetingpoint[gridNumber];
}



