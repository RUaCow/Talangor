#ifndef VECTOR2D_H
#define VECTOR2D_H

#include <cmath>

template <class T>

class Vector2D
{
	T x , y;
public:
	//constructors
	vector2D(T x , T y)
	{
		this->x = x;
		this->y = y;
	}

	vector2D(void)
	{
		x = 0;
		y = 0;
	}

	//getters
	//Get length of the vector.
	float getLength(void)
	{
		return sqrtf(x * x + y * y);
	}

	//Get normalized vector of this vector.
	vector2D getNormalizedVector(void)
	{
		vector2D res;
		if ( x == 0 && y == 0 )
		{
			res.x = 0;
			res.y = 0;
		}
		else
		{
			res.x = this->x / this->getLength();
			res.y = this->y / this->getLength();
		}
		return res;
	}

	//Get prependicular vector.
	vector2D getPrependicularVector(void)
	{
		return vector2D(-y , x);
	}
	
	//Get x component.
	T getX(void)
	{
		return x;
	}

	//Get y component.
	T getY(void)
	{
		return y;
	}

	//setters
	//Set x component.
	void setX(T in)
	{
		x = in;
	}

	//Set y component.
	void setY(T in)
	{
		y = in;
	}

	//OPERATORS
	//Dot product of two vectors.
	float operator *(vector2D in) 
	{
		return (this->x * in.x + this->y * in.y);
	}

	//Multipication of vector and scalar.
	vector2D operator *(float in)
	{
		return vector2D(this->x * in , this->y * in);
	}

	//Addition of two vectors.
	vector2D operator +(vector2D in)
	{
		return vector2D(this->x + in.x , this->y + in.y);
	}

	//Substraction of two vectors.
	vector2D operator -(vector2D in)
	{
		return vector2D(this->x - in.x , this->y - in.y);
	}
};//vector2D class.


//Type defines:
typedef Vector2D<int> vector2Di;
typedef Vector2D<float> vector2Df;


//Multipicationn of a scalar and a vector.
inline Vector2Df operator*(float scl , vector2Df in)
{
	return vector2Df(in.getX() * scl , in.getY() * scl);
}

#endif //VECTOR2D_H
