#ifndef FORM_HPP
# define FORM_HPP
# include <iostream>
# include "CustomException.hpp"
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string _name;
		const int gradeSign;
		const int gradeExec;
		const CustomException GradeTooLowException;
		const CustomException GradeTooHighException;
		bool isSigned;
	public:
		Form();
		~Form();
		Form(const std::string &name, int sign, int exec);
		Form(const Form &other);
		Form &operator=(const Form &other);
		const std::string &getName() const;
		int getGradeSign() const;
		int getGradeExec() const;
		bool getIsSigned() const;
		void beSigned(const Bureaucrat &guy);
};

std::ostream &operator<<(std::ostream &out, Form &obj);

#endif
