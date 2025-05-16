#include <cstring>
#include <iostream>

class	PhoneBook
{
	public:
		Contact	cons[8];
		void	addContact();
		void	printContacts();
		void	setUp();
};

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
	int index;
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
	if (index < 0 || index > 7 || cons[index].info[0][0] == '\0')
	{
		std::cout << index << ": bad index\n";
		return ;
	}
	cons[index].printContact();
	return ;
}
