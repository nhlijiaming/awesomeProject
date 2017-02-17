#include "systemc.h"

/*The modole Senor includes:
1:the robots and humans position
2:real map(grids ID and position)
3:distance between each robot and boundary &stop and resume command
4:distance between each robot and obstacle & stop and resume command*/
SC_MODULE(sensor){
	//sc_in <int> vertical;
	//sc_in <int> horizon;
	//sc_in <int> robot_num;
	//sc_in <float> humsp1, humsp2;

	sc_in <bool> clock;
	sc_in <float> range;
	sc_out <float> ostop;
	sc_out <bool> bres, ores;

	int grid_map[4][7];		//2-D arry 
	float robot_map[2][5];
	float robsp;			//robot speed
	float humsp1, humsp2;	//human speed

	void dosens();
	SC_CTOR(sensor){
		robsp = 1;
		humsp1 = 0.5;
		humsp2 = 1.5;

		/*grid map*/
		grid_map[0][0] = 1;
		grid_map[0][1] = 0;
		grid_map[0][2] = 0;
		grid_map[0][3] = -1;
		grid_map[0][4] = -1;
		grid_map[0][5] = 0;
		grid_map[0][6] = 2;
		grid_map[0][7] = 0;
		grid_map[0][8] = 0;
		grid_map[1][0] = 2;
		grid_map[1][1] = -1;
		grid_map[1][2] = 0;
		grid_map[1][3] = -2;
		grid_map[1][4] = -1;
		grid_map[1][5] = 1;
		grid_map[1][6] = 3;
		grid_map[1][7] = 0;
		grid_map[1][8] = 0;
		grid_map[2][0] = 3;
		grid_map[2][1] = -2;
		grid_map[2][2] = 0;
		grid_map[2][3] = -3;
		grid_map[2][4] = -1;
		grid_map[2][5] = 2;
		grid_map[2][6] = 4;
		grid_map[2][7] = 0;
		grid_map[2][8] = 0;
		grid_map[3][0] = 4;
		grid_map[3][1] = -3;
		grid_map[3][2] = 0;
		grid_map[3][3] = -4;
		grid_map[3][4] = -1;
		grid_map[3][5] = 3;
		grid_map[3][6] = 5;
		grid_map[3][7] = 0;
		grid_map[3][8] = 0;
		grid_map[4][0] = 5;
		grid_map[4][1] = -4;
		grid_map[4][2] = 0;
		grid_map[4][3] = -5;
		grid_map[4][4] = -1;
		grid_map[4][5] = 4;
		grid_map[4][6] = 6;
		grid_map[4][7] = 0;
		grid_map[4][8] = 0;
		grid_map[5][0] = 6;
		grid_map[5][1] = -5;
		grid_map[5][2] = 0;
		grid_map[5][3] = -6;
		grid_map[5][4] = -1;
		grid_map[5][5] = 5;
		grid_map[5][6] = 7;
		grid_map[5][7] = 0;
		grid_map[5][8] = 0;
		grid_map[6][0] = 7;
		grid_map[6][1] = -6;
		grid_map[6][2] = 0;
		grid_map[6][3] = -7;
		grid_map[6][4] = -1;
		grid_map[6][5] = 6;
		grid_map[6][6] = 0;
		grid_map[6][7] = 0;
		grid_map[6][8] = 8;
		grid_map[7][0] = 8;
		grid_map[7][1] = -6;
		grid_map[7][2] = -1;
		grid_map[7][3] = -7;
		grid_map[7][4] = -2;
		grid_map[7][5] = 0;
		grid_map[7][6] = 0;
		grid_map[7][7] = 7;
		grid_map[7][8] = 9;
		grid_map[8][0] = 9;
		grid_map[8][1] = -6;
		grid_map[8][2] = -2;
		grid_map[8][3] = -7;
		grid_map[8][4] = -3;
		grid_map[8][5] = 0;
		grid_map[8][6] = 0;
		grid_map[8][7] = 8;
		grid_map[8][8] = 10;
		grid_map[9][0] = 10;
		grid_map[9][1] = -6;
		grid_map[9][2] = -3;
		grid_map[9][3] = -7;
		grid_map[9][4] = -4;
		grid_map[9][5] = 0;
		grid_map[9][6] = 0;
		grid_map[9][7] = 9;
		grid_map[9][8] = 0;


		


		SC_METHOD(dosens);
		sensitive << clock.pos();
	}
};