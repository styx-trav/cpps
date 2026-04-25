#include <vector>
#include <iostream>
#include <cstring>

typedef std::vector<std::pair<std::vector<unsigned int>,std::vector<unsigned int> > > s_list;
typedef std::vector<unsigned int> a_list;

int comps = 0;

//future regular pass here, testing for now so just one level
s_list phase_one(s_list l, std::vector<a_list> &lo)
{
	if (l.size() < 2) { return l; } //approx
	s_list res;
	for (s_list::iterator it = l.begin(); it != l.end(); it++)
	{
		s_list::iterator prev = it;
		it++;
		if (it == l.end()) {
			a_list tmp;
			for (a_list::iterator itt = prev->first.begin(); itt != prev->first.end(); itt++)
				tmp.push_back(*itt);
			for (a_list::iterator itt = prev->second.begin(); itt != prev->second.end(); itt++)
				tmp.push_back(*itt);
			lo.push_back(tmp);
			return phase_one(res, lo);
		}
		a_list tmp1;
		a_list tmp2;
		if (it->second.back() < prev->second.back()) {
			for (a_list::iterator itt = prev->first.begin(); itt != prev->first.end(); itt++)
				tmp2.push_back(*itt);
			for (a_list::iterator itt = prev->second.begin(); itt != prev->second.end(); itt++)
				tmp2.push_back(*itt);
			for (a_list::iterator itt = it->first.begin(); itt != it->first.end(); itt++)
				tmp1.push_back(*itt);
			for (a_list::iterator itt = it->second.begin(); itt != it->second.end(); itt++)
				tmp1.push_back(*itt);
		}
		else {
			for (a_list::iterator itt = prev->first.begin(); itt != prev->first.end(); itt++)
				tmp1.push_back(*itt);
			for (a_list::iterator itt = prev->second.begin(); itt != prev->second.end(); itt++)
				tmp1.push_back(*itt);
			for (a_list::iterator itt = it->first.begin(); itt != it->first.end(); itt++)
				tmp2.push_back(*itt);
			for (a_list::iterator itt = it->second.begin(); itt != it->second.end(); itt++)
				tmp2.push_back(*itt);
		}
		res.push_back(std::pair<a_list, a_list>(tmp1, tmp2));
	}
	return phase_one(res, lo);
}

//first pass here, create first pair list
s_list phase_one(std::vector<unsigned int> l, std::vector<std::vector<unsigned int> > &lo)
{
	s_list res;
	for (a_list::iterator it = l.begin(); it != l.end(); it++) {
		a_list::iterator prev = it;
		it++;
		if (it == l.end()) {
			a_list tmp;
			tmp.push_back(*prev);
			lo.push_back(tmp);
			return phase_one(res, lo);
		}
		a_list tmp1;
		a_list tmp2;
		if (*it < *prev) {
			tmp1.push_back(*it);
			tmp2.push_back(*prev);
		}
		else {
			tmp2.push_back(*it);
			tmp1.push_back(*prev);
		}
		res.push_back(std::pair<a_list, a_list>(tmp1, tmp2));
	}
	return phase_one(res, lo);
}

//utils for adding a new pair (ex: b1 || a1)
void makePair(s_list &to_add, a_list &add)
{
	a_list tmp1;
	a_list tmp2;
	unsigned int n = 0;
	unsigned int size = add.size();
	for (a_list::iterator it = add.begin(); it != add.end(); it++) {
		switch (n < size / 2) {
			case true :
				tmp1.push_back(*it);
				break ;
			default :
				tmp2.push_back(*it);
				break ;
		}
		n++;
	}
	to_add.push_back(std::pair<a_list, a_list>(tmp1, tmp2));
}

//adding a new pair, but inserted
void makePair(s_list &to_add, a_list &add, unsigned int index)
{
	a_list tmp1;
	a_list tmp2;
	unsigned int n = 0;
	unsigned int size = add.size();
	for (a_list::iterator it = add.begin(); it != add.end(); it++) {
		switch (n < size / 2) {
			case true :
				tmp1.push_back(*it);
				break ;
			default :
				tmp2.push_back(*it);
				break ;
		}
		n++;
	}
	to_add.insert((to_add.begin() + index), std::pair<a_list, a_list>(tmp1, tmp2));
}

unsigned int get_js(unsigned int n) //hardcoded for now, equation later
{
	switch (n) {
		case 1 :
			return 3;
		case 2 :
			return 5;
		case 3 :
			return 11;
		case 4 :
			return 21;
		default :
			return 100;
	}
	return 0;
}

bool cmp(unsigned int b, unsigned int a) { comps++; return (b <= a); }

void binary_insert(s_list &res, a_list &lo, unsigned int end)
{
	if (!end) { end = res.size(); }
	unsigned int beg = 0;
	unsigned int pos;
	unsigned int i = 0;
	while (true) {
		pos = beg + (end - beg) /2 +1;
		if (pos == 0) { std::cout << "error here :: for end " << end << ", beg " << beg << std::endl; return ; }
		if (pos == res.size()) { std::cout << "pos at end " << pos << ", adding\n"; makePair(res, lo); return ; }
		std::cout << "scouring " << beg << " to " << end << ", pos " << pos << std::endl;
		unsigned int prev = res[pos -1].second.back();
		unsigned int next = res[pos].second.back();
		std::cout << "comparing " << prev << " to " << lo.back() << " to " << next << std::endl;
		if (i > 87) { return ; }
		i++;
		if (!cmp(prev, lo.back())) {
			if (pos-1) { end = pos -1; }
			else { makePair(res, lo, pos -1); return ; }
		}
		else if (!cmp(lo.back(), next)) {
			if (pos != end) { beg = pos; }
			else { makePair(res, lo, pos + 1) ; return ;}
		}
		else {  break ;}
	}
	makePair(res, lo, pos);
}

