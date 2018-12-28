#ifndef VECTOR3_H
#define VECTOR3_H

namespace BHive
{
	template<class T>
	struct Vector3
	{
		T X;
		T Y;
		T Z;

		Vector3();
		Vector3(T x);
		Vector3(T x, T y, T z);
		Vector3(const Vector3& vec);
		Vector3& operator=(const Vector3& vec);
		bool operator==(const Vector3& vec) const;
		T& operator[](size_t index) const;
		const Vector3& operator+() const;
		const Vector3& operator+(const Vector3& vec) const;
		Vector3& operator+=(const Vector3& vec);
		const Vector3& operator-();		
		const Vector3& operator-(const Vector3& vec) const;
		Vector3& operator-=(const Vector3& vec);
		const Vector3& operator*(const T& scaler) const;
		Vector3& operator*=(const T& scaler);
		const Vector3& operator/(const T& scaler) const;
		const T operator*(const Vector3& vec) const; // Dot
		const Vector3& operator^(const Vector3& vec) const; //Cross
		const T Length();
		const T LengthSquared();
		const Vector3 Unit() const;

		static float Dot(const Vector3& A, const Vector3& B);
		static Vector3 Cross(const Vector3& A, const Vector3& B);
	};

	template<class T>
	BHive::Vector3<T>::Vector3()
	{
		X = 0;
		Y = 0;
		Z = 0;
	}

	template<class T>
	BHive::Vector3<T>::Vector3(T x)
	{
		X = x;
		Y = x;
		Z = x;
	}

	template<class T>
	BHive::Vector3<T>::Vector3(T x, T y, T z)
	{
		X = x;
		Y = y;
		Z = z;
	}

	template<class T>
	BHive::Vector3<T>::Vector3(const Vector3& vec)
	{
		this = vec;
	}

	template<class T>
	Vector3<T>& BHive::Vector3<T>::operator=(const Vector3& vec)
	{
		X = vec.X;
		Y = vec.Y;
		Z = vec.Z;
	}

	template<class T>
	bool BHive::Vector3<T>::operator==(const Vector3& vec) const
	{
		return X == vec.X && Y == vec.Y && Z == vec.Z;
	}

	template<class T>
	T& BHive::Vector3<T>::operator[](size_t index) const
	{
		switch (index)
		{
		case 0:
			return X;
			break;
		case 1:
			return Y;
			break;
		case 2:
			return Z;
			break;
		}

		return 0;
	}

	template<class T>
	const Vector3<T>& BHive::Vector3<T>::operator+() const
	{
		return *this;
	}

	template<class T>
	const Vector3<T>& BHive::Vector3<T>::operator+(const Vector3& vec) const
	{
		return Vector3(this->X + vec.X, this->Y + vec.Y, this->Z + vec.Z);
	}

	template<class T>
	Vector3<T>& BHive::Vector3<T>::operator+=(const Vector3& vec)
	{
		this = this + vec;
		return *this;
	}

	template<class T>
	const Vector3<T>& BHive::Vector3<T>::operator-()
	{
		return Vector3(-this->X,-this->Y, -this->Z);
	}

	template<class T>
	const Vector3<T>& BHive::Vector3<T>::operator-(const Vector3& vec) const
	{
		return Vector3(this->X - vec.X, this->Y - vec.Y, this->Z - vec.Z);
	}

	template<class T>
	Vector3<T>& BHive::Vector3<T>::operator-=(const Vector3& vec)
	{
		this = this - vec;
		return *this;
	}

	template<class T>
	const Vector3<T>& BHive::Vector3<T>::operator*(const T& scaler) const
	{
		return Vector3(this->X * scaler, this->Y * scaler, this->Z * scaler);
	}

	template<class T>
	Vector3<T>& BHive::Vector3<T>::operator*=(const T& scaler)
	{
		X *= scaler;
		Y *= scaler;
		Z *= scaler;

		return *this;
	}

	template<class T>
	const Vector3<T>& BHive::Vector3<T>::operator/(const T& scaler) const
	{
		return Vector3(this->X / scaler, this->Y / scaler, this->Z / scaler);
	}

	template<class T>
	const T BHive::Vector3<T>::operator*(const Vector3& vec) const
	{
		return A.X * B.X + A.Y * B.Y + A.Z * B.Z;
	}

	template<class T>
	const Vector3<T>& BHive::Vector3<T>::operator^(const Vector3& vec) const
	{

	}

	template<class T>
	const T BHive::Vector3<T>::Length()
	{
		return std::sqrt(LengthSquared());
	}

	template<class T>
	const T BHive::Vector3<T>::LengthSquared()
	{
		return X * X + Y * Y + Z * Z;
	}

	template<class T>
	const Vector3<T> BHive::Vector3<T>::Unit() const
	{
		if (LengthSquared() != 0)
		{
			return *this / Length();
		}

		return *this;
	}

	template<class T>
	float BHive::Vector3<T>::Dot(const Vector3& A, const Vector3& B)
	{
		return A * B;
	}

	template<class T>
	Vector3<T> BHive::Vector3<T>::Cross(const Vector3& A, const Vector3& B)
	{
		return A ^ B;
	}
}

#endif // FVECTOR_H
