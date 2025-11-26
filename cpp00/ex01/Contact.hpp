#ifndef CONTACT_HPP
#define CONTACT_HPP
#include <cstring>
#include <iostream>

class Contact
{
	private:
		std::string	info[5];
	public:
		int	isEmpty() const;
		void	printContact() const;
		void	printLine() const;
		void	newContact();
};

#endif
