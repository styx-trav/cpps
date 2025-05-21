#include <cstring>
#include <iostream>
#include "Contact.hpp"

class	PhoneBook
{
	public:
		Contact	cons[8];
		void	addContact();
		void	printContacts();
		void	setUp();
};

//void	PhoneBook::addContact();
//void	PhoneBook::printContacts();
