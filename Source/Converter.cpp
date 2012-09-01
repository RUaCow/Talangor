#include "Converter.h"

Converter::Converter(const int xmin, const int xmax, const int ymin, const int ymax, const int w, const int h)
	: xMin(xmin), xMax(xmax), yMin(ymin), yMax(yMax), width(w), height(h) { }

Converter::~Converter() { }

Vector2df Converter::convert(const Vector2df &vector) {
	cout << "Called!" << endl;
	cerr << yMax << endl;

	return Vector2df(
		/* X */				 (width * (vector.x() - xMin)) / (xMax - xMin),
		/* Y */		height - (height * (vector.y() - yMin)) / (yMax - yMin)
		);
}

