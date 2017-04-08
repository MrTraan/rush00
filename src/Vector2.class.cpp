#include <Vector2.class.hpp>

Vector2::Vector2(void) {}

Vector2::Vector2(int a, int b) : x(a), y(b) {}

Vector2::Vector2(const Vector2& src) {
	*this = src;
}

Vector2::~Vector2(void) {}

Vector2& Vector2::operator=(const Vector2& rhs) {
	x = rhs.x;
	y = rhs.y;
	return *this;
}

Vector2 operator+(const Vector2& v1, const Vector2& v2) {
	return Vector2(v1.x + v2.x, v2.y + v2.y);
}

std::ostream& operator<<(std::ostream& os, const Vector2& v) {
	os << "{x: " << v.x << ", y: " << v.y << "}";
	return os;
}
