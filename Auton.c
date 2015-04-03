#pragma config(UART_Usage, UART1, uartVEXLCD, baudRate19200, IOPins, None, None)
#pragma config(UART_Usage, UART2, uartNotUsed, baudRate4800, IOPins, None, None)
#pragma config(I2C_Usage, I2C1, i2cSensors)
#pragma config(Sensor, in1,    leftPot,        sensorPotentiometer)
#pragma config(Sensor, in2,    rightPot,       sensorPotentiometer)
#pragma config(Sensor, in5,    autoSelect,     sensorPotentiometer)
#pragma config(Sensor, dgtl1,  cubeIntake,     sensorDigitalOut)
#pragma config(Sensor, dgtl2,  skyriseClaw,    sensorDigitalOut)
#pragma config(Sensor, dgtl3,  skyriseArm,     sensorDigitalOut)
#pragma config(Sensor, I2C_1,  ,               sensorQuadEncoderOnI2CPort,    , AutoAssign)
#pragma config(Sensor, I2C_2,  ,               sensorQuadEncoderOnI2CPort,    , AutoAssign)
#pragma config(Sensor, I2C_3,  ,               sensorQuadEncoderOnI2CPort,    , AutoAssign)
#pragma config(Sensor, I2C_4,  ,               sensorQuadEncoderOnI2CPort,    , AutoAssign)
#pragma config(Motor,  port1,           botLeft,       tmotorVex393_HBridge, openLoop)
#pragma config(Motor,  port2,           midLeft,       tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port3,           midRight,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           topLeft,       tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port5,           topRight,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           backLeft,      tmotorVex393_MC29, openLoop, reversed, encoderPort, I2C_1)
#pragma config(Motor,  port7,           frontLeft,     tmotorVex393_MC29, openLoop, reversed, encoderPort, I2C_2)
#pragma config(Motor,  port8,           frontRight,    tmotorVex393_MC29, openLoop, encoderPort, I2C_3)
#pragma config(Motor,  port9,           backRight,     tmotorVex393_MC29, openLoop, encoderPort, I2C_4)
#pragma config(Motor,  port10,          botRight,      tmotorVex393_HBridge, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

const int fullPower = 127;

typedef enum {
  FORWARDS,
  RIGHT,
  BACKWARDS,
  LEFT
} moveDir;

typedef enum {
  UP,
  DOWN
} armDir;

typedef enum {
  CLOSED,
  OPEN
} clawPos;

typedef enum {
CLOSED,
OPEN
} skyClaw;

typedef enum{
CLOSED,
OPEN
}skyArm;

void drive(int power, moveDir dir){
  switch(dir){
    case FORWARDS:
      motor[frontRight] = fullPower * power;
    	motor[backRight] = fullPower * power;
    	motor[backLeft] = fullPower * power;
	    motor[frontLeft] = fullPower * power;
    break;
    case RIGHT:
      motor[frontRight] = -fullPower * power;
    	motor[backRight] = fullPower * power;
    	motor[backLeft] = -fullPower * power;
	    motor[frontLeft] = fullPower * power;
    break;
    case BACKWARDS:
      motor[frontRight] =  fullPower * power;
    	motor[backRight] = fullPower * power;
    	motor[backLeft] = fullPower * power;
	    motor[frontLeft] = fullPower * power;
    break;
    case LEFT:
      motor[frontRight] = fullPower * power;
    	motor[backRight] = -fullPower * power;
    	motor[backLeft] = fullPower * power;
	    motor[frontLeft] = -fullPower * power;
    break;
  }
}

void arm(int power, armDir dir){
  switch(dir){
    case UP:
      motor[botRight] = fullPower * power;
	  	motor[botLeft] = fullPower * power;
		motor[midRight] = fullPower * power;
		motor[midLeft] = fullPower * power;
	  	motor[topRight] = fullPower * power;
	  	motor[topLeft] = fullPower * power;
    break;
    case DOWN:
      motor[botRight] = -fullPower * power;
	  	motor[botLeft] = -fullPower * power;
	  	motor[midRight] = -fullPower * power;
  		motor[midLeft] = -fullPower * power;
  		motor[topRight] = -fullPower * power;
  		motor[topLeft] = -fullPower * power;
    break;
  }
}

void armControl(clawPos pos) {
SensorValue[cubeIntake] = pos; //OPEN OR CLOSE
}

void skyriseClawControl(skyClaw pos){
	SensorValue[skyriseClaw] = pos;
}
void skyriseArmControl(skyArm pos){
	SensorValue[skyriseArm] = pos;
}

void rotate(int power, moveDir dir){ 
	switch(dir){
	case LEFT:
	motor[frontRight] = fullPower;
    	motor[backRight] = fullPower;
    	motor[backLeft] = -fullPower;
	motor[frontLeft] = -fullPower;
	    break;
	case RIGHT:
	motor[frontRight] = -fullPower;
    	motor[backRight] = -fullPower;
    	motor[backLeft] = fullPower;
	motor[frontLeft] = fullPower;
	    break;
	}

}

void encoderDrive(int x){
nMotorEncoder[frontRight] = x;
nMotorEncoder[backRight] = x;
nMotorEncoder[backLeft] = x;
nMotorEncoder[frontLeft] = x;
	    }
void encoderArm(){
	//2 arm encoders
}




task main(){

while(encoderDrive(0) < 500){
drive(1,FORWARDS);
}

}
