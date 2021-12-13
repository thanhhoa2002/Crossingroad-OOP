#include "CTRAFFICLIGHT.h"

CTRAFFICLIGHT::CTRAFFICLIGHT()
{
	light1 = true;
	light2 = true;
}

bool CTRAFFICLIGHT::getLight1()
{
	return light1;
}

bool CTRAFFICLIGHT::getLight2()
{
	return light2;
}

void CTRAFFICLIGHT::setLight1(bool light)
{
	light1 = light;
}

void CTRAFFICLIGHT::setLight2(bool light)
{
	light2 = light;
}

bool CTRAFFICLIGHT::changeLight1(int count1)
{
	if (count1 % GO_VALUE_1 == 0 && light1 == true)
	{
		light1 = false;
		return true;
	}
	if (count1 % STOP_VALUE_1 == 0 && light1 == false)
	{
		light1 = true;
		return true;
	}
	return false;
}

bool CTRAFFICLIGHT::changeLight2(int count2)
{
	if (count2 % GO_VALUE_2 == 0 && light2 == true)
	{
		light2 = false;
		return true;
	}
	if (count2 % STOP_VALUE_2 == 0 && light2 == false)
	{
		light2 = true;
		return true;
	}
	return false;
}

void CTRAFFICLIGHT::drawTL()
{
	if (light1 == true)
	{
		// add green light
		GotoXY(1, 3);
		GREEN_LIGHT;
		cout << "  ";
		NORMAL;
	}
	else
	{	
		// add red light
		GotoXY(1, 3);
		RED_LIGHT;
		cout << "  ";
		NORMAL;
	}

	if (light2 == true)
	{
		// add green light
		GotoXY(1, 19);
		GREEN_LIGHT;
		cout << "  ";
		NORMAL;
	}
	else
	{
		// add red light
		GotoXY(1, 19);
		RED_LIGHT;
		cout << "  ";
		NORMAL;
	}
}