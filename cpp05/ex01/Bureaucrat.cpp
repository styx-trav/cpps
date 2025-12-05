#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("bureaucrat"), GradeTooHighException(CustomException("this bureaucrat's grade is too high !\n")), GradeTooLowException(CustomException("this bureaucrat's grade is too low !\n"))
{
	std::cout << "Bureaucrat default constructor called\n";
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat destructor called\n";
}

Bureaucrat::Bureaucrat(const std::string &name, int r) :  _name(name), grade(r), GradeTooHighException(CustomException("this bureaucrat's grade is too high !\n")), GradeTooLowException(CustomException("this bureaucrat's grade is too low !\n"))
{
	std::cout << "Bureaucrat constructor called\n";
	if (r < high)
		throw GradeTooHighException;
	if (r > low)
		throw GradeTooLowException;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other._name), GradeTooHighException(other.GradeTooHighException), GradeTooLowException(other.GradeTooLowException)
{
	grade = other.grade;
	std::cout << "Bureaucrat copy constructor called\n";
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other)
	{
		grade = other.grade;
		std::cout << "Bureaucrat assignment operator called\n";
	}
	return *this;
}

const std::string &Bureaucrat::getName() const
{
	return this->_name;
}

int Bureaucrat::getGrade() const
{
	return this->grade;
}

void Bureaucrat::promotion()
{
	std::cout << _name << " gets a promotion !\n";
	if (grade == high)
		throw GradeTooHighException;
	this->grade = this->grade -1;
	std::cout << _name << "'s new grade is " << grade << ".\n";
}

void Bureaucrat::demotion()
{
	std::cout << _name << " gets a demotion.\n";
	if (grade == low)
		throw GradeTooLowException;
	this->grade = this->grade +1;
	std::cout << _name << "'s new grade is " << grade << ".\n";
}

void Bureaucrat::signForm(Form &f)
{
	try
	{
		f.beSigned(*this);
		std::cout << _name << " signed ";
		std::cout << f.getName() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << _name << " couldn't sign ";
		std::cout << f.getName() << " because " << e.what();
	}
}

std::ostream &operator<<(std::ostream &out, Bureaucrat &obj)
{
	out << obj.getName() << ", bureaucrat grade ";
	std::cout << obj.getGrade() << ".\n";
	return out;
}
