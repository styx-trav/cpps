#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
	std::cout << "Cure default constructor called\n";
}

Cure::~Cure()
{
	std::cout << "Cure destructor called\n";
}

Cure::Cure(const Cure &other) : AMateria(other)
{
	types = other.getType();
	std::cout << "Cure copy constructor called\n";
}

Cure& Cure::operator=(const Cure &other)
{
	if (this != &other)
		std::cout << "Cure assignment operator called\n";
	return *this;
}

void Cure::use(ICharacter& target, unsigned int att, unsigned int def, unsigned int med) const
{
	std::cout << "* heals " << target.getName() << "'s wounds *\n";
	(void) att;
	(void) def;
	target.beRepaired(med * 10);
}

Cure* Cure::clone() const
{
	return (new Cure(*this));
}
