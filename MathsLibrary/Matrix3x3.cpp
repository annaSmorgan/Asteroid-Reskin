#include <cmath>
#include "Matrix3x3.h"
#include "Vector3D.h"

Matrix3x3::Matrix3x3()
{
	m_matrixValues[0] = 0.0f;
	m_matrixValues[1] = 0.0f;
	m_matrixValues[2] = 0.0f;

	m_matrixValues[3] = 0.0f;
	m_matrixValues[4] = 0.0f;
	m_matrixValues[5] = 0.0f;

	m_matrixValues[6] = 0.0f;
	m_matrixValues[7] = 0.0f;
	m_matrixValues[8] = 0.0f;
}

Matrix3x3::Matrix3x3(const float a_fm11, const float a_fm12, const float a_fm13, const float a_fm21, const float a_fm22, const float a_fm23, const float a_fm31, const float a_fm32, const float a_fm33)
{
	m_matrixValues[0] = a_fm11;
	m_matrixValues[1] = a_fm12;
	m_matrixValues[2] = a_fm13;

	m_matrixValues[3] = a_fm21;
	m_matrixValues[4] = a_fm22;
	m_matrixValues[5] = a_fm23;

	m_matrixValues[6] = a_fm31;
	m_matrixValues[7] = a_fm32;
	m_matrixValues[8] = a_fm33;

}

Matrix3x3::Matrix3x3(const float* a_fpm33Values)
{
	m_matrixValues[0] = a_fpm33Values[0];
	m_matrixValues[1] = a_fpm33Values[1];
	m_matrixValues[2] = a_fpm33Values[2];

	m_matrixValues[3] = a_fpm33Values[3];
	m_matrixValues[4] = a_fpm33Values[4];
	m_matrixValues[5] = a_fpm33Values[5];

	m_matrixValues[6] = a_fpm33Values[6];
	m_matrixValues[7] = a_fpm33Values[7];
	m_matrixValues[8] = a_fpm33Values[8];
}

const Matrix3x3 Matrix3x3::Identity()
{
	Matrix3x3 newMatrix;
	newMatrix.m_matrixValues[0] = 1;
	newMatrix.m_matrixValues[1] = 0;
	newMatrix.m_matrixValues[2] = 0;
	newMatrix.m_matrixValues[3] = 0;
	newMatrix.m_matrixValues[4] = 1;
	newMatrix.m_matrixValues[5] = 0;
	newMatrix.m_matrixValues[6] = 0;
	newMatrix.m_matrixValues[7] = 0;
	newMatrix.m_matrixValues[8] = 1;
	return newMatrix;
}

const Vector3D Matrix3x3::GetRow(const int a_irowNumber) const
{
	Vector3D rowOne;
	rowOne.SetX(m_matrixValues[0]);
	rowOne.SetY(m_matrixValues[1]);
	rowOne.SetZ(m_matrixValues[2]);

	Vector3D rowTwo;
	rowTwo.SetX(m_matrixValues[3]); 
	rowTwo.SetY(m_matrixValues[4]); 
	rowTwo.SetZ(m_matrixValues[5]);

	Vector3D rowThree;
	rowThree.SetX(m_matrixValues[6]);
	rowThree.SetX(m_matrixValues[7]);
	rowThree.SetX(m_matrixValues[8]);

	if (a_irowNumber == 0) 
	{
		return rowOne;
	}
	else if (a_irowNumber == 1)
	{
		return rowTwo;
	}
	else if (a_irowNumber == 2)
	{
		return rowThree;
	}
	
}

void Matrix3x3::SetRow(const int a_irowNumber, const Vector3D& a_rowValues)
{
	if (a_irowNumber == 0)
	{
		m_matrixValues[0] = a_rowValues[0];
		m_matrixValues[1] = a_rowValues[1];
		m_matrixValues[2] = a_rowValues[2];
	}
	else if (a_irowNumber == 1)
	{
		m_matrixValues[3] = a_rowValues[0];
		m_matrixValues[4] = a_rowValues[1];
		m_matrixValues[5] = a_rowValues[2];
	}
	else if (a_irowNumber == 2)
	{
		m_matrixValues[6] = a_rowValues[0];
		m_matrixValues[7] = a_rowValues[1];
		m_matrixValues[8] = a_rowValues[2];
	}
}

