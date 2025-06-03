#include "Zombie.hpp"

Zombie	*newZombie(std::string name)
{
	Zombie *rando = new Zombie;
	rando->nameMe(name);
	return (rando);
}
