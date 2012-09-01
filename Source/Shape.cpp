#include "Shape.h"



Shape::Shape(vector<Vector2Df> points , float mCOF) : COF(mCOF)
{
	*this->points = points;
	shapes = new vector<Shape>;
	centerCalc();
}

Shape::~Shape(void)
{
	delete(points);
	delete(shapes);
}

void Shape::centerCalc(void)
{
	Vector2Df tmp;
	for(int i = 0 ; i < (int)points->size() ; i++)
		tmp += points->at(i);
	tmp /= (int)points->size();
	center = tmp;
}

void Shape::addShape(vector<Vector2Df> spoints , float sCOF)
{
	shapes->push_back(Shape(spoints , sCOF));
}

//I don't know why :D. But it had error: "Source/Shape.h:7:7: error: non-static const member ‘const float Shape::COF’, can’t use default assignment operator"
Shape& Shape::operator=(Shape const& s){
	return (Shape&)s;
}
