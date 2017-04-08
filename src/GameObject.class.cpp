#include "GameObject.class.hpp"

GameObject::GameObject(void) {}

GameObject::GameObject(const GameObject& src) {
	*this = src;
}

GameObject::~GameObject(void) {}

GameObject& GameObject::operator=(const GameObject& rhs) {
	(void)rhs;
	return *this;
}

void GameObject::draw(NDisplay& window) {
	window.draw(_shape);
}

void GameObject::update() {}

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