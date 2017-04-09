#pragma once

#include <Shape.hpp>
#include <NDisplay.hpp>
#include <Vector2.class.hpp>

class GameObject {
   public:
	GameObject(void);
	GameObject(Shape s);
	GameObject(const GameObject& src);
	virtual ~GameObject(void);

	GameObject& operator=(const GameObject& rhs);

	virtual void draw(NDisplay& window);
	virtual void update();

	virtual bool collide(GameObject& go);
	virtual void collideWithPlayerLaser();
	virtual void collideWithEnnemy();
	virtual void collideWithEnnemyLaser();

	int getWidth() const;
	int getHeight() const;

	void setPosition(int x, int y);
	Vector2 getPosition() const;

	void setShape(Shape s);
	Shape const& getShape() const;

	bool alive;

   protected:
	Shape _shape;
};
