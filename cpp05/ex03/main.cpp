#include "Intern.hpp"
#include "Bureaucrat.hpp"

int main()
{
	Intern myGuy;
	std::cout << std::endl << std::endl;
	//first, trying out the SrubberyCreationForm;
	std::cout << std::endl;
	AForm *neo = myGuy.makeForm("shrubbery creation", "home");
	try
	{
		std::cout << std::endl << *neo << std::endl;
		
		//this Alice can both sign and execute this file
		//Bureaucrat Alice("Alice", 137);
		
		//this Alice can sign the file, but not execute it
		//Bureaucrat Alice("Alice", 138);
		
		//and this Alice can neither sign nor execute the file
		Bureaucrat Alice("Alice", 146);
		std::cout << std::endl;
		
		Alice.signForm(*neo);
		std::cout << std::endl;
		Alice.executeForm(*neo);
		std::cout << std::endl;
		delete neo;
	}
	catch (std::exception &e)
	{
		std::cout << std::endl;
		std::cout << e.what();
		std::cout << std::endl;
		delete neo;
	}
	
	//then, trying out the RobotomyRequestForm;
	std::cout << std::endl;
	neo = myGuy.makeForm("robotomy request", "Mark's worst enemy");
	try
	{
		std::cout << std::endl << *neo << std::endl;
		
		//this Mark can both sign and execute this file
		//Bureaucrat Mark("Mark", 45);
		
		//this Mark can sign the file, but not execute it
		//Bureaucrat Mark("Mark", 46);
		
		//and this Mark can neither sign nor execute the file
		Bureaucrat Mark("Mark", 73);
		std::cout << std::endl;
		
		Mark.signForm(*neo);
		std::cout << std::endl;
		Mark.executeForm(*neo);
		std::cout << std::endl;
		delete neo;
	}
	catch (std::exception &e)
	{
		std::cout << std::endl;
		std::cout << e.what();
		std::cout << std::endl;
		delete neo;
	}
	//and finally, trying out the PresidentialPardonForm;
	std::cout << std::endl;
	neo = myGuy.makeForm("presidential pardon", "Bob's Dad");
	try
	{
		std::cout << std::endl << *neo << std::endl;
		
		//this Bob can both sign and execute this file
		//Bureaucrat Bob("Bob", 5);
		
		//this Bob can sign the file, but not execute it
		//Bureaucrat Bob("Bob", 6);
		
		//and this Bob can neither sign nor execute the file
		Bureaucrat Bob("Bob", 26);
		std::cout << std::endl;
		
		Bob.signForm(*neo);
		std::cout << std::endl;
		Bob.executeForm(*neo);
		std::cout << std::endl;
		delete neo;
	}
	catch (std::exception &e)
	{
		std::cout << std::endl;
		std::cout << e.what();
		std::cout << std::endl;
		delete neo;
	}
	std::cout << std::endl << std::endl;
}
