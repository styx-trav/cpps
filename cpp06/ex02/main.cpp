#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
# include <cstdlib>
# include <ctime>

Base * generate(void)
{
	srand(time(0));
	int s = rand() % 3;
	Base *ptr = 0;
	if (!s)
		ptr = new A();
	else if (s == 1)
		ptr = new B();
	else
		ptr = new C();
	return ptr;
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p) != 0)
		std::cout << "A";
	else if (dynamic_cast<B*>(p) != 0)
		std::cout << "B";
	else
		std::cout << "C";
}

void identify(Base& p)
{
	try
	{
		A &obj = dynamic_cast<A&>(p);
		(void)obj;
		std::cout << "A";
	}
	catch (std::exception &e)
	{
		try
		{
			B &obj = dynamic_cast<B&>(p);
			(void)obj;
			std::cout << "B";
		}
		catch (std::exception &e)
		{
			std::cout << "C";
		}
	}
}

int main()
{
	std::cout << "First we'll generate an object\n";
	Base *s = generate();
	std::cout << "Then we identify it as a pointer !\nThis object is a Base type : ";
	identify(s);
	std::cout << std::endl << "And then we identify it as a reference !\nThis object is a Base type : ";
	identify(*s);
	std::cout << std::endl;
	delete s;
}
