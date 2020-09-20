#pragma once
/* This is my own header only Math library I use to make my C++ demos */

namespace MaxenceTools
{
	struct Vector2 {
		//properties
		float x;
		float y;

		//ctor
		Vector2() { x = 0; y = 0; };
		Vector2(float _x, float _y) { x = _x; y = _y; };

		//dtor
		~Vector2() {  };

		//operators
		friend Vector2 operator +(Vector2 lhs, const Vector2 rhs) { lhs.x + rhs.x; lhs.y + rhs.y; return lhs; };
		Vector2& operator +=(const Vector2 rhs) { x + rhs.x; y + rhs.y; return *this; };
		friend Vector2 operator -(Vector2 lhs, const Vector2 rhs) { lhs.x - rhs.x; lhs.y - rhs.y; return lhs; };
		Vector2& operator -=(const Vector2 rhs) { x - rhs.x; y - rhs.y; return *this; };
		friend Vector2 operator *(Vector2 lhs, const float f) { lhs.x * f; lhs.y * f; return lhs; };
		friend Vector2 operator /(Vector2 lhs, const float f) { lhs.x / f; lhs.y / f; return lhs; };
	};

	struct Vector2i {
		//properties
		int x;
		int y;

		//ctor
		Vector2i() { x = 0; y = 0; };
		Vector2i(int _x, int _y) { x = _x; y = _y; };

		//dtor
		~Vector2i() {  };

		//operators
		friend Vector2i operator +(Vector2i lhs, const Vector2i rhs) { lhs.x + rhs.x; lhs.y + rhs.y; return lhs; };
		Vector2i& operator +=(const Vector2i rhs) { x + rhs.x; y + rhs.y; return *this; };
		friend Vector2i operator -(Vector2i lhs, const Vector2i rhs) { lhs.x - rhs.x; lhs.y - rhs.y; return lhs; };
		Vector2i& operator -=(const Vector2i rhs) { x - rhs.x; y - rhs.y; return *this; };
		friend Vector2i operator *(Vector2i lhs, const float f) { lhs.x * f; lhs.y * f; return lhs; };
		friend Vector2i operator /(Vector2i lhs, const float f) { lhs.x / f; lhs.y / f; return lhs; };
	};
}