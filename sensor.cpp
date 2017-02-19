#include "systemc.h"
#include "sensor.h"

void sensor::dosens(){
	/*human moving*/
	if (x_human1>-6.5) x_human1 = x_human1 - humsp1/20;//
	else x_human1 = x_human1 + humsp1 / 20;
	if (n % 2 == 0){
		if (y_human2 < -0.5) 	y_human2 = y_human2 + humsp2 / 20;
		else x_human2 = x_human2 + humsp2 / 20;
	}
	else

	/*human detection*/
	if (in_stop == 0){			//robot moving
		if (obstacle <= range){
			stop_ = 1;
			out_stop = stop_;  //output port out_stop=1
			res = 0;
		}
	}
	else {
		if (obstacle >= range){	
			res_ = 1;
			res = res_;  //output port res=1
			out_stop = 0; //output port
			}
	}
	/*boundary*/
	if (boundary < 0.5){  //calculation of boundary
		if (){//robot in next grid



	}


}


