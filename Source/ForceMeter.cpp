#include "ForceMeter.h"
#include <SDL/SDL_gfxPrimitives.h>

#define PI 3.141592245225

ForceMeter::ForceMeter(float mcolorChangeLength) : colorChangeLength(mcolorChangeLength) , colorChangeRate(255.0f / mcolorChangeLength) , theta(PI/12)
{

}

void ForceMeter::drawForceVector(SDL_Surface *display, Vector2Df firstPoint , Vector2Df secondPoint)
{
	//Input vector.
	Vector2Df mainVector = secondPoint - firstPoint;

	//Length of the input.
	float L = mainVector.getLength();

	//alpha : the angle of the input.
	float alpha = atan2f(mainVector.y() , mainVector.x());

	float Red = 0.0f , Green = 255.0f , Blue = 0.0f;
	for(int l = 0 ; l <= L ; l++)
	{
		arcRGBA(display, firstPoint.x() , firstPoint.y() , l , (alpha - theta) * 180 / PI , (alpha + theta) * 180 / PI , Red , Green , Blue , 255);
		//Setting color for the next arc to draw.
		if(l >= 0 && l < colorChangeLength)
		{
			Green -= colorChangeRate;
		}
		else if(l >= colorChangeLength && l < 2 * colorChangeLength)
		{
			Green += colorChangeRate;
			Red += colorChangeRate;
		}
		else
		{
			Green > 0 ? Green -= colorChangeRate : Green = 0;
		}
		//Just for fun!!
		//SDL_Flip(screen);
	}
}
