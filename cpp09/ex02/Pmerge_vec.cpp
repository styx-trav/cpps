#include "PmergeMe.hpp"

static void setup_inloop(std::string str, a_vec &ref)
{
	std::stringstream s(str);
	std::string current;
	while (!s.eof()) {
		getline(s, current);
		if (current.empty()) { continue ; }
		int n = atoi(current.c_str());
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

//create first pair list
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
		comps_add();
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

//regular recursive first phase
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
		comps_add();
		if (it->second.back() < prev->second.back())
			res.push_back(std::pair<a_vec, a_vec>(tmp2, tmp1));
		else
			res.push_back(std::pair<a_vec, a_vec>(tmp1, tmp2));
	}
	return phase_one(res, lo);
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
