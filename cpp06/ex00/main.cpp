#include "ScalarConverter.hpp"

int main(int argc, char *argv[])
{
	if (argc != 2)
		return 0;
	std::string sdl = argv[1];
	ScalarConverter::convert(sdl);
}
