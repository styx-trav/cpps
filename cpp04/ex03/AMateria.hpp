#ifndef AMATERIA_HPP
# define AMATERIA_HPP
# include <iostream>
# include "ICharacter.hpp"

class ICharacter;

class AMateria
{
	protected:
		std::string type;
	public:
		AMateria();
		virtual ~AMateria() = 0;
		AMateria(std::string name);
		AMateria(const AMateria &other);
		AMateria &operator=(const AMateria &other);
		const std::string &getType() const;
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target, unsigned int att, unsigned int def, unsigned int med) const = 0;
};

#endif