const Matrix3x3 Matrix3x3::RotateX(const float a_ftheta) const
{
	Matrix3x3 newMatrix;
	newMatrix.m_matrixValues[0] = 1;
	newMatrix.m_matrixValues[1] = 0;
	newMatrix.m_matrixValues[2] = 0;

	newMatrix.m_matrixValues[3] = 0;
	newMatrix.m_matrixValues[4] = cos(a_ftheta);
	newMatrix.m_matrixValues[5] = -sin(a_ftheta);

	newMatrix.m_matrixValues[6] = 0;
	newMatrix.m_matrixValues[7] = sin(a_ftheta);
	newMatrix.m_matrixValues[8] = cos(a_ftheta);

	Matrix3x3 newMatrixRotated;
	newMatrixRotated.m_matrixValues[0] = (m_matrixValues[0] * newMatrix.m_matrixValues[0]) + (m_matrixValues[1] * newMatrix.m_matrixValues[3]) + (m_matrixValues[2] * newMatrix.m_matrixValues[6]);
	newMatrixRotated.m_matrixValues[1] = (m_matrixValues[0] * newMatrix.m_matrixValues[1]) + (m_matrixValues[1] * newMatrix.m_matrixValues[4]) + (m_matrixValues[2] * newMatrix.m_matrixValues[7]);
	newMatrixRotated.m_matrixValues[2] = (m_matrixValues[0] * newMatrix.m_matrixValues[2]) + (m_matrixValues[1] * newMatrix.m_matrixValues[5]) + (m_matrixValues[2] * newMatrix.m_matrixValues[8]);

	newMatrixRotated.m_matrixValues[3] = (m_matrixValues[3] * newMatrix.m_matrixValues[0]) + (m_matrixValues[4] * newMatrix.m_matrixValues[3]) + (m_matrixValues[5] * newMatrix.m_matrixValues[6]);
	newMatrixRotated.m_matrixValues[4] = (m_matrixValues[3] * newMatrix.m_matrixValues[1]) + (m_matrixValues[4] * newMatrix.m_matrixValues[4]) + (m_matrixValues[5] * newMatrix.m_matrixValues[7]);
	newMatrixRotated.m_matrixValues[5] = (m_matrixValues[3] * newMatrix.m_matrixValues[2]) + (m_matrixValues[4] * newMatrix.m_matrixValues[5]) + (m_matrixValues[5] * newMatrix.m_matrixValues[8]);

	newMatrixRotated.m_matrixValues[6] = (m_matrixValues[6] * newMatrix.m_matrixValues[0]) + (m_matrixValues[7] * newMatrix.m_matrixValues[3]) + (m_matrixValues[8] * newMatrix.m_matrixValues[6]);
	newMatrixRotated.m_matrixValues[7] = (m_matrixValues[6] * newMatrix.m_matrixValues[1]) + (m_matrixValues[7] * newMatrix.m_matrixValues[4]) + (m_matrixValues[8] * newMatrix.m_matrixValues[7]);
	newMatrixRotated.m_matrixValues[8] = (m_matrixValues[6] * newMatrix.m_matrixValues[2]) + (m_matrixValues[7] * newMatrix.m_matrixValues[5]) + (m_matrixValues[8] * newMatrix.m_matrixValues[8]);

	return newMatrixRotated;
}

