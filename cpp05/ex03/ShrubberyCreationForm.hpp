#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP
# include <string>
# include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	private:
		const std::string _target;
		const CustomException NoFileException;
	public:
		ShrubberyCreationForm();
		~ShrubberyCreationForm();
		ShrubberyCreationForm(const std::string &target);
		ShrubberyCreationForm(const ShrubberyCreationForm &other);
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);
		void execute(Bureaucrat const & executor) const;
		AForm *clone(const std::string &target) const;
};

#endif
