#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
# include <cstring>
# include <iostream>

class Zombie
{
	private:
		std::string name;
	public:
		Zombie();
		~Zombie();
		void	announce(void);
		void	nameMe(std::string newname);
};

Zombie *ZombieHorde(int N, std::string name);

#endif
