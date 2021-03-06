#pragma once

#include "Shape.hpp"
#include "GameObject.class.hpp"
#include "Game.class.hpp"

#define IND 22

class Zorg : public GameObject {
   public:
   public:
	Zorg(void);
	Zorg(Shape s);
	Zorg(const Zorg& src);
	~Zorg(void);

	Zorg& operator=(const Zorg& rhs);

	void collideWithPlayerLaser();

	virtual void update();

   protected:
	Vector2 _behaviour[IND];
	int _ind;
};
