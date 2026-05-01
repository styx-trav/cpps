#include "PmergeMe.hpp"

bool cmp(unsigned int b, unsigned int a) { comps_add(); return (b <= a); }

unsigned int get_js(unsigned int n)
{
	double s = (pow(2, n+1) + pow(-1, n)) / 3;
	return static_cast<unsigned int>(s);
}

int F(int n)
{
    int sum = 0;
    for (int k = 1; k <= n; ++k) {
        double value = (3.0 / 4.0) * k;
        sum += static_cast<int>(ceil(log2(value)));
    }
    return sum;
}

void print_list(a_vec &ref)
{
	for (a_vec::iterator it = ref.begin(); it != ref.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
}
