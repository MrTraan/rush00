#pragma once

#include "GameObject.class.hpp"
#include "game.class.hpp"
#include "Vector2.class.hpp"

class Ennemy : public GameObject {
   public:
	Ennemy(void);
	Ennemy(Shape s);
	Ennemy(const Ennemy& src);
	~Ennemy(void);

	Ennemy& operator=(const Ennemy& rhs);

	void collideWithPlayerLaser();

	virtual void update();

};
