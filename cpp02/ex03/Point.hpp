#ifndef POINT_HPP
# define POINT_HPP
# include <iostream>
# include "Fixed.hpp"


class Point
{
	private:
		const Fixed x;
		const Fixed y;
	public:
		Point();
		~Point();
		Point(const float xs, const float ys);
		Point(const Point &other);
		//Point &operator=(const Point &other) : x( Fixed(other.x) ), y( Fixed (other.y) ){return *this};
		float to_edge(Fixed const Ax, Fixed const Ay, Fixed const Bx, Fixed const By) const;
		const Fixed &get_x() const;
		const Fixed &get_y() const;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif
