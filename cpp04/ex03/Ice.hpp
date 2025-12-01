#ifndef ICE_HPP
# define ICE_HPP
# include "AMateria.hpp"


class Ice : public AMateria
{
	public:
		Ice();
		~Ice();
		Ice(const Ice &other);
		Ice &operator=(const Ice &other);
		void use(ICharacter& target, unsigned int att, unsigned int def, unsigned int med) const;
		Ice* clone() const;
};

#endif
