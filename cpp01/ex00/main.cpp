#include "Zombie.hpp"

int main()
{
	Zombie *Mark;
	
	Mark = newZombie("Mark");
	Mark->announce();
	delete Mark;
	Zombie Elise;
	Elise.announce();
	randomChump("Eric");
}
