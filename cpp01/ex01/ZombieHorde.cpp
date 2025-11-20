#include "Zombie.hpp"

Zombie *ZombieHorde(int N, std::string name)
{
	Zombie *horde = new Zombie[5];
	for (int i = 0; i != N; ++i)
		horde[i].nameMe(name);
	return (horde);
}
