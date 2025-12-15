#include "Bureaucrat.hpp"

int main()
{
	try {Bureaucrat Alice("Alice", 0);}
	catch (const std::exception &e)
	{
		std::cout << e.what();
	}
	std::cout << std::endl;
	try {Bureaucrat Bob("Bob", 151);}
	catch (const std::exception &e)
	{
		std::cout << e.what();
	}
	std::cout << std::endl;
	Bureaucrat Bob("Bob", 150);
	Bureaucrat Alice("Alice", 1);
	std::cout << std::endl;
	try
	{
		Bob.promotion();
		Alice.promotion();
	}
	catch (const std::exception &e)
	{
		std::cout << e.what();
	}
	std::cout << std::endl;
	try
	{
		Alice.demotion();
		Bob.demotion();
		Bob.demotion();
	}
	catch (const std::exception &e)
	{
		std::cout << e.what();
	}
	std::cout << std::endl;
	std::cout << Bob << Alice;
}