const Matrix3x3 Matrix3x3::RotateY(const float a_ftheta) const
{
	Matrix3x3 newMatrix;
	newMatrix.m_matrixValues[0] = cos(a_ftheta);
	newMatrix.m_matrixValues[1] = 0;
	newMatrix.m_matrixValues[2] = sin(a_ftheta);

	newMatrix.m_matrixValues[3] = 0;
	newMatrix.m_matrixValues[4] = 1;
	newMatrix.m_matrixValues[5] = 0;

	newMatrix.m_matrixValues[6] = -sin(a_ftheta);
	newMatrix.m_matrixValues[7] = 0;
	newMatrix.m_matrixValues[8] = cos(a_ftheta);
	
	Matrix3x3 newMatrixRotated;
	newMatrixRotated.m_matrixValues[0] = (m_matrixValues[0] * newMatrix.m_matrixValues[0]) + (m_matrixValues[1] * newMatrix.m_matrixValues[3]) + (m_matrixValues[2] * newMatrix.m_matrixValues[6]);
	newMatrixRotated.m_matrixValues[1] = (m_matrixValues[0] * newMatrix.m_matrixValues[1]) + (m_matrixValues[1] * newMatrix.m_matrixValues[4]) + (m_matrixValues[2] * newMatrix.m_matrixValues[7]);
	newMatrixRotated.m_matrixValues[2] = (m_matrixValues[0] * newMatrix.m_matrixValues[2]) + (m_matrixValues[1] * newMatrix.m_matrixValues[5]) + (m_matrixValues[2] * newMatrix.m_matrixValues[8]);

	newMatrixRotated.m_matrixValues[3] = (m_matrixValues[3] * newMatrix.m_matrixValues[0]) + (m_matrixValues[4] * newMatrix.m_matrixValues[3]) + (m_matrixValues[5] * newMatrix.m_matrixValues[6]);
	newMatrixRotated.m_matrixValues[4] = (m_matrixValues[3] * newMatrix.m_matrixValues[1]) + (m_matrixValues[4] * newMatrix.m_matrixValues[4]) + (m_matrixValues[5] * newMatrix.m_matrixValues[7]);
	newMatrixRotated.m_matrixValues[5] = (m_matrixValues[3] * newMatrix.m_matrixValues[2]) + (m_matrixValues[4] * newMatrix.m_matrixValues[5]) + (m_matrixValues[5] * newMatrix.m_matrixValues[8]);

	newMatrixRotated.m_matrixValues[6] = (m_matrixValues[6] * newMatrix.m_matrixValues[0]) + (m_matrixValues[7] * newMatrix.m_matrixValues[3]) + (m_matrixValues[8] * newMatrix.m_matrixValues[6]);
	newMatrixRotated.m_matrixValues[7] = (m_matrixValues[6] * newMatrix.m_matrixValues[1]) + (m_matrixValues[7] * newMatrix.m_matrixValues[4]) + (m_matrixValues[8] * newMatrix.m_matrixValues[7]);
	newMatrixRotated.m_matrixValues[8] = (m_matrixValues[6] * newMatrix.m_matrixValues[2]) + (m_matrixValues[7] * newMatrix.m_matrixValues[5]) + (m_matrixValues[8] * newMatrix.m_matrixValues[8]);

	return newMatrixRotated;
		
}

const Matrix3x3 Matrix3x3::RotateZ(const float a_ftheta) const
{
	Matrix3x3 newMatrix;
	newMatrix.m_matrixValues[0] = cos(a_ftheta);
	newMatrix.m_matrixValues[1] = -sin(a_ftheta);
	newMatrix.m_matrixValues[2] = 0;

	newMatrix.m_matrixValues[3] = sin(a_ftheta);
	newMatrix.m_matrixValues[4] = cos(a_ftheta);
	newMatrix.m_matrixValues[5] = 0;

	newMatrix.m_matrixValues[6] = 0;
	newMatrix.m_matrixValues[7] = 0;
	newMatrix.m_matrixValues[8] = 1;

	Matrix3x3 newMatrixRotated;
	newMatrixRotated.m_matrixValues[0] = (m_matrixValues[0] * newMatrix.m_matrixValues[0]) + (m_matrixValues[1] * newMatrix.m_matrixValues[3]) + (m_matrixValues[2] * newMatrix.m_matrixValues[6]);
	newMatrixRotated.m_matrixValues[1] = (m_matrixValues[0] * newMatrix.m_matrixValues[1]) + (m_matrixValues[1] * newMatrix.m_matrixValues[4]) + (m_matrixValues[2] * newMatrix.m_matrixValues[7]);
	newMatrixRotated.m_matrixValues[2] = (m_matrixValues[0] * newMatrix.m_matrixValues[2]) + (m_matrixValues[1] * newMatrix.m_matrixValues[5]) + (m_matrixValues[2] * newMatrix.m_matrixValues[8]);

	newMatrixRotated.m_matrixValues[3] = (m_matrixValues[3] * newMatrix.m_matrixValues[0]) + (m_matrixValues[4] * newMatrix.m_matrixValues[3]) + (m_matrixValues[5] * newMatrix.m_matrixValues[6]);
	newMatrixRotated.m_matrixValues[4] = (m_matrixValues[3] * newMatrix.m_matrixValues[1]) + (m_matrixValues[4] * newMatrix.m_matrixValues[4]) + (m_matrixValues[5] * newMatrix.m_matrixValues[7]);
	newMatrixRotated.m_matrixValues[5] = (m_matrixValues[3] * newMatrix.m_matrixValues[2]) + (m_matrixValues[4] * newMatrix.m_matrixValues[5]) + (m_matrixValues[5] * newMatrix.m_matrixValues[8]);

	newMatrixRotated.m_matrixValues[6] = (m_matrixValues[6] * newMatrix.m_matrixValues[0]) + (m_matrixValues[7] * newMatrix.m_matrixValues[3]) + (m_matrixValues[8] * newMatrix.m_matrixValues[6]);
	newMatrixRotated.m_matrixValues[7] = (m_matrixValues[6] * newMatrix.m_matrixValues[1]) + (m_matrixValues[7] * newMatrix.m_matrixValues[4]) + (m_matrixValues[8] * newMatrix.m_matrixValues[7]);
	newMatrixRotated.m_matrixValues[8] = (m_matrixValues[6] * newMatrix.m_matrixValues[2]) + (m_matrixValues[7] * newMatrix.m_matrixValues[5]) + (m_matrixValues[8] * newMatrix.m_matrixValues[8]);

	return newMatrixRotated;
}

