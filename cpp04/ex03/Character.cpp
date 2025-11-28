#include "Character.hpp"

Character::Character()
{
	std::cout << "Character default constructor called\n";
}

Character::~Character()
{
	std::cout << "Character destructor called\n";
}

Character::Character(std::string name)
{
	std::cout << "Character constructor called\n";
	_name = name;
}

Character::Character(const Character &other)
{
	_name = other.name;
	std::cout << "Character copy constructor called\n";
}

Character& Character::operator=(const Character &other)
{
	if (this != &other)
	{
		_name = other.name;
		std::cout << "Character assignment operator called\n";
	}
	return *this;
}

