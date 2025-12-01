#include "AMateria.hpp"

AMateria::AMateria()
{
	std::cout << "AMateria default constructor called\n";
}

AMateria::~AMateria()
{
	std::cout << "AMateria destructor called\n";
}

AMateria::AMateria(std::string name)
{
	std::cout << "AMateria constructor called\n";
	type = name;
}

AMateria::AMateria(const AMateria &other)
{
	type = other.type;
	std::cout << "AMateria copy constructor called\n";
}

AMateria& AMateria::operator=(const AMateria &other)
{
	if (this != &other)
	{
		type = other.type;
		std::cout << "AMateria assignment operator called\n";
	}
	return *this;
}

const std::string &AMateria::getType() const
{
	return type;
}
