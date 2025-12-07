#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

int main()
{
	try
	{
		std::cout << std::endl;
		Bureaucrat Alice("Alice", 150);
		std::cout << std::endl;
		ShrubberyCreationForm neo("home");
		std::cout << std::endl;
		Alice.signForm(neo);
		std::cout << std::endl;
		Alice.executeForm(neo);
		std::cout << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << std::endl;
		std::cout << e.what();
		std::cout << std::endl;
	}
}
