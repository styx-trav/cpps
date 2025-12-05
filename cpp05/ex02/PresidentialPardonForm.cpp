#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm default constructor called\n";
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm destructor called\n";
}

PresidentialPardonForm::PresidentialPardonForm(std::string name)
{
	std::cout << "PresidentialPardonForm constructor called\n";
	_name = name;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other)
{
	_name = other.name;
	std::cout << "PresidentialPardonForm copy constructor called\n";
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	if (this != &other)
	{
		_name = other.name;
		std::cout << "PresidentialPardonForm assignment operator called\n";
	}
	return *this;
}

