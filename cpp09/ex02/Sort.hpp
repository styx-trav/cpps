#ifndef SORT_HPP
# define SORT_HPP
# include <iostream>
# include <sstream>
# include <cmath>

unsigned int pwr(unsigned int num, unsigned int el);

template <typename T> void setup(T *tab, std::string lm)
{
	std::stringstream s(lm);
	std::string current;
	while (!s.eof())
	{
		getline(s, current, ' ');
		int at = atoi(current.c_str());
		if (at < 0)
			throw std::out_of_range("negative  number !\n");
		tab->push_back(at);
	}
}

template <typename T> void tab_print(T tab)
{
	for (typename T::iterator it = tab.begin(); it != tab.end(); it++)
		std::cout << *it << " ";
}

template <typename T> T *algo(T *tab, unsigned int pass, unsigned int end)
{
	T *newtab = new T[10];
	for (int i = 0; i != 10; i++)
	{
		for (typename T::iterator it = tab[i].begin(); it != tab[i].end(); it++)
		{
			unsigned int ell = *it % pwr(10, pass+1) / pwr(10, pass);
			newtab[ell].push_back(*it);
		}
	}
	delete[] tab;
	if (pass == end)
		return newtab;
	else
		return algo(newtab, pass + 1, end);
}

#endif
