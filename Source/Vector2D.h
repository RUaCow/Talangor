#ifndef VeCtOr2D_h
#define VeCtOr2D_h

#include <cmath>
#include <iostream>
using namespace std;
template <class T>

class Vector2D
{
	T mx , my;
public:
	//constructors
	Vector2D(T mx , T my)
	{
		this->mx = mx;
		this->my = my;
	}

	Vector2D(void)
	{
		mx = 0;
		my = 0;
	}

	//getters
	//Get length of the vector.
	float getLength(void)
	{
		return sqrtf(mx * mx + my * my);
	}

	//Get normalized vector of this vector.
	Vector2D getNormalizedVector(void)
	{
		Vector2D res;
		if ( mx == 0 && my == 0 )
		{
			res.mx = 0;
			res.my = 0;
		}
		else
		{
			res.mx = this->mx / this->getLength();
			res.my = this->my / this->getLength();
		}
		return res;
	}

	//Get prependicular vector.
	Vector2D getPrependicularVector(void)
	{
		return Vector2D(-my , mx);
	}
	T& x(){
		return mx;
	}
	const T& x() const {
		return mx;
	}
	T& y(){
		return my;
	}
	const T& y() const {
		return my;
	}
	//Get mx component.
	T getX(void)
	{
		return mx;
	}

	//Get my component.
	T getY(void)
	{
		return my;
	}

	//setters
	//Set mx component.
	void setX(T in)
	{
		mx = in;
	}

	//Set my component.
	void setY(T in)
	{
		my = in;
	}

	//OPERATORS
	//Dot product of two vectors.
	float operator *(Vector2D in) 
	{
		return (this->mx * in.mx + this->my * in.my);
	}

	//Multipication of vector and scalar.
	Vector2D operator *(float in)
	{
		return Vector2D(this->mx * in , this->my * in);
	}

	//Division of vector and scalar.
	Vector2D operator /(float in)
	{
		return Vector2D(this->mx / in , this->my / in);
	}

	//Addition of two vectors.
	Vector2D operator +(Vector2D in)
	{
		return Vector2D(this->mx + in.mx , this->my + in.my);
	}

	//Substraction of two vectors.
	Vector2D operator -(Vector2D in)
	{
		return Vector2D(this->mx - in.mx , this->my - in.my);
	}

	//-=
	void operator -=(Vector2D in)
	{
		*this = *this - in;
	}
	//+=
	void operator +=(Vector2D in)
	{
		*this = *this + in;
	}
	//*=
	void operator *=(float in)
	{
		*this = *this * in;
	}
	// /=
	void operator /=(float in)
	{
		*this = *this / in;
	}
	template <class C>
	friend ostream& operator<<(ostream& in , const Vector2D<C>& a);
};//Vector2D class.

//Tmype defines:
typedef Vector2D<int> Vector2Di;
typedef Vector2D<float> Vector2Df;

typedef Vector2Di Vector2di;
typedef Vector2Df Vector2df;

//Multipicationn of a scalar and a vector.
inline Vector2Df operator*(float scl , Vector2Df in)
{
	return in * scl;
}

//Determinant of a vector.
inline float determinant(Vector2Df in1 , Vector2Df in2)
{
	return(in1.x() * in2.y() - in1.y() * in2.x());
}

template <class C>
ostream& operator<<(ostream& in , const Vector2D<C>& a)
{
		in << a.mx << " " << a.my;
		return in;
}

#endif //VECTOR2D_H
