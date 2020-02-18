// Do not remove the include below
#include "PlutoPilot.h"
#include "Led.h"
#include "Control.h"
#include "Flight.h"
#include "Print.h"
#include "Utils.h"

bool isPlutoArmed;
bool isLandCommandSet;
Timer landTimer;
//The setup function is called once at Pluto's hardware startup
void plutoInit()
{
// Add your hardware initialization code here
}



//The function is called once before plutoPilot when you activate Developer Mode
void onPilotStart()
{
  // do your one time stuffs here
	isPlutoArmed=false;
	isLandCommandSet=false;
	landTimer.reset();
	Control.disableFlightStatus(true);

}



// The loop function is called in an endless loop
void plutoPilot()
{

//Add your repeated code here
	Flight.activateFlightMode(FM_ALTHOLD);
	if(Flight.getVelocityZ() > 0){
	ledOp(L_LEFT, ON);
	ledOp(L_RIGHT, OFF);

	}
	else{

	ledOp(L_LEFT, OFF);
	ledOp(L_RIGHT, ON); }
	  if(!Control.isArmed()&&!isPlutoArmed) //checking if Pluto is Disarmed
	   {
		 Control.setCommand(COMMAND_TAKE_OFF); //setting Take Off command
		 Flight.setAltholdHeight(10);
		 isPlutoArmed=true; //setting it to true to prevent re-arming
	   }


	  if(Control.isArmed()&&!isLandCommandSet) // checking if Pluto is Armed
		{

		if(landTimer.set(5000,true)) //Setting up timer for 5 seconds
		{

		Control.setCommand(COMMAND_LAND); //setting Land Command
		isLandCommandSet=true;
		}
		}
	Print.monitor("Velocity Z:", Flight.getVelocityZ());
	Print.monitor("\n");
	Print.redGraph(Flight.getEstimatedAltitude());

}



//The function is called once after plutoPilot when you deactivate Developer Mode
void onPilotFinish()
{

// do your cleanup stuffs here
	Control.disableFlightStatus(false);

}




