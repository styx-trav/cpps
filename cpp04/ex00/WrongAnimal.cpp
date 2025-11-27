#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal")
{
	std::cout << "WrongAnimal default constructor called\n";
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructor called\n";
}

WrongAnimal::WrongAnimal(std::string name)
{
	std::cout << "WrongAnimal constructor called\n";
	type = name;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other)
{
	type = other.type;
	std::cout << "WrongAnimal copy constructor called\n";
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &other)
{
	if (this != &other)
	{
		type = other.type;
		std::cout << "WrongAnimal assignment operator called\n";
	}
	return *this;
}

void WrongAnimal::makeSound()
{
	std::cout << type << " makes a sound.\n";
}

const std::string &WrongAnimal::getType()
{
	return type;
}
