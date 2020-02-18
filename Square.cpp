// Do not remove the include below
#include "PlutoPilot.h"
#include "Motor.h"
#include "Control.h"
#include "Utils.h"
//The setup function is called once at Pluto's hardware startup
Timer time;
Timer time2;

void plutoInit()
{
// Add your hardware initialization code here
}



//The function is called once before plutoPilot when you activate Developer Mode
void onPilotStart()
{
  // do your one time stuffs here
	time.reset();
	time2.reset();

}



// The loop function is called in an endless loop
void plutoPilot()
{

//Add your repeated code here


	while(!(time.set(250,true))){ //running this loop for 250 millisecond to rotate by 90 degrees
	Motor.set(M1, 1800);
		Motor.setDirection(M4,FORWARD);
		Motor.set(M4, 1800); // setting outer motors at higher speed

		Motor.set(M2, 1200); //setting inner motors at low speed
		Motor.set(M3, 1200);
		Motor.setDirection(M3, BACKWARD); //setting the direction of m3 motor opposite to configured rotation

	}

	while(time.set(550,true)){
time2.reset();
		while(!(time2.set(5000,true))){ //running this loop for 5 sec to move straight ahead
			Motor.setDirection(M3, BACKWARD);
			Motor.setDirection(M4, FORWARD);
				 Motor.set(M1, 1999);
				 Motor.set(M2, 1999);
				 Motor.set(M3, 1999);
				 Motor.set(M4, 1999);

	 }
	}

}

//The function is called once after plutoPilot when you deactivate Developer Mode
void onPilotFinish()
{

// do your cleanup stuffs here
	Motor.set(M1, 1000);
	Motor.set(M2, 1000);
	Motor.set(M3, 1000);
	Motor.set(M4, 1000); //stopping all the motors when developer mode is switched off

}




