#ifndef AFORM_HPP
# define AFORM_HPP
# include <iostream>
# include "CustomException.hpp"
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		const std::string _name;
		const int gradeSign;
		const int gradeExec;
		const CustomException GradeTooLowException;
		const CustomException GradeTooHighException;
		const CustomException NotSignedException;
		bool isSigned;
	public:
		AForm();
		virtual ~AForm() = 0;
		AForm(const std::string &name, int sign, int exec);
		AForm(const AForm &other);
		AForm &operator=(const AForm &other);
		const std::string &getName() const;
		int getGradeSign() const;
		int getGradeExec() const;
		bool getIsSigned() const;
		void beSigned(const Bureaucrat &guy);
		virtual void execute(Bureaucrat const & executor) const;
};

std::ostream &operator<<(std::ostream &out, AForm &obj);

#endif
