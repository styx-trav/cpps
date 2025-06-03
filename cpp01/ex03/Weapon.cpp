#include "Weapon.hpp"

Weapon::Weapon(std::string typo)
{
	std::cout << "creating a Weapon\n";
	type = typo;
}

Weapon::~Weapon()
{
	std::cout << "destroying Weapon \n";
}

Weapon::Weapon()
{
	std::cout << "creating Weapon \n";
}


const std::string	&Weapon::getType(void)
{
	const std::string &ref = type;
	return (ref);
}

void	Weapon::setType(std::string name)
{
	type = name;
}
