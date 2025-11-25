#include "Point.hpp"

//5, 0 should be yes;
// -5, 6 should be no;
//a vertice should also be no
//there's so much copy constructions going on, though, it feels like i might be able to cut that down if I really put my mind to it (ie read up on why const arguments seem to drag me into so many copies;
//last necessary step :: figure out the assign operator overload given the const nature of our private members -- do I just not touch them ? seems weird to ask

int main()
{
	const Point a(15.5, -6.2);
	const Point b(2.1, -1.2);
	const Point c(5.6, 2.6);
	const Point p(2.1, -1.2);
	std::cout << "is that point in the triangle ? answer : " << bsp(a, b, c, p) << std::endl;
}
