#include "PmergeMe.hpp"
#include <ctime>
#include <vector>
#include <list>
#include <cmath>

//looks pretty good, next step abstract the amount of passes needed (just calc by biggest number honestly)
int main(int ac, char **argv)
{
	if (ac < 2) {
		std::cout << "proper usage : ./pMergeMe \"[list of positive numbers here]\"\n";
		return 0;
	}
	do_all(ac, argv);
	return 0;
}
