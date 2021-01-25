#pragma once
#include "Vector3D.h"
#define M_PI       3.14159265358979323846f
namespace Maths
{
	class Quaternion
	{
	public:

		// Radians
		float w;
		// Vector
		Vector3D vector;

		// Constructors
		Quaternion();
		Quaternion(float _w, const Vector3D& _vector);
		Quaternion(float _w, float x, float y, float z);
		Quaternion(const Quaternion& quaternion);
		Quaternion& operator=(const Quaternion& quaternion);


		// Deconstructors
		~Quaternion();

		// Show
		void Show();

		// Addition
		Quaternion operator+(const Quaternion& quaternion);
		void operator+=(const Quaternion& quaternion);

		// Subtraction
		Quaternion operator-(const Quaternion& quaternion);
		void operator-=(const Quaternion& quaternion);

		// Multiplication
		Quaternion operator*(Quaternion& quaternion);
		void operator*=(Quaternion& quaternion);
		Quaternion Multiplication(Quaternion& quaternion);

		// Scalar Multiplication
		void operator*=(const float value);
		Quaternion operator*(const float value);

		void DegreesToRadians();
		void Inverse();

	};

}
