#ifndef USERCONTROL_H
#define USERCONTROL_H

int chnl1 = 0, chnl4 = 0, chnl3 = 0, threshold = 10;

void deadZone() {
	//Joystick variables

	//Create deadzone for Channel 1
	if(abs(vexRT[Ch1]) > threshold) {
		chnl1 = vexRT[Ch1];
	}
	else {
		chnl1 = 0;
	}
	//Create deadzone for Channel 4
	if(abs(vexRT[Ch4]) > threshold) {
		chnl4 = vexRT[Ch4];
	}
	else {
		chnl4 = 0;
	}
	//Create deadzone for Channel 3
	if(abs(vexRT[Ch3]) > threshold) {
		chnl3 = vexRT[Ch3];
	}
	else {
		chnl3 = 0;
	}
}
void driveControl() {
	//Joystick control for driver
	motor[frontRight] = chnl3 + chnl1 + chnl4;
	motor[backRight] = chnl3 + chnl1 - chnl4;
	motor[backLeft] = chnl3 - chnl1 + chnl4;
	motor[frontLeft] = chnl3 - chnl1 - chnl4;

	if(vexRT[Btn6D] == 1) {												//arm moves up
		/*
		int masterPower = 127;
		int slavePower = 127;
		int error = 0;
		int kp = 5;
		SensorValue[topLeft] = 0;
		SensorValue[topRight] = 0;
		if (SensorValue[topRight] > SensorValue[topLeft]) {
		while (SensorValue[topRight] > SensorValue[topLeft]) {
		error = SensorValue[topLeft] - SensorValue[topRight];
		slavePower += error/kp;
		motor[botRight] = slavePower;
		motor[botLeft] = masterPower;
		motor[midRight] = slavePower;
		motor[midLeft] = masterPower;
		motor[topRight] = slavePower;
		motor[topLeft] = masterPower;
		}
		}
		if (SensorValue[topRight] < SensorValue[topLeft]) {
		while (SensorValue[topRight] > SensorValue[topLeft]) {
		error = SensorValue[topLeft] - SensorValue[topRight];
		masterPower += error/kp;
		motor[botRight] = slavePower;
		motor[botLeft] = masterPower;
		motor[midRight] = slavePower;
		motor[midLeft] = masterPower;
		motor[topRight] = slavePower;
		motor[topLeft] = masterPower;
		}
		}*/
		motor[botRight] = fullPower;
		motor[botLeft] = fullPower;
		motor[midRight] = fullPower;
		motor[midLeft] = fullPower;
		motor[topRight] = fullPower;
		motor[topLeft] = fullPower;
	}
	else if(vexRT[Btn5D] == 1) {											//arm moves down

		motor[botRight] = -fullPower;
		motor[botLeft] = -fullPower;
		motor[midRight] = -fullPower;
		motor[midLeft] = -fullPower;
		motor[topRight] = -fullPower;
		motor[topLeft] = -fullPower;

	}
	else {
		motor[botRight] = 0;
		motor[botLeft] = 0;
		motor[midRight] = 0;
		motor[midLeft] = 0;
		motor[topRight] = 0;
		motor[topLeft] = 0;
	}
}
void cubeControl() {
	if(vexRT[Btn6U] == 1) {
		SensorValue[cubeIntake] = 0;
		//SensorValue[leftSkyArm] = 1;
	}
	else {
		SensorValue[cubeIntake] = 1;
		//SensorValue[leftSkyArm] = 0;
	}
}
void skyriseControl() {

	if (vexRT[Btn8L] == 1) {
		SensorValue[skyriseClaw] = 1;
	}
	else if (vexRT[Btn8R] == 1) {
		SensorValue[skyriseClaw] = 0;
	}
}
void controllerMove(){
if (vexRT[Btn7D] == 1) {
		motor[frontRight] = chnl3 - chnl1 - chnl4;
		motor[backRight] = chnl3 - chnl1 + chnl4;
		motor[backLeft] = chnl3 + chnl1 - chnl4;
		motor[frontLeft] = chnl3 + chnl1 + chnl4;
	}
	else if (vexRT[Btn7U] == 1) {
		motor[frontRight] = chnl3 + chnl1 + chnl4;
		motor[backRight] = chnl3 + chnl1 - chnl4;
		motor[backLeft] = chnl3 - chnl1 + chnl4;
		motor[frontLeft] = chnl3 - chnl1 - chnl4;
}
}
/*void balance() {
	int masterPower = 127;
	int slavePower = 127;
	int error = 0;
	int kp = 5;
	SensorValue[topLeft] = 0;
	SensorValue[topRight] = 0;

	while (SensorValue[topRight] > SensorValue[topLeft]) {
		motor[botRight] = slavePower;
		motor[botLeft] = masterPower;
		motor[midRight] = slavePower;
		motor[midLeft] = masterPower;
		motor[topRight] = slavePower;
		motor[topLeft] = masterPower;
		error = SensorValue[topLeft] - SensorValue[topRight];
		slavePower += error/kp;
		SensorValue[topLeft] = 0;
		SensorValue[topRight] = 0;
		wait1Msec(100);
	}
}*/

#endif
