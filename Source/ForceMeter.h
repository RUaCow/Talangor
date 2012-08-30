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
	const float colorChangeLength , colorChangeRate;
public:
	ForceMeter(float mcolorChangeLength);
	void drawForceVector(SDL_Surface *display, Vector2Df firstPoint , Vector2Df secondPoint);
};

#endif