const Matrix3x3 Matrix3x3::operator+(const Matrix3x3& a_other) const
{
	Matrix3x3 newMatrix;
	newMatrix.m_matrixValues[0] = m_matrixValues[0] + a_other.m_matrixValues[0];
	newMatrix.m_matrixValues[1] = m_matrixValues[1] + a_other.m_matrixValues[1];
	newMatrix.m_matrixValues[2] = m_matrixValues[2] + a_other.m_matrixValues[2];
	newMatrix.m_matrixValues[3] = m_matrixValues[3] + a_other.m_matrixValues[3];
	newMatrix.m_matrixValues[4] = m_matrixValues[4] + a_other.m_matrixValues[4];
	newMatrix.m_matrixValues[5] = m_matrixValues[5] + a_other.m_matrixValues[5];
	newMatrix.m_matrixValues[6] = m_matrixValues[6] + a_other.m_matrixValues[6];
	newMatrix.m_matrixValues[7] = m_matrixValues[7] + a_other.m_matrixValues[7];
	newMatrix.m_matrixValues[8] = m_matrixValues[8] + a_other.m_matrixValues[8];
	return newMatrix;
}

void Matrix3x3::operator+=(const Matrix3x3& a_other)
{
	m_matrixValues[0] += a_other.m_matrixValues[0];
	m_matrixValues[1] += a_other.m_matrixValues[1];
	m_matrixValues[2] += a_other.m_matrixValues[2];
	m_matrixValues[3] += a_other.m_matrixValues[3];
	m_matrixValues[4] += a_other.m_matrixValues[4];
	m_matrixValues[5] += a_other.m_matrixValues[5];
	m_matrixValues[6] += a_other.m_matrixValues[6];
	m_matrixValues[7] += a_other.m_matrixValues[7];
	m_matrixValues[8] += a_other.m_matrixValues[8];
	
}

const Matrix3x3 Matrix3x3::operator-(const Matrix3x3& a_other) const
{
	Matrix3x3 newMatrix;
	newMatrix.m_matrixValues[0] = m_matrixValues[0] - a_other.m_matrixValues[0];
	newMatrix.m_matrixValues[1] = m_matrixValues[1] - a_other.m_matrixValues[1];
	newMatrix.m_matrixValues[2] = m_matrixValues[2] - a_other.m_matrixValues[2];
	newMatrix.m_matrixValues[3] = m_matrixValues[3] - a_other.m_matrixValues[3];
	newMatrix.m_matrixValues[4] = m_matrixValues[4] - a_other.m_matrixValues[4];
	newMatrix.m_matrixValues[5] = m_matrixValues[5] - a_other.m_matrixValues[5];
	newMatrix.m_matrixValues[6] = m_matrixValues[6] - a_other.m_matrixValues[6];
	newMatrix.m_matrixValues[7] = m_matrixValues[7] - a_other.m_matrixValues[7];
	newMatrix.m_matrixValues[8] = m_matrixValues[8] - a_other.m_matrixValues[8];
	return newMatrix;
}

void Matrix3x3::operator-=(const Matrix3x3& a_other)
{
	m_matrixValues[0] -= a_other.m_matrixValues[0];
	m_matrixValues[1] -= a_other.m_matrixValues[1];
	m_matrixValues[2] -= a_other.m_matrixValues[2];
	m_matrixValues[3] -= a_other.m_matrixValues[3];
	m_matrixValues[4] -= a_other.m_matrixValues[4];
	m_matrixValues[5] -= a_other.m_matrixValues[5];
	m_matrixValues[6] -= a_other.m_matrixValues[6];
	m_matrixValues[7] -= a_other.m_matrixValues[7];
	m_matrixValues[8] -= a_other.m_matrixValues[8];
}

