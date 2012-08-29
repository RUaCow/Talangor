/**************************************************************
	ForceMeter.h
	Author : Arman and co!
	Purpose : To draw a nice (!) force meter.
	Date : 8 / 29 / 2012
**************************************************************/
#ifndef FoRcEmEtEr_H
#define FoRcEmEtEr_H
#include "Vector2D.h"


struct SDL_Surface;

class ForceMeter
{
	SDL_Surface* screen;
	const float colorChangeLength , colorChangeRate;
public:
	ForceMeter(SDL_Surface* display , float mcolorChangeLength);
	void drawForceVector(Vector2Df firstPoint , Vector2Df secondPoint);
};

#endif