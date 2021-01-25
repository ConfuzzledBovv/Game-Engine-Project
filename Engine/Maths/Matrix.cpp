#include "Matrix.h"
#include "iostream"

namespace Maths
{
	Matrix::Matrix()
	{
		// If no data is given then set as identity matrix
		for (int i = 0; i < 9; i++)
		{
			matrixData[i] = 0;

		}
		matrixData[0] = matrixData[4] = matrixData[8] = 1.0f;
	}
	Matrix::Matrix(float matrix0, float matrix3, float matrix6, float matrix1, float matrix4, float matrix7, float matrix2, float matrix5, float matrix8)
	{
		matrixData[0] = matrix0;
		matrixData[3] = matrix3;
		matrixData[6] = matrix6;

		matrixData[1] = matrix1;
		matrixData[4] = matrix4;
		matrixData[7] = matrix7;

		matrixData[2] = matrix2;
		matrixData[5] = matrix5;
		matrixData[8] = matrix8;

	}
	Matrix & Matrix::operator=(const Matrix & matrix)
	{
		for (int i = 0; i <= 8; i++)
		{
			matrixData[i] = matrix.matrixData[i];
		}
		return *this;
	}
	Matrix & Matrix::operator=(const Matrix * matrix)
	{
		for (int i = 0; i <= 8; i++)
		{
			matrixData[i] = matrix->matrixData[i];
		}
		return *this;
	}
	Matrix::~Matrix()
	{

	}
	void Matrix::Show()
	{
		std::cout << matrixData[0] << ", " << matrixData[3] << ", " << matrixData[6] << std::endl;
		std::cout << matrixData[1] << ", " << matrixData[4] << ", " << matrixData[7] << std::endl;
		std::cout << matrixData[2] << ", " << matrixData[5] << ", " << matrixData[8] << std::endl;
	}
	Matrix Matrix::operator+(const Matrix & matrix)
	{
		return Matrix(matrixData[0] + matrix.matrixData[0], matrixData[3] + matrix.matrixData[3], matrixData[6] + matrix.matrixData[6],
			matrixData[1] + matrix.matrixData[1], matrixData[4] + matrix.matrixData[4], matrixData[7] + matrix.matrixData[7],
			matrixData[2] + matrix.matrixData[2], matrixData[5] + matrix.matrixData[5], matrixData[8] + matrix.matrixData[8]);
	}
	void Matrix::operator+=(const Matrix & matrix)
	{
		for (int i = 0; i <= 8; i++)
		{
			matrixData[i] += matrix.matrixData[i];
		}
	}
	Matrix Matrix::operator-(const Matrix & matrix)
	{
		return Matrix(matrixData[0] - matrix.matrixData[0], matrixData[3] - matrix.matrixData[3], matrixData[6] - matrix.matrixData[6],
			matrixData[1] - matrix.matrixData[1], matrixData[4] - matrix.matrixData[4], matrixData[7] - matrix.matrixData[7],
			matrixData[2] - matrix.matrixData[2], matrixData[5] - matrix.matrixData[5], matrixData[8] - matrix.matrixData[8]);
	}
	void Matrix::operator-=(const Matrix & matrix)
	{

		for (int i = 0; i <= 8; i++)
		{
			matrixData[i] -= matrix.matrixData[i];
		}
	}
	Matrix Matrix::operator*(const float Multiplication)
	{
		return Matrix(matrixData[0] * Multiplication, matrixData[3] * Multiplication, matrixData[6] * Multiplication,
			matrixData[1] * Multiplication, matrixData[4] * Multiplication, matrixData[7] * Multiplication,
			matrixData[2] * Multiplication, matrixData[5] * Multiplication, matrixData[8] * Multiplication);
	}
	void Matrix::operator*=(const float Multiplication)
	{
		for (int i = 0; i <= 8; i++)
		{
			matrixData[i] *= Multiplication;
		}
	}
	Matrix Matrix::operator/(const float Division)
	{
		return Matrix(matrixData[0] / Division, matrixData[3] / Division, matrixData[6] / Division,
			matrixData[1] / Division, matrixData[4] / Division, matrixData[7] / Division,
			matrixData[2] / Division, matrixData[5] / Division, matrixData[8] / Division);
	}
	void Matrix::operator/=(const float Division)
	{
		for (int i = 0; i <= 8; i++)
		{
			matrixData[i] /= Division;
		}
	}
	Matrix Matrix::operator*(const Matrix & matrix)
	{
		return Matrix(matrixData[0] * matrix.matrixData[0] + matrixData[3] * matrix.matrixData[1] + matrixData[6] * matrix.matrixData[2],
			matrixData[0] * matrix.matrixData[3] + matrixData[3] * matrix.matrixData[4] + matrixData[6] * matrix.matrixData[5],
			matrixData[0] * matrix.matrixData[6] + matrixData[3] * matrix.matrixData[7] + matrixData[6] * matrix.matrixData[8],

			matrixData[1] * matrix.matrixData[0] + matrixData[4] * matrix.matrixData[1] + matrixData[7] * matrix.matrixData[2],
			matrixData[1] * matrix.matrixData[3] + matrixData[4] * matrix.matrixData[4] + matrixData[7] * matrix.matrixData[5],
			matrixData[1] * matrix.matrixData[6] + matrixData[4] * matrix.matrixData[7] + matrixData[7] * matrix.matrixData[8],

			matrixData[2] * matrix.matrixData[0] + matrixData[5] * matrix.matrixData[1] + matrixData[8] * matrix.matrixData[2],
			matrixData[2] * matrix.matrixData[3] + matrixData[5] * matrix.matrixData[4] + matrixData[8] * matrix.matrixData[5],
			matrixData[2] * matrix.matrixData[6] + matrixData[5] * matrix.matrixData[7] + matrixData[8] * matrix.matrixData[8]);
	}
	void Matrix::operator*=(const Matrix & matrix)
	{
		matrixData[0] = matrixData[0] * matrix.matrixData[0] + matrixData[3] * matrix.matrixData[1] + matrixData[6] * matrix.matrixData[2];
		matrixData[3] = matrixData[0] * matrix.matrixData[3] + matrixData[3] * matrix.matrixData[4] + matrixData[6] * matrix.matrixData[5];
		matrixData[6] = matrixData[0] * matrix.matrixData[6] + matrixData[3] * matrix.matrixData[7] + matrixData[6] * matrix.matrixData[8];

		matrixData[1] = matrixData[1] * matrix.matrixData[0] + matrixData[4] * matrix.matrixData[1] + matrixData[7] * matrix.matrixData[2];
		matrixData[4] = matrixData[1] * matrix.matrixData[3] + matrixData[4] * matrix.matrixData[4] + matrixData[7] * matrix.matrixData[5];
		matrixData[7] = matrixData[1] * matrix.matrixData[6] + matrixData[4] * matrix.matrixData[7] + matrixData[7] * matrix.matrixData[8];

		matrixData[2] = matrixData[2] * matrix.matrixData[0] + matrixData[5] * matrix.matrixData[1] + matrixData[8] * matrix.matrixData[2];
		matrixData[5] = matrixData[2] * matrix.matrixData[3] + matrixData[5] * matrix.matrixData[4] + matrixData[8] * matrix.matrixData[5];
		matrixData[8] = matrixData[2] * matrix.matrixData[6] + matrixData[5] * matrix.matrixData[7] + matrixData[8] * matrix.matrixData[8];


	}
	void Matrix::SetAsIdentityMatrix()
	{
		for (int i = 0; i <= 8; i++)
		{
			matrixData[i] = 0.0f;
		}
		matrixData[0] = matrixData[4] = matrixData[8] = 1.0f;
	}
	void Matrix::SetMatrixAsInverseOf(const Matrix & matrix)
	{
		float detCalc[6];
		detCalc[0] = matrix.matrixData[0] * matrix.matrixData[4];
		detCalc[1] = matrix.matrixData[0] * matrix.matrixData[7];
		detCalc[2] = matrix.matrixData[3] * matrix.matrixData[1];
		detCalc[3] = matrix.matrixData[6] * matrix.matrixData[1];
		detCalc[4] = matrix.matrixData[3] * matrix.matrixData[2];
		detCalc[5] = matrix.matrixData[6] * matrix.matrixData[2];

		float determinant = (detCalc[0] * matrix.matrixData[8] - detCalc[1] * matrix.matrixData[5] - detCalc[2] * matrix.matrixData[8] + detCalc[3] * matrix.matrixData[5] +
			detCalc[4] * matrix.matrixData[7] - detCalc[5] * matrix.matrixData[4]);


		if (determinant == 0.0f)
		{
			return;
		}

		float invd = 1.0f / determinant;

		float inverseCalc[9];

		inverseCalc[0] = (matrix.matrixData[4] * matrix.matrixData[8] - matrix.matrixData[7] * matrix.matrixData[5]) * invd;
		inverseCalc[3] = -(matrix.matrixData[3] * matrix.matrixData[8] - matrix.matrixData[6] * matrix.matrixData[5]) * invd;
		inverseCalc[6] = (matrix.matrixData[3] * matrix.matrixData[7] - matrix.matrixData[6] * matrix.matrixData[4]) * invd;
		inverseCalc[1] = -(matrix.matrixData[1] * matrix.matrixData[8] - matrix.matrixData[7] * matrix.matrixData[2]) * invd;
		inverseCalc[4] = (matrix.matrixData[0] * matrix.matrixData[8] - detCalc[5]) * invd;
		inverseCalc[7] = -(detCalc[1] - detCalc[3]) * invd;
		inverseCalc[2] = (matrix.matrixData[1] * matrix.matrixData[5] - matrix.matrixData[4] * matrix.matrixData[2]) * invd;
		inverseCalc[5] = -(matrix.matrixData[0] * matrix.matrixData[5] - detCalc[4]) * invd;
		inverseCalc[8] = (detCalc[0] - detCalc[2]) * invd;

		matrixData[0] = inverseCalc[0];
		matrixData[3] = inverseCalc[3];
		matrixData[6] = inverseCalc[6];

		matrixData[1] = inverseCalc[1];
		matrixData[4] = inverseCalc[4];
		matrixData[7] = inverseCalc[7];

		matrixData[2] = inverseCalc[2];
		matrixData[5] = inverseCalc[5];
		matrixData[8] = inverseCalc[8];

	}
	const Matrix Matrix::GetInverseOfMatrix()
	{
		Matrix Result;
		Result.SetMatrixAsInverseOf(*this);
		return Result;
	}
	void Matrix::InvertMatrix()
	{
		SetMatrixAsInverseOf(*this);
	}
	void Matrix::SetTranspose(const Matrix & matrix)
	{
		matrixData[0] = matrix.matrixData[0];
		matrixData[3] = matrix.matrixData[1];
		matrixData[6] = matrix.matrixData[2];

		matrixData[1] = matrix.matrixData[3];
		matrixData[4] = matrix.matrixData[4];
		matrixData[7] = matrix.matrixData[5];

		matrixData[2] = matrix.matrixData[6];
		matrixData[5] = matrix.matrixData[7];
		matrixData[8] = matrix.matrixData[8];

	}
	const Matrix Matrix::GetTranspose()
	{
		Matrix Result;
		Result.SetTranspose(*this);
		return Result;
	}

	Vector3D Matrix::operator*(const Vector3D & vector)
	{
		return Vector3D(matrixData[0] * vector.x + matrixData[3] * vector.y + matrixData[6] * vector.z,
			matrixData[1] * vector.x + matrixData[4] * vector.y + matrixData[7] * vector.z,
			matrixData[2] * vector.x + matrixData[5] * vector.y + matrixData[8] * vector.z);
	}

	Vector3D Matrix::TransformVectorByMatrix(const Vector3D & vector)
	{
		return(*this * vector);
	}

}

