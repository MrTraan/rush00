#include "../includes/Shape.hpp"


Shape::Shape(int width, int height, int posX, int posY, std::string shape) : _width(width), _height(height), _posX(posX), _posY(posY), _shape(shape)
{
	//std::cout<<"Default constructor called"<<std::endl;
}

Shape::Shape(Shape const &src)
{
	//std::cout<<"Copy constructor called"<<std::endl;
	*this = src;
}

Shape::~Shape(void)
{
	//std::cout<<"Destructor called"<<std::endl;
}

int Shape::getWidth(void) { return _width; }
int Shape::getHeight(void) { return _height; }
int Shape::getPosX(void) { return _posX; }
int Shape::getPosY(void) { return _posY; }
std::string Shape::getshape(void) { return _shape; }

Shape &Shape::operator=(Shape const &rhs)
{
	//std::cout<<"Assignation operator called"<<std::endl;
	if (&rhs != this)
	{
		_width = rhs._width;
		_height = rhs._height;
		_posX = rhs._posX;
		_posY = rhs._posY;
		std::string _shape = rhs._shape;
	}

	return *this;
}

