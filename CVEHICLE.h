#pragma once

#include "CONSOLE.h"

class CVEHICLE
{
private:
	int mX, mY;
public:
	int getX();
	int getY();
	void setX(int);
	void setY(int);
	void Move(int x, int y);
	void setPos(int, int);
};

class CTRUCK : public CVEHICLE
{
public:
	string shape[5];
	CTRUCK() {
		shape[0] = "   _______________________ ";
		shape[1] = "  /  | |    |    |    |   |";
		shape[2] = " /___|_|____|____|____|___|";
		shape[3] = "/    | |                  |";
		shape[4] = "'--(o)------------(o)(o)--'";
	}

	bool isImpact(int, int);
};

class CCAR : public CVEHICLE
{
public:
	string shape[5];
	CCAR() {
		shape[0] = "           /               ";
		shape[1] = "  ________<_\\______________  ";
		shape[2] = " /  ____  |     <> / ____  \\ ";
		shape[3] = "O__/ __ \\_|_______/_/ __ \\_/=";
		shape[4] = "    (__)             (__)  ";
	}
	bool isImpact(int, int);
};

class CPLANE : public CVEHICLE
{
public:
	string shape[8];
	CPLANE() {
		shape[0] = "            ______                                          ";
		shape[1] = "            _\\ _~-\\___        O                             ";
		shape[2] = "    =  = ==(____AA____D      /|\\                           ";
		shape[3] = "                \\_____\\______/_\\__________,-~~~~~~~`-.._    ";
		shape[4] = "                /     o O o - L O S E - G A M E o O o  |\\_  ";
		shape[5] = "                `~-.__        ___..----..                  )";
		shape[6] = "                      `---~~\\___________/------------`````  ";
		shape[7] = "                      =  ===(_________D                     ";
	}
};