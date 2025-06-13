#include "PhoneBook.hpp"

PhoneBook::PhoneBook(){index = 0;}

void	PhoneBook::addContact()
{
	cons[index].newContact();
	index++;
	if (index == 8)
		index = 0;
}

void	PhoneBook::printContacts()
{
	char index;
	std::cout << "|     index|    f_name|    l_name|  nickname|\n";
	if (cons[0].isEmpty())
		return ;
	for(int i = 0; i != 8; ++i)
	{
		if (cons[i].isEmpty())
			break ;
		std::cout << "|         " << i;
		cons[i].printLine();
	}
	std::cin >> index;
	if (std::cin.eof())
		return;
	if (!(std::isdigit(index)) || index < '0' || index > '7' || cons[index - '0'].isEmpty())
	{
		std::cout << index << ": bad index\n";
		return ;
	}
	std::cin.ignore();
	cons[index - '0'].printContact();
	return ;
}
