#include "Zombie.hpp"

Zombie::Zombie(void)
{
	std::cout << "creating zombie\n";
}

Zombie::~Zombie(void)
{
	std::cout << "destroying " << name << " \n";
}

void	Zombie::announce(void)
{
	std::cout << name << ": BraiiiiiiinnnzzzZ...\n";
}

void	Zombie::nameMe(std::string newname)
{
	name = newname;
}

