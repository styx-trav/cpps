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
		ScalarConverter(const ScalarConverter &other);
		~ScalarConverter();
	public:
		static void convert(std::string val);
		ScalarConverter &operator=(const ScalarConverter &other);
};

bool case_zero(const char *s);
void disp_char(char a);
bool disp_int(std::string val);
void disp_float(std::string val);
void disp_double(std::string val);

#endif
