#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "Animal default constructor called\n";
}

Animal::~Animal()
{
	std::cout << "Animal destructor called\n";
}

Animal::Animal(std::string name)
{
	std::cout << "Animal constructor called\n";
	_name = name;
}

Animal::Animal(const Animal &other)
{
	_name = other.name;
	std::cout << "Animal copy constructor called\n";
}

Animal& Animal::operator=(const Animal &other)
{
	if (this != &other)
	{
		_name = other.name;
		std::cout << "Animal assignment operator called\n";
	}
	return *this;
}

