#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
	std::cout << "Cat default constructor called\n";
}

Cat::~Cat()
{
	std::cout << "Cat destructor called\n";
}

Cat::Cat(const Cat &other) : Animal(other)
{
	std::cout << "Cat copy constructor called\n";
}

Cat& Cat::operator=(const Cat &other)
{
	if (this != &other)
	{
		type = other.type;
		std::cout << "Cat assignment operator called\n";
	}
	return *this;
}

void Cat::makeSound() const
{
	std::cout << type << " meows.\n";
}
