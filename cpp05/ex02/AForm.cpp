#include "AForm.hpp"

AForm::AForm() : _name("name"), gradeSign(1), gradeExec(1), GradeTooLowException(CustomException("this grade is too low.\n")), GradeTooHighException(CustomException("this grade is too high !\n")), isSigned(false)
{
	std::cout << "AForm default constructor called\n";
}

AForm::~AForm()
{
	std::cout << "AForm destructor called\n";
}

AForm::AForm(const std::string &name, int sign, int exec) : _name(name), gradeSign(sign), gradeExec(exec), GradeTooLowException(CustomException("this grade is too low.\n")), GradeTooHighException(CustomException("this grade is too high !\n")), isSigned(false)
{
	std::cout << "AForm constructor called\n";
	if (sign < 1 || exec < 1)
		throw GradeTooHighException;
	if (sign > 150 || exec > 150)
		throw GradeTooLowException;
}

AForm::AForm(const AForm &other) : _name(other._name), gradeSign(other.gradeSign), gradeExec(other.gradeExec), GradeTooLowException(CustomException("this grade is too low.\n")), GradeTooHighException(CustomException("this grade is too high !\n")), isSigned(other.isSigned)
{
	std::cout << "AForm copy constructor called\n";
}

AForm& AForm::operator=(const AForm &other)
{
	if (this != &other)
	{
		isSigned = other.isSigned;
		std::cout << "AForm assignment operator called\n";
	}
	return *this;
}

const std::string &AForm::getName() const {return this->_name;}

int AForm::getGradeSign() const {return this->gradeSign;}

int AForm::getGradeExec() const {return this->gradeExec;}

bool AForm::getIsSigned() const {return this->isSigned;}

void AForm::beSigned(const Bureaucrat &guy)
{
	if (guy.getGrade() > gradeSign)
		throw GradeTooLowException;
	else
		isSigned = true;
}

std::ostream &operator<<(std::ostream &out, AForm &obj)
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
