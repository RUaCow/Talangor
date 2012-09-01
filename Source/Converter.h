#ifndef _CONVERTER_H
#define _CONVERTER_H

#include "Vector2D.h"

class Converter {

	const int xMin, xMax;
	const int yMin, yMax;

	const int width, height;

public:

	Converter(const int xmin, const int xmax, const int ymin, const int ymax, const int w, const int h);
	~Converter();

	Vector2df convert(const Vector2df &vector);

}; // class Converter

#endif // _CONVERTER_H

