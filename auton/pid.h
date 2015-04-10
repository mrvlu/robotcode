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

void encArm(int x){

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

void arm(int power, armDir dir, int changeEnc){
encArm(0);
while(abs(nMotorEncoder[topLeft]) < changeEnc && abs(nMotorEncoder[topRight]) < changeEnc){
		switch(dir){
		case UP:
			motor[botRight] = -fullPower * power;
			motor[botLeft] = -fullPower * power;
			motor[midRight] = -fullPower * power;
			motor[midLeft] = -fullPower * power;
			motor[topRight] = -fullPower * power;
			motor[topLeft] = -fullPower * power;
			break;
		case DOWN:
			motor[botRight] = fullPower * power;
			motor[botLeft] =  fullPower * power;
			motor[midRight] =  fullPower * power;
			motor[midLeft] =  fullPower * power;
			motor[topRight] =  fullPower * power;
			motor[topLeft] =  fullPower * power;
			break;
		}
	}
}

void pidArm(armDir dir, int dist){
	//2 arm encoders
	lastTime = time1(T1);

	while(nMotorEncoder[left] >= dist &&nMotorEncoder[right] >= dist){
		int checkValue = nMotorEncoder[left] - nMotorEncoder[right];
		switch(dir){
		case UP:
			if(checkValue > 0){
				error = (nMotorEncoder[left] - nMotorEncoder[right])/mEV;
				intrg += error * ((time1(T1) - lastTime) / mI);
				if(-100 < error && error < 100)
					intrg = 0;
				if(abs(intrg) <= mIV)
					intrg = mIV;
				power = error*mS - intrg;
				armRight(1, dir);
				armLeft(1-power, dir);
				}else if(checkValue < 0){
				error = (nMotorEncoder[right] - nMotorEncoder[left])/mEV;
				intrg += error * ((time1(T1) - lastTime) / mI);
				if(-100 < error && error < 100)
					intrg = 0;
				if(abs(intrg) <= mIV)
					intrg = mIV;
				power = error*mS - intrg;
				armLeft(1, dir);
				armRight(1-power, dir);
				}else {
				arm(1,dir,1);
			}
			lastTime = time1(T1);
			break;
		case DOWN:
			checkValue *= -1;
			if(checkValue > 0){
				error = (nMotorEncoder[left] - nMotorEncoder[right])/mEV;
				intrg += error * ((time1(T1) - lastTime) / mI);
				if(-100 < error && error < 100)
					intrg = 0;
				if(abs(intrg) <= mIV)
					intrg = mIV;
				power = error*mS - intrg;
				armRight(-1, dir);
				armLeft(-1-power, dir);
				}else if(checkValue < 0){
				error = (nMotorEncoder[right] - nMotorEncoder[left])/mEV;
				intrg += error * ((time1(T1) - lastTime) / mI);
				if(-100 < error && error < 100)
					intrg = 0;
				if(abs(intrg) <= mIV)
					intrg = mIV;
				power = error*mS - intrg;
				armLeft(-1, dir);
				armRight(-1-power, dir);
				}else {
				arm(-1,dir,1);
			}
			lastTime = time1(T1);
			break;
		}
	}

}





#endif
