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
	friend class Manager;
	//Ball's identity
	int number;
	//Ball's radius
	float radius;
	//Ball's mass
	float mass;
	//Ball's velocity
	Vector2Df velocity;

	//Added By Elk
	Vector2Df pos; //Ball's Position
	Vector2Df prePos; //Ball's previous stopped position
public:
	Ball(int mNumber , float mRadius , float mMass , Vector2Df mPos);
	const Vector2Df& getPos() const;
	const Vector2Df& getPrePos() const;
};

#endif //BALL_H