unsigned int get_a_pos(s_list &res, unsigned int a, unsigned int min)
{
	unsigned int i = res.size() - min -1;
	std::cout << "currently seeking value " << a << " in res, from " << i;
	while (i && res[i].second.back() >= a)
		i--;
	std::cout << ", result, " << i << std::endl;
	return i;
}

s_list phase_two(s_list l, std::vector<a_list> &lo)
{
	s_list res;
	//set up :: add b1 and a1 to the main
	makePair(res, l.begin()->first);
	makePair(res, l.begin()->second);
	//setup over, next part only happens if l.size() > 1
	unsigned int n = 1;
	unsigned int js;
	unsigned int prev = 1;
	while ((js = get_js(n)) <= l.size()) {
		n++;
		for (unsigned int i = prev; i != js; i++)
			makePair(res, l[i].second);
		for (unsigned int i = js -1; i >= prev; i--)
			binary_insert(res, l[i].first, get_a_pos(res, l[i].second.back(), i - prev));
		prev = js;
	}
	if (prev != l.size()) {
		for (unsigned int i = prev; i != l.size(); i++)
			makePair(res, l[i].second);
		for (unsigned int i = l.size() -1; i >= prev; i--)
			binary_insert(res, l[i].first, get_a_pos(res, l[i].second.back(), i - prev));
	}
	if (lo.back().size() == l.front().first.size()) {
		binary_insert(res, lo.back(), 0);
		lo.erase(--lo.end());
	}
	if (!(res.front().first.empty())) { return phase_two(res, lo); }
	return res;
}

#include <cmath>

int F(int n)
{
    int sum = 0;
    for (int k = 1; k <= n; ++k) {
        double value = (3.0 / 4.0) * k;
        sum += static_cast<int>(ceil(log2(value)));
    }
    return sum;
}

int main()
{
	std::vector<unsigned int> nerf;
	unsigned int ner[19] = {16, 14, 2, 5, 18, 17, 13, 4, 11, 1, 10, 8, 9, 12, 7, 3, 15, 19};
	//{12, 8, 2, 6, 1, 10, 14, 3, 4, 11, 15, 13, 7, 18, 19, 9, 16, 17, 5};
	//{3, 7, 11, 19, 13, 4, 15, 2, 12, 6, 14, 8, 18, 10, 17, 16, 1, 9, 5};
	//{4, 57, 8, 6, 44, 2, 0, 81, 10, 7, 3, 1, 42, 75, 44, 11, 25, 98, 9};
	for (int i = 0; i != 19; i++)
		nerf.push_back(ner[i]);
	std::vector<std::vector<unsigned int> > leftovers;
	s_list res = phase_one(nerf, leftovers);
	int i = 1;
	for (s_list::iterator it = res.begin(); it != res.end(); it++) {
		std::cout << "b" << i << " { ";
		for (std::vector<unsigned int>::iterator itt = it->first.begin(); itt != it->first.end(); itt++)
			std::cout << *itt << ", ";
		std::cout << "}, a" << i << " { ";
		for (std::vector<unsigned int>::iterator itt = it->second.begin(); itt != it->second.end(); itt++)
			std::cout << *itt << ", ";
		std::cout << "}\n";
		i++;
	}
	if (!leftovers.empty()) {
		std::cout << "leftovers : { ";
		for (std::vector<std::vector<unsigned int> >::iterator it = leftovers.begin(); it != leftovers.end(); it++) {
			std::cout << "\n\t{ ";
			for (std::vector<unsigned int>::iterator itt = it->begin(); itt != it->end(); itt++)
				std::cout << *itt << ", ";
			std::cout << "}";
		}
		std::cout << "\n}\n";
	}
	std::cout << "phase two pt1 starts ------------------------------------------------------------------\n";
	res = phase_two(res, leftovers);
	std::cout << "phase two pt1 over --------------------------------------------------------------------\n";
	i = 1;
	for (s_list::iterator it = res.begin(); it != res.end(); it++) {
		std::cout << "b" << i << " { ";
		for (std::vector<unsigned int>::iterator itt = it->first.begin(); itt != it->first.end(); itt++)
			std::cout << *itt << ", ";
		std::cout << "}, a" << i << " { ";
		for (std::vector<unsigned int>::iterator itt = it->second.begin(); itt != it->second.end(); itt++)
			std::cout << *itt << ", ";
		std::cout << "}\n";
		i++;
	}
	if (!leftovers.empty()) {
		std::cout << "leftovers : { ";
		for (std::vector<std::vector<unsigned int> >::iterator it = leftovers.begin(); it != leftovers.end(); it++) {
			std::cout << "\n\t{ ";
			for (std::vector<unsigned int>::iterator itt = it->begin(); itt != it->end(); itt++)
				std::cout << *itt << ", ";
			std::cout << "}";
		}
		std::cout << "\n}\n";
	}
	std::cout << "show me max comparisons for 19 : " << F(19) << " v our amount " << comps << std::endl;
}
