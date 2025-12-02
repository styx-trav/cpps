#ifndef ICHARACTER_HPP
# define ICHARACTER_HPP
# include <iostream>
# include "AMateria.hpp"

class AMateria;

class ICharacter
{
	public:
		virtual ~ICharacter() {};
		virtual std::string const & getName() const = 0;
		virtual void equip(AMateria* m) = 0;
		virtual void unequip(int idx) = 0;
		virtual void gift(int idx, ICharacter &target) = 0;
		virtual void use(int idx, ICharacter& target) = 0;
		virtual void takeDamage(unsigned int dam) = 0;
		virtual void beRepaired(unsigned int heal) = 0;
		virtual void beProtected(unsigned int protection) = 0;
};

#endif
