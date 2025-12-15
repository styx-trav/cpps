#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _target("target")
{
	std::cout << "RobotomyRequestForm default constructor called\n";
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm destructor called\n";
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
	std::cout << "RobotomyRequestForm constructor called\n";
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm(other), _target(other._target)
{
	std::cout << "RobotomyRequestForm copy constructor called\n";
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	if (this != &other)
		std::cout << "RobotomyRequestForm assignment operator called\n";
	return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	try
	{
		this->AForm::execute(executor);
		srand(time(0));
		int s = rand() % 2;
		if (s)
			std::cout << _target << " has been successfully robotomized.\n";
		else
			std::cout << _target << "'s robotomy has failed.\n";
	}
	catch (std::exception &e) {throw ;}
}

AForm *RobotomyRequestForm::clone(const std::string &target) const
{
	return new RobotomyRequestForm(target);
}
