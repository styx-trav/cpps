#include <list>
#include <iostream>
#include <cstring>

typedef std::list<std::pair<std::list<unsigned int>,std::list<unsigned int> > > s_list;
typedef std::list<unsigned int> a_list;

//future regular pass here, testing for now so just one level
s_list phase_one(s_list l, std::list<a_list> &lo)
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
s_list phase_one(std::list<unsigned int> l, std::list<std::list<unsigned int> > &lo)
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

int main()
{
	std::list<unsigned int> nerf;
	unsigned int ner[13] = {4, 57, 8, 6, 44, 2, 0, 81, 10, 7, 3, 1, 42};
	for (int i = 0; i != 13; i++)
		nerf.push_back(ner[i]);
	
	std::list<std::list<unsigned int> > leftovers;
	s_list res = phase_one(nerf, leftovers);
	int i = 1;
	for (s_list::iterator it = res.begin(); it != res.end(); it++) {
		std::cout << "b" << i << " { ";
		for (std::list<unsigned int>::iterator itt = it->first.begin(); itt != it->first.end(); itt++)
			std::cout << *itt << ", ";
		std::cout << "}, a" << i << " { ";
		for (std::list<unsigned int>::iterator itt = it->second.begin(); itt != it->second.end(); itt++)
			std::cout << *itt << ", ";
		std::cout << "}\n";
		i++;
	}
	if (!leftovers.empty()) {
		std::cout << "leftovers : { ";
		for (std::list<std::list<unsigned int> >::iterator it = leftovers.begin(); it != leftovers.end(); it++) {
			std::cout << "\n\t{ ";
			for (std::list<unsigned int>::iterator itt = it->begin(); itt != it->end(); itt++)
				std::cout << *itt << ", ";
			std::cout << "}";
		}
		std::cout << "\n}\n";
	}
}
