#ifndef ARM_H
#define ARM_H

const int fullPower = 127;
void encArm(int x){														//you can set encoder values for the arm

	SensorValue[leftShaft] = x;
	SensorValue[rightShaft] = x;

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

bool checkArm(armDir dir, int armVal){
	switch(dir){

	case UP:
		if(abs(SensorValue[leftShaft]) < armVal &&
			abs(SensorValue[rightShaft])  < armVal)
		return false;
		break;

	case DOWN:
		if(abs(SensorValue[leftShaft]) < armVal &&
			abs(SensorValue[rightShaft]) < armVal)
		return false;
		break;
	}
	return true;
}

void arm(armDir dir){
	switch(dir){
	case UP:
		motor[botRight] = fullPower;
		motor[botLeft] =  fullPower;
		motor[midRight] =  fullPower;
		motor[midLeft] =  fullPower;
		motor[topRight] =  fullPower;
		motor[topLeft] =  fullPower;
		break;
	case DOWN:
		motor[botRight] = -fullPower;
		motor[botLeft] = -fullPower;
		motor[midRight] = -fullPower;
		motor[midLeft] = -fullPower;
		motor[topRight] = -fullPower;
		motor[topLeft] = -fullPower;
		break;
	}
}
void arm(armDir dir, int armVal){
	encArm(0);
	while(!checkArm(dir,armVal)){
		arm(dir);
	}
	stopArm();
	wait1Msec(100);
}
//PID

int power;
int error = 0;
int intrg = 0;		//integral
int mI = 1;			//integral multiplyer
int mS = 1;			//speed multiplyer
int mIV = 0;		//maximum integral value
int lastTime = 0;	//last integral check

void pidArm(armDir dir, int dist){

	//2 arm encoders
	lastTime = time1(T1);
	encArm(0);
	while(abs(SensorValue[leftShaft]) >= dist &&abs(SensorValue[rightShaft]) >= dist){
		int checkValue = abs(SensorValue[leftShaft]) - abs(SensorValue[rightShaft]); //initial error
		switch(dir){
		case UP:
			if(checkValue > 0){
				error = (SensorValue[leftShaft] - SensorValue[rightShaft]);
				intrg += error * ((time1(T1) - lastTime) / mI);
				if(-100 < error && error < 100){
					intrg = 0;
					if(abs(intrg) <= mIV)
						intrg = mIV;
					power = error*mS - intrg;
					armRight(1, dir);
					armLeft(1-power, dir);
					}else if(checkValue < 0){
					error = (abs(SensorValue[rightShaft]) - abs(SensorValue[leftShaft]));
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
					error = (abs(SensorValue[leftShaft]) - abs(SensorValue[rightShaft]));
					intrg += error * ((time1(T1) - lastTime) / mI);
					if(-100 < error && error < 100)
						intrg = 0;
					if(abs(intrg) <= mIV)
						intrg = mIV;
					power = error*mS - intrg;
					armRight(-1, dir);
					armLeft(-1-power, dir);
					}else if(checkValue < 0){
					error = (abs(SensorValue[rightShaft]) - abs(SensorValue[leftShaft]));
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
}




#endif
