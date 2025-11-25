#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	float res1 = point.to_edge(a.get_x(), a.get_y(), b.get_x(), b.get_y());
	float res2 = point.to_edge(b.get_x(), b.get_y(), c.get_x(), c.get_y());
	float res3 = point.to_edge(c.get_x(), c.get_y(), a.get_x(), a.get_y());
	if ((res1 < 0) && (res2 < 0) && (res3 < 0))
		return true;
	if ((res1 > 0) && (res2 > 0) && (res3 > 0))
		return true;
	return false;
}
