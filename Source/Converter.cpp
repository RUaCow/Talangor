#include "Converter.h"

Converter::Converter(const float xmin, const float xmax, const float ymin, const float ymax, const int w, const int h) {
	xMin = xmin;
	xMax = xmax;

	yMin = ymin;
	yMax = ymax;

	width = w;
	height = h;
}

Converter::~Converter() { }

Vector2df Converter::convert(const Vector2df &vector) {
	return Vector2df(
		/* X */				 (width * (vector.x() - xMin)) / (xMax - xMin),
		/* Y */		height - (height * (vector.y() - yMin)) / (yMax - yMin)
		);
}

Vector2df Converter::deconvert(const Vector2df &vector) {
	return Vector2df(
		/* X */	 			   (vector.x() * (xMax - xMin)) / width + xMin,
					((height - vector.y()) * (yMax - yMin)) / height + yMin
		/* Y */
		);
}

