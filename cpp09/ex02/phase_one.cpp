#include <vector>
#include <deque>
#include <iostream>
#include <cstring>
#include <sstream>
#include <cmath>
#include <time.h>

//vector typedefs
typedef std::vector<unsigned int> a_vec;
typedef std::vector<std::pair<a_vec , a_vec> > s_vec;

//deque typedefs
typedef std::deque<unsigned int> a_deq;
typedef std::deque<std::pair<a_deq , a_deq> > s_deq;

//clock here
//setup ::
void setup(int argc, char **argv, a_vec &ref);
//full algorithm, in order ::
s_vec phase_one(a_vec &l, std::vector<a_vec> &lo); //very first pass, with a_vec nerf
s_vec phase_one(s_vec l, std::vector<a_vec> &lo); //every subsequent pass, with previous s_vec
s_vec phase_two(s_vec l, std::vector<a_vec> &lo); //phase two, starting with the last huge pair
//phase two utils
unsigned int get_a_pos(s_vec &res, unsigned int max); //slight optimisation on the "seeking a_pos"
void binary_insert(s_vec &res, a_vec &lo, unsigned int end); //binary insert algo portion
bool cmp(unsigned int b, unsigned int a); //comparison + add to comps
//final round for a_vec return
void get_res(s_vec &res, a_vec &nerf);
//clock here
//printing func (before, after)
void print_setup(a_vec &nerf);

void print_res(s_vec &res, std::vector<a_vec> &leftovers);

int comps = 0;

//future regular pass here, testing for now so just one level
s_vec phase_one(s_vec l, std::vector<a_vec> &lo)
{
	if (l.size() < 2) { return l; }
	s_vec res;
	for (s_vec::iterator it = l.begin(); it != l.end(); it++)
	{
		s_vec::iterator prev = it;
		it++;
		if (it == l.end()) {
			a_vec tmp;
			for (a_vec::iterator itt = prev->first.begin(); itt != prev->first.end(); itt++)
				tmp.push_back(*itt);
			for (a_vec::iterator itt = prev->second.begin(); itt != prev->second.end(); itt++)
				tmp.push_back(*itt);
			lo.push_back(tmp);
			return phase_one(res, lo);
		}
		a_vec tmp1;
		a_vec tmp2;
		for (a_vec::iterator itt = prev->first.begin(); itt != prev->first.end(); itt++)
			tmp1.push_back(*itt);
		for (a_vec::iterator itt = prev->second.begin(); itt != prev->second.end(); itt++)
			tmp1.push_back(*itt);
		for (a_vec::iterator itt = it->first.begin(); itt != it->first.end(); itt++)
			tmp2.push_back(*itt);
		for (a_vec::iterator itt = it->second.begin(); itt != it->second.end(); itt++)
			tmp2.push_back(*itt);
		comps++;
		if (it->second.back() < prev->second.back())
			res.push_back(std::pair<a_vec, a_vec>(tmp2, tmp1));
		else
			res.push_back(std::pair<a_vec, a_vec>(tmp1, tmp2));
	}
	return phase_one(res, lo);
}

//first pass here, create first pair list
s_vec phase_one(a_vec &l, std::vector<a_vec> &lo)
{
	s_vec res;
	for (a_vec::iterator it = l.begin(); it != l.end(); it++) {
		a_vec::iterator prev = it;
		it++;
		if (it == l.end()) {
			a_vec tmp;
			tmp.push_back(*prev);
			lo.push_back(tmp);
			return phase_one(res, lo);
		}
		a_vec tmp1;
		a_vec tmp2;
		comps++;
		if (*it < *prev) {
			tmp1.push_back(*it);
			tmp2.push_back(*prev);
		}
		else {
			tmp2.push_back(*it);
			tmp1.push_back(*prev);
		}
		res.push_back(std::pair<a_vec, a_vec>(tmp1, tmp2));
	}
	return phase_one(res, lo);
}

//utils for adding a new pair (ex: b1 || a1)
void makePair(s_vec &to_add, a_vec &add)
{
	a_vec tmp1;
	a_vec tmp2;
	unsigned int n = 0;
	unsigned int size = add.size();
	for (a_vec::iterator it = add.begin(); it != add.end(); it++) {
		if (n < size / 2)
			tmp1.push_back(*it);
		else
			tmp2.push_back(*it);
		n++;
	}
	to_add.push_back(std::pair<a_vec, a_vec>(tmp1, tmp2));
}

