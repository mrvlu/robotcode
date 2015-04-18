#ifndef INTAKECONTROL_H
#define INTAKECONTROL_H

void clawIntake(clawPos pos){
	switch(pos){
	case CLOSED:
		SensorValue[skyriseClaw] = 1;
		break;
	case OPEN:
		SensorValue[skyriseClaw] = 0;
		break;
	}
}


void cube(clawPos pos){
	switch(pos){
	case OPEN:
		SensorValue[cubeIntake] = 0;
		break;
	case CLOSED:
		SensorValue[cubeIntake] = 1;
		break;
	}
}



#endif
