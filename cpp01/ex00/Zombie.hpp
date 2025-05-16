#include <cstring>
#include <iostream>

class Zombie
{
	private:
		std::string name;
	public:
		void	announce(void);
		Zombie	*newZombie(std::string name);
}

void	Zombie::announce(void)
{
	std::cout << name << "e>: BraiiiiiiinnnzzzZ...\n";
}

Zombie	*Zombie::newZombie(std::string name)
{
	new Zombie zombie(name);
	return (&zombie);
}

//allocating stack vs heap is the point of the exercise, but also please make a special constructor with name included, and look up destructors in the same breath
