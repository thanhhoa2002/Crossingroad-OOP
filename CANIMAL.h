#pragma once

#include "CONSOLE.h"

class CANIMAL
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

class CDINO : public CANIMAL
{
public:
	string shape[5];
	CDINO() {
		shape[0] = "              __ ";
		shape[1] = "             / _)";
		shape[2] = "     _.----./ /  ";
		shape[3] = " __/ (  | (  |   ";
		shape[4] = "/__.-'|_|--|_|   ";
	}
	bool isImpact(int, int);
};

class CBIRD : public CANIMAL
{
public:
	string shape[5];
	CBIRD() {
		shape[0] = "    __  ";
		shape[1] = "___( o)>";
		shape[2] = "\\ <_. ) ";
		shape[3] = " `---'  ";
		shape[4] = " ^   ^  ";
	}
	bool isImpact(int, int);
};

