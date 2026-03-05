#include "Data.hpp"

Data::Data() : _name("name"), age(0)
{
	std::cout << "Data default constructor called\n";
}

Data::~Data()
{
	std::cout << "Data destructor called\n";
}

Data::Data(const std::string &name, int _age) : _name(name), age(_age)
{
	std::cout << "Data constructor called\n";
}

Data::Data(const Data &other) : _name(other._name), age(other.age)
{
	std::cout << "Data copy constructor called\n";
}

Data& Data::operator=(const Data &other)
{
	if (this != &other) {
		age = other.age;
		std::cout << "Data assignment operator called\n";
	}
	return *this;
}

const std::string &Data::getName() const { return _name; }

void Data::read() const { std::cout << "My name is " << _name << ", Im " << age << " years old."; }
