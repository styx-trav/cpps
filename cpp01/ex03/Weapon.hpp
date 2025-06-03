#ifndef WEAPON_H
# define WEAPON_H

# include <cstring>
# include <iostream>

class Weapon
{
	private:
		std::string type;
	public:
		Weapon();
		Weapon(std::string typo);
		~Weapon();
		const std::string &getType(void);
		void  setType(std::string name);
};

#endif
