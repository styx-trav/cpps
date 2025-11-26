#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("name")
{
	std::cout << "FragTrap default constructor called\n";
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called\n";
}

FragTrap::FragTrap(std::string names) : ClapTrap(names)
{
	std::cout << "FragTrap constructor called\n";
	hp = 100;
	ep = 100;
	att = 30;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
	std::cout << "FragTrap copy constructor called\n";
}

FragTrap& FragTrap::operator=(const FragTrap &other)
{
	if (this != &other)
	{
		name = other.name;
		hp = other.hp;
		ep = other.ep;
		att = other.att;
		std::cout << "FragTrap assignment operator called\n";
	}
	return *this;
}

void FragTrap::highFivesGuys()
{
	std::cout << name << " says: \"hey guys, high five !\"\n";
}
