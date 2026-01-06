#include <map>
#include <exception>
#include <iostream>
#include <string>

std::map<std::string, float> setup(char *filename)
{
	std::ifstream Input(filename, std::ios::in);
	if (!Input)
		throw std::out_of_range("database file could not be opened\n");
	
