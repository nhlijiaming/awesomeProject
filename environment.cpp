#include "systemc.h"
#include "environment.h"

// Constructor
environment::environment(void)
{
	/*Grid Map*/

	// gridMap[][0] number, starting from 0
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
	gridMap[0][2] = 6;
	gridMap[0][3] = 8;
	gridMap[0][4] = 0;
	gridMap[0][5] = -1;
	gridMap[0][6] = 1;
	gridMap[0][7] = 5;
	gridMap[0][8] = -1;
	gridMap[1][0] = 1;
	gridMap[1][1] = 8;
	gridMap[1][2] = 6;
	gridMap[1][3] = 16;
	gridMap[1][4] = 0;
	gridMap[1][5] = 0;
	gridMap[1][6] = 2;
	gridMap[1][7] = -1;
	gridMap[1][8] = -1;
	gridMap[2][0] = 2;
	gridMap[2][1] = 16;
	gridMap[2][2] = 6;
	gridMap[2][3] = 24;
	gridMap[2][4] = 0;
	gridMap[2][5] = 1;
	gridMap[2][6] = 3;
	gridMap[2][7] = 6;
	gridMap[2][8] = -1;
	gridMap[3][0] = 3;
	gridMap[3][1] = 24;
	gridMap[3][2] = 6;
	gridMap[3][3] = 62;
	gridMap[3][4] = 0;
	gridMap[3][5] = 2;
	gridMap[3][6] = 4;
	gridMap[3][7] = -1;
	gridMap[3][8] = -1;
	gridMap[4][0] = 4;
	gridMap[4][1] = 62;
	gridMap[4][2] = 6;
	gridMap[4][3] = 70;
	gridMap[4][4] = 0;
	gridMap[4][5] = 3;
	gridMap[4][6] = -1;
	gridMap[4][7] = 7;
	gridMap[4][8] = -1;
	gridMap[5][0] = 5;
	gridMap[5][1] = 0;
	gridMap[5][2] = 22;
	gridMap[5][3] = 8;
	gridMap[5][4] = 6;
	gridMap[5][5] = -1;
	gridMap[5][6] = -1;
	gridMap[5][7] = 16;
	gridMap[5][8] = 0;
	gridMap[6][0] = 6;
	gridMap[6][1] = 16;
	gridMap[6][2] = 12;
	gridMap[6][3] = 24;
	gridMap[6][4] = 6;
	gridMap[6][5] = -1;
	gridMap[6][6] = -1;
	gridMap[6][7] = 8;
	gridMap[6][8] = 2;
	gridMap[7][0] = 7;
	gridMap[7][1] = 62;
	gridMap[7][2] = 12;
	gridMap[7][3] = 70;
	gridMap[7][4] = 6;
	gridMap[7][5] = -1;
	gridMap[7][6] = -1;
	gridMap[7][7] = 12;
	gridMap[7][8] = 4;
	gridMap[8][0] = 8;
	gridMap[8][1] = 16;
	gridMap[8][2] = 16;
	gridMap[8][3] = 24;
	gridMap[8][4] = 12;
	gridMap[8][5] = -1;
	gridMap[8][6] = 9;
	gridMap[8][7] = 13;
	gridMap[8][8] = 6;
	gridMap[9][0] = 9;
	gridMap[9][1] = 24;
	gridMap[9][2] = 16;
	gridMap[9][3] = 44;
	gridMap[9][4] = 12;
	gridMap[9][5] = 8;
	gridMap[9][6] = 10;
	gridMap[9][7] = -1;
	gridMap[9][8] = -1;
	gridMap[10][0] = 10;
	gridMap[10][1] = 44;
	gridMap[10][2] = 16;
	gridMap[10][3] = 52;
	gridMap[10][4] = 12;
	gridMap[10][5] = 9;
	gridMap[10][6] = 11;
	gridMap[10][7] = 14;
	gridMap[10][8] = -1;
	gridMap[11][0] = 11;
	gridMap[11][1] = 52;
	gridMap[11][2] = 16;
	gridMap[11][3] = 62;
	gridMap[11][4] = 12;
	gridMap[11][5] = 10;
	gridMap[11][6] = 12;
	gridMap[11][7] = -1;
	gridMap[11][8] = -1;
	gridMap[12][0] = 12;
	gridMap[12][1] = 62;
	gridMap[12][2] = 16;
	gridMap[12][3] = 70;
	gridMap[12][4] = 12;
	gridMap[12][5] = 11;
	gridMap[12][6] = -1;
	gridMap[12][7] = 15;
	gridMap[12][8] = 7;
	gridMap[13][0] = 13;
	gridMap[13][1] = 16;
	gridMap[13][2] = 22;
	gridMap[13][3] = 24;
	gridMap[13][4] = 16;
	gridMap[13][5] = -1;
	gridMap[13][6] = -1;
	gridMap[13][7] = 18;
	gridMap[13][8] = 8;
	gridMap[14][0] = 14;
	gridMap[14][1] = 44;
	gridMap[14][2] = 22;
	gridMap[14][3] = 52;
	gridMap[14][4] = 16;
	gridMap[14][5] = -1;
	gridMap[14][6] = -1;
	gridMap[14][7] = 22;
	gridMap[14][8] = 10;
	gridMap[15][0] = 15;
	gridMap[15][1] = 62;
	gridMap[15][2] = 22;
	gridMap[15][3] = 70;
	gridMap[15][4] = 16;
	gridMap[15][5] = -1;
	gridMap[15][6] = -1;
	gridMap[15][7] = 24;
	gridMap[15][8] = 12;
	gridMap[16][0] = 16;
	gridMap[16][1] = 0;
	gridMap[16][2] = 26;
	gridMap[16][3] = 8;
	gridMap[16][4] = 22;
	gridMap[16][5] = -1;
	gridMap[16][6] = 17;
	gridMap[16][7] = 25;
	gridMap[16][8] = 5;
	gridMap[17][0] = 17;
	gridMap[17][1] = 8;
	gridMap[17][2] = 26;
	gridMap[17][3] = 16;
	gridMap[17][4] = 22;
	gridMap[17][5] = 16;
	gridMap[17][6] = 18;
	gridMap[17][7] = -1;
	gridMap[17][8] = -1;
	gridMap[18][0] = 18;
	gridMap[18][1] = 16;
	gridMap[18][2] = 26;
	gridMap[18][3] = 24;
	gridMap[18][4] = 22;
	gridMap[18][5] = 17;
	gridMap[18][6] = 19;
	gridMap[18][7] = -1;
	gridMap[18][8] = 13;
	gridMap[19][0] = 19;
	gridMap[19][1] = 24;
	gridMap[19][2] = 26;
	gridMap[19][3] = 36;
	gridMap[19][4] = 22;
	gridMap[19][5] = 18;
	gridMap[19][6] = 20;
	gridMap[19][7] = -1;
	gridMap[19][8] = -1;
	gridMap[20][0] = 20;
	gridMap[20][1] = 36;
	gridMap[20][2] = 26;
	gridMap[20][3] = 42;
	gridMap[20][4] = 22;
	gridMap[20][5] = 19;
	gridMap[20][6] = 21;
	gridMap[20][7] = 26;
	gridMap[20][8] = -1;
	gridMap[21][0] = 21;
	gridMap[21][1] = 42;
	gridMap[21][2] = 26;
	gridMap[21][3] = 44;
	gridMap[21][4] = 22;
	gridMap[21][5] = 20;
	gridMap[21][6] = 22;
	gridMap[21][7] = -1;
	gridMap[21][8] = -1;
	gridMap[22][0] = 22;
	gridMap[22][1] = 44;
	gridMap[22][2] = 26;
	gridMap[22][3] = 52;
	gridMap[22][4] = 22;
	gridMap[22][5] = 21;
	gridMap[22][6] = 23;
	gridMap[22][7] = -1;
	gridMap[22][8] = 14;
	gridMap[23][0] = 23;
	gridMap[23][1] = 52;
	gridMap[23][2] = 26;
	gridMap[23][3] = 62;
	gridMap[23][4] = 22;
	gridMap[23][5] = 22;
	gridMap[23][6] = 24;
	gridMap[23][7] = -1;
	gridMap[23][8] = -1;
	gridMap[24][0] = 24;
	gridMap[24][1] = 62;
	gridMap[24][2] = 26;
	gridMap[24][3] = 70;
	gridMap[24][4] = 22;
	gridMap[24][5] = 23;
	gridMap[24][6] = -1;
	gridMap[24][7] = 27;
	gridMap[24][8] = 15;
	gridMap[25][0] = 25;
	gridMap[25][1] = 0;
	gridMap[25][2] = 32;
	gridMap[25][3] = 8;
	gridMap[25][4] = 26;
	gridMap[25][5] = -1;
	gridMap[25][6] = -1;
	gridMap[25][7] = 28;
	gridMap[25][8] = 16;
	gridMap[26][0] = 26;
	gridMap[26][1] = 36;
	gridMap[26][2] = 32;
	gridMap[26][3] = 42;
	gridMap[26][4] = 26;
	gridMap[26][5] = -1;
	gridMap[26][6] = -1;
	gridMap[26][7] = 32;
	gridMap[26][8] = 20;
	gridMap[27][0] = 27;
	gridMap[27][1] = 62;
	gridMap[27][2] = 32;
	gridMap[27][3] = 70;
	gridMap[27][4] = 26;
	gridMap[27][5] = -1;
	gridMap[27][6] = -1;
	gridMap[27][7] = 36;
	gridMap[27][8] = 24;
	gridMap[28][0] = 28;
	gridMap[28][1] = 0;
	gridMap[28][2] = 40;
	gridMap[28][3] = 8;
	gridMap[28][4] = 32;
	gridMap[28][5] = -1;
	gridMap[28][6] = 29;
	gridMap[28][7] = 37;
	gridMap[28][8] = 25;
	gridMap[29][0] = 29;
	gridMap[29][1] = 8;
	gridMap[29][2] = 40;
	gridMap[29][3] = 18;
	gridMap[29][4] = 32;
	gridMap[29][5] = 28;
	gridMap[29][6] = 30;
	gridMap[29][7] = -1;
	gridMap[29][8] = -1;
	gridMap[30][0] = 30;
	gridMap[30][1] = 18;
	gridMap[30][2] = 40;
	gridMap[30][3] = 26;
	gridMap[30][4] = 32;
	gridMap[30][5] = 29;
	gridMap[30][6] = 31;
	gridMap[30][7] = 38;
	gridMap[30][8] = -1;
	gridMap[31][0] = 31;
	gridMap[31][1] = 26;
	gridMap[31][2] = 40;
	gridMap[31][3] = 36;
	gridMap[31][4] = 32;
	gridMap[31][5] = 30;
	gridMap[31][6] = 32;
	gridMap[31][7] = -1;
	gridMap[31][8] = -1;
	gridMap[32][0] = 32;
	gridMap[32][1] = 36;
	gridMap[32][2] = 40;
	gridMap[32][3] = 42;
	gridMap[32][4] = 32;
	gridMap[32][5] = 31;
	gridMap[32][6] = 33;
	gridMap[32][7] = -1;
	gridMap[32][8] = 26;
	gridMap[33][0] = 33;
	gridMap[33][1] = 42;
	gridMap[33][2] = 40;
	gridMap[33][3] = 46;
	gridMap[33][4] = 32;
	gridMap[33][5] = 32;
	gridMap[33][6] = 34;
	gridMap[33][7] = -1;
	gridMap[33][8] = -1;
	gridMap[34][0] = 34;
	gridMap[34][1] = 46;
	gridMap[34][2] = 40;
	gridMap[34][3] = 52;
	gridMap[34][4] = 32;
	gridMap[34][5] = 33;
	gridMap[34][6] = 35;
	gridMap[34][7] = 39;
	gridMap[34][8] = -1;
	gridMap[35][0] = 35;
	gridMap[35][1] = 52;
	gridMap[35][2] = 40;
	gridMap[35][3] = 62;
	gridMap[35][4] = 32;
	gridMap[35][5] = 34;
	gridMap[35][6] = 36;
	gridMap[35][7] = -1;
	gridMap[35][8] = -1;
	gridMap[36][0] = 36;
	gridMap[36][1] = 62;
	gridMap[36][2] = 40;
	gridMap[36][3] = 70;
	gridMap[36][4] = 32;
	gridMap[36][5] = 35;
	gridMap[36][6] = -1;
	gridMap[36][7] = 40;
	gridMap[36][8] = 27;
	gridMap[37][0] = 37;
	gridMap[37][1] = 0;
	gridMap[37][2] = 46;
	gridMap[37][3] = 8;
	gridMap[37][4] = 40;
	gridMap[37][5] = -1;
	gridMap[37][6] = -1;
	gridMap[37][7] = 41;
	gridMap[37][8] = 28;
	gridMap[38][0] = 38;
	gridMap[38][1] = 18;
	gridMap[38][2] = 46;
	gridMap[38][3] = 26;
	gridMap[38][4] = 40;
	gridMap[38][5] = -1;
	gridMap[38][6] = -1;
	gridMap[38][7] = 43;
	gridMap[38][8] = 30;
	gridMap[39][0] = 39;
	gridMap[39][1] = 46;
	gridMap[39][2] = 46;
	gridMap[39][3] = 52;
	gridMap[39][4] = 40;
	gridMap[39][5] = -1;
	gridMap[39][6] = -1;
	gridMap[39][7] = 45;
	gridMap[39][8] = 34;
	gridMap[40][0] = 40;
	gridMap[40][1] = 62;
	gridMap[40][2] = 46;
	gridMap[40][3] = 70;
	gridMap[40][4] = 40;
	gridMap[40][5] = -1;
	gridMap[40][6] = -1;
	gridMap[40][7] = 47;
	gridMap[40][8] = 36;
	gridMap[41][0] = 41;
	gridMap[41][1] = 0;
	gridMap[41][2] = 52;
	gridMap[41][3] = 8;
	gridMap[41][4] = 46;
	gridMap[41][5] = -1;
	gridMap[41][6] = 42;
	gridMap[41][7] = -1;
	gridMap[41][8] = 37;
	gridMap[42][0] = 42;
	gridMap[42][1] = 8;
	gridMap[42][2] = 52;
	gridMap[42][3] = 18;
	gridMap[42][4] = 46;
	gridMap[42][5] = 41;
	gridMap[42][6] = 43;
	gridMap[42][7] = -1;
	gridMap[42][8] = -1;
	gridMap[43][0] = 43;
	gridMap[43][1] = 18;
	gridMap[43][2] = 52;
	gridMap[43][3] = 26;
	gridMap[43][4] = 46;
	gridMap[43][5] = 42;
	gridMap[43][6] = 44;
	gridMap[43][7] = -1;
	gridMap[43][8] = 38;
	gridMap[44][0] = 44;
	gridMap[44][1] = 26;
	gridMap[44][2] = 52;
	gridMap[44][3] = 46;
	gridMap[44][4] = 46;
	gridMap[44][5] = 43;
	gridMap[44][6] = 45;
	gridMap[44][7] = -1;
	gridMap[44][8] = -1;
	gridMap[45][0] = 45;
	gridMap[45][1] = 46;
	gridMap[45][2] = 52;
	gridMap[45][3] = 52;
	gridMap[45][4] = 46;
	gridMap[45][5] = 44;
	gridMap[45][6] = 46;
	gridMap[45][7] = -1;
	gridMap[45][8] = 39;
	gridMap[46][0] = 46;
	gridMap[46][1] = 52;
	gridMap[46][2] = 52;
	gridMap[46][3] = 62;
	gridMap[46][4] = 46;
	gridMap[46][5] = 45;
	gridMap[46][6] = 47;
	gridMap[46][7] = -1;
	gridMap[46][8] = -1;
	gridMap[47][0] = 47;
	gridMap[47][1] = 62;
	gridMap[47][2] = 52;
	gridMap[47][3] = 70;
	gridMap[47][4] = 46;
	gridMap[47][5] = 46;
	gridMap[47][6] = -1;
	gridMap[47][7] = -1;
	gridMap[47][8] = 40;

	time = 0.0;

	stop = false;

	human[0].direction = 0;
	human[0].location[0] = 4.5;
	human[0].location[1] = 3.0;

	human[1].direction = 0;
	human[1].location[0] = 66;
	human[1].location[1] = 3.5;

	human[2].direction = 2;
	human[2].location[0] = 66;
	human[2].location[1] = 36;

	human[3].direction = 1;
	human[3].location[0] = 4;
	human[3].location[1] = 49;

	robot[0].direction = 3;
	robot[0].location[0] = 42;
	robot[0].location[1] = 49;

	robot[1].direction = 2;
	robot[1].location[0] = 56;
	robot[1].location[1] = 49;

	robot[2].direction = 2;
	robot[2].location[0] = 48;
	robot[2].location[1] = 14;

	robot[3].direction = 2;
	robot[3].location[0] = 33;
	robot[3].location[1] = 3;


	path_pointer[0] = 2;
	path[0][0] = 9;
	path[0][1] = 44;
	path[0][2] = 45;
	path[0][3] = 39;
	path[0][4] = 34;
	path[0][5] = 33;
	path[0][6] = 32;
	path[0][7] = 26;
	path[0][8] = 20;
	path[0][9] = 21;

	path_pointer[1] = 2;  
	path[1][0] = 7; 
	path[1][1] = 46;
	path[1][2] = 45;
	path[1][3] = 39;
	path[1][4] = 34;
	path[1][5] = 35;
	path[1][6] = 36;
	path[1][7] = 27;

	path_pointer[2] = 2;
	path[2][0] = 12;
	path[2][1] = 10;
	path[2][2] = 9;
	path[2][3] = 8;
	path[2][4] = 13;
	path[2][5] = 18;
	path[2][6] = 19;
	path[2][7] = 20;
	path[2][8] = 26;
	path[2][9] = 32;
	path[2][10] = 31;
	path[2][11] = 30;
	path[2][12] = 29;

	path_pointer[3] = 2;
	path[3][0] = 14;
	path[3][1] = 3;
	path[3][2] = 2;
	path[3][3] = 6;
	path[3][4] = 8;
	path[3][5] = 13;
	path[3][6] = 18;
	path[3][7] = 17;
	path[3][8] = 16;
	path[3][9] = 25;
	path[3][10] = 28;
	path[3][11] = 37;
	path[3][12] = 41;
	path[3][13] = 42;
	path[3][14] = 43;


	for(int i = 0 ; i < numberOfRobots ; i ++)
		for(int j = i + 1 ; j < numberOfRobots ; j ++)
			for(int p = 1 ; p <= path[i][0] ; p ++)
				for(int q = 1 ; q <= path[j][0] ; q ++)
					if (path[i][p] == path[j][q])
					{
						meetingpoint[path[i][p]] = true;
						cout << path[i][p] << " is a meetingpoint." << endl;
					}
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
	for (i = 0; i < numberOfGrids; i++){
		if (y <= gridMap[i][2] && y > gridMap[i][4] && x >= gridMap[i][1] && x < gridMap[i][3]) return gridMap[i][0];
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
	for(int i = path_pointer[robotNumber]; i <= path[robotNumber][0] ; i ++)
		if (path[robotNumber][i] == targetGridNumber)
		{
			n = i;
			break;
		}
	if (n == 0)
	{
		return 9999999.9;	//has passed or will never arrive the targer grid
	}


	pointer = path_pointer[robotNumber];
	nextGridNumber = path[robotNumber][pointer];

	thisGrid = getGrid(gridNumber);
	centerx = ((float)thisGrid[1] + (float)thisGrid[3]) / 2;
	centery = ((float)thisGrid[2] + (float)thisGrid[4]) / 2;
	direction = 0;
	if (gridNumber == nextGridNumber) // to avoid gridNumber==nextGridNumber, happens when crossed before
	{
		gridNumber = path[robotNumber][pointer-1];
		thisGrid = getGrid(gridNumber);
		centerx = ((float)thisGrid[1] + (float)thisGrid[3]) / 2;
		centery = ((float)thisGrid[2] + (float)thisGrid[4]) / 2;
		direction = 0;
	}
	if (thisGrid[5] == nextGridNumber) // facing west side
		direction = 2;
	else if (thisGrid[6] == nextGridNumber) // facing east side
		direction = 3;
	else if (thisGrid[7] == nextGridNumber) // facing north side
		direction = 0;
	else if (thisGrid[8] == nextGridNumber) // facing south side
		direction = 1;
	else {
		cout << "**************************   ERR @ environment::distanceToGrid : grid " << gridNumber << " has no neighbor " << nextGridNumber << " for Robot " << robotNumber << ".  ***************************" << endl;
		stop = true;
	}

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
		if (direction == 0 || direction == 1){ // going up/down
			distance += 0.5 * (thisGrid[2] - thisGrid[4]);
		}
		
		else if (direction == 2 || direction == 3) // going left/right
			distance += 0.5 * (thisGrid[3] - thisGrid[1]);
		
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
		else {
			cout << "**************************   ERR @ environment::distanceToGrid in path : grid " << gridNumber << " has no neighbor " << nextGridNumber << " for Robot " << robotNumber << ".  ***************************" << endl;
			stop = true;
		}

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



