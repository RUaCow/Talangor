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
	//theta : the angle of the arc of the force meter.
	float theta;
	//color table
	float** colorTable;

	//This will fill the color table.
	void fillColorTable(void);
public:
	//constructor
	ForceMeter(float mcolorChangeLength);
	//destructor
	~ForceMeter(void);
	//Draw force vector.
	void drawForceVector(SDL_Surface *display, Vector2Df firstPoint , Vector2Df secondPoint);
};

#endif
