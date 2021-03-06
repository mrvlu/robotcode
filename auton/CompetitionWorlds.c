#pragma config(UART_Usage, UART1, uartVEXLCD, baudRate19200, IOPins, None, None)
#pragma config(UART_Usage, UART2, uartNotUsed, baudRate4800, IOPins, None, None)
#pragma config(I2C_Usage, I2C1, i2cSensors)
#pragma config(Sensor, in1,    autoSelect,     sensorPotentiometer)
#pragma config(Sensor, dgtl1,  skyriseClaw,    sensorDigitalOut)
#pragma config(Sensor, dgtl2,  cubeIntake,     sensorDigitalOut)
#pragma config(Sensor, dgtl4,  rightShaft,     sensorQuadEncoder)
#pragma config(Sensor, dgtl6,  leftShaft,      sensorQuadEncoder)
#pragma config(Sensor, I2C_1,  backLeftEnc,    sensorQuadEncoderOnI2CPort,    , AutoAssign)
#pragma config(Sensor, I2C_2,  frontLeftEnc,   sensorQuadEncoderOnI2CPort,    , AutoAssign)
#pragma config(Sensor, I2C_3,  backRightEnc,   sensorQuadEncoderOnI2CPort,    , AutoAssign)
#pragma config(Sensor, I2C_4,  frontRightEnc,  sensorQuadEncoderOnI2CPort,    , AutoAssign)
#pragma config(Motor,  port1,           botLeft,       tmotorVex393_HBridge, openLoop)
#pragma config(Motor,  port2,           midLeft,       tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           midRight,      tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port4,           topLeft,       tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           topRight,      tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port6,           backLeft,      tmotorVex393_MC29, openLoop, reversed, encoderPort, I2C_1)
#pragma config(Motor,  port7,           frontLeft,     tmotorVex393_MC29, openLoop, reversed, encoderPort, I2C_2)
#pragma config(Motor,  port8,           frontRight,    tmotorVex393_MC29, openLoop, encoderPort, I2C_3)
#pragma config(Motor,  port9,           backRight,     tmotorVex393_MC29, openLoop, encoderPort, I2C_4)
#pragma config(Motor,  port10,          botRight,      tmotorVex393_HBridge, openLoop, reversed)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#pragma platform(VEX)

//Competition Control and Duration Settings
#pragma competitionControl(Competition)
#pragma autonomousDuration(20)
#pragma userControlDuration(120)

#include "Vex_Competition_Includes.c"   //Main competition background code...do not modify!
#include "states.h"
#include "arm.h"
#include "intakeControl.h"
#include "drive.h"
#include "userControl.h"
#include "autonTasks.h"
#include "autonSwitcher.h"





/////////////////////////////////////////////////////////////////////////////////////////
//
//                          Pre-Autonomous Functions
//
// You may want to perform some actions before the competition starts. Do them in the
// following function.
//
/////////////////////////////////////////////////////////////////////////////////////////

void pre_auton()
{
	// Set bStopTasksBetweenModes to false if you want to keep user created tasks running between
	// Autonomous and Tele-Op modes. You will need to manage all user created tasks if set to false.
	bStopTasksBetweenModes = true;

	// All activities that occur before the competition starts
	// Example: clearing encoders, setting servo positions, ...
}

/////////////////////////////////////////////////////////////////////////////////////////
//
//                                 Autonomous Task
//
// This task is used to control your robot during the autonomous phase of a VEX Competition.
// You must modify the code to add your own robot specific commands here.
//
/////////////////////////////////////////////////////////////////////////////////////////

task autonomous()
{
//void driveAndMove(int driVal, moveDir dirX, int armVal, armDir dirY ){
//autonSwitch(0, 100, 1099, 2098, 3097);
skyriseAuto(RED);
}

/////////////////////////////////////////////////////////////////////////////////////////
//
//                                 User Control Task
//
// This task is used to control your robot during the user control phase of a VEX Competition.
// You must modify the code to add your own robot specific commands here.
//
/////////////////////////////////////////////////////////////////////////////////////////

task usercontrol()
{
	// User control code here, inside the loop

	//nMotorEncoder[topLeft] = 0;
	//nMotorEncoder[topRight] = 0;
	//Driver control
	while (true){
		bLCDBacklight = true;
		clearLCDLine(0);
		clearLCDLine(1);
		displayLCDString(0, 0, "L:");
		displayNextLCDNumber(nMotorEncoder[topLeft], 4);
		displayLCDString(1, 0, "R:");
		displayNextLCDNumber(nMotorEncoder[topRight], 4);
		wait1Msec(10);
		deadZone();
		driveControl();
		cubeControl();
		skyriseControl();
		controllerMove();
		//balance();
	}
}
