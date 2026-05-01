#include "PmergeMe.hpp"

unsigned int get_a_pos(s_deq &res, unsigned int max) { return (res.size() - max); }

void binary_insert(s_deq &res, a_deq &lo, unsigned int end)
{
	if (!end) { end = res.size(); }
	unsigned int beg = 0;
	unsigned int pos;
	while (true) {
		pos = beg + (end - beg) /2;
		if (pos == end) { break ; }
		unsigned int compare = res[pos].second.back();
		if (!cmp(lo.back(), compare)) { beg = pos +1; }
		else if (beg == pos) { break ; }
		else { end = pos; }
		
	}
	makePair(res, lo, pos);
}

void makePair(s_deq &to_add, a_deq &add)
{
	a_deq tmp1;
	a_deq tmp2;
	unsigned int n = 0;
	unsigned int size = add.size();
	for (a_deq::iterator it = add.begin(); it != add.end(); it++) {
		if (n < size / 2)
			tmp1.push_back(*it);
		else
			tmp2.push_back(*it);
		n++;
	}
	to_add.push_back(std::pair<a_deq, a_deq>(tmp1, tmp2));
}

//makePair, but inserted
void makePair(s_deq &to_add, a_deq &add, unsigned int index)
{
	a_deq tmp1;
	a_deq tmp2;
	unsigned int n = 0;
	unsigned int size = add.size();
	for (a_deq::iterator it = add.begin(); it != add.end(); it++) {
		if (n < size / 2)
			tmp1.push_back(*it);
		else
			tmp2.push_back(*it);
		n++;
	}
	to_add.insert((to_add.begin() + index), std::pair<a_deq, a_deq>(tmp1, tmp2));
}
