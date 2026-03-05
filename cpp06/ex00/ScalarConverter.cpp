#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::~ScalarConverter() {}

bool isint(std::string s)
{
	bool neg = false;
	if (s.at(0) == '-')
	{
		s.erase(s.begin());
		neg = true;
	}
	while (!s.empty() && s.at(0) == '0')
		s.erase(s.begin());
	if (s.empty())
		return true;
	std::string::iterator it = s.begin();
	while (it != s.end() && std::isdigit(*it))
		it++;
	if (it != s.end())
		return false;
	if (s.length() > 10)
		return false;
	if (s.length() == 10)
	{
		if (!neg && s.compare("2147483647") > 0)
			return false;
		if (neg && s.compare("2147483648") > 0)
			return false;
		return true;
	}
	return true;
}

void disp_int(std::string val)
{
	int s;
	s = std::atoi(val.c_str());
	std::cout << "char : ";
	if (CHAR_MIN <= s && s <= CHAR_MAX)
	{
		if (isprint(s))
		std::cout << static_cast<char>(s) << std::endl;
		else
			std::cout << "Non displayable\n";
	}
	else
		std::cout << "impossible\n";
	std::cout << "int : " << s << std::endl;
	std::cout << "float : " << static_cast<float>(s) << "f\n";
	std::cout << "double : " << static_cast<double>(s) << std::endl;
}

void disp_char(char a)
{
	std::cout << "char : " << a << std::endl;
	std::cout << "int : " << static_cast<int>(a) << std::endl;
	std::cout << "float : " << static_cast<float>(a) << "f\n";
	std::cout << "double : " << static_cast<double>(a) << "\n";
}

bool case_zero(const char *s)
{
	if (s[0] && s[0] != '0')
		return false;
	int i = 1;
	int dot = 0;
	while ((s[i] == '0' || s[i] == '.') && dot < 2)
	{
		if (s[i] == '.')
			dot++;
		i++;
	}
	std::cout << "char : Non displayable\n";
	if (!s[i] && !dot)
	{
		i = 0;
		std::cout << "int : " << i << "\n";
		std::cout << "float : " << static_cast<float>(i) << "f\n";
		std::cout << "double : " << static_cast<double>(i) << "\n";
		return true;
	}
	if (s[i] == 'f' && !s[i +1])
	{
		float f = 0.0;
		std::cout << "int : " << static_cast<int>(f) << "\n";
		std::cout << "float : " << f << "f\n";
		std::cout << "double : " << static_cast<double>(f) << "\n";
		return true;
	}
	if (!s[i])
	{
		double f = 0.0;
		std::cout << "int : " << static_cast<int>(f) << "\n";
		std::cout << "float : " << static_cast<float>(f) << "f\n";
		std::cout << "double : " << f << "\n";
		return true;
	}
	return false;
}

void disp_double(std::string val)
{
	double n = atof(val.c_str());
	if (n == 0)
	{
		std::cout << "char : impossible\nint : impossible\nfloat : impossible\ndouble : impossible\n";
		return ;
	}
	std::cout << "char : ";
	//overflow char
	if (!std::isinf(n) && n == n && CHAR_MIN <= n && n <= CHAR_MAX)
	{
		if (std::isprint(static_cast<int>(n)))
			std::cout << static_cast<char>(n) << std::endl;
		else
			std::cout << "Non displayable\n";
	}
	else
		std::cout << "impossible\n";
	std::cout << "int : ";
	//overflow again (int)
	if (!std::isinf(n) && n == n && n <= INT_MAX && n >= INT_MIN)
		std::cout << static_cast<int>(n) << std::endl;
	else
		std::cout << "impossible\n";
	std::cout << "float : ";
	//overflow again (float)
	if (std::isinf(n) || n != n || (n >= -FLT_MAX && n <= FLT_MAX))
		std::cout << static_cast<float>(n) << "f\n";
	else
		std::cout << "impossible\n";
	std::cout << "double : " << n << std::endl;
}

void disp_float(std::string val)
{
	if (case_zero(val.c_str()))
		return ;
	if (*(val.rbegin()) != 'f')
	{
		disp_double(val);
		return ;
	}
	float n = atof(val.c_str());
	if (n == 0)
	{
		std::cout << "char : impossible\nint : impossible\nfloat : impossible\ndouble : impossible\n";
		return ;
	}
	std::cout << "char : ";
	//overflow char
	if (!std::isinf(n) && n == n && CHAR_MIN <= n && n <= CHAR_MAX)
	{
		if (std::isprint(static_cast<int>(n)))
			std::cout << static_cast<char>(n) << std::endl;
		else
			std::cout << "Non displayable\n";
	}
	else
		std::cout << "impossible\n";
	std::cout << "int : ";
	//overflow again (int)
	if (!std::isinf(n) && n == n && n < static_cast<float>(INT_MAX) && n >= INT_MIN)
		std::cout << static_cast<int>(n) << std::endl;
	else
		std::cout << "impossible\n";
	std::cout << "float : ";
	std::cout << n << "f\n";
	std::cout << "double : " << static_cast<double>(n) << std::endl;
}

void ScalarConverter::convert(std::string val)
{
	std::cout << std::fixed;
	std::cout.precision(1);
	if (val.length() == 1)
	{
		char a = (val.c_str())[0];
		if (isdigit(a))
			disp_int(val);
		else
			disp_char(a);
	}
	else
	{
		if (isint(val))
			disp_int(val);
		else
			disp_float(val);
	}
}
