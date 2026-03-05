#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP
# include <iostream>
# include <string>
# include <cstdlib>
# include <climits>
# include <cfloat>
# include <cmath>

class ScalarConverter
{
	private:
		ScalarConverter();
		~ScalarConverter();
	public:
		static void convert(std::string val);
};

bool case_zero(const char *s);
bool isint(std::string s);
void disp_char(char a);
void disp_int(std::string val);
void disp_float(std::string val);
void disp_double(std::string val);

#endif
