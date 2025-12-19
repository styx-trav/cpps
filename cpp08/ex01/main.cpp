#include "Span.hpp"

int main()
{
	//these tests are sparse and bare bones at best, here the outline for their better halves ::
	//we'll need :: testing adding a number beyond; testing an assignment unequal sizes; empty spans + one number spans fed into short/longest spans(); huge amount of numbers (10000 min recommended amount); testing multiple appends;
	Span a(3);
	a.print();
	a.addNumber(47);
	a.print();
	a.addNumber(58);
	a.print();
	a.addNumber(21);
	a.print();
	try
	{
		a.addNumber(89);
	}
	catch (std::exception &e)
	{
		std::cout << e.what();
	}
	a.print();
	try
	{
		std::cout << std::endl << "here the shortest span, lets see it :: " << a.shortestSpan() << std::endl << std::endl;
		std::cout << std::endl << "here the longest span, lets see it :: " << a.longestSpan() << std::endl << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what();
	}
	std::cout << std::endl << std::endl;
	Span b(8);
	try
	{
		b = a;
	}
	catch (std::exception &e)
	{
		std::cout << e.what();
	}
	b.addNumber(-2147483648);
	b.addNumber(2147483647);
	int mapi[] = {6, 5, 1, 78, 24, 57, 6};
	b.append<int *>(&(mapi[0]), &(mapi[6]));
	b.print();
	try
	{
		std::cout << std::endl << "here the shortest span, lets see it :: " << b.shortestSpan() << std::endl << std::endl;
		std::cout << std::endl << "here the longest span, lets see it :: " << b.longestSpan() << std::endl << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what();
	}
	std::cout << std::endl << std::endl;
}
	
