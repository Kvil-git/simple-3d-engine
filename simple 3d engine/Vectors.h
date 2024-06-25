#pragma once

template<class Type> class Vector2 {
	private:
		Type x, y;

};

template<class Type> class Vector3 {
	private:
		Type x, y, z;
	public:
		Vector3 normal();
		void normalize();

		Type magnitude();
		Type length();

		void operator=(const Vector3& other);
		void operator+=(const Vector3& other);
		template<typename ScalarType> void operator*=(const ScalarType scalar);
		template<typename ScalarType> void operator/=(const ScalarType scalar);

		Vector3 operator+(const Vector3& other);
		Vector3 operator*(const Vector3& other);
		template<typename ScalarType> Vector3 operator*(const ScalarType other);
		template<typename ScalarType> Vector3 operator/(const ScalarType other);

		Vector3 dotProduct(const Vector3& other);
		Vector3 scalarProduct(const Vector3& other);

		Vector3 crossProduct(const Vector3& other);

};

