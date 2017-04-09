#include "../includes/GameObject.class.hpp"

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
	Vector2 pos = _shape.getPosition();
		pos.y += 3;

	_shape.setPosition(pos.x, pos.y);
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

void GameObject::collideWithPlayerLaser() {}
void GameObject::collideWithEnnemy() {}
void GameObject::collideWithEnnemyLaser() {}

bool valueInRange(int value, int min, int max) {
	return (value >= min) && (value <= max);
}

bool GameObject::collide(GameObject& go) {
	if (go.getShape().getshape() == "o" || this->getShape().getshape() == "o")
		return false;
	Shape const& oShape = go.getShape();

	bool xOverlap = valueInRange(_shape.getPosX(), oShape.getPosX(),
	                             oShape.getPosX() + oShape.getWidth()) ||
	                valueInRange(oShape.getPosX(), _shape.getPosX(),
	                             _shape.getPosX() + _shape.getWidth());

	bool yOverlap = valueInRange(_shape.getPosY(), oShape.getPosY(),
	                             oShape.getPosY() + oShape.getHeight()) ||

	                valueInRange(oShape.getPosY(), _shape.getPosY(),
	                             _shape.getPosY() + _shape.getHeight());

	return xOverlap && yOverlap;
}
