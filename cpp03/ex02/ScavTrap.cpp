#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("name")
{
	std::cout << "ScavTrap default constructor called\n";
	hp = 100;
	ep = 50;
	att = 20;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called\n";
}

ScavTrap::ScavTrap(std::string names) : ClapTrap(names)
{
	std::cout << "ScavTrap constructor called\n";
	hp = 100;
	ep = 50;
	att = 20;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
	std::cout << "ScavTrap copy constructor called\n";
}

ScavTrap& ScavTrap::operator=(const ScavTrap &other)
{
	if (this != &other)
	{
		name = other.name;
		hp = other.hp;
		ep = other.ep;
		att = other.att;
		std::cout << "ScavTrap assignment operator called\n";
	}
	return *this;
}

void ScavTrap::guardGate()
{
	std::cout << name << " is now in Gate keeper mode\n";
}

void ScavTrap::attack(const std::string &target)
{
	std::cout << "Scav " << name << " attacks " << target << " straight in the face, causing " << att << " points of damage\n";
}
