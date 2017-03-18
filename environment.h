#ifndef __ENVIR__H
#define __ENVIR__H
#include "systemc.h"

#define numberOfGrids 10
#define numberOfRobots 1
#define numberOfHumans 2

#define period 0.05

struct motionData
{
	int direction; // 0 for go up, 1 for down, 2 for left and 3 for right
	float location[2];

	inline bool operator == (const motionData& rhs) const{
		return (rhs.direction==direction && rhs.location[0]==location[0] && rhs.location[1]==location[1]);
	}

    inline motionData& operator = (const motionData& rhs) {
      direction = rhs.direction;
      location[0] = rhs.location[0];
      location[1] = rhs.location[1];
      return *this;
    }

    inline friend void sc_trace(sc_trace_file *tf, const motionData & v, const std::string & NAME ) {
      sc_trace(tf,v.direction, NAME + ".direction");
      sc_trace(tf,v.location[0], NAME + ".x");
      sc_trace(tf,v.location[1], NAME + ".y");
    }

    inline friend ostream& operator << ( ostream& os,  motionData const & v ) {
      os << "(" << v.direction << "," << v.location[0] << "," << v.location[1] << ")";
      return os;
    }
};



class environment
{
public:
	int gridMap[numberOfGrids][9];
	bool meetingpoint[numberOfGrids];
	struct motionData human[numberOfHumans];
	struct motionData robot[numberOfRobots];
	int path[numberOfRobots][numberOfGrids+1];
	int path_pointer[numberOfRobots];
	float time;

public:
	environment(void);
	int (*getMap(void))[9];
	int *getGrid(int gridNumber);
	int getGridNumber(struct motionData* motionData);
	int getNumberOfHumans(void);
	int getNumberOfRobots(void);
	struct motionData* getHumanLocation(int n);
	void setHumanLocation(int n, struct motionData* motionData);
	struct motionData* getRobotLocation(int n);
	void setRobotLocation(int n, struct motionData* motionData);
	void move(struct motionData* motionData, float distance);
	void timeIncrement();
	void timeIncrement(float deltaTime);
	float getTime();
	int getRobotNextGridNumber(int robotNumber);
	void moveRobotToNextGrid(int robotNumber);
	bool checkRobotIfArrived(int robotNumber);
	float distanceToGrid(int robotNumber,int targetGridNumber);
	bool isMeetingPoint(int gridNumber);
};

#endif
