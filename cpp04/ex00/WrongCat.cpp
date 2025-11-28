#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
	std::cout << "WrongCat default constructor called\n";
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor called\n";
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other)
{
	std::cout << "WrongCat copy constructor called\n";
}

WrongCat& WrongCat::operator=(const WrongCat &other)
{
	if (this != &other)
	{
		type = other.type;
		std::cout << "WrongCat assignment operator called\n";
	}
	return *this;
}

void WrongCat::makeSound() const
{
	std::cout << "WrongCat meows\n";
}
