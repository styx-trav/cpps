#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
	std::cout << "ScalarConverter default constructor called\n";
}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
	(void)other;
	std::cout << "ScalarConverter copy constructor called\n";
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter &other)
{
	if (this != &other)
		std::cout << "ScalarConverter assignment operator called\n";
	return *this;
}

int our_stoi(const std::string &s)
{
	const char *n = s.c_str();
	std::out_of_range her("out of range, baby !\n");
	int i = 0;
	if (n[i] == '-')
		i++;
	while (n[i] && std::isdigit(n[i]))
		i++;
	if (n[i])
		throw her;
	if (n[0] != '-')
	{
		if (s.length() > 10)
			throw her;
		if (s.length() == 10 && s.compare("2147483647") > 0)
			throw her;
		return std::atoi(n);
	}
	if (n[1] == '0' || s.length() > 11)
		throw her;
	if (s.length() == 11 && s.compare("-2147483648") > 0)
		throw her;
	return std::atoi(n);
}

bool isint(const std::string &val)
{
	try
	{
		int res = our_stoi(val);
		(void)res;
	}
	catch (std::exception &e)
	{
		return false;
	}
	return true;
}

void disp_int(const std::string &val)
{
	int s;
	s = our_stoi(val);
	std::cout << "char : ";
	if (isprint(s))
		std::cout << static_cast<char>(s) << std::endl;
	else if (CHAR_MIN <= s && s >= CHAR_MAX)
		std::cout << "Non displayable\n";
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
	if (!s[i] || (s[i] == 'f' && !s[i +1]))
	{
		std::cout << "char : Non displayable\n";
		i = 0;
		std::cout << "int : " << i << "\n";
		std::cout << "float : " << static_cast<float>(i) << "f\n";
		std::cout << "double : " << static_cast<double>(i) << "\n";
		return true;
	}
	return false;
}

void disp_float(const std::string &val)
{
	if (case_zero(val.c_str()))
		return ;
	double n = atof(val.c_str());
	if (n == 0)
		std::cout << "char : impossible\nint : impossible\nfloat : impossible\ndouble : impossible\n";
	else
	{
		std::cout << "char : ";
		//overflow char
		if (!std::isinf(n) && n != NAN && CHAR_MIN <= n && n <= CHAR_MAX)
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
		if (!std::isinf(n) && n != NAN && n <= INT_MAX && n >= INT_MIN)
			std::cout << static_cast<int>(n) << std::endl;
		else
			std::cout << "impossible\n";
		std::cout << "float : ";
		//overflow again (float)
		if (std::isinf(n) || n == NAN || (n >= -FLT_MAX && n <= FLT_MAX))
			std::cout << static_cast<float>(n) << "f\n";
		else
			std::cout << "impossible\n";
		std::cout << "double : " << n << std::endl;
	}
}

void ScalarConverter::convert(const std::string &val)
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
