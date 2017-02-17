#include "systemc.h"
#include "sensor.h"

void sensor::dosens(){

	if (in_stop == 0){
		if (obstacle <= range){
			stop_ = 1;
			out_stop = stop_;
		}
	}
	else {
		if (obstacle >= range){
			res_ = 1;
			res = res_;
		}
	}


}

	
