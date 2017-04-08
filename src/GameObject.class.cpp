#include "../includes/GameObject.class.hpp"
//#include <debug.hpp>

GameObject::GameObject(void) : alive(true) {}

GameObject::GameObject(Shape s) : alive(true), _shape(s) {}

GameObject::GameObject(const GameObject& src) {
	*this = src;
}

GameObject::~GameObject(void) {}

GameObject& GameObject::operator=(const GameObject& rhs) {
	_shape = rhs.getShape();
	alive = rhs.alive;
	return *this;
}

void GameObject::draw(NDisplay& window) {
	window.draw(_shape);
}

void GameObject::update() {
	setPosition(getPosition().x, getPosition().y + 1);
}

int GameObject::getWidth() const {
	return _shape.getWidth();
}

int GameObject::getHeight() const {
	return _shape.getHeight();
}

void GameObject::setPosition(int x, int y) {
	_shape.setPosition(x, y);
}

Vector2 GameObject::getPosition() const {
	return _shape.getPosition();
}

void GameObject::setShape(Shape s) {
	_shape = s;
}

Shape const& GameObject::getShape() const {
	return _shape;
}
