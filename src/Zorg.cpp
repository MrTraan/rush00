#include "../includes/Zorg.hpp"

Zorg::Zorg(void) {}

Zorg::Zorg(Shape s) : GameObject(s) {
	_behaviour[0].x = 1;
	_behaviour[0].y = 0;

	_behaviour[1].x = 1;
	_behaviour[1].y = 0;

	_behaviour[2].x = 1;
	_behaviour[2].y = 0;

	_behaviour[3].x = 1;
	_behaviour[3].y = 0;

	_behaviour[4].x = 1;
	_behaviour[4].y = 0;

	_behaviour[5].x = 1;
	_behaviour[5].y = 0;

	_behaviour[6].x = -1;
	_behaviour[6].y = 1;

	_behaviour[7].x = -1;
	_behaviour[7].y = 1;

	_behaviour[8].x = -1;
	_behaviour[8].y = 1;

	_behaviour[9].x = -1;
	_behaviour[9].y = 1;

	_behaviour[10].x = -1;
	_behaviour[10].y = 1;

	_behaviour[10].x = -1;
	_behaviour[10].y = 1;
}

Zorg::Zorg(Zorg const& src) {
	// std::cout<<"Copy constructor called"<<std::endl;
	*this = src;
}

Zorg::~Zorg(void) {
	// std::cout<<"Destructor called"<<std::endl;
}

void Zorg::collideWithPlayerLaser() {
	alive = false;
}

void Zorg::update() {
	Vector2 pos = _shape.getPosition();

	if (Game::tick % 2) {
		if (_ind > 10)
			_ind = 0;
		pos.x += _behaviour[_ind].x;
		pos.y += _behaviour[_ind].y;
		_ind++;
	}


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

Zorg& Zorg::operator=(Zorg const& rhs) {
	// std::cout<<"Assignation operator called"<<std::endl;
	if (&rhs != this)
		_ind = rhs._ind;
	return *this;
}
