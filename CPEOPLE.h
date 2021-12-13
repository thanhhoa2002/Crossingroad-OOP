#pragma once

#include "CVEHICLE.h"
#include "CANIMAL.h"
#include "CONSTANT.h"

class CPEOPLE 
{
private:
	int mX, mY;
	bool mState; //Trạng thái sống chết
public:
	string peopleShape[3];
	CPEOPLE()
	{
		this->mX = 45;
		this->mY = 19;
		this->mState = true;

		peopleShape[0] = " O ";
		peopleShape[1] = "/|\\";
		peopleShape[2] = "/ \\";
	}

	int getX();
	int getY();
	bool getState();
	void setX(int);
	void setY(int);
	void setState(bool);

	void Up(int);
	void Left(int);
	void Right(int);
	void Down(int);

	bool isFinish();
	bool isDead();

	template<class T>
	bool isImpact(vector<T> vt, int maxLength)
	{
		for (int i = 0; i < maxLength; ++i)
			if (vt[i].isImpact(mX, mY))
			{
				mState = 0;
				return true;
			}
		return false;
	}
};


