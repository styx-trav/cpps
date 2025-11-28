#ifndef CHARACTER_HPP
# define CHARACTER_HPP
# include "ICharacter.hpp"


class Character : public ICharacter
{
	private:
		std::string _name;
		AMateria *inventory[4];
	public:
		Character();
		~Character();
		Character(std::string name);
		Character(const Character &other);
		Character &operator=(const Character &other);
};

#endif
