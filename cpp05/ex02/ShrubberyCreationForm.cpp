#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm default constructor called\n";
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm destructor called\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string name)
{
	std::cout << "ShrubberyCreationForm constructor called\n";
	_name = name;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
{
	_name = other.name;
	std::cout << "ShrubberyCreationForm copy constructor called\n";
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	if (this != &other)
	{
		_name = other.name;
		std::cout << "ShrubberyCreationForm assignment operator called\n";
	}
	return *this;
}

