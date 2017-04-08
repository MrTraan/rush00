#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <iostream>
#include <Vector2.class.hpp>

class Shape {
   public:
	Shape();
	Shape(int width, int height, int posX, int posY, std::string shape);
	Shape(Shape const& src);
	~Shape(void);

	int getWidth(void) const;
	int getHeight(void) const;

	int getPosX(void) const;
	int getPosY(void) const;
	Vector2 getPosition() const;
	std::string getshape(void) const;

	Shape& operator=(Shape const& rhs);

	void setPosition(int x, int y);
	void setPosition(Vector2 v);

	void setShape(std::string s);

   private:
	int _width;
	int _height;
	int _posX;
	int _posY;
	std::string _shape;
};

#endif
