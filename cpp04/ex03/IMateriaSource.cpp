#include "IMateriaSource.hpp"

IMateriaSource::IMateriaSource()
{
	std::cout << "IMateriaSource default constructor called\n";
}

IMateriaSource::~IMateriaSource()
{
	std::cout << "IMateriaSource destructor called\n";
}

IMateriaSource::IMateriaSource(std::string name)
{
	std::cout << "IMateriaSource constructor called\n";
	_name = name;
}

IMateriaSource::IMateriaSource(const IMateriaSource &other)
{
	_name = other.name;
	std::cout << "IMateriaSource copy constructor called\n";
}

IMateriaSource& IMateriaSource::operator=(const IMateriaSource &other)
{
	if (this != &other)
	{
		_name = other.name;
		std::cout << "IMateriaSource assignment operator called\n";
	}
	return *this;
}

