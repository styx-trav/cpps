#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP
# include <iostream>
# include <cstdlib>
# include <ctime>
# include "AForm.hpp"


class RobotomyRequestForm : public AForm
{
	private:
		const std::string _target;
	public:
		RobotomyRequestForm();
		~RobotomyRequestForm();
		RobotomyRequestForm(const std::string &target);
		RobotomyRequestForm(const RobotomyRequestForm &other);
		RobotomyRequestForm &operator=(const RobotomyRequestForm &other);
		void execute(Bureaucrat const & executor) const;
		AForm *clone(const std::string &target) const;
};

#endif
