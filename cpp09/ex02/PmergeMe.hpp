#ifndef PMERGEME_HPP
# define PMERGEME_HPP
# include <vector>
# include <deque>
# include <iostream>
# include <cstring>
# include <sstream>
# include <cmath>
# include <time.h>

template <class T> void setup_inloop(std::string str, T &ref)
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

template <class T> void setup(int argc, char **argv, T &ref)
{
	int i = 1;
	while (i < argc) {
		try { setup_inloop(argv[i], ref); i++; }
		catch (std::exception &e) { throw ; }
	}
}

#endif
