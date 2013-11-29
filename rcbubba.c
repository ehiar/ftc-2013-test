#pragma config(Hubs,  S1, HTMotor,  HTServo,  none,     none)
#pragma config(Motor,  mtr_S1_C1_1,     motorD,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C1_2,     motorE,        tmotorTetrix, openLoop)

#include "JoystickDriver.c"

task main()
{
  int threshold = 20;                      /* Int 'threshold' will allow us to ignore low       */
                                           /* readings that keep our robot in perpetual motion. */

  while(true)                              // Infinite loop:
  {
    getJoystickSettings(joystick);
		if(abs(joystick.joy1_y2) > threshold)   // If the right analog stick's Y-axis readings are either above or below the threshold:
    {
      motor[motorD] = joystick.joy1_y2;     // Motor B is assigned a power level equal to the right analog stick's Y-axis reading.
    }
    else                                    // Else if the readings are within the threshold:
    {
      motor[motorD] = 0;                    // Motor B is stopped with a power level of 0.
    }

    if(abs(joystick.joy1_y1) > threshold)   // If the left analog stick's Y-axis readings are either above or below the threshold:
    {
      motor[motorE] = joystick.joy1_y1;     // Motor C is assigned a power level equal to the left analog stick's Y-axis reading.
    }
    else                                    // Else if the readings are within the threshold:
    {
      motor[motorE]= 0;                    // Motor C is stopped with a power level of 0.
    }
	}
}
