#include "Shape.h"



Shape::Shape(vector<Vector2Df> points , float mCOF) : COF(mCOF)
{
	this->points = points;
	centerCalc();
}

Shape::~Shape(void)
{
}

void Shape::centerCalc(void)
{
	Vector2Df tmp;
	for(int i = 0 ; i < (int)points.size() ; i++)
		tmp += points.at(i);
	tmp /= (int)points.size();
	center = tmp;
}

void Shape::addShape(vector<Vector2Df> spoints , float sCOF)
{
	shapes.push_back(Shape(spoints , sCOF));
}

Shape& Shape::operator=(Shape const& s){
	return (Shape&)s;
}