const Matrix3x3 Matrix3x3::operator*(const Matrix3x3& a_other) const
{
	Matrix3x3 newMatrix;
	newMatrix.m_matrixValues[0] = (m_matrixValues[0] * a_other.m_matrixValues[0]) + (m_matrixValues[1] * a_other.m_matrixValues[3]) + (m_matrixValues[2] * a_other.m_matrixValues[6]);
	newMatrix.m_matrixValues[1] = (m_matrixValues[0] * a_other.m_matrixValues[1]) + (m_matrixValues[1] * a_other.m_matrixValues[4]) + (m_matrixValues[2] * a_other.m_matrixValues[7]);
	newMatrix.m_matrixValues[2] = (m_matrixValues[0] * a_other.m_matrixValues[2]) + (m_matrixValues[1] * a_other.m_matrixValues[5]) + (m_matrixValues[2] * a_other.m_matrixValues[8]);

	newMatrix.m_matrixValues[3] = (m_matrixValues[3] * a_other.m_matrixValues[0]) + (m_matrixValues[4] * a_other.m_matrixValues[3]) + (m_matrixValues[5] * a_other.m_matrixValues[6]);
	newMatrix.m_matrixValues[4] = (m_matrixValues[3] * a_other.m_matrixValues[1]) + (m_matrixValues[4] * a_other.m_matrixValues[4]) + (m_matrixValues[5] * a_other.m_matrixValues[7]);
	newMatrix.m_matrixValues[5] = (m_matrixValues[3] * a_other.m_matrixValues[2]) + (m_matrixValues[4] * a_other.m_matrixValues[5]) + (m_matrixValues[5] * a_other.m_matrixValues[8]);

	newMatrix.m_matrixValues[6] = (m_matrixValues[6] * a_other.m_matrixValues[0]) + (m_matrixValues[7] * a_other.m_matrixValues[3]) + (m_matrixValues[8] * a_other.m_matrixValues[6]);
	newMatrix.m_matrixValues[7] = (m_matrixValues[6] * a_other.m_matrixValues[1]) + (m_matrixValues[7] * a_other.m_matrixValues[4]) + (m_matrixValues[8] * a_other.m_matrixValues[7]);
	newMatrix.m_matrixValues[8] = (m_matrixValues[6] * a_other.m_matrixValues[2]) + (m_matrixValues[7] * a_other.m_matrixValues[5]) + (m_matrixValues[8] * a_other.m_matrixValues[8]);
	
	return newMatrix;
}

void Matrix3x3::operator*=(const Matrix3x3& a_other)
{
	Matrix3x3 newMatrix;
	newMatrix.m_matrixValues[0] = (m_matrixValues[0] * a_other.m_matrixValues[0]) + (m_matrixValues[1] * a_other.m_matrixValues[3]) + (m_matrixValues[2] * a_other.m_matrixValues[6]);
	newMatrix.m_matrixValues[1] = (m_matrixValues[0] * a_other.m_matrixValues[1]) + (m_matrixValues[1] * a_other.m_matrixValues[4]) + (m_matrixValues[2] * a_other.m_matrixValues[7]);
	newMatrix.m_matrixValues[2] = (m_matrixValues[0] * a_other.m_matrixValues[2]) + (m_matrixValues[1] * a_other.m_matrixValues[5]) + (m_matrixValues[2] * a_other.m_matrixValues[8]);

	newMatrix.m_matrixValues[3] = (m_matrixValues[3] * a_other.m_matrixValues[0]) + (m_matrixValues[4] * a_other.m_matrixValues[3]) + (m_matrixValues[5] * a_other.m_matrixValues[6]);
	newMatrix.m_matrixValues[4] = (m_matrixValues[3] * a_other.m_matrixValues[1]) + (m_matrixValues[4] * a_other.m_matrixValues[4]) + (m_matrixValues[5] * a_other.m_matrixValues[7]);
	newMatrix.m_matrixValues[5] = (m_matrixValues[3] * a_other.m_matrixValues[2]) + (m_matrixValues[4] * a_other.m_matrixValues[5]) + (m_matrixValues[5] * a_other.m_matrixValues[8]);

	newMatrix.m_matrixValues[6] = (m_matrixValues[6] * a_other.m_matrixValues[0]) + (m_matrixValues[7] * a_other.m_matrixValues[3]) + (m_matrixValues[8] * a_other.m_matrixValues[6]);
	newMatrix.m_matrixValues[7] = (m_matrixValues[6] * a_other.m_matrixValues[1]) + (m_matrixValues[7] * a_other.m_matrixValues[4]) + (m_matrixValues[8] * a_other.m_matrixValues[7]);
	newMatrix.m_matrixValues[8] = (m_matrixValues[6] * a_other.m_matrixValues[2]) + (m_matrixValues[7] * a_other.m_matrixValues[5]) + (m_matrixValues[8] * a_other.m_matrixValues[8]);

	m_matrixValues[0] = newMatrix.m_matrixValues[0];
	m_matrixValues[1] = newMatrix.m_matrixValues[1];
	m_matrixValues[2] = newMatrix.m_matrixValues[2];

	m_matrixValues[3] = newMatrix.m_matrixValues[3];
	m_matrixValues[4] = newMatrix.m_matrixValues[4];
	m_matrixValues[5] = newMatrix.m_matrixValues[5];

	m_matrixValues[6] = newMatrix.m_matrixValues[6];
	m_matrixValues[7] = newMatrix.m_matrixValues[7];
	m_matrixValues[8] = newMatrix.m_matrixValues[8];

}

