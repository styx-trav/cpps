#include "Span.hpp"

int main()
{
	//these tests are sparse and bare bones at best, here the outline for their better halves ::
	//we'll need :: huge amount of numbers (10000 min recommended amount); testing multiple appends;
	{
		std::cout << "-----------------------------------------------------------\n";
		std::cout << "testing shortest and longest spans on empty Span\n";
		Span e;
		try { std::cout << "see shortest : " << e.shortestSpan() << "and/or longest span : " << e.longestSpan() << std::endl; }
		catch (std::exception &e) { std::cout << e.what(); }
	}
	{
		std::cout << "-----------------------------------------------------------\n";
		std::cout << "testing shortest and longest spans on one-sized Span\n";
		Span e(1);
		e.addNumber(6);
		try { std::cout << "see shortest : " << e.shortestSpan() << "and/or longest span : " << e.longestSpan() << std::endl; }
		catch (std::exception &e) { std::cout << e.what(); }
	}
	{
		std::cout << "------------------------------------------------------------\n";
		Span a(3);
		a.print();
		a.addNumber(47);
		a.print();
		a.addNumber(58);
		a.print();
		a.addNumber(21);
		a.print();
		try { a.addNumber(89); }
		catch (std::exception &e) { std::cout << e.what(); }
		a.print();
		try {
			std::cout << std::endl << "here the shortest span, lets see it :: " << a.shortestSpan() << std::endl;
			std::cout << std::endl << "here the longest span, lets see it :: " << a.longestSpan() << std::endl;
		}
		catch (std::exception &e) { std::cout << e.what(); }
		std::cout << std::endl << std::endl;
		std::cout << "-----------------------------------------------------------------------\n";
		Span b(8);
		try { b = a; }
		catch (std::exception &e) { std::cout << e.what(); }
		b.addNumber(2147483647);
		int mapi[] = {6, 1, 78, 24, 57, 5, 6};
		b.append<int *>(&(mapi[0]), &(mapi[6]), 6);
		b.addNumber(-2147483648);
		b.print();
		try
		{
			std::cout << std::endl << "here the shortest span, lets see it :: " << b.shortestSpan() << std::endl;
			std::cout << std::endl << "here the longest span, lets see it :: " << b.longestSpan() << std::endl;
			b.append<int *>(&(mapi[0]), 6);
		}
		catch (std::exception &e) { std::cout << e.what(); }
		std::cout << std::endl << std::endl;
	}
	{
		std::cout << "------------------------------------------------------------------\n";
		std::cout << "testing three appends in a row, one too long\n";
		Span e(9);
		int mapi[] = {4, 6, -1};
		int map1[] = {7, -8, 5};
		int map2[] = {8, 7, 2, 17, 77, -46};
		try {
			e.append<int *>(&(mapi[0]), 3);
			e.append<int *>(&(map1[0]), &(map1[2]), 2);
			e.append<int *>(&(map2[0]), &(map2[5]), 4);
		}
		catch (std::exception &e) { std::cout << e.what(); }
		e.print();
		std::cout << std::endl << std::endl;
	}
}
	
