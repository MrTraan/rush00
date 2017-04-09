#include "../includes/Ennemy.class.hpp"
#include "../includes/Game.class.hpp"

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
	alive = false;
}

void Ennemy::update() {
	for (Node* itr = Game::getGameObjectManager()._gameObjectList.begin(); itr;
	     itr = itr->next) {
		if (itr->go != this) {  // prevent self collision
			if (collide(*(itr->go))) {
				itr->go->collideWithEnnemy();
			}
		}
	}
}
