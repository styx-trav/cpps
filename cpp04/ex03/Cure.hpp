#ifndef CURE_HPP
# define CURE_HPP
# include "AMateria.hpp"


class Cure : public AMateria
{
	public:
		Cure();
		~Cure();
		Cure(const Cure &other);
		Cure &operator=(const Cure &other);
		void use(ICharacter& target, unsigned int att, unsigned int def, unsigned int med) const;
		Cure* clone() const;
};

#endif
