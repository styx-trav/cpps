#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm default constructor called\n";
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm destructor called\n";
}

RobotomyRequestForm::RobotomyRequestForm(std::string name)
{
	std::cout << "RobotomyRequestForm constructor called\n";
	_name = name;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
{
	_name = other.name;
	std::cout << "RobotomyRequestForm copy constructor called\n";
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	if (this != &other)
	{
		_name = other.name;
		std::cout << "RobotomyRequestForm assignment operator called\n";
	}
	return *this;
}

