#pragma once

#include <GameObject.class.hpp>
#include <Vector2.class.hpp>

class Laser : public GameObject {
   public:
	Laser(void);
	Laser(const Laser& src);
	Laser(Vector2 pos, Vector2 speed);
	~Laser(void);

	Laser& operator=(const Laser& rhs);

	void update();

	Vector2 getSpeed() const;
	void setSpeed(int x, int y);
	void setSpeed(Vector2 v);

	static Vector2 defaultSpeed;

   private:
	Vector2 _speed;
};
