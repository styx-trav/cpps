#include "Boost.hpp"

Boost::Boost() : AMateria("boost")
{
	std::cout << "Boost default constructor called\n";
}

Boost::~Boost()
{
	std::cout << "Boost destructor called\n";
}

Boost::Boost(const Boost &other) : AMateria(other)
{
	type = other.getType();
	std::cout << "Boost copy constructor called\n";
}

Boost& Boost::operator=(const Boost &other)
{
	if (this != &other)
		std::cout << "Boost assignment operator called\n";
	return *this;
}

void Boost::use(ICharacter& target, unsigned int att, unsigned int def, unsigned int med) const
{
	std::cout << "* pours a shot down " << target.getName() << "'s throat *\n";
	(void)med;
	(void)def;
	(void)att;
	target.eBoost(10);
}


Boost* Boost::clone() const
{
	return (new Boost(*this));
}
