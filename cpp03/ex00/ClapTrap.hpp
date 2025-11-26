#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP
# include <iostream>


class ClapTrap
{
	private:
		std::string name;
		unsigned int hp;
		unsigned int ep;
		unsigned int att;
	public:
		ClapTrap();
		~ClapTrap();
		ClapTrap(std::string names);
		ClapTrap(const ClapTrap &other);
		ClapTrap &operator=(const ClapTrap &other);
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};

#endif
