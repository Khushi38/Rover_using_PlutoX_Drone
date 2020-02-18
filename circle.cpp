// Do not remove the include below
#include "PlutoPilot.h"
#include  "Control.h"
#include  "Motor.h"

//The setup function is called once at Pluto's hardware startup
void plutoInit()
{
// Add your hardware initialization code here
}



//The function is called once before plutoPilot when you activate Developer Mode
void onPilotStart()
{
  // do your one time stuffs here

}



// The loop function is called in an endless loop
void plutoPilot()
{

//Add your repeated code here
	Motor.set(M1, 1500);
		Motor.setDirection(M4,FORWARD);
		Motor.set(M4, 1500); // setting outer motors at higher speed

		Motor.set(M2, 1200); //setting inner motors at low speed
		Motor.set(M3, 1200);
		Motor.setDirection(M3, BACKWARD); //setting the direction of m3 motor opposite to configured rotation

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




