#include "Form.hpp"
#include "Bureaucrat.hpp"

int main()
{
	try {Form randomForm("form", 0, 150);}
	catch (std::exception &e)
	{
		std::cout << e.what();
	}
	std::cout << std::endl;
	try {Form randomForm("form", 1, 153);}
	catch (std::exception &e)
	{
		std::cout << e.what();
	}
	std::cout << std::endl;
	try {Form randomForm("form", 1, 0);}
	catch (std::exception &e)
	{
		std::cout << e.what();
	}
	std::cout << std::endl;
	try {Form randomForm("form", 173, 1);}
	catch (std::exception &e)
	{
		std::cout << e.what();
	}
	std::cout << std::endl;
	Bureaucrat Bob("Bob", 143);
	Bureaucrat Cecil("Cecil", 142);
	Form realForm("thisIsARealForm", 142, 127);
	std::cout << std::endl;
	std::cout << "creating ::\n" << Bob << Cecil << realForm << std::endl;
	try {Bob.signForm(realForm);}
	catch (std::exception &e)
	{
		std::cout << e.what();
	}
	std::cout << std::endl;
	try {Cecil.signForm(realForm);}
	catch (std::exception &e)
	{
		std::cout << e.what();
	}
	std::cout << realForm << std::endl;
}
