#include "RPN.hpp"

static bool isin(char a, std::string set)
{
	size_t pos = set.find(a);
	return (pos != std::string::npos);
}

int operate(char *lm)
{
	std::stack<int> stac;
	std::string s = lm;
	int tmp2, tmp1;
	std::string::iterator prev = s.begin();
	for (std::string::iterator it = s.begin(); it != s.end(); it++)
	{
		if (!isin(*it, " *+-/0123456789"))
			throw std::out_of_range("Error\n");
		if (*it != ' ' && prev != s.begin() && *prev != ' ')
			throw std::out_of_range("Error\n");
		if (isdigit(*it))
			stac.push((*it - '0'));
		else if (*it != ' ')
		{
			if (stac.size() != 2)
				throw std::out_of_range("Error\n");
			tmp2 = stac.top();
			stac.pop();
			tmp1 = stac.top();
			stac.pop();
			if (*it == '-')
				tmp1 -= tmp2;
			if (*it == '+')
				tmp1 += tmp2;
			if (*it == '*')
				tmp1 *= tmp2;
			if (*it == '/') {
				if (!tmp2) { throw std::out_of_range("Error\ndivision by 0\n"); }
				tmp1 /= tmp2;
			}
			stac.push(tmp1);
		}
		prev = it;
	}
	if (stac.size() != 1)
		throw std::out_of_range("Error\n");
	return stac.top();
}
