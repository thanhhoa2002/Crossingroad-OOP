#include "CVEHICLE.h"

int CVEHICLE::getX() 
{
	return this->mX;
}

int CVEHICLE::getY() 
{
	return this->mY;
}

void CVEHICLE::setX(int mX)
{
	this->mX = mX;
}

void CVEHICLE::setY(int mY)
{
	this->mY = mY;
}

void CVEHICLE::Move(int x, int y)
{
	this->mX += x;
	this->mY += y;
}

void CVEHICLE::setPos(int x, int y)
{
	this->setX(x);
	this->setY(y);
}

bool carImpact()
{
	if (!MUTED)
		PlaySound(TEXT("Sound\\Sound_Car.wav"), NULL, SND_ASYNC);
	Sleep(500);
	return true;
}

bool truckImpact()
{
	if (!MUTED)
		PlaySound(TEXT("Sound\\Sound_Car_1.wav"), NULL, SND_ASYNC);
	Sleep(500);
	return true;
}

bool CCAR::isImpact(int mX, int mY) 
{
	if (mY == this->getY() - 2)
	{
		if (mX == this->getX() + 9 || mX == this->getX() + 11)
			return carImpact();
	}

	else if (mY == this->getY() - 1)
	{
		if (mX >= this->getX() && mX <= this->getX() + 26)
			return carImpact();
	}

	else if (mY == this->getY())
	{
		if (mX >= this->getX() - 1 && mX <= this->getX() + 27)
			return carImpact();
	}

	else if (mY == this->getY() + 1)
	{
		if (mX >= this->getX() - 2 && mX <= this->getX() + 28)
			return carImpact();
	}

	else if (mY == this->getY() + 2)
	{
		if (mX >= this->getX() - 2 && mX <= this->getX() + 28)
			return carImpact();
	}

	else if (mY == this->getY() + 3)
	{
		if (mX >= this->getX() - 1 && mX <= this->getX() + 27)
			return carImpact();
	}

	else if (mY == this->getY() + 4)
	{
		if ((mX >= this->getX() + 3 && mX <= this->getX() + 6) || (mX >= this->getX() + 20 && mX <= this->getX() + 23))
			return carImpact();
	}

	return false;
}

bool CTRUCK::isImpact(int mX, int mY)
{
	if (mY == this->getY() - 2)
	{
		if (mX >= this->getX() + 1 && mX <= this->getX() + 26)
			return truckImpact();
	}

	else if (mY == this->getY() - 1)
	{
		if (mX >= this->getX() && mX <= this->getX() + 26)
			return truckImpact();
	}

	else if (mY == this->getY())
	{
		if (mX >= this->getX() - 1 && mX <= this->getX() + 26)
			return truckImpact();
	}

	else if (mY == this->getY() + 1)
	{
		if (mX >= this->getX() - 2 && mX <= this->getX() + 26)
			return truckImpact();
	}

	else if (mY == this->getY() + 2)
	{
		if (mX >= this->getX() - 2 && mX <= this->getX() + 26)
			return truckImpact();
	}

	else if (mY == this->getY() + 3)
	{
		if (mX >= this->getX() - 2 && mX <= this->getX() + 26)
			return truckImpact();
	}

	else if (mY == this->getY() + 4)
	{
		if (mX >= this->getX() - 1 && mX <= this->getX() + 25)
			return truckImpact();
	}

	return false;
}