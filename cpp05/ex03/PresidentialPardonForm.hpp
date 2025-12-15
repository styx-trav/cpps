#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP
# include <iostream>
# include "AForm.hpp"


class PresidentialPardonForm : public AForm
{
	private:
		const std::string _target;
	public:
		PresidentialPardonForm();
		~PresidentialPardonForm();
		PresidentialPardonForm(const std::string &target);
		PresidentialPardonForm(const PresidentialPardonForm &other);
		PresidentialPardonForm &operator=(const PresidentialPardonForm &other);
		void execute(Bureaucrat const & executor) const;
		AForm *clone(const std::string &target) const;
};

#endif
