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
	sc_out <float> bstop;
	sc_out <float> ostop;
	sc_out <bool> bres, ores;



	


	int real_map[4][7];		//2-D arry (fifo?)
	float robot_map[2][5];
	float robsp;			//robot speed
	float humsp1, humsp2;	//human speed

	void dosens();
	SC_CTOR(sensor){
		robsp = 1;
		humsp1 = 0.5;
		humsp2 = 1.5;

		SC_METHOD(dosens);
		sensitive << clock.pos();
	}
};