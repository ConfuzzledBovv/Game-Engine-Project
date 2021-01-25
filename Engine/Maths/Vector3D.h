#pragma once
#define M_PI       3.14159265358979323846f
namespace Maths
{
	class Vector3D
	{
	public:

		float x, y, z;

		// Constructors
		Vector3D();
		Vector3D(float _x, float _y, float _z);
		Vector3D(const Vector3D& vector);
		Vector3D& operator=(const Vector3D& vector);

		// Deconstructor
		~Vector3D();

		void Show();

		// Addition
		Vector3D operator+(const Vector3D& vector);
		void operator+=(const Vector3D& vector);

		// Subtraction
		Vector3D operator-(const Vector3D& vector);
		void operator-=(const Vector3D& vector);

		// Scalar Multiplication
		Vector3D operator*(const float Multiplication);
		void operator*=(const float Multiplication);
		void operator*=(const Vector3D Multiplication);

		// Division
		Vector3D operator/(const float Division);
		void operator/=(const float Division);

		// Dot Product
		float DotProduct(const Vector3D vector);
		float operator*(const Vector3D Multiplication);

		// Cross Product
		Vector3D CrossProduct(const Vector3D vector);
		Vector3D operator%(const Vector3D vector);
		void operator%=(const Vector3D vector);

		// Magnitude
		float Magnitude();

		// Normalising
		void Normalise();

		// Zero
		void ZeroVector();
		const bool IsZero();

		// Absolute
		void AbsoluteVector();

		// Equal
		const bool IsEqual(Vector3D& vector);

		// Distance
		float Distance(Vector3D& vector);
		bool IsNear(Vector3D& vector, float);

		// One Vector
		void OneVector();

		//Rotations
		void SetRoll(float angle);
		void SetPitch(float angle);
		void SetYaw(float angle);
		void RotateAll(float angle);

	};

}
