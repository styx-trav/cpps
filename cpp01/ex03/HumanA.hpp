#ifndef HUMANA_H
# define HUMANA_H

# include "Weapon.hpp"

class HumanA
{
	private:
		std::string name;
		Weapon &weapon;
	public:
		HumanA(std::string naming, Weapon &weaponing);
		~HumanA();
		void	attack(void);
};

#endif
