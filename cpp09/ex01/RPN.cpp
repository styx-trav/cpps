#include "RPN.hpp"

static bool isin(char a, std::string set)
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
			throw std::out_of_range("Error\n");
		else if (*it != ' ')
		{
			if (stac.empty())
				throw std::out_of_range("Error\n");
			tmp2 = stac.top();
			stac.pop();
			if (stac.empty())
				throw std::out_of_range("Error\n");
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
		throw std::out_of_range("Error\n");
	return stac.top();
}
