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

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);

#endif
