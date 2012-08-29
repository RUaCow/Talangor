#include "ForceMeter.h"
#include <SDL/SDL_gfxPrimitives.h>

#define PI 3.141592245225

ForceMeter::ForceMeter(SDL_Surface* display , float mcolorChangeLength) : colorChangeLength(mcolorChangeLength) , colorChangeRate(255.0f / mcolorChangeLength)
{
	screen = display;
}

void ForceMeter::drawForceVector(Vector2Df firstPoint , Vector2Df secondPoint)
{
	//Input vector.
	Vector2Df mainVector = secondPoint - firstPoint;

	//Length of the input.
	float L = mainVector.getLength();

	//Unit vector of the force vector.
	Vector2Df unitFVector = mainVector.getNormalizedVector();

	//Unit vector of the prependicular vector to the unitFVector.
	Vector2Df unitPVector = unitFVector.getPrependicularVector();

	for(float theta = 0.0f ; theta < PI / 12 ; theta += 0.01)
	{
		float Red = 0.0f , Green = 255.0f , Blue = 0.0f;
		for(int l = 0 ; l <= L ; l++)
		{
			//Vector of the specific point to draw.
			Vector2Df pointVector = firstPoint + cosf(theta) * l * unitFVector + sinf(theta) * l * unitPVector;
			pixelRGBA(screen , pointVector.x() , pointVector.y() , Red , Green , Blue , 255);
			pointVector -= 2 * sinf(theta) * l * unitPVector;
			pixelRGBA(screen , pointVector.x() , pointVector.y() , Red , Green , Blue , 255);

			//Setting color for the next pixel to draw.
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
		}
		//Just for fun!!
		//SDL_Flip(screen);
	}
}
