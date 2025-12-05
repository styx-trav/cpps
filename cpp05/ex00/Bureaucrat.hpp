#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <iostream>
# include <string>
# include "CustomException.hpp"

class Bureaucrat
{
	private:
		const std::string _name;
		int grade;
		static const int high = 1;
		static const int low = 150;
		const CustomException GradeTooHighException;
		const CustomException GradeTooLowException;
	public:
		Bureaucrat();
		~Bureaucrat();
		Bureaucrat(const std::string &name, int r);
		Bureaucrat(const Bureaucrat &other);
		Bureaucrat &operator=(const Bureaucrat &other);
		const std::string &getName() const;
		int getGrade() const;
		void demotion();
		void promotion();
};

std::ostream &operator<<(std::ostream &out, Bureaucrat &obj);

#endif
