#include "AMateria.hpp"

AMateria::AMateria()
{
	std::cout << "AMateria default constructor called\n";
}

AMateria::~AMateria()
{
	std::cout << "AMateria destructor called\n";
}

AMateria::AMateria(std::string const & type)
{
	std::cout << "AMateria constructor called\n";
	types = type;
}

AMateria::AMateria(const AMateria &other)
{
	types = other.types;
	std::cout << "AMateria copy constructor called\n";
}

AMateria& AMateria::operator=(const AMateria &other)
{
	if (this != &other)
		std::cout << "AMateria assignment operator called\n";
	return *this;
}

const std::string &AMateria::getType() const
{
	return types;
}
