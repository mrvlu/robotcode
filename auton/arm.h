#ifndef PID_H
#define PID_H
const int fullPower = 127;
int power = 0;
int error = 0;
int intrg = 0;		//integral
int mI = 1;			//integral multiplyer
int mS = 1;			//speed multiplyer
int mIV = 0;		//maximum integral value
int mEV = 100;		//max encoder value
int lastTime = 0;	//last integral check

void encArm(int x){														//you can set encoder values for the arm

	nMotorEncoder[topLeft] = x;
	nMotorEncoder[topRight] = x;

}

void armLeft(int power, armDir dir){												
	switch(dir){
	case UP:
		//Left
		motor[topLeft] = fullPower * power;
		motor[midLeft] = fullPower * power;
		motor[botLeft] = fullPower * power;
		break;
	case DOWN:
		//Left
		motor[topLeft] = -fullPower * power;
		motor[midLeft] = -fullPower * power;
		motor[botLeft] = -fullPower * power;
		break;
	}
}
void armRight(int power, armDir dir){
	switch(dir){
	case UP:
		//Right
		motor[topRight] = fullPower * power;
		motor[botRight] = fullPower * power;
		motor[midRight] = fullPower * power;
		break;
	case DOWN:
		//Right
		motor[topRight] = -fullPower * power;
		motor[midRight] = -fullPower * power;
		motor[botRight] = -fullPower * power;
		break;
	}
}

void stopArm(){
			motor[botRight] = 0;
			motor[botLeft] = 0;
			motor[midRight] = 0;
			motor[midLeft] = 0;
			motor[topRight] = 0;
			motor[topLeft] = 0;

		
	}
	
void arm(armDir dir, int changeEnc){


		switch(dir){
		case UP:
		while(nMotorEncoder[topLeft] < changeEnc && nMotorEncoder[topRight] < changeEnc){
			motor[botRight] = -fullPower;
			motor[botLeft] = -fullPower;
			motor[midRight] = -fullPower;
			motor[midLeft] = -fullPower;
			motor[topRight] = -fullPower;
			motor[topLeft] = -fullPower;
		}
			break;
		case DOWN:
		while(nMotorEncoder[topLeft] > changeEnc && nMotorEncoder[topRight] > changeEnc){
			motor[botRight] = fullPower;
			motor[botLeft] =  fullPower;
			motor[midRight] =  fullPower;
			motor[midLeft] =  fullPower;
			motor[topRight] =  fullPower;
			motor[topLeft] =  fullPower;
		}
			break;
		}
	
	
		stopArm();
		wait1Msec(500);
}

	

void pidArm(armDir dir, int dist){
	//2 arm encoders
	lastTime = time1(T1);

	while(nMotorEncoder[LEFT] >= dist &&nMotorEncoder[RIGHT] >= dist){
		int checkValue = nMotorEncoder[LEFT] - nMotorEncoder[RIGHT];
		switch(dir){
		case UP:
			if(checkValue > 0){
				error = (nMotorEncoder[LEFT] - nMotorEncoder[RIGHT])/mEV;
				intrg += error * ((time1(T1) - lastTime) / mI);
				if(-100 < error && error < 100)
					intrg = 0;
				if(abs(intrg) <= mIV)
					intrg = mIV;
				power = error*mS - intrg;
				armRight(1, dir);
				armLeft(1-power, dir);
				}else if(checkValue < 0){
				error = (nMotorEncoder[RIGHT] - nMotorEncoder[LEFT])/mEV;
				intrg += error * ((time1(T1) - lastTime) / mI);
				if(-100 < error && error < 100)
					intrg = 0;
				if(abs(intrg) <= mIV)
					intrg = mIV;
				power = error*mS - intrg;
				armLeft(1, dir);
				armRight(1-power, dir);
				}else {
				arm(dir,1);
			}
			lastTime = time1(T1);
			break;
		case DOWN:
			checkValue *= -1;
			if(checkValue > 0){
				error = (nMotorEncoder[LEFT] - nMotorEncoder[RIGHT])/mEV;
				intrg += error * ((time1(T1) - lastTime) / mI);
				if(-100 < error && error < 100)
					intrg = 0;
				if(abs(intrg) <= mIV)
					intrg = mIV;
				power = error*mS - intrg;
				armRight(-1, dir);
				armLeft(-1-power, dir);
				}else if(checkValue < 0){
				error = (nMotorEncoder[RIGHT] - nMotorEncoder[LEFT])/mEV;
				intrg += error * ((time1(T1) - lastTime) / mI);
				if(-100 < error && error < 100)
					intrg = 0;
				if(abs(intrg) <= mIV)
					intrg = mIV;
				power = error*mS - intrg;
				armLeft(-1, dir);
				armRight(-1-power, dir);
				}else {
				arm(dir,1);
			}
			lastTime = time1(T1);
			break;
		}
	}

}





#endif
