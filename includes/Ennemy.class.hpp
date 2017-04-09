#pragma once

#include "../includes/GameObject.class.hpp"

class Ennemy : public GameObject {
   public:
	Ennemy(void);
	Ennemy(Shape s);
	Ennemy(const Ennemy& src);
	~Ennemy(void);

	Ennemy& operator=(const Ennemy& rhs);

	void collideWithPlayerLaser();

	void update();
};
