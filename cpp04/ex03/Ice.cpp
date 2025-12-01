#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
	std::cout << "Ice default constructor called\n";
}

Ice::~Ice()
{
	std::cout << "Ice destructor called\n";
}

Ice::Ice(const Ice &other) : AMateria(other)
{
	type = other.getType();
	std::cout << "Ice copy constructor called\n";
}

Ice& Ice::operator=(const Ice &other)
{
	if (this != &other)
		std::cout << "Ice assignment operator called\n";
	return *this;
}

void Ice::use(ICharacter& target, unsigned int att, unsigned int def, unsigned int med) const
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *\n";
	(void)med;
	(void)def;
	target.takeDamage(att * 10);
}

Ice* Ice::clone() const
{
	return (new Ice(*this));
}
