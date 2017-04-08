#include "../includes/Shape.hpp"


Shape::Shape() : _width(0), _height(0), _posX(0), _posY(0), _shape("") {}

Shape::Shape(int width, int height, int posX, int posY, std::string shape)
    : _width(width), _height(height), _posX(posX), _posY(posY), _shape(shape) {
	// std::cout<<"Default constructor called"<<std::endl;
}

Shape::Shape(Shape const& src) {
	// std::cout<<"Copy constructor called"<<std::endl;
	*this = src;
}

Shape::~Shape(void) {
	// std::cout<<"Destructor called"<<std::endl;
}

int Shape::getWidth(void) const {
	return _width;
}
int Shape::getHeight(void) const {
	return _height;
}
int Shape::getPosX(void) const {
	return _posX;
}
int Shape::getPosY(void) const {
	return _posY;
}
std::string Shape::getshape(void) const {
	return _shape;
}

Shape& Shape::operator=(Shape const& rhs) {
	// std::cout<<"Assignation operator called"<<std::endl;
	if (&rhs != this) {
		_width = rhs._width;
		_height = rhs._height;
		_posX = rhs._posX;
		_posY = rhs._posY;
		std::string _shape = rhs._shape;
	}

	return *this;
}

void Shape::setPosition(int x, int y) {
	_posX = x;
	_posY = y;
}

void Shape::setPosition(Vector2 v) {
	_posX = v.x;
	_posY = v.y;
}

Vector2 Shape::getPosition() const {
	return Vector2(_posX, _posY);
}

void Shape::setShape(std::string s) {
	_shape = s;
}
