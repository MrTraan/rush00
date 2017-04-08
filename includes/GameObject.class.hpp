#pragma once

#include <Shape.hpp>
#include <NDisplay.hpp>
#include <Vector2.class.hpp>

class GameObject {
   public:
	GameObject(void);
	GameObject(const GameObject& src);
	virtual ~GameObject(void);

	GameObject& operator=(const GameObject& rhs);

	virtual void draw(NDisplay& window);
	virtual void update();

	virtual int getWidth() const;
	virtual int getHeight() const;

	virtual void setPosition(int x, int y);
	virtual Vector2 getPosition() const;

   private:
	Shape _shape;
};