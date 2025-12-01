#ifndef SHIELD_HPP
# define SHIELD_HPP
# include "AMateria.hpp"


class Shield : public AMateria
{
	public:
		Shield();
		~Shield();
		Shield(const Shield &other);
		Shield &operator=(const Shield &other);
		void use(ICharacter& target, unsigned int att, unsigned int def, unsigned int med) const;
		Shield* clone() const;
};

#endif
