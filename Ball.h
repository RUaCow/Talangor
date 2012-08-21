/**************************************************************
	Ball.h
	Author : Arman Maghoul	
	Purpose : Handling the balls.
	Date : 8 / 1 / 2012
**************************************************************/
#ifndef BaLl_H
#define BaLl_H

#include "Vector2D.h"

class Ball
{
	friend class WorldModel;
	friend class GUI;
	//Ball's identity
	int number;
	//Ball's radius
	int radius;
	//Ball's mass
	float mass;
	//Ball's velocity
	Vector2Df velocity;

	//Added By Elk
	Vector2Df pos; //Ball's Position
public:
	Ball(int mNumber , int mRadius , float mMass , Vector2Df mPos);
};

#endif //BALL_H
