#include "systemc.h"
#include "environment.h"

// Constructor
void environment(void)
{
	cout << "constructing class \"environment\"" << endl;

	/*grid map*/
	gridMap[0][0] = 1;
	gridMap[0][1] = 0;
	gridMap[0][2] = 0;
	gridMap[0][3] = -1;
	gridMap[0][4] = -1;
	gridMap[0][5] = 0;
	gridMap[0][6] = 2;
	gridMap[0][7] = 0;
	gridMap[0][8] = 0;
	gridMap[1][0] = 2;
	gridMap[1][1] = -1;
	gridMap[1][2] = 0;
	gridMap[1][3] = -2;
	gridMap[1][4] = -1;
	gridMap[1][5] = 1;
	gridMap[1][6] = 3;
	gridMap[1][7] = 0;
	gridMap[1][8] = 0;
	gridMap[2][0] = 3;
	gridMap[2][1] = -2;
	gridMap[2][2] = 0;
	gridMap[2][3] = -3;
	gridMap[2][4] = -1;
	gridMap[2][5] = 2;
	gridMap[2][6] = 4;
	gridMap[2][7] = 0;
	gridMap[2][8] = 0;
	gridMap[3][0] = 4;
	gridMap[3][1] = -3;
	gridMap[3][2] = 0;
	gridMap[3][3] = -4;
	gridMap[3][4] = -1;
	gridMap[3][5] = 3;
	gridMap[3][6] = 5;
	gridMap[3][7] = 0;
	gridMap[3][8] = 0;
	gridMap[4][0] = 5;
	gridMap[4][1] = -4;
	gridMap[4][2] = 0;
	gridMap[4][3] = -5;
	gridMap[4][4] = -1;
	gridMap[4][5] = 4;
	gridMap[4][6] = 6;
	gridMap[4][7] = 0;
	gridMap[4][8] = 0;
	gridMap[5][0] = 6;
	gridMap[5][1] = -5;
	gridMap[5][2] = 0;
	gridMap[5][3] = -6;
	gridMap[5][4] = -1;
	gridMap[5][5] = 5;
	gridMap[5][6] = 7;
	gridMap[5][7] = 0;
	gridMap[5][8] = 0;
	gridMap[6][0] = 7;
	gridMap[6][1] = -6;
	gridMap[6][2] = 0;
	gridMap[6][3] = -7;
	gridMap[6][4] = -1;
	gridMap[6][5] = 6;
	gridMap[6][6] = 0;
	gridMap[6][7] = 0;
	gridMap[6][8] = 8;
	gridMap[7][0] = 8;
	gridMap[7][1] = -6;
	gridMap[7][2] = -1;
	gridMap[7][3] = -7;
	gridMap[7][4] = -2;
	gridMap[7][5] = 0;
	gridMap[7][6] = 0;
	gridMap[7][7] = 7;
	gridMap[7][8] = 9;
	gridMap[8][0] = 9;
	gridMap[8][1] = -6;
	gridMap[8][2] = -2;
	gridMap[8][3] = -7;
	gridMap[8][4] = -3;
	gridMap[8][5] = 0;
	gridMap[8][6] = 0;
	gridMap[8][7] = 8;
	gridMap[8][8] = 10;
	gridMap[9][0] = 10;
	gridMap[9][1] = -6;
	gridMap[9][2] = -3;
	gridMap[9][3] = -7;
	gridMap[9][4] = -4;
	gridMap[9][5] = 0;
	gridMap[9][6] = 0;
	gridMap[9][7] = 9;
	gridMap[9][8] = 0;

	human[0].location[0] = 6.5;
	human[0].location[1] = -0.5;

	human[1].location[0] = 6.5;
	human[1].location[1] = -3.5;

	robot[0].location[0] = 0.5;
	robot[0].location[1] = -0.5;
}

int* environment::getMap(){
	return gridMap;
}

int getNumberOfHumans(void)
{
	return numberOfHumans;
}

int getNumberOfRobots(void)
{
	return numberOfRobots;
}

struct motionData* getHuamnLocation(int n)
{
	return human[n];
}

void setHuamnLocation(int n, struct motionData* motionData)
{
	human[n].direction = motionData->direction;
	human[n].location[0] = motionData->location[0];
	human[n].location[1] = motionData->location[1];
	return;
}

struct motionData* getRobotLocation(int n)
{
	return robot[n];
}

void setRobotLocation(int n, struct motionData* motionData)
{
	robot[n].direction = motionData->direction;
	robot[n].location[0] = motionData->location[0];
	robot[n].location[1] = motionData->location[1];
	return;
}

