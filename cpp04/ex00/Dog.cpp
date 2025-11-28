#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
	std::cout << "Dog default constructor called\n";
}

Dog::~Dog()
{
	std::cout << "Dog destructor called\n";
}

Dog::Dog(const Dog &other) : Animal(other)
{
	std::cout << "Dog copy constructor called\n";
}

Dog& Dog::operator=(const Dog &other)
{
	if (this != &other)
	{
		type = other.type;
		std::cout << "Dog assignment operator called\n";
	}
	return *this;
}


void Dog::makeSound() const
{
	std::cout << type << " barks.\n";
}
