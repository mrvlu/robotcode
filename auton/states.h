#ifndef STATES_H
#define STATES_H

enum moveDir {		//sets direction
	RIGHT = 0,
	LEFT = 1,
	FORWARDS = 2,
	BACKWARDS = 3
};

enum armDir {		//direction of arm
	UP,
	DOWN
};

enum clawPos {		//intake state
	CLOSED,
	OPEN
};
enum sideOf{
	BLUE = 0,
	RED = 1,
}
#endif
