#include "Shape.h"



Shape::Shape(int num , vector<Vector2Df> points , float mCOF) : COF(mCOF) , points(points) , n(num)
{
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
	shapes.push_back(Shape((int)shapes.size() , spoints , sCOF));
}

const vector<Vector2Df> Shape::getPoints(void) const
{
	return points;
}

const vector<Shape> Shape::getInsideShapes(void) const
{
	return shapes;
}

Shape& Shape::operator=(Shape const& s){
	return (Shape&)s;
}
