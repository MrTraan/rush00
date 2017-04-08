#include "Laser.class.hpp"
#include <debug.hpp>
#include <sstream>

Laser::Laser(void) : _speed(Laser::defaultSpeed) {
	_shape = Shape(1, 1, 0, 0, "|");
}

Laser::Laser(Vector2 pos, Vector2 speed) : _speed(speed) {
	_shape = Shape(1, 1, pos.x, pos.y, "|");
}

Laser::Laser(const Laser& src) {
	*this = src;
}

Laser::~Laser(void) {}

Laser& Laser::operator=(const Laser& rhs) {
	_speed = rhs.getSpeed();
	return *this;
}

Vector2 Laser::getSpeed() const {
	return _speed;
}

void Laser::setSpeed(int x, int y) {
	_speed.x = x;
	_speed.y = y;
}

void Laser::setSpeed(Vector2 v) {
	_speed = v;
}

void Laser::update() {
	Vector2 pos = _shape.getPosition();

	pos.y += _speed.y;
	pos.x += _speed.x;

	_shape.setPosition(pos);
}

Vector2 Laser::defaultSpeed(0, -1);
