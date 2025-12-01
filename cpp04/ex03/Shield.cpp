#include "Shield.hpp"

Shield::Shield() : AMateria("shield")
{
	std::cout << "Shield default constructor called\n";
}

Shield::~Shield()
{
	std::cout << "Shield destructor called\n";
}

Shield::Shield(const Shield &other) : AMateria(other)
{
	type = other.getType();
	std::cout << "Shield copy constructor called\n";
}

Shield& Shield::operator=(const Shield &other)
{
	if (this != &other)
		std::cout << "Shield assignment operator called\n";
	return *this;
}

void Shield::use(ICharacter& target, unsigned int att, unsigned int def, unsigned int med) const
{
	std::cout << "* throws a protection shield around " << target.getName() << " *\n";
	(void)med;
	(void)att;
	target.beProtected(def + 10);
}

Shield* Shield::clone() const
{
	return (new Shield(*this));
}
