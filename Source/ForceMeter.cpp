#include "ForceMeter.h"
#include <SDL/SDL_gfxPrimitives.h>

#define PI 3.141592245225

ForceMeter::ForceMeter(float mcolorChangeLength) : colorChangeLength(mcolorChangeLength) , colorChangeRate(255.0f / mcolorChangeLength) , theta(PI/12)
{
	fillColorTable();
}

ForceMeter::~ForceMeter(void)
{
	for(int i = 0 ; i < 3 ; i++)
		delete[] colorTable[i];
	delete[] colorTable;
}

void ForceMeter::fillColorTable(void)
{
	colorTable = new float*[3];
	for(int i = 0 ; i < 3 ; i++)
		colorTable[i] = new float[4 * int(colorChangeLength + 0.5f)];
	float Red = 0.0f , Green = 255.0f , Blue = 0.0f;
	for(int i = 0 ; i < 4 * int(colorChangeLength + 0.5f) ; i++)
	{
		colorTable[0][i] = Red , colorTable[1][i] = Green , colorTable[2][i] = Blue;
		if(i >= 0 && i < colorChangeLength)
		{
			Green -= colorChangeRate;
		}
		else if(i >= colorChangeLength && i < 2 * colorChangeLength)
		{
			Green += colorChangeRate;
			Red += colorChangeRate;
		}
		else
		{
			Green > 0 ? Green -= colorChangeRate : Green = 0;
		}
	}

}

void ForceMeter::drawForceVector(SDL_Surface *display, Vector2Df firstPoint , Vector2Df secondPoint)
{
	//Input vector.
	Vector2Df mainVector = secondPoint - firstPoint;

	//Length of the input.
	float L = mainVector.getLength();

	//alpha : the angle of the input.
	float alpha = atan2f(mainVector.y() , mainVector.x());

	for(int l = 0 ; l <= L ; l++)
	{
		if(l <= 4 * colorChangeLength)
			arcRGBA(display, firstPoint.x() , firstPoint.y() , l , (alpha - theta) * 180 / PI , (alpha + theta) * 180 / PI , colorTable[0][l] , colorTable[1][l] , colorTable[2][l] , 255);
	}
}
