#ifndef DRIVE_H
#define DRIVE_H
const int skyrise = 127; //for skyrise turn speed
void encDrive(int x){
	nMotorEncoder[backRight] = x;
	nMotorEncoder[backLeft] = x;
	nMotorEncoder[frontRight] = x;
	nMotorEncoder[frontLeft] = x;

}

void stopDrive(){
	motor[frontRight] = 0;
	motor[backRight] = 0;
	motor[backLeft] =  0;
	motor[frontLeft] =  0;

}

bool checkWheels(moveDir dir, int distance){

			if((abs(nMotorEncoder[frontLeft]) < distance &&
				abs(nMotorEncoder[frontRight]) < distance)
				||(abs(nMotorEncoder[backLeft]) < distance &&
				abs(nMotorEncoder[backRight]) < distance)){
				return false;
			}
		else{
			return true;
	}
}

bool checkWheels(rotDir dir, int distance){

			if((abs(nMotorEncoder[frontLeft]) < distance &&
				abs(nMotorEncoder[frontRight]) < distance)
				||(abs(nMotorEncoder[backLeft]) < distance &&
				abs(nMotorEncoder[backRight]) < distance)){
				return false;
	}else{
return true;
}
}
void drive(moveDir dir){
	switch(dir){
		case FORWARDS:
			motor[frontRight] = fullPower;
			motor[backRight] = fullPower;
			motor[backLeft] = fullPower;
			motor[frontLeft] = fullPower;
			break;
		case BACKWARDS:
			motor[frontRight] = -fullPower;
			motor[backRight] = -fullPower;
			motor[backLeft] = -fullPower;
			motor[frontLeft] = -fullPower;
			break;
		case LEFT:
			motor[frontRight] = fullPower;
			motor[backRight] = -fullPower;
			motor[frontLeft] = -fullPower;
			motor[backLeft] = fullPower;
			break;
		case RIGHT:
			motor[frontRight] = fullPower;
			motor[backRight] =  fullPower;
			motor[frontLeft] = fullPower;
			motor[backLeft] =  fullPower;
			break;
	}
}

void drive(moveDir dir, int encoder){
	encDrive(0);
	while(!checkWheels(dir, encoder)){
		drive(dir);
	}
	stopDrive();
	wait1Msec(100);
}

void rotate(rotDir dir){
	switch(dir){
		case LEFTTURN:
			motor[frontRight] = -skyrise;
			motor[backRight] = -skyrise;
			motor[backLeft] =  skyrise;
			motor[frontLeft] =  skyrise;
			break;
		case RIGHTTURN:
			motor[frontRight] =  skyrise;
			motor[backRight] = skyrise;
			motor[backLeft] = -skyrise;
			motor[frontLeft] = -skyrise;
			break;
		}
}

void rotate(rotDir dir, int rVal){
	encDrive(0);
	while(!checkWheels(dir, rVal)){
		rotate(dir);
	}
	stopDrive();
	wait1Msec(100);
}

void driveAndMove(int driVal, moveDir dirX, int armVal, armDir dirY ){
	encDrive(0);
	encArm(0);
	bool movement = true;
	bool armMove = true;
	drive(dirX);
	arm(dirY);
	while(movement||armMove){
		if(checkWheels(dirX, driVal)){
			movement = false;
			stopDrive();
		}
		if(checkArm(dirY, armVal)){
			armMove = false;
			stopArm();
		}

	}
	wait1Msec(100);
}
void rotAndMove(int rVal, rotDir dirX, int armVal, armDir dirY ){
	encDrive(0);
	encArm(0);
	bool rotation = true;
	bool armMove = true;
	rotate(dirX);
	arm(dirY);
	while(rotation||armMove){
		if(checkWheels(dirX, rVal)){
			rotation = false;
			stopDrive();
		}
		if(checkArm(dirY, armVal)){
			armMove = false;
			stopArm();
		}

	}
	wait1Msec(100);
}

#endif
