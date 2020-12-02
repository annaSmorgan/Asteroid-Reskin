#include "Vector2D.h"

#include <cmath>

Vector2D::Vector2D()
{
	m_coordinates[0] = 0.f;
	m_coordinates[1] = 0.f;
}

Vector2D::Vector2D(float a_x, float a_y)
{
	m_coordinates[0] = a_x;
	m_coordinates[1] = a_y;
}

Vector2D::Vector2D(Vector2D& a_other)
{
	m_coordinates[0] = a_other.m_coordinates[0];
	m_coordinates[1] = a_other.m_coordinates[1];
}
const float Vector2D::operator[](const int a_i) const
{
	return m_coordinates[a_i];
}

const Vector2D Vector2D::operator*(const float a_other) const
{
	Vector2D newVec;
	newVec.m_coordinates[0] = m_coordinates[0] * a_other;
	newVec.m_coordinates[1] = m_coordinates[1] * a_other;
	return newVec;
}

void Vector2D::operator*=(const float a_other)
{
	m_coordinates[0] = m_coordinates[0] *= a_other;
	m_coordinates[1] = m_coordinates[1] *= a_other;
}

const Vector2D Vector2D::operator*(const Vector2D& a_other) const
{
	Vector2D newVec;
	newVec.m_coordinates[0] = m_coordinates[0] * a_other.m_coordinates[0];
	newVec.m_coordinates[1] = m_coordinates[1] * a_other.m_coordinates[1];
	return newVec;
}

void Vector2D::operator*=(const Vector2D& a_other)
{
	m_coordinates[0] = m_coordinates[0] *= a_other.m_coordinates[0];
	m_coordinates[1] = m_coordinates[1] *= a_other.m_coordinates[1];
}

const Vector2D Vector2D::operator/(const Vector2D& a_other) const
{
	Vector2D newVec;
	newVec.m_coordinates[0] = m_coordinates[0] / a_other.m_coordinates[0];
	newVec.m_coordinates[1] = m_coordinates[1] / a_other.m_coordinates[1];
	return newVec;
}

void Vector2D::operator/=(const Vector2D& a_other)
{
	m_coordinates[0] = m_coordinates[0] /= a_other.m_coordinates[0];
	m_coordinates[1] = m_coordinates[1] /= a_other.m_coordinates[1];
}

const Vector2D Vector2D::operator/(const float a_other) const
{
	Vector2D newVec;
	newVec.m_coordinates[0] = m_coordinates[0] / a_other;
	newVec.m_coordinates[1] = m_coordinates[1] / a_other;
	return newVec;
}

void Vector2D::operator/=(const float a_other)
{
	m_coordinates[0] = m_coordinates[0] /= a_other;
	m_coordinates[1] = m_coordinates[1] /= a_other;
}

const Vector2D Vector2D::operator+(const Vector2D& a_other) const
{
	Vector2D newVec;
	newVec.m_coordinates[0] = m_coordinates[0] + a_other.m_coordinates[0];
	newVec.m_coordinates[1] = m_coordinates[1] + a_other.m_coordinates[1];
	return newVec;
}

void Vector2D::operator+=(const Vector2D& a_other)
{
	m_coordinates[0] = m_coordinates[0] += a_other.m_coordinates[0];
	m_coordinates[1] = m_coordinates[1] += a_other.m_coordinates[1];
}

const Vector2D Vector2D::operator-(const Vector2D& a_other) const
{
	Vector2D newVec;
	newVec.m_coordinates[0] = m_coordinates[0] - a_other.m_coordinates[0];
	newVec.m_coordinates[1] = m_coordinates[1] - a_other.m_coordinates[1];
	return newVec;
}

void Vector2D::operator-=(const Vector2D& a_other)
{
	m_coordinates[0] = m_coordinates[0] -= a_other.m_coordinates[0];
	m_coordinates[1] = m_coordinates[1] -= a_other.m_coordinates[1];
}

const float Vector2D::magnitude() const {

	float v;
	v = sqrtf(magnitudeSq());
	return v;

}

const float Vector2D::magnitudeSq() const {

	float v;
	v = (m_coordinates[0] * m_coordinates[0]) + (m_coordinates[1] * m_coordinates[1]);
	return v;
}

const float Vector2D::distance(const Vector2D& a_other) const
{
	float v;
	v = sqrtf(distanceSq(a_other));
	return v;
}
const float Vector2D::distanceSq(const Vector2D& a_other) const
{
	float v;
	v = ((m_coordinates[0] - a_other[0]) * (m_coordinates[0] - a_other[0])) + ((m_coordinates[1] - a_other[1]) * (m_coordinates[1] - a_other[1]));
	return v;
}

const float Vector2D::dotProduct(const Vector2D& a_other) const
{
	float AB;
	AB = (m_coordinates[0] * a_other[0]) + (m_coordinates[1] * a_other[1]);
	return AB;
}

const Vector2D Vector2D::crossProduct() const
{
	Vector2D clock;
	clock.m_coordinates[0] = -m_coordinates[1];
	clock.m_coordinates[1] = m_coordinates[0];

	return clock;
}

const Vector2D Vector2D::crossProductAnti() const
{
	Vector2D antiClock;
	antiClock.m_coordinates[0] = m_coordinates[1];
	antiClock.m_coordinates[1] = -m_coordinates[0];

	return antiClock;
}

void Vector2D::normalise()
{
	m_coordinates[0] = m_coordinates[0] / magnitude();
	m_coordinates[1] = m_coordinates[1] / magnitude();

}

const Vector2D Vector2D::normalised() const
{
	Vector2D normalised;
	normalised.m_coordinates[0] = m_coordinates[0] / magnitude();
	normalised.m_coordinates[1] = m_coordinates[1] / magnitude();

	return normalised;
}

const float* Vector2D::GetPointer() const
{
	return m_coordinates;
}