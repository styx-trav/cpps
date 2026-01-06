#include <stack>
#include <iostream>
#include <string>
#include <exception>

bool isin(char a, std::string set)
{
	for (std::string::iterator it = set.begin(); it != set.end(); it++)
	{
		if (a == *it)
			return true;
	}
	return false;
}

int operate(char *lm)
{
	std::stack<int> stac;
	std::string s = lm;
	int tmp2, tmp1;
	for (std::string::iterator it = s.begin(); it != s.end(); it++)
	{
		if (isdigit(*it))
			stac.push((*it - '0'));
		else if (!isin(*it, " *+-/"))
			throw std::out_of_range("incorrect input\n");
		else if (*it != ' ')
		{
			if (stac.empty())
				throw std::out_of_range("incorrect input\n");
			tmp2 = stac.top();
			stac.pop();
			if (stac.empty())
				throw std::out_of_range("incorrect input\n");
			tmp1 = stac.top();
			stac.pop();
			if (*it == '-')
				tmp1 -= tmp2;
			if (*it == '+')
				tmp1 += tmp2;
			if (*it == '*')
				tmp1 *= tmp2;
			if (*it == '/')
				tmp1 /= tmp2;
			stac.push(tmp1);
		}
	}
	if (stac.empty())
		throw std::out_of_range("incorrect input\n");
	return stac.top();
}

int main(int ac, char **argv)
{
	if (ac != 2)
		return 0;
	try {
		std::cout << "here our results ! " << operate(argv[1]) << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Error : " << e.what();
	}
}
