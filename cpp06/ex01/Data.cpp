#include "Data.hpp"

Data::Data() : _name("name")
{
	std::cout << "Data default constructor called\n";
}

Data::~Data()
{
	std::cout << "Data destructor called\n";
}

Data::Data(const std::string &name) : _name(name)
{
	std::cout << "Data constructor called\n";
}

Data::Data(const Data &other) : _name(other._name)
{
	std::cout << "Data copy constructor called\n";
}

Data& Data::operator=(const Data &other)
{
	if (this != &other)
		std::cout << "Data assignment operator called\n";
	return *this;
}

const std::string &Data::getName() const
{
	return _name;
}
