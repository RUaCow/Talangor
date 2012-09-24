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

	Vector2Df convert(const Vector2Df &vector);
	Vector2Df C(const Vector2Df& vector);
	Vector2Df deconvert(const Vector2Df &vector);
	Vector2Df dC(const Vector2Df& vector);

}; // class Converter

#endif // _CONVERTER_H

