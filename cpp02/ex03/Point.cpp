#include "Point.hpp"

Point::Point() : x( Fixed(0) ), y( Fixed (0) )
{
	std::cout << "Point default constructor called\n";
}

Point::~Point()
{
	std::cout << "Point destructor called\n";
}

Point::Point(const float xs, const float ys) : x( Fixed(xs) ), y( Fixed (ys) )
{
	std::cout << "Point constructor called\n";
}

Point::Point(const Point &other) : x( Fixed(other.x) ), y( Fixed (other.y) )
{
	//std::cout << "Point copy constructor called\n";
}

Point& Point::operator=(const Point &other)
{
	if (this != &other)
		std::cout << "Point assignment operator called\n";
	return *this;
}

const Fixed &Point::get_x( void ) const
{
	return this->x;
}

const Fixed &Point::get_y( void ) const
{
	return this->y;
}

float Point::to_edge(Fixed const Ax, Fixed const Ay, Fixed const Bx, Fixed const By) const
{
	Fixed neo((Bx - Ax) * (y - Ay) - (By - Ay) * (x - Ax));
	return neo.toFloat();
}
