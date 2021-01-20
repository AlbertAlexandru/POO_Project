#include "Vector.h"

Vector::Vector()
{
	x = 0.0f;
	y = 0.0f;
}
Vector::Vector(float x, float y)
{
	this->x = x;
	this->y = y;
}

Vector& Vector::Aduna(const Vector& v)
{
	this-> x += v.x;
	this->y += v.y;

	return *this;
}
Vector& Vector::Scade(const Vector& v)
{
	this->x -= v.x;
	this->y -= v.y;

	return *this;
}
Vector& Vector::Inmulteste(const Vector& v)
{
	this->x *= v.x;
	this->y *= v.y;

	return *this;
}
Vector& Vector::Imparte(const Vector& v)
{
	this->x /= v.x;
	this->y /= v.y;

	return *this;
}

Vector& operator+(Vector& v1, const Vector& v2)
{
	return v1.Aduna(v2);
}
Vector& operator-(Vector& v1, const Vector& v2)
{
	return v1.Scade(v2);
}
Vector& operator*(Vector& v1, const Vector& v2)
{
	return v1.Inmulteste(v2);
}
Vector& operator/(Vector& v1, const Vector& v2)
{
	return v1.Imparte(v2);
}

Vector& Vector::operator+=(const Vector& v)
{
	return this->Aduna(v);
}

Vector& Vector::operator-=(const Vector& v)
{
	return this->Scade(v);
}
Vector& Vector::operator*=(const Vector& v)
{
	return this->Inmulteste(v);
}
Vector& Vector::operator/=(const Vector& v)
{
	return this->Imparte(v);
}