#ifndef CHARACTER_HPP
# define CHARACTER_HPP
# include "ICharacter.hpp"


class Character : public ICharacter
{
	protected:
		std::string _name;
		AMateria *inventory[4];
		unsigned int hp;
		unsigned int ep;
		unsigned int att;
		unsigned int med;
		unsigned int def;
	public:
		Character();
		~Character();
		Character(std::string name);
		Character(std::string name, unsigned int at, unsigned int me, unsigned int de);
		Character(const Character &other);
		Character &operator=(const Character &other);
		std::string const & getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void gift(int idx, ICharacter &target);
		void use(int idx, ICharacter& target);
		void takeDamage(unsigned int dam);
		void beRepaired(unsigned int heal);
		void eBoost(unsigned int boost);
		void beProtected(unsigned int protection);
};

#endif
