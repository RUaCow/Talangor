/**************************************************************
	ball.h
	Author : Arman Maghoul	
	Purpose : Handling the balls.
	Date : 8 / 1 / 2012
**************************************************************/
#ifndef BALL_H
#define BALL_H

#include "Vector2D.h"

class Ball
{
	//Ball's identity
	int number;
	//Ball's radius
	int radius;
	//Ball's mass
	float mass;
	//Ball's velocity
	vector2Df velocity;

	//Added By Elk
	Vector2Df Pos; //Ball's Position
public:
	Ball(int mRadius , float mMass , Vector2Df mPos);
};

#endif //BALL_H
