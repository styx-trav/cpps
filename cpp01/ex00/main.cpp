#include "Zombie.hpp"

int main()
{
	Zombie *Mark;
	
	Mark = newZombie("Mark");
	Mark->announce();
	delete Mark;
	randomChump("Eric");
}
