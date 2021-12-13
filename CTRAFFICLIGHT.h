#pragma once
#include"CONSOLE.h"

class CTRAFFICLIGHT {
	bool light1;
	bool light2;
public:
	CTRAFFICLIGHT();

	bool getLight1();
	bool getLight2();
	void setLight1(bool);
	void setLight2(bool);
	
	bool changeLight1(int);
	bool changeLight2(int);

	void drawTL();
};