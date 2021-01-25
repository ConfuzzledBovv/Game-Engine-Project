#include "Quaternion.h"
#include "iostream"

namespace Maths
{
	Quaternion::Quaternion()
	{
		vector = Vector3D(0, 0, 0);
		w = 0;
	}
	Quaternion::Quaternion(float _w, const Vector3D & _vector)
	{
		w = _w;
		vector = _vector;
		DegreesToRadians();
	}
	Quaternion::Quaternion(float _w, float x, float y, float z)
	{
		w = _w;
		vector = Vector3D(x, y, z);
		DegreesToRadians();
	}
	Quaternion::Quaternion(const Quaternion & quaternion)
	{
		w = quaternion.w;
		vector = quaternion.vector;
		DegreesToRadians();
	}
	Quaternion & Quaternion::operator=(const Quaternion & quaternion)
	{
		w = quaternion.w;
		vector = quaternion.vector;

		return *this;
	}
	Quaternion::~Quaternion()
	{

	}

	void Quaternion::Show()
	{
		std::cout << "< W: " << w << ", X: " << vector.x << ", Y: " << vector.y << ", Z: " << vector.z << " >" << std::endl;
	}

	Quaternion Quaternion::operator+(const Quaternion & quaternion)
	{
		return Quaternion(w + quaternion.w, vector + quaternion.vector);
	}
	void Quaternion::operator+=(const Quaternion & quaternion)
	{
		w += quaternion.w;
		vector += quaternion.vector;
	}

	Quaternion Quaternion::operator-(const Quaternion & quaternion)
	{
		return Quaternion(w - quaternion.w, vector - quaternion.vector);
	}

	void Quaternion::operator-=(const Quaternion & quaternion)
	{
		w -= quaternion.w;
		vector -= quaternion.vector;
	}

	Quaternion Quaternion::operator*(Quaternion & quaternion)
	{
		return Quaternion(w * quaternion.w + vector.DotProduct(quaternion.vector), quaternion.vector * w + vector * quaternion.w + vector.CrossProduct(quaternion.vector));
	}

	void Quaternion::operator*=(Quaternion & quaternion)
	{
		*this = Multiplication(quaternion);
	}

	Quaternion Quaternion::Multiplication(Quaternion & quaternion)
	{
		return Quaternion(w * quaternion.w - vector.DotProduct(quaternion.vector), quaternion.vector * w + vector * quaternion.w + vector.CrossProduct(quaternion.vector));
	}

	void Quaternion::operator*=(const float value)
	{
		w *= value;
		vector *= vector;
	}

	Quaternion Quaternion::operator*(const float value)
	{
		return Quaternion(w * value, vector * value);
	}

	void Quaternion::DegreesToRadians()
	{
		float degrees = w;
		w *= M_PI / 180;
		vector *= sin(w / 2);
		if (degrees != 180)
		{
			w = cos(w / 2);
			return;
		}
		w = 0;
	}

	void Quaternion::Inverse()
	{
		vector.x = -vector.x;
		vector.y = -vector.y;
		vector.z = -vector.z;
	}
}
