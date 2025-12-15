#include "ScalarConverter.hpp"

int main(int argc, char *argv[])
{
	if (argc != 2)
		return 0;
	std::string sdl = argv[1];
	ScalarConverter::convert(sdl);
}

//okay, looks good now, hopefully that's it. will need more tests, but that's down the line. I ended up recreating my own stoi to make up for my misread
