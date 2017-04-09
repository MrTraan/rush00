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

	_behaviour[5].x = 1;			//c'est degeu, je sais...dsl :p
	_behaviour[5].y = 0;

	_behaviour[6].x = 1;
	_behaviour[6].y = 0;

	_behaviour[7].x = 1;
	_behaviour[7].y = 0;

	_behaviour[8].x = 1;
	_behaviour[8].y = 0;

	_behaviour[9].x = 1;
	_behaviour[9].y = 0;

	_behaviour[10].x = 1;
	_behaviour[10].y = 0;

	_behaviour[11].x = 1;			//c'est degeu, je sais...dsl :p
	_behaviour[11].y = 0;

	_behaviour[12].x = -1;
	_behaviour[12].y = 1;

	_behaviour[13].x = -1;
	_behaviour[13].y = 1;

	_behaviour[14].x = -1;
	_behaviour[14].y = 1;

	_behaviour[15].x = -1;
	_behaviour[15].y = 1;

	_behaviour[16].x = -1;
	_behaviour[16].y = 1;

	_behaviour[17].x = -1;
	_behaviour[17].y = 1;

	_behaviour[18].x = -1;
	_behaviour[18].y = 1;

	_behaviour[19].x = -1;
	_behaviour[19].y = 1;

	_behaviour[20].x = -1;
	_behaviour[20].y = 1;

	_behaviour[21].x = -1;
	_behaviour[21].y = 1;
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
		if (_ind > IND - 1) {
			_ind = 0;
		}
		pos.x += _behaviour[_ind % IND].x;
		pos.y += _behaviour[_ind % IND].y;
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
		_ind = 0;
	return *this;
}
