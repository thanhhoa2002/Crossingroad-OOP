#include "CPEOPLE.h"

int CPEOPLE::getX() 
{
	return this->mX;
}

int CPEOPLE::getY() 
{
	return this->mY;
}

bool CPEOPLE::getState() 
{
	return this->mState;
}

void CPEOPLE::setX(int mX) 
{
	this->mX = mX;
}

void CPEOPLE::setY(int mY)
{
	this->mY = mY;
}

void CPEOPLE::setState(bool mState)
{
	this->mState = mState;
}

void CPEOPLE::Up(int step)
{
	if (this->mY > 1)
	{
		this->mY -= step;
	}
}

void CPEOPLE::Left(int step)
{
	if (this->mX > 1) 
	{
		this->mX -= step;
	}
}

void CPEOPLE::Right(int step)
{
	if (this->mX < WIDTH_CONSOLE - 3) 
	{
		this->mX += step;
	}
}

void CPEOPLE::Down(int step)
{
	if (this->mY < HEIGH_CONSOLE - 3) 
	{
		this->mY += step;
	}
}

bool CPEOPLE::isFinish() 
{
	if (this->mY == mYFinish) 
	{
		return true;
	}
	return false;
}

bool CPEOPLE::isDead() 
{
	if (this->mState == false) 
	{
		return true;
	}
	return false;
}