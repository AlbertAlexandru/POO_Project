#pragma once

class Vector
{
public:
	float x;
	float y;

	Vector();
	Vector(float x, float y);

	Vector& Aduna(const Vector& v);
	Vector& Scade(const Vector& v);
	Vector& Inmulteste(const Vector& v);
	Vector& Imparte(const Vector& v);

	friend Vector& operator+(Vector& v1, const Vector& v2);
	friend Vector& operator-(Vector& v1, const Vector& v2);
	friend Vector& operator*(Vector& v1, const Vector& v2);
	friend Vector& operator/(Vector& v1, const Vector& v2);

	Vector& operator+=(const Vector& v);
	Vector& operator-=(const Vector& v);
	Vector& operator*=(const Vector& v);
	Vector& operator/=(const Vector& v);
};