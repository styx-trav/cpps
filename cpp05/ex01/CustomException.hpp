#ifndef CUSTOMEXCEPTION_HPP
# define CUSTOMEXCEPTION_HPP
# include <iostream>
# include <bits/stdc++.h>
# include <string>

class CustomException : public std::out_of_range
{
	public:
		CustomException();
		CustomException(const CustomException &other);
		CustomException &operator=(const CustomException &other);
		~CustomException() throw();
		CustomException(const std::string &msg);
};

#endif
