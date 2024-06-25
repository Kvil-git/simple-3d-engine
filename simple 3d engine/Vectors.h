#pragma once

class Vector2 {
	private:
		float x, y;
};

class Vector4 {
private:
	float x, y, z, h;
public:
	void operator*=(const float matrix[16]);
	Vector4 operator*(const float matrix[16]);
};

class Vector3 {
	private:
		float x, y, z;
	public:
		Vector3 normal();
		void normalize();

		float magnitude();
		float length();

		void operator=(const Vector3& other);
		void operator+=(const Vector3& other);
		void operator-=(const Vector3& other);
		void operator*=(const float matrix[9]);

		void operator*=(const float scalar);
		void operator/=(const float scalar);

		Vector3 operator*(const float matrix[9]);
		Vector3 operator+(const Vector3& other);
		Vector3 operator-(const Vector3& other);

		Vector3 operator*(const float scalar);
		Vector3 operator/(const float scalar);

		Vector3 projectionOn(const Vector3& other);
		void projectOn(const Vector3& other);

		float dotProduct(const Vector3& other);
		float scalarProduct(const Vector3& other);
		Vector3 crossProduct(const Vector3& other);

		Vector4 toHomogeneous();
};

