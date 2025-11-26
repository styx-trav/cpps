#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name("name"), hp(10), ep(10), att(0)
{
	std::cout << "ClapTrap default constructor called\n";
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor called\n";
}

ClapTrap::ClapTrap(std::string names) : hp(10), ep(10), att(0)
{
	std::cout << "ClapTrap constructor called\n";
	name = names;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
	name = other.name;
	hp = other.hp;
	ep = other.ep;
	att = other.att;
	std::cout << "ClapTrap copy constructor called\n";
}

ClapTrap& ClapTrap::operator=(const ClapTrap &other)
{
	if (this != &other)
	{
		name = other.name;
		hp = other.hp;
		ep = other.ep;
		att = other.att;
		std::cout << "ClapTrap assignment operator called\n";
	}
	return *this;
}

void ClapTrap::attack(const std::string& target)
{
	if (!hp)
	{
		std::cout << name << " is dead.\n";
		return ;
	}
	if (!ep)
	{
		std::cout << name << " has no energy.\n";
		return ;
	}
	std::cout << name << " attacks " << target << " for " << att << " attack damage\n";
	ep--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << name << " takes " << amount << " attack damage\n";
	if (hp > amount)
	{
		hp = hp - amount;
		std::cout << name << " now has " << hp << "hp.\n";
	}
	else
	{
		hp = 0;
		std::cout << name << " is dead.\n";
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (!hp)
	{
		std::cout << name << " is dead.\n";
		return ;
	}
	if (!ep)
	{
		std::cout << name << " has no energy.\n";
		return ;
	}
	std::cout << name << " repairs itself for " << amount << "hp\n";
	ep--;
	hp = hp + amount;
	std::cout << name << " now has " << hp << std::endl;
}
