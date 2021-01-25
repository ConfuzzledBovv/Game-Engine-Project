#include "Vector3D.h"
#include "iostream"
#include "Quaternion.h"
namespace Maths
{
	Vector3D::Vector3D()
	{
		x = 0.0f;
		y = 0.0f;
		z = 0.0f;
	}
	Vector3D::Vector3D(float _x, float _y, float _z)
	{
		x = _x;
		y = _y;
		z = _z;
	}
	Vector3D::Vector3D(const Vector3D & vector)
	{
		x = vector.x;
		y = vector.y;
		z = vector.z;
	}
	Vector3D & Vector3D::operator=(const Vector3D & vector)
	{
		x = vector.x;
		y = vector.y;
		z = vector.z;

		return *this;
	}
	Vector3D::~Vector3D()
	{

	}
	void Vector3D::Show()
	{
		std::cout << x << ", " << y << ", " << z << std::endl;
	}
	Vector3D Vector3D::operator+(const Vector3D & vector)
	{
		return Vector3D(x + vector.x, y + vector.y, z + vector.z);
	}
	void Vector3D::operator+=(const Vector3D & vector)
	{
		x += vector.x;
		y += vector.y;
		z += vector.z;
	}
	Vector3D Vector3D::operator-(const Vector3D & vector)
	{
		return Vector3D(x - vector.x, y - vector.y, z - vector.z);
	}
	void Vector3D::operator-=(const Vector3D & vector)
	{
		x -= vector.x;
		y -= vector.y;
		z -= vector.z;
	}
	Vector3D Vector3D::operator*(const float Multiplication)
	{
		return Vector3D(x * Multiplication, y * Multiplication, z * Multiplication);
	}
	void Vector3D::operator*=(const float Multiplication)
	{
		x *= Multiplication;
		y *= Multiplication;
		z *= Multiplication;
	}
	void Vector3D::operator*=(const Vector3D Multiplication)
	{
		x *= Multiplication.x;
		y *= Multiplication.y;
		z *= Multiplication.z;
	}
	Vector3D Vector3D::operator/(const float Division)
	{
		return Vector3D(x / Division, y / Division, z / Division);
	}
	void Vector3D::operator/=(const float Division)
	{
		x /= Division;
		y /= Division;
		z /= Division;
	}
	float Vector3D::DotProduct(const Vector3D vector)
	{
		return x * vector.x + y * vector.y + z * vector.z;
	}
	float Vector3D::operator*(const Vector3D vector)
	{
		return x * vector.x + y * vector.y + z * vector.z;
	}
	Vector3D Vector3D::CrossProduct(const Vector3D vector)
	{
		return Vector3D(y * vector.z - z * vector.y,
			z * vector.x - x * vector.z,
			x * vector.y - y * vector.x);
	}
	Vector3D Vector3D::operator%(const Vector3D vector)
	{
		return CrossProduct(vector);
	}
	void Vector3D::operator%=(const Vector3D vector)
	{
		*this = CrossProduct(vector);
	}
	float Vector3D::Magnitude()
	{
		float _magnitude = std::sqrt(x * x + y * y + z * z);

		return _magnitude;
	}
	void Vector3D::Normalise()
	{
		float magnitude = std::sqrt(x * x + y * y + z * z);

		// If its not a unit vector
		if (magnitude > 1)
		{
			float normal = 1 / magnitude;

			x *= normal;
			y *= normal;
			z *= normal;
		}
	}
	void Vector3D::ZeroVector()
	{
		x = 0;
		y = 0;
		z = 0;
	}
	const bool Vector3D::IsZero()
	{
		if (x == 0 && y == 0 && z == 0)
		{
			return true;
		}
		return false;
	}
	void Vector3D::AbsoluteVector()
	{
		x = std::abs(x);
		y = std::abs(y);
		z = std::abs(z);
	}
	const bool Vector3D::IsEqual(Vector3D & vector)
	{
		if (x == vector.x && y == vector.y && z == vector.z)
		{
			return true;
		}

		return false;
	}
	float Vector3D::Distance(Vector3D & vector)
	{
		float points[3];
		points[0] = x - vector.x;
		points[1] = y - vector.y;
		points[2] = z - vector.z;

		points[0] *= points[0];
		points[1] *= points[1];
		points[2] *= points[2];

		return std::sqrt(points[0] + points[1] + points[2]);
	}
	bool Vector3D::IsNear(Vector3D & vector, float distance)
	{
		if (Distance(vector) < distance)
		{
			return true;
		}
		return false;
	}
	void Vector3D::OneVector()
	{
		x = y = z = 1;
	}

	void Vector3D::SetRoll(float angle)
	{
		float rollCos = cos(angle * M_PI / 180);
		float rollSin = sin(angle * M_PI / 180);
		float _y = y;

		y = rollCos * _y - rollSin * z;
		z = rollCos * z + rollSin * _y;
	}

	void Vector3D::SetPitch(float angle)
	{
		float rollCos = cos(angle * M_PI / 180);
		float rollSin = sin(angle * M_PI / 180);
		float _x = x;

		x = rollCos * _x + rollSin * z;
		z = rollCos * z - rollSin * _x;
	}

	void Vector3D::SetYaw(float angle)
	{
		float rollCos = cos(angle * M_PI / 180);
		float rollSin = sin(angle * M_PI / 180);
		float _x = x;

		x = rollCos * _x - rollSin * y;
		y = rollCos * y + rollSin * _x;

	}

	void Vector3D::RotateAll(float angle)
	{
		float rollCos = cos(angle * M_PI / 180);
		float rollSin = sin(angle * M_PI / 180);
		float _x = x;
		float _y = y;
		float _z = z;

		// Set Roll
		y = rollCos * _y - rollSin * _z;
		z = rollCos * _z + rollSin * _y;

		// Set Pitch
		x = rollCos * _x + rollSin * _z;
		z = rollCos * _z - rollSin * _x;

		// Set Yaw
		x = rollCos * _x - rollSin * _y;
		y = rollCos * _y + rollSin * _x;
	}



}