#include "Zombie.hpp"

int main()
{
	Zombie *hoard;
	hoard = zombieHorde(5, "Yelena");
	if (hoard == NULL)
	{
		std::cout << "error allocating\n";
		return 0;
	}
	for (int i = 0; i != 5; ++i)
		hoard[i].announce();
	std::cout << "changing n°3's name to Bucky\n";
	hoard[2].nameMe("Bucky");
	for (int i = 0; i != 5; ++i)
		hoard[i].announce();
	delete[] hoard;
}
