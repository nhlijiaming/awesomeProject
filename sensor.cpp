#include "systemc.h"
#include "sensor.h"

void sensor::dosens(){
<<<<<<< HEAD
	void robot::assignment(){
		/*human moving*/
		if (n % 2 == 0){
			//human 1
			if (y_human1 < -0.025) 	y_human1 = y_human1 + humsp1 / 20;
			else if (x_human1 > 0.5)	x_human1 = x_human1 + humsp1 / 20;
			else n = n + 1;
		}
		else {
			if (x_human1 < 6.975) 	x_human1 = x_human1 + humsp1 / 20;
			else if (y_human1 > -3.975)	y_human1 = y_human1 + humsp1 / 20;
			else n = n + 1;
		}
		//human 0
		if (m % 2 == 0){
			if (x_human0 > 0.025) x_human0 = x_human0 - humsp0 / 20;
			else m = m + 1;
		}
		else {
			if (x_human0 < 6.975) x_human0 = x_human0 + humsp0 / 20;
			else m = m + 1;
		}


		/*human detection*/
		obstacle=
		/*obstacle calculation*/
		if (obstacle <= 0.5)	v = 0;
		else v = 1;


			
=======
>>>>>>> dev_jeff

		

	}
}
