#ifndef BOOST_HPP
# define BOOST_HPP
# include "AMateria.hpp"


class Boost : public AMateria
{
	public:
		Boost();
		~Boost();
		Boost(const Boost &other);
		Boost &operator=(const Boost &other);
		void use(ICharacter& target, unsigned int att, unsigned int def, unsigned int med) const;
		Boost* clone() const;
};

#endif
