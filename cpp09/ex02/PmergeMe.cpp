#include "PmergeMe.hpp"

unsigned int pwr(unsigned int num, unsigned int el)
{
	if (el == 1)
		return num;
	if (!el)
		return 1;
	return pwr(num * num, el - 1);
}
