#include "Zombie.hpp"

void	randomChump(std::string name)
{
	Zombie chump;
	chump.nameMe(name);
	chump.announce();
}
