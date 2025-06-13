#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP
#include "Contact.hpp"

class	PhoneBook
{
	private:
		Contact	cons[8];
		int index;
	public:
		PhoneBook();
		void	addContact();
		void	printContacts();
		void	setUp();
};

#endif
