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
