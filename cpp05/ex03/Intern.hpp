#ifndef INTERN_HPP
# define INTERN_HPP
# include <iostream>
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern
{
	private:
		const AForm *inventory[3];
	public:
		Intern();
		~Intern();
		Intern(const Intern &other);
		Intern &operator=(const Intern &other);
		AForm *makeForm(const std::string &form, const std::string &target) const;
};

#endif
