#ifndef AUTOSELECTOR_H
#define AUTOSELECTOR_H

void autonomousSelector(int a, int b, int c, int d, int e) {
	string mainBattery, backupBattery;
	if (SensorValue[autoSelect] >= a && SensorValue[autoSelect] <= b) {
		//Clear LCD
		clearLCDLine(0);

		//Display the Primary Robot battery voltage
		displayLCDString(0, 0, "Primary: ");
		sprintf(mainBattery, "%1.2f%c", nImmediateBatteryLevel/1000.0,'V'); //Build the value to be displayed
		displayNextLCDString(mainBattery);

		//Display the Backup battery voltage
		displayLCDString(1, 0, "Backup: ");
		sprintf(backupBattery, "%1.2f%c", BackupBatteryLevel/1000.0, 'V');    //Build the value to be displayed
		displayNextLCDString(backupBattery);
	}
	//Display and select autonomous mode 1
	else if (SensorValue[autoSelect] > b && SensorValue[autoSelect] <= c) {
		clearLCDLine(0);
		clearLCDLine(1);
		displayLCDString(0, 0, "Autonomous Mode:");
		displayLCDString(1, 7, "1");
	}
	//Display and select autonomous mode 2
	else if (SensorValue[autoSelect] > c && SensorValue[autoSelect] <= d) {
		clearLCDLine(0);
		clearLCDLine(1);
		displayLCDString(0, 0, "Autonomous Mode:");
		displayLCDString(1, 7, "2");
	}
	//Display and select autonomous mode 3
	else if (SensorValue[autoSelect] > d && SensorValue[autoSelect] <= e) {
		clearLCDLine(0);
		clearLCDLine(1);
		displayLCDString(0, 0, "Autonomous Mode:");
		displayLCDString(1, 7, "3");
	}
	//Display and select autonomous mode 4
	else if (SensorValue[autoSelect] > e) {
		clearLCDLine(0);
		clearLCDLine(1);
		displayLCDString(0, 0, "Autonomous Mode:");
		displayLCDString(1, 7, "4");
	}
	//Short delay for the LCD refresh rate
	wait1Msec(100);
}

#endif
