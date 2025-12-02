#include "Bite.hpp"

Bite::Bite() : AMateria("bite")
{
	std::cout << "Bite default constructor called\n";
}

Bite::~Bite()
{
	std::cout << "Bite destructor called\n";
}

Bite::Bite(const Bite &other) : AMateria(other)
{
	types = other.getType();
	std::cout << "Bite copy constructor called\n";
}

Bite& Bite::operator=(const Bite &other)
{
	if (this != &other)
		std::cout << "Bite assignment operator called\n";
	return *this;
}

void Bite::use(ICharacter& target, unsigned int att, unsigned int def, unsigned int med) const
{
	std::cout << "* lunges at " << target.getName() << " and takes out a chunk of flesh from their body *\n";
	(void)med;
	(void)def;
	target.takeDamage(att);
}

Bite* Bite::clone() const
{
	return (new Bite(*this));
}
