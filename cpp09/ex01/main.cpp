#include "RPN.hpp"
#include <iostream>

int main(int ac, char **argv)
{
	if (ac != 2)
		return 0;
	try {std::cout << operate(argv[1]) << std::endl;}
	catch (std::exception &e) {std::cerr << e.what();}
}
