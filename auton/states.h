#ifndef STATES_H
#define STATES_H

enum clawPos {
	CLOSED,
	OPEN
};

enum dirArmRot{
	UPFORWARD,
	UPBACKWARD,
	UPLEFT,
	UPRIGHT,
	DOWNFORWARD,
	DOWNBACKWARD,
	DOWNLEFT,
	DOWNRIGHT
};


enum moveDir{
	RIGHT,
	LEFT,
	BACKWARDS,
	FORWARDS
};

enum armDir {
	UP,
	DOWN
};


enum sideOf{
	BLUE,
	RED
};

enum rotDir{
	RIGHTTURN,
	LEFTTURN
};

#endif
