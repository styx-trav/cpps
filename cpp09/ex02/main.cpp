#include "PmergeMe.hpp"
#include <ctime>
#include <vector>
#include <list>
#include <cmath>

//looks pretty good, next step abstract the amount of passes needed (just calc by biggest number honestly)
int main(int ac, char **argv)
{
	if (ac != 2)
		return 0;
	std::string lm = argv[1];
	clock_t start, end;
	std::vector<unsigned int> *tab = new std::vector<unsigned int>[10];
	std::cout << lm << std::endl;
	try {
		start = clock();
		setup<std::vector<unsigned int> >(&(tab[0]), lm);
		tab = algo<std::vector<unsigned int> >(*(&tab), 0, 2);
		end = clock();
		for(int i = 0; i != 10; i++)
			tab_print<std::vector<unsigned int> >(tab[i]);
		std::cout << std::endl;
		std::cout << "all in all in " << ((end - start) / (CLOCKS_PER_SEC / 1000000)) << " microseconds, apparently\n";
	}
	catch (std::exception &e) {std::cerr << e.what();}
	delete[] tab;
	
	std::cout << std::endl << std::endl;
	std::list<unsigned int> *tab1 = new std::list<unsigned int>[10];
	std::cout << lm << std::endl;
	try {
		start = clock();
		setup<std::list<unsigned int> >(&(tab1[0]), lm);
		tab1 = algo<std::list<unsigned int> >(*(&tab1), 0, 2);
		end = clock();
		for(int i = 0; i != 10; i++)
			tab_print<std::list<unsigned int> >(tab1[i]);
		std::cout << std::endl;
		std::cout << "all in all in " << ((end - start) / (CLOCKS_PER_SEC / 1000000)) << " microseconds, apparently\n";
	}
	catch (std::exception &e) {std::cerr << e.what();}
	delete[] tab1;
}
