#include <cstring>
#include <iostream>

class Contact
{
	public:
		std::string	info[5];
		void	printContact();
		void	printLine();
		void	newContact();
};

void	Contact::newContact()
{
	for(int j = 0; j != 5; ++j)
	{
		std::cout << "Please enter ";
		if (j == 0)
			std::cout << "the first name\n";
		else if (j == 1)
			std::cout << "the last name\n";
		else if (j == 2)
			std::cout << "the nickname\n";
		else if (j == 3)
			std::cout << "the phone number\n";
		else
			std::cout << "the darkest secret\n";
		std::cin >> info[j];
	}
}

void	Contact::printContact()
{
	std::cout << "first name : " << info[0] << '\n';
	std::cout << "last name : " << info[1] << '\n';
	std::cout << "nickname : " << info[2] << '\n';
	std::cout << "phone number : " << info[3] << '\n';
	std::cout << "darkest secret : " << info[4] << '\n';
}

void	Contact::printLine()
{
	int	dist;

	std::cout << '|';
	for(int i = 0; i != 3; ++i)
	{
		dist = 10 - info[i].length();
		if (dist >= 0)
		{
			for(int j = 0; j != dist; ++j)
				std::cout << ' ';
		}
		for(int j = 0; (j != -dist + 10) && (j != 10); ++j)
		{
			if (j == 9 && dist < 0)
				std::cout << '.';
			else
				std::cout << info[i][j];
		}
		std::cout << '|';
	}
	std::cout << '\n';
}
