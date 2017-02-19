#ifndef __ENVIR__H
#define __ENVIR__H

#define numberOfGrids 10
#define numberOfRobots 1
#define numberOfHumans 2


struct motionData
{
	int direction;
	float location[2];
};

class environment
{
private:
	int gridMap[numberOfGrids][9];

	struct motionData human[numberOfHumans];
	struct motionData robot[numberOfRobots];
	void environment(void);
public:
	int* getMap(void);
	int getNumberOfHumans(void);
	int getNumberOfRobots(void);
	struct motionData* getHuamnLocation(int n);
	void setHuamnLocation(int n, struct motionData* motionData);
	struct motionData* getRobotLocation(int n);
	void setRobotLocation(int n, struct motionData* motionData);
}

#endif
