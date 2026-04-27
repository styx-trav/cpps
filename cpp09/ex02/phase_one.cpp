#include <vector>
#include <iostream>
#include <cstring>
#include <sstream>
#include <cmath>

typedef std::vector<std::pair<std::vector<unsigned int>,std::vector<unsigned int> > > s_list;
typedef std::vector<unsigned int> a_list;

void print_res(s_list &res, std::vector<a_list> &leftovers);

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
		comps++;
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
s_list phase_one(std::vector<unsigned int> &l, std::vector<std::vector<unsigned int> > &lo)
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

unsigned int get_js(unsigned int n) //equation, approximated
{
	double s = (pow(2, n+1) + pow(-1, n)) / 3;
	return static_cast<unsigned int>(s);
}

bool cmp(unsigned int b, unsigned int a) { comps++; return (b <= a); }

void binary_insert(s_list &res, a_list &lo, unsigned int end)
{
	if (!end) { end = res.size(); }
	unsigned int beg = 0;
	unsigned int pos;
	while (true) {
		pos = beg + (end - beg) /2;
		//if (beg == res.size()) { std::cout << "beg == size(), adding\n"; break ; }
		if (pos == end) { std::cout << "pos at the end of the list ! adding " << lo.back(); break ; }
		std::cout << "scouring " << beg << ":" << res[beg].second.back() << " to " << end;
		if (end == res.size()) { std::cout << ":end"; }
		else
			std::cout << ":" << res[end].second.back();
		std::cout << ", pos " << pos << " for " << lo.back() << std::endl;
		unsigned int compare = res[pos].second.back();
		if (!cmp(lo.back(), compare)) { beg = pos +1; }
		else if (beg == pos) { break ; }
		else { end = pos; }
		
	}
	std::cout << "adding " << lo.back() << ", in between\n";
	makePair(res, lo, pos);
}

unsigned int get_a_pos(s_list &res, unsigned int a)
{
	unsigned int i = res.size() -1;
	while (i && res[i].second.back() >= a)
		i--;
	return ++i;
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
			binary_insert(res, l[i].first, get_a_pos(res, l[i].second.back()));
		prev = js;
	}
	if (prev != l.size()) {
		for (unsigned int i = prev; i != l.size(); i++)
			makePair(res, l[i].second);
		for (unsigned int i = l.size() -1; i >= prev; i--)
			binary_insert(res, l[i].first, get_a_pos(res, l[i].second.back()));
	}
	if (!lo.empty() && lo.back().size() == l.front().first.size()) {
		binary_insert(res, lo.back(), 0);
		lo.erase(--lo.end());
	}
	//print_res(res, lo);
	//std::cout << "\n-------------------------------------------\n";
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

void setup(std::string str, std::vector<unsigned int> &ref)
{
	std::stringstream s(str);
	std::string current;
	while (!s.eof()) {
		getline(s, current);
		if (current.empty()) { continue ; }
		int n = std::atoi(current.c_str());
		if (n < 0) { std::cerr << "negative number !\n"; throw std::exception(); }
		ref.push_back(n);
	}
}

bool verify(s_list &res);

int main(int argc, char **argv)
{
	if (argc != 2) { std::cerr << "proper usage : ./pMerge \"[list of positive numbers here]\"\n"; return 0; }
	std::vector<unsigned int> nerf;
	try { setup(argv[1], nerf); }
	catch (std::exception &e) { return 0; }
	std::vector<std::vector<unsigned int> > leftovers;
	s_list res = phase_one(nerf, leftovers);
	print_res(res, leftovers);
	std::cout << "phase two starts ------------------------------------------------------------------\n";
	res = phase_two(res, leftovers);
	std::cout << "phase two over --------------------------------------------------------------------\n";
	print_res(res, leftovers);
	std::cout << "is list ordered ? " << verify(res) << std::endl;
	std::cout << "show me max comparisons for " << nerf.size() << " : " << F(nerf.size()) << " v our amount " << comps << std::endl;
	return 0;
}

void print_res(s_list &res, std::vector<a_list> &leftovers)
{
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
}

bool verify(s_list &res)
{
	s_list::iterator prev = res.begin();
	for (s_list::iterator it = ++res.begin(); it != res.end(); it++) {
		if (it->second.back() < prev->second.back()) { return false; }
		prev = it;
	}
	return true;
}
