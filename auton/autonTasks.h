#ifndef AUTONTASKS_H
#define AUTONTASKS_H

//AUTONOMOUS FUNCTIONS
const int roVal = 870;
const int skyHgt = 10;


void skyriseAuto(sideOf colour){
	//starting point												//1000 does 90 degree turn on regular tiled floor
	arm(UP, skyHgt);
	clawIntake(OPEN);
	rotate(abs(LEFTTURN - colour), 450
	);
	arm(DOWN, skyHgt);

	//Move arm up and rotate at same time
	//void rotAndMove(int rotVal, moveDir dirX, int armVal, armDir dirY )
	for(int i = 0; i < 7; i++){
		clawIntake(CLOSED);																//close claw to pickup skyrise
		arm(UP,skyHgt);																		//raise skyrise piece out of holder
		rotAndMove(roVal,abs(RIGHTTURN - colour), 						//rotate towards skyrise
							skyHgt * i,UP);										      //raise to skyrise height
		arm(DOWN, skyHgt);																//moves arm down
		clawIntake(OPEN);																	//drops skyrise off
		arm(UP, skyHgt);																	//moves arm up

		rotate(abs(LEFTTURN - colour), roVal);
		arm(DOWN, skyHgt * (i + 1) + 1);
	}
}
	/*
	else if(i >= 4 ){
		if(i <= 4){
		clawIntake(CLOSED);																//close claw to pickup skyrise
		arm(UP,skyHgt);																		//raise skyrise piece out of holder
		rotAndMove(roVal + 15,abs(RIGHTTURN - colour), 						//rotate towards skyrise
							skyHgt * i,UP);										      //raise to skyrise height
		arm(DOWN, skyHgt + 1);																//moves arm down
		clawIntake(OPEN);																	//drops skyrise off
		arm(UP, skyHgt);																	//moves arm up

		rotate(abs(LEFTTURN - colour), roVal);
		arm(DOWN, skyHgt * (i + 1) + 1);
	}
	*/

void cubeAuto(sideOf colour){
	//driveAndMove(500, FORWARDS, 600, UP);	//sets arm in position pick up first cube and moves forward to pick up first cube
	arm(UP, 20);
	drive(FORWARDS, 500);
	arm(DOWN, 10); //needles into first cube
	//driveAndMove(200, FORWARDS, 600, UP);	 // moves to second cube sets arm in position for second cube
	arm(UP, 40);
	drive(FORWARDS, 500);
	rotate(abs(LEFTTURN - colour), roVal);//rotate to other cube
	drive(FORWARDS,  200);
	cube(OPEN);

	//drive();
	/*arm(DOWN, 600);//needles into first cube
	drive(FORWARDS, 700); // moves toward pole pushing cubes away
	rotate(abs(RIGHTTURN - colour), 1000);//rotate to other cube
	arm(UP, 1200);
	drive(FORWARDS, 700);
	//driveAndMove(700, FORWARDS, 1200, UP);//move up aligning to pole while setting arm to skyrise height
	*/
	//drive(FORWARDS, 300);
}

#endif
