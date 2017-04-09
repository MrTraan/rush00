#include "../includes/Ennemy.class.hpp"

Ennemy::Ennemy(void) {}

Ennemy::Ennemy(Shape s) : GameObject(s) {}

Ennemy::Ennemy(const Ennemy& src) {
	*this = src;
}

Ennemy::~Ennemy(void) {}

Ennemy& Ennemy::operator=(const Ennemy& rhs) {
	_shape = rhs.getShape();
	return *this;
}

void Ennemy::collideWithPlayerLaser() {
	printf("\a");
	alive = false;
}

void Ennemy::update() {
	Vector2 pos = _shape.getPosition();

	if (Game::tick % 6 == 0)
		pos.y += 1;
	// pos.x += _speed.x;

	_shape.setPosition(pos);


	for (Node* itr = Game::getGameObjectManager()._gameObjectList.begin(); itr;
	     itr = itr->next) {
		if (itr->go != this) {  // prevent self collision
			if (collide(*(itr->go))) {
				itr->go->collideWithEnnemy();
			}
		}
	}
}