const Matrix3x3 Matrix3x3::operator*(const float& a_other) const
{
	Matrix3x3 newMatrix;

	newMatrix.m_matrixValues[0] = m_matrixValues[0] * a_other;
	newMatrix.m_matrixValues[1] = m_matrixValues[1] * a_other;
	newMatrix.m_matrixValues[2] = m_matrixValues[2] * a_other;

	newMatrix.m_matrixValues[3] = m_matrixValues[3] * a_other;
	newMatrix.m_matrixValues[4] = m_matrixValues[4] * a_other;
	newMatrix.m_matrixValues[5] = m_matrixValues[5] * a_other;

	newMatrix.m_matrixValues[6] = m_matrixValues[6] * a_other;
	newMatrix.m_matrixValues[7] = m_matrixValues[7] * a_other;
	newMatrix.m_matrixValues[8] = m_matrixValues[8] * a_other;

	return Matrix3x3();
}

void Matrix3x3::operator*=(const float& a_other)
{
	m_matrixValues[0] = m_matrixValues[0] * a_other;
	m_matrixValues[1] = m_matrixValues[1] * a_other;
	m_matrixValues[2] = m_matrixValues[2] * a_other;

	m_matrixValues[3] = m_matrixValues[3] * a_other;
	m_matrixValues[4] = m_matrixValues[4] * a_other;
	m_matrixValues[5] = m_matrixValues[5] * a_other;

	m_matrixValues[6] = m_matrixValues[6] * a_other;
	m_matrixValues[7] = m_matrixValues[7] * a_other;
	m_matrixValues[8] = m_matrixValues[8] * a_other;
}

const bool Matrix3x3::operator==(const Matrix3x3& a_other) const
{
	if (m_matrixValues[0] == a_other.m_matrixValues[0] &&
		m_matrixValues[1] == a_other.m_matrixValues[1] &&
		m_matrixValues[2] == a_other.m_matrixValues[2] &&
		m_matrixValues[3] == a_other.m_matrixValues[3] &&
		m_matrixValues[4] == a_other.m_matrixValues[4] &&
		m_matrixValues[5] == a_other.m_matrixValues[5] &&
		m_matrixValues[6] == a_other.m_matrixValues[6] &&
		m_matrixValues[7] == a_other.m_matrixValues[7] &&
		m_matrixValues[8] == a_other.m_matrixValues[8])
	{
		return true;
	}
	else
	{
		return false;
	}
}

const bool Matrix3x3::operator!=(const Matrix3x3& a_other) const
{
	if (m_matrixValues[0] != a_other.m_matrixValues[0] &&
		m_matrixValues[1] != a_other.m_matrixValues[1] &&
		m_matrixValues[2] != a_other.m_matrixValues[2] &&
		m_matrixValues[3] != a_other.m_matrixValues[3] &&
		m_matrixValues[4] != a_other.m_matrixValues[4] &&
		m_matrixValues[5] != a_other.m_matrixValues[5] &&
		m_matrixValues[6] != a_other.m_matrixValues[6] &&
		m_matrixValues[7] != a_other.m_matrixValues[7] &&
		m_matrixValues[8] != a_other.m_matrixValues[8])
	{
		return true;
	}
	else
	{
		return false;
	}
}

const float Matrix3x3::operator[](const int i) const
{
	return m_matrixValues[i];
}
