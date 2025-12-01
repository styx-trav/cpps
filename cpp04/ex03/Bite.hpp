#ifndef BITE_HPP
# define BITE_HPP
# include "AMateria.hpp"


class Bite : public AMateria
{
	public:
		Bite();
		~Bite();
		Bite(const Bite &other);
		Bite &operator=(const Bite &other);
		void use(ICharacter& target, unsigned int att, unsigned int def, unsigned int med) const;
		Bite* clone() const;
};

#endif
