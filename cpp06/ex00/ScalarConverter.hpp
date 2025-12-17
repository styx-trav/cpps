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
	public:
		ScalarConverter();
		virtual ~ScalarConverter() = 0;
		ScalarConverter(const ScalarConverter &other);
		ScalarConverter &operator=(const ScalarConverter &other);
		static void convert(const std::string &val);
};

#endif
