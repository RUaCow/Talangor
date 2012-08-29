#include "Ball.h"


Ball::Ball(int mNumber , float mRadius , float mMass , Vector2Df mPos)
{
	this->number = mNumber;
	this->mass = mMass;
	this->radius = mRadius;
	this->pos = mPos;
	this->prePos = mPos;
}

const Vector2Df& Ball::getPos() const{
	return pos;
}

const Vector2Df& Ball::getPrePos() const{
	return prePos;
}
