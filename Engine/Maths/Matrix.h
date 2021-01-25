#pragma once

#include "Vector3D.h"

namespace Maths
{
	class Matrix
	{
	public:
		// Data Elements
		float matrixData[9] = { 0.0f };

		// Constructors
		Matrix();
		Matrix(float matrix0, float matrix3, float matrix6, float matrix1, float matrix4, float matrix7, float matrix2, float matrix5, float matrix8);
		Matrix& operator=(const Matrix& matrix);
		Matrix& operator=(const Matrix* matrix);

		// Deconstructor
		~Matrix();

		void Show();

		// Addition
		Matrix operator+(const Matrix& matrix);
		void operator+=(const Matrix& matrix);

		// Subtraction
		Matrix operator-(const Matrix& matrix);
		void operator-=(const Matrix& matrix);

		// Scalar Multiplication
		Matrix operator*(const float Multiplication);
		void operator*=(const float Multiplication);

		// Division
		Matrix operator/(const float Division);
		void operator/=(const float Division);

		// Matrix Multiplication
		Matrix operator*(const Matrix& matrix);
		void operator*=(const Matrix& matrix);

		// Identity Matrix
		void SetAsIdentityMatrix();

		//Set Inverse
		void SetMatrixAsInverseOf(const Matrix& matrix);
		const Matrix GetInverseOfMatrix();
		void InvertMatrix();

		// Transpose
		void SetTranspose(const Matrix& matrix);
		const Matrix GetTranspose();

		// Multiply vector by matrix
		Vector3D operator*(const Vector3D& vector);
		Vector3D TransformVectorByMatrix(const Vector3D& vector);

	};

}


/*

Column format preferred by OpenGL

0 3 6
1 4 7
2 5 8

*/