#include "Intern.hpp"

Intern::Intern()
{
	inventory[0] = new ShrubberyCreationForm();
	inventory[1] = new RobotomyRequestForm();
	inventory[2] = new PresidentialPardonForm();
	std::cout << "Intern default constructor called\n";
}

Intern::~Intern()
{
	for (int i = 0; i != 3; i++)
		delete inventory[i];
	std::cout << "Intern destructor called\n";
}

Intern::Intern(const Intern &other)
{
	(void)other;
	inventory[0] = new ShrubberyCreationForm();
	inventory[1] = new RobotomyRequestForm();
	inventory[2] = new PresidentialPardonForm();
	std::cout << "Intern copy constructor called\n";
}

Intern& Intern::operator=(const Intern &other)
{
	if (this != &other)
		std::cout << "Intern assignment operator called\n";
	return *this;
}

AForm *Intern::makeForm(const std::string &form, const std::string &target) const
{
	std::string forms[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	for (int i = 0; i != 3; i++)
	{
		if (form == forms[i])
			return (inventory[i])->clone(target);
	}
	std::cout << "this form does not exist, sorry. please dont fire me.\n";
	return NULL;
}
