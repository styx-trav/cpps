#include "PhoneBook.hpp"

void	PhoneBook::addContact()
{
	int index = 0;
	for(int i = 0; i != 8; ++i)
	{
		if (cons[i].info[0][0] == '\0')
		{
			index = i;
			break ;
		}
	}
	cons[index].newContact();
}

void	PhoneBook::printContacts()
{
	char index;
	std::cout << "|     index|    f_name|    l_name|  nickname|\n";
	if (cons[0].info[0][0] == '\0')
		return ;
	for(int i = 0; i != 8; ++i)
	{
		if (cons[i].info[0][0] == '\0')
			break ;
		std::cout << "|         " << i;
		cons[i].printLine();
	}
	std::cin >> index;
	if (!(std::isdigit(index)) || index < '0' || index > '7' || cons[index - '0'].info[0][0] == '\0')
	{
		std::cout << index << ": bad index\n";
		return ;
	}
	cons[index - '0'].printContact();
	return ;
}
