#include "Form.hpp"

Form::Form() : _name("name"), gradeSign(1), gradeExec(1), GradeTooLowException(CustomException("this grade is too low.\n")), GradeTooHighException(CustomException("this grade is too high !\n")), isSigned(false)
{
	std::cout << "Form default constructor called\n";
}

Form::~Form()
{
	std::cout << "Form destructor called\n";
}

Form::Form(const std::string &name, int sign, int exec) : _name(name), gradeSign(sign), gradeExec(exec), GradeTooLowException(CustomException("this grade is too low.\n")), GradeTooHighException(CustomException("this grade is too high !\n")), isSigned(false)
{
	std::cout << "Form constructor called\n";
	if (sign < 1 || exec < 1)
		throw GradeTooHighException;
	if (sign > 150 || exec > 150)
		throw GradeTooLowException;
}

Form::Form(const Form &other) : _name(other._name), gradeSign(other.gradeSign), gradeExec(other.gradeExec), GradeTooLowException(CustomException("this grade is too low.\n")), GradeTooHighException(CustomException("this grade is too high !\n")), isSigned(other.isSigned)
{
	std::cout << "Form copy constructor called\n";
}

Form& Form::operator=(const Form &other)
{
	if (this != &other)
	{
		isSigned = other.isSigned;
		std::cout << "Form assignment operator called\n";
	}
	return *this;
}

const std::string &Form::getName() const {return this->_name;}

int Form::getGradeSign() const {return this->gradeSign;}

int Form::getGradeExec() const {return this->gradeExec;}

bool Form::getIsSigned() const {return this->isSigned;}

void Form::beSigned(const Bureaucrat &guy)
{
	if (guy.getGrade() > gradeSign)
		throw GradeTooLowException;
	else
		isSigned = true;
}

std::ostream &operator<<(std::ostream &out, Form &obj)
{
	out << obj.getName() << ", a form you'll need a grade ";
	out << obj.getGradeSign() << " to sign, and a grade ";
	out << obj.getGradeExec() << " to execute, which is currently ";
	if (obj.getIsSigned())
		std::cout << "signed.\n";
	else
		std::cout << "unsigned.\n";
	return out;
}
