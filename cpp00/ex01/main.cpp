#include <cstring>
#include <iostream>
#include "PhoneBook.hpp"

int main()
{
	PhoneBook bookNote;
	for (std::string current; current != "EXIT"; std::cin >> current)
	{
		if (current == "ADD")
		{
			bookNote.addContact();
			std::cout << "ADD over\n";
		}
		else if (current == "SEARCH")
		{
			bookNote.printContacts();
			std::cout << "SEARCH over\n";
		}
	}
	return 0;
}
