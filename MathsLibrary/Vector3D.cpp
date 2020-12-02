#include "Vector3D.h"
#include "Vector2D.h"
#include "Matrix3x3.h"
#include <cmath>

Vector3D::Vector3D()
{
	m_coordinates[0] = 0.f;
	m_coordinates[1] = 0.f;
	m_coordinates[2] = 0.f;
}

Vector3D::Vector3D(Vector2D a_other)
{
	m_coordinates[0] = a_other.GetX();
	m_coordinates[1] = a_other.GetY();
	m_coordinates[2] = 0.0f;
}
Vector3D::Vector3D(float a_x, float a_y, float a_z)
{
	m_coordinates[0] = a_x;
	m_coordinates[1] = a_y;
	m_coordinates[2] = a_z;
}

const float Vector3D::operator[](const int a_i) const
{

	return m_coordinates[a_i];
}

const Vector3D Vector3D::operator*(const float a_other) const
{
	Vector3D newVec;
	newVec.m_coordinates[0] = m_coordinates[0] * a_other;
	newVec.m_coordinates[1] = m_coordinates[1] * a_other;
	newVec.m_coordinates[2] = m_coordinates[2] * a_other;
	return newVec;
}

void Vector3D::operator*=(const float a_other)
{
	m_coordinates[0] *= a_other;
	m_coordinates[1] *= a_other;
	m_coordinates[2] *= a_other;
}

const Vector3D Vector3D::operator*(const Vector3D& a_other) const
{
	Vector3D newVec;
	newVec.m_coordinates[0] = m_coordinates[0] * a_other.m_coordinates[0];
	newVec.m_coordinates[1] = m_coordinates[1] * a_other.m_coordinates[1];
	newVec.m_coordinates[2] = m_coordinates[2] * a_other.m_coordinates[2];
	return newVec;
}

void Vector3D::operator*=(const Vector3D& a_other)
{
	m_coordinates[0] *= a_other.m_coordinates[0];
	m_coordinates[1] *= a_other.m_coordinates[1];
	m_coordinates[2] *= a_other.m_coordinates[2];
}

const Vector3D Vector3D::operator/(const Vector3D& a_other) const
{
	Vector3D newVec;
	newVec.m_coordinates[0] = m_coordinates[0] / a_other.m_coordinates[0];
	newVec.m_coordinates[1] = m_coordinates[1] / a_other.m_coordinates[1];
	newVec.m_coordinates[2] = m_coordinates[2] / a_other.m_coordinates[2];
	return newVec;
}

void Vector3D::operator/=(const Vector3D& a_other)
{
	m_coordinates[0] /= a_other.m_coordinates[0];
	m_coordinates[1] /= a_other.m_coordinates[1];
	m_coordinates[2] /= a_other.m_coordinates[2];
}

const Vector3D Vector3D::operator/(const float a_other) const
{
	Vector3D newVec;
	newVec.m_coordinates[0] = m_coordinates[0] / a_other;
	newVec.m_coordinates[1] = m_coordinates[1] / a_other;
	newVec.m_coordinates[2] = m_coordinates[2] / a_other;
	return newVec;
}

void Vector3D::operator/=(const float a_other)
{
	m_coordinates[0] /= a_other;
	m_coordinates[1] /= a_other;
	m_coordinates[2] /= a_other;
}

const Vector3D Vector3D::operator*(const Matrix3x3& a_other) const
{
	return Vector3D();
}

const Vector3D Vector3D::operator+(const Vector3D& a_other) const
{
	Vector3D newVec;
	newVec.m_coordinates[0] = m_coordinates[0] + a_other.m_coordinates[0];
	newVec.m_coordinates[1] = m_coordinates[1] + a_other.m_coordinates[1];
	newVec.m_coordinates[2] = m_coordinates[2] + a_other.m_coordinates[2];
	return newVec;
}

void Vector3D::operator+=(const Vector3D& a_other)
{
	m_coordinates[0] += a_other.m_coordinates[0];
	m_coordinates[1] += a_other.m_coordinates[1];
	m_coordinates[2] += a_other.m_coordinates[2];
}

const Vector3D Vector3D::operator-(const Vector3D& a_other) const
{
	Vector3D newVec;
	newVec.m_coordinates[0] = m_coordinates[0] - a_other.m_coordinates[0];
	newVec.m_coordinates[1] = m_coordinates[1] - a_other.m_coordinates[1];
	newVec.m_coordinates[2] = m_coordinates[2] - a_other.m_coordinates[2];
	return newVec;
}

void Vector3D::operator-=(const Vector3D& a_other)
{
	m_coordinates[0] -= a_other.m_coordinates[0];
	m_coordinates[1] -= a_other.m_coordinates[1];
	m_coordinates[2] -= a_other.m_coordinates[2];
}
const float Vector3D::magnitude() const
{
	float v;
	v = sqrtf(magnitudeSq());
	return v;
}

const float Vector3D::magnitudeSq() const
{
	float v;
	v = (m_coordinates[0] * m_coordinates[0]) + (m_coordinates[1] * m_coordinates[1]) + (m_coordinates[2] * m_coordinates[2]);
	return v;
}

const float Vector3D::distance(const Vector3D& a_other) const
{
	float v;
	v = sqrtf(distanceSq(a_other));
	return v;
}

const float Vector3D::distanceSq(const Vector3D& a_other) const
{
	float v;
	v = ((m_coordinates[0] - a_other[0]) * (m_coordinates[0] - a_other[0])) + ((m_coordinates[1] - a_other[1]) * (m_coordinates[1] - a_other[1])) + ((m_coordinates[2] - a_other[2]) * (m_coordinates[2] - a_other[2]));
	return v;
}

const float Vector3D::dotProduct(const Vector3D& a_other) const
{
	float v;
	v = (m_coordinates[0] * a_other[0]) + (m_coordinates[1] * a_other[1]) + (m_coordinates[2] * a_other[2]);
	return v;
}

const Vector3D Vector3D::crossProduct(const Vector3D& a_rv3a) const
{
	Vector3D newVec;

	newVec.m_coordinates[0] = (m_coordinates[1] * a_rv3a.m_coordinates[2]) - (m_coordinates[2] * a_rv3a.m_coordinates[1]);
	newVec.m_coordinates[1] = (m_coordinates[2] * a_rv3a.m_coordinates[0]) - (m_coordinates[0] * a_rv3a.m_coordinates[2]);
	newVec.m_coordinates[2] = (m_coordinates[0] * a_rv3a.m_coordinates[1]) - (m_coordinates[1] * a_rv3a.m_coordinates[0]);
	return newVec;
}

void Vector3D::normalise()
{

	m_coordinates[0] = m_coordinates[0] / magnitude();
	m_coordinates[1] = m_coordinates[1] / magnitude();
	m_coordinates[2] = m_coordinates[2] / magnitude();

}

const Vector3D Vector3D::normalised() const
{
	Vector3D normalised;
	normalised.m_coordinates[0] = m_coordinates[0] / magnitude();
	normalised.m_coordinates[1] = m_coordinates[1] / magnitude();
	normalised.m_coordinates[2] = m_coordinates[2] / magnitude();

	return normalised;
}

const float* Vector3D::GetPointer() const
{
	return m_coordinates;
}