#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), _target("target")
{
	std::cout << "PresidentialPardonForm default constructor called\n";
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm destructor called\n";
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : AForm("PresidentialPardonForm", 25, 5), _target(target)
{
	std::cout << "PresidentialPardonForm constructor called\n";
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : AForm(other), _target(other._target)
{
	std::cout << "PresidentialPardonForm copy constructor called\n";
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	if (this != &other)
		std::cout << "PresidentialPardonForm assignment operator called\n";
	return *this;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	try
	{
		this->AForm::execute(executor);
		std::cout << _target << " has been pardoned by Zaphod Beeblebrox.\n";
	}
	catch (std::exception &e) {throw ;}
}

AForm *PresidentialPardonForm::clone(const std::string &target) const
{
	return new PresidentialPardonForm(target);
}
