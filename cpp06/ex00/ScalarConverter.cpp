#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &other) {(void)other; }

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other) { if (&other == this) { std::cout << "assignment on same object !\n"; } return *this; }

ScalarConverter::~ScalarConverter() {}

void ScalarConverter::convert(std::string val)
{
	std::cout << std::fixed;
	std::cout.precision(1);
	if (val.length() == 1 && !isdigit(val.at(0)))
		disp_char(val.at(0));
	else if (!case_zero(val.c_str()) && !disp_int(val))
		disp_float(val);
}

bool is_int(std::string val)
{
	bool neg = (val.at(0) == '-');
	if (val.at(0) == '+' || val.at(0) == '-') { val.erase(val.begin()); }
	bool done = false;
	for (std::string::iterator it = val.begin(); it != val.end(); it++) {
		if (!done && !isdigit(*it)) { done = true; }
		if (done) { it = val.erase(it); }
	}
	if (val.empty() || val.length() > 10) { return false; }
	if (neg && val.compare("2147483648") > 0) { return false; }
	if (!neg && val.compare("2147483647") > 0) { return false; }
	return true;
}

bool disp_int(std::string val)
{
	int s;
	if (!is_int(val)) { return false; }
	s = std::atoi(val.c_str());
	if (!s) { return false; }
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
	return true ;
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
	int i = 0;
	while (s[i] == '+' || s[i] == '-') { i++; }
	if (!s[i] || s[i] != '0')
		return false;
	bool dot = false;
	while ((s[i] == '0' || s[i] == '.')) {
		if (s[i] == '.') {
			if (dot) { break ; }
			dot = true;
		}
		i++;
	}
	if (s[i] && isdigit(s[i])) { return false; }
	std::cout << "char : Non displayable\n";
	if (!s[i] && !dot)
	{
		i = 0;
		std::cout << "int : " << i << "\n";
		std::cout << "float : " << static_cast<float>(i) << "f\n";
		std::cout << "double : " << static_cast<double>(i) << "\n";
		return true;
	}
	if (s[i] == 'f')
	{
		float f = 0.0;
		std::cout << "int : " << static_cast<int>(f) << "\n";
		std::cout << "float : " << f << "f\n";
		std::cout << "double : " << static_cast<double>(f) << "\n";
		return true;
	}
	double f = 0.0;
	std::cout << "int : " << static_cast<int>(f) << "\n";
	std::cout << "float : " << static_cast<float>(f) << "f\n";
	std::cout << "double : " << f << "\n";
	return true;
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
