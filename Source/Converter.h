#ifndef _CONVERTER_H
#define _CONVERTER_H

#include "Vector2D.h"

class Converter {

	float xMin, xMax;
	float yMin, yMax;

	int width, height;

public:

	Converter(const float xmin, const float xmax, const float ymin, const float ymax, const int w, const int h);
	~Converter();

	Vector2df convert(const Vector2df &vector);
	Vector2df deconvert(const Vector2df &vector);

}; // class Converter

#endif // _CONVERTER_H

