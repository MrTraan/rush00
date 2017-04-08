#pragma once

#include <GameObject.class.hpp>

class Player : public GameObject {
   public:
	Player(void);
	Player(const Player& src);
	~Player(void);

	Player& operator=(const Player& rhs);

	void update();
};
