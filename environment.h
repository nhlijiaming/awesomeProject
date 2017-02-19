#ifndef __ENVIR__H
#define __ENVIR__H

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
	struct motionData human[numberOfHumans];
	struct motionData robot[numberOfRobots];

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
