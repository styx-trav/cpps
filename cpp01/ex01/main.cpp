#include "Zombie.hpp"

int main()
{
	Zombie *hoard;
	hoard = ZombieHorde(5, "Yelena");
	for (int i = 0; i != 5; ++i)
	{
		hoard[i].announce();
	}
	std::cout << "changing Yelena n°3's name to Bucky\n";
	hoard[2].nameMe("Bucky");
	for (int i = 0; i != 5; ++i)
	{
		hoard[i].announce();
	}
	delete[] hoard;
}
