#include "PmergeMe.hpp"

static void setup_inloop(std::string str, a_deq &ref)
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

void setup_deq(int argc, char **argv, a_deq &ref) {
	int i = 1;
	while (i < argc) {
		try { setup_inloop(argv[i], ref); i++; }
		catch (std::exception &e) { throw ; }
	}
}

//create first pair list
s_deq phase_one_deq(a_deq &l, std::deque<a_deq> &lo)
{
	s_deq res;
	for (a_deq::iterator it = l.begin(); it != l.end(); it++) {
		a_deq::iterator prev = it;
		it++;
		if (it == l.end()) {
			a_deq tmp;
			tmp.push_back(*prev);
			lo.push_back(tmp);
			return phase_one_deq(res, lo);
		}
		a_deq tmp1;
		a_deq tmp2;
		comps_add();
		if (*it < *prev) {
			tmp1.push_back(*it);
			tmp2.push_back(*prev);
		}
		else {
			tmp2.push_back(*it);
			tmp1.push_back(*prev);
		}
		res.push_back(std::pair<a_deq, a_deq>(tmp1, tmp2));
	}
	return phase_one_deq(res, lo);
}

//regular recursive first phase
s_deq phase_one_deq(s_deq l, std::deque<a_deq> &lo)
{
	if (l.size() < 2) { return l; }
	s_deq res;
	for (s_deq::iterator it = l.begin(); it != l.end(); it++)
	{
		s_deq::iterator prev = it;
		it++;
		if (it == l.end()) {
			a_deq tmp;
			for (a_deq::iterator itt = prev->first.begin(); itt != prev->first.end(); itt++)
				tmp.push_back(*itt);
			for (a_deq::iterator itt = prev->second.begin(); itt != prev->second.end(); itt++)
				tmp.push_back(*itt);
			lo.push_back(tmp);
			return phase_one_deq(res, lo);
		}
		a_deq tmp1;
		a_deq tmp2;
		for (a_deq::iterator itt = prev->first.begin(); itt != prev->first.end(); itt++)
			tmp1.push_back(*itt);
		for (a_deq::iterator itt = prev->second.begin(); itt != prev->second.end(); itt++)
			tmp1.push_back(*itt);
		for (a_deq::iterator itt = it->first.begin(); itt != it->first.end(); itt++)
			tmp2.push_back(*itt);
		for (a_deq::iterator itt = it->second.begin(); itt != it->second.end(); itt++)
			tmp2.push_back(*itt);
		comps_add();
		if (it->second.back() < prev->second.back())
			res.push_back(std::pair<a_deq, a_deq>(tmp2, tmp1));
		else
			res.push_back(std::pair<a_deq, a_deq>(tmp1, tmp2));
	}
	return phase_one_deq(res, lo);
}

s_deq phase_two(s_deq l, std::deque<a_deq> &lo)
{
	s_deq res;
	//set up :: add b1 and a1 to the main
	makePair_deq(res, l.begin()->first);
	makePair_deq(res, l.begin()->second);
	//setup over, next part only happens if l.size() > 1
	unsigned int n = 1;
	unsigned int js;
	unsigned int prev = 1;
	while ((js = get_js(n)) <= l.size()) {
		n++;
		for (unsigned int i = prev; i != js; i++)
			makePair_deq(res, l[i].second);
		for (unsigned int i = js -1; i >= prev; i--)
			binary_insert_deq(res, l[i].first, get_a_pos_deq(res, (js - i)));
		prev = js;
	}
	if (prev != l.size()) {
		for (unsigned int i = prev; i != l.size(); i++)
			makePair_deq(res, l[i].second);
		for (unsigned int i = l.size() -1; i >= prev; i--)
			binary_insert_deq(res, l[i].first, get_a_pos_deq(res, (l.size() - i)));
	}
	if (!lo.empty() && lo.back().size() == l.front().first.size()) {
		binary_insert_deq(res, lo.back(), 0);
		lo.erase(--lo.end());
	}
	if (!(res.front().first.empty())) { return phase_two(res, lo); }
	return res;
}
