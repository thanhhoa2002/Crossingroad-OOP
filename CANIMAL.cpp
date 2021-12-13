#include "CANIMAL.h"

int CANIMAL::getX()
{
	return this->mX;
}

int CANIMAL::getY()
{
	return this->mY;
}

void CANIMAL::setX(int mX)
{
	this->mX = mX;
}

void CANIMAL::setY(int mY)
{
	this->mY = mY;
}

void CANIMAL::Move(int x, int y)
{
	this->mX += x;
	this->mY += y;
}

void CANIMAL::setPos(int x, int y)
{
	this->setX(x);
	this->setY(y);
}

bool dinoImpact()
{
	if (!MUTED)
		PlaySound(TEXT("Sound\\Sound_Dino.wav"), NULL, SND_ASYNC);
	Sleep(2000);
	return true;
}

bool birdImpact()
{
	if (!MUTED)
		PlaySound(TEXT("Sound\\Sound_Bird.wav"), NULL, SND_ASYNC);
	Sleep(300);
	return true;
}

bool CDINO::isImpact(int mX, int mY)
{
	if (mY == this->getY() - 2)
	{
		if (mX >= this->getX() + 12 && mX <= this->getX() + 15)
			return dinoImpact();
	}

	else if (mY == this->getY() - 1)
	{
		if (mX >= this->getX() + 11 && mX <= this->getX() + 16)
			return dinoImpact();
	}

	else if (mY == this->getY())
	{
		if (mX >= this->getX() + 3 && mX <= this->getX() + 16)
			return dinoImpact();
	}

	else if (mY == this->getY() + 1)
	{
		if (mX >= this->getX() - 1 && mX <= this->getX() + 15)
			return dinoImpact();
	}

	else if (mY == this->getY() + 2)
	{
		if (mX >= this->getX() - 2 && mX <= this->getX() + 13)
			return dinoImpact();
	}

	else if (mY == this->getY() + 3)
	{
		if (mX >= this->getX() - 2 && mX <= this->getX() + 13)
			return dinoImpact();
	}

	else if (mY == this->getY() + 4)
	{
		if (mX >= this->getX() - 1 && mX <= this->getX() + 12)
			return dinoImpact();
	}

	return false;
}

bool CBIRD::isImpact(int mX, int mY)
{
	if (mY == this->getY() - 2)
	{
		if (mX >= this->getX() + 2 && mX <= this->getX() + 5)
			return birdImpact();
	}

	else if (mY == this->getY() - 1)
	{
		if (mX >= this->getX() - 2 && mX <= this->getX() + 7)
			return birdImpact();
	}

	else if (mY == this->getY())
	{
		if (mX >= this->getX() - 2 && mX <= this->getX() + 7)
			return birdImpact();
	}

	else if (mY == this->getY() + 1)
	{
		if (mX >= this->getX() - 2 && mX <= this->getX() + 6)
			return birdImpact();
	}

	else if (mY == this->getY() + 2)
	{
		if (mX >= this->getX() - 1 && mX <= this->getX() + 5)
			return birdImpact();
	}

	else if (mY == this->getY() + 3)
	{
		if (mX >= this->getX() - 1 && mX <= this->getX() + 5)
			return birdImpact();
	}

	else if (mY == this->getY() + 4)
	{
		if (mX == this->getX() || mX == this->getX() + 4)
			return birdImpact();
	}

	return false;
}