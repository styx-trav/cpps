#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "Dog default constructor called\n";
}

Dog::~Dog()
{
	std::cout << "Dog destructor called\n";
}

Dog::Dog(std::string name)
{
	std::cout << "Dog constructor called\n";
	_name = name;
}

Dog::Dog(const Dog &other)
{
	_name = other.name;
	std::cout << "Dog copy constructor called\n";
}

Dog& Dog::operator=(const Dog &other)
{
	if (this != &other)
	{
		_name = other.name;
		std::cout << "Dog assignment operator called\n";
	}
	return *this;
}