//adding a new pair, but inserted
void makePair(s_vec &to_add, a_vec &add, unsigned int index)
{
	a_vec tmp1;
	a_vec tmp2;
	unsigned int n = 0;
	unsigned int size = add.size();
	for (a_vec::iterator it = add.begin(); it != add.end(); it++) {
		if (n < size / 2)
			tmp1.push_back(*it);
		else
			tmp2.push_back(*it);
		n++;
	}
	to_add.insert((to_add.begin() + index), std::pair<a_vec, a_vec>(tmp1, tmp2));
}

unsigned int get_js(unsigned int n) //equation, approximated
{
	double s = (pow(2, n+1) + pow(-1, n)) / 3;
	return static_cast<unsigned int>(s);
}

bool cmp(unsigned int b, unsigned int a) { comps++; return (b <= a); }

void binary_insert(s_vec &res, a_vec &lo, unsigned int end)
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

unsigned int get_a_pos(s_vec &res, unsigned int max)
{
	return (res.size() - max);
}

s_vec phase_two(s_vec l, std::vector<a_vec> &lo)
{
	s_vec res;
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
			binary_insert(res, l[i].first, get_a_pos(res, (js - i)));
		prev = js;
	}
	if (prev != l.size()) {
		for (unsigned int i = prev; i != l.size(); i++)
			makePair(res, l[i].second);
		for (unsigned int i = l.size() -1; i >= prev; i--)
			binary_insert(res, l[i].first, get_a_pos(res, (l.size() - i)));
	}
	if (!lo.empty() && lo.back().size() == l.front().first.size()) {
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

void setup_inloop(std::string str, a_vec &ref)
{
	std::stringstream s(str);
	std::string current;
	while (!s.eof()) {
		getline(s, current);
		if (current.empty()) { continue ; }
		int n = std::atoi(current.c_str());
		if (n < 0) { std::cerr << "Error\nnegative number !\n"; throw std::exception(); }
		ref.push_back(n);
	}
}

void setup(int argc, char **argv, a_vec &ref) {
	int i = 1;
	while (i < argc) {
		try { setup_inloop(argv[i], ref); i++; }
		catch (std::exception &e) { throw ; }
	}
}

bool verify(s_vec &res);

void print_setup(std::vector<unsigned int> &nerf)
{
	for (std::vector<unsigned int>::iterator it = nerf.begin(); it != nerf.end(); it++)
		std::cout << *it << ", ";
	std::cout << std::endl;
}

void get_res(s_vec &res, a_vec &nerf)
{
	nerf.clear();
	for (s_vec::iterator it = res.begin(); it != res.end(); it++)
		nerf.push_back(it->second.back());
}

int main(int argc, char **argv)
{
	if (argc < 2) { std::cerr << "proper usage : ./pMerge \"[list of positive numbers here]\"\n"; return 0; }
	std::vector<unsigned int> nerf;
	try { setup(argc, argv, nerf); }
	catch (std::exception &e) { return 0; }
	std::vector<std::vector<unsigned int> > leftovers;
	print_setup(nerf);
	clock_t start = clock();
	s_vec res = phase_one(nerf, leftovers);
	res = phase_two(res, leftovers);
	get_res(res, nerf);
	clock_t end = clock();
	print_setup(nerf);
	std::cout << "show me max comparisons for " << nerf.size() << " : " << F(nerf.size()) << " v our amount " << comps << std::endl;
	std::cout << "show me time :: " << (end - start) / 1000 << std::endl;
	return 0;
}

void print_res(s_vec &res, std::vector<a_vec> &leftovers)
{
	int i = 1;
	for (s_vec::iterator it = res.begin(); it != res.end(); it++) {
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

bool verify(s_vec &res)
{
	s_vec::iterator prev = res.begin();
	for (s_vec::iterator it = ++res.begin(); it != res.end(); it++) {
		if (it->second.back() < prev->second.back()) { return false; }
		prev = it;
	}
	return true;
}
