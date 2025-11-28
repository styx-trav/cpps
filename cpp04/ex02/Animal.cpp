#include "Animal.hpp"

Animal::Animal() : type("Animal")
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
	type = name;
}

Animal::Animal(const Animal &other)
{
	type = other.type;
	std::cout << "Animal copy constructor called\n";
}

Animal& Animal::operator=(const Animal &other)
{
	if (this != &other)
	{
		type = other.type;
		std::cout << "Animal assignment operator called\n";
	}
	return *this;
}

void Animal::makeSound() const
{
	std::cout << type << " makes a sound.\n";
}

const std::string &Animal::getType() const
{
	return type;
}
