#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "Cat default constructor called\n";
}

Cat::~Cat()
{
	std::cout << "Cat destructor called\n";
}

Cat::Cat(std::string name)
{
	std::cout << "Cat constructor called\n";
	_name = name;
}

Cat::Cat(const Cat &other)
{
	_name = other.name;
	std::cout << "Cat copy constructor called\n";
}

Cat& Cat::operator=(const Cat &other)
{
	if (this != &other)
	{
		_name = other.name;
		std::cout << "Cat assignment operator called\n";
	}
	return *this;
}

