#ifndef AUTOSWITCHER_H
#define AUTOSWITCHER_H
void autonSwitch(int a, int b, int c, int d, int e){

		if(SensorValue[autoSelect] > a && SensorValue[autoSelect] < b){
		clearLCDLine(0);
		clearLCDLine(1);
		displayLCDString(0, 0, "SKYRISE RED");
		displayLCDString(1, 7, "1");
		skyriseAuto(RED);
	}
	else if(SensorValue[autoSelect] > b && SensorValue[autoSelect] < c){
		clearLCDLine(0);
		clearLCDLine(1);
		displayLCDString(0, 0, "SKYRISE BLUE");
		displayLCDString(1, 7, "1");
		skyriseAuto(BLUE);
	}
	else if(SensorValue[autoSelect] > c && SensorValue[autoSelect] < d){
		clearLCDLine(0);
		clearLCDLine(1);
		displayLCDString(0, 0, "CUBE RED");
		displayLCDString(1, 7, "2");
		cubeAuto(RED);
	}
	else if(SensorValue[autoSelect] > d && SensorValue[autoSelect] < e){
		clearLCDLine(0);
		clearLCDLine(1);
		displayLCDString(0, 0, "CUBE BLUE");
		displayLCDString(1, 7, "4");
		cubeAuto(BLUE);
	}
}


#endif
