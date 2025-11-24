#include "Point.hpp"

Point::Point()
{
	std::cout << "Point default constructor called\n";
	x = Fixed(0);
	y = Fixed(0);
}

Point::~Point()
{
	std::cout << "Point destructor called\n";
}

Point::Point(const float xs, const float ys)
{
	std::cout << "Point constructor called\n";
	x = Fixed(xs);
	y = Fixed(ys);
}

Point::Point(const Point &other)
{
	x = other.x;
	y = other.y;
	std::cout << "Point copy constructor called\n";
}

Point& Point::operator=(const Point &other)
{
	if (this != &other)
	{
		x = other.x;
		y = other.y
		std::cout << "Point assignment operator called\n";
	}
	return *this;
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	
}
