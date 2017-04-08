#ifndef SHAPE_HPP
# define SHAPE_HPP

#include <iostream>

class Shape
{

public:

	Shape(int width, int height, int posX, int posY, std::string shape);
	Shape(Shape const &src);
	~Shape(void);

	int getWidth(void);
	int getHeight(void);
	int getPosX(void);
	int getPosY(void);
	std::string getshape(void);

	Shape &operator=(Shape const &rhs);

private:
	int _width;
	int _height;
	int _posX;
	int _posY;
	std::string _shape;

	Shape(void);

};

#endif