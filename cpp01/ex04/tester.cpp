#include <iostream>
#include <fstream>
#include <cstring>

int main()
{
	ifstream streamHere("notes");
	ofstream streamOut("notes.replace");
	const std::string	s1 = "file";
	const std::string	s2 = "input";
	std::string line;
	size_t pos;

	if (!streamHere)
		return 0;
	do
	{
		getline(streamHere, line);
		pos = 0;
		do
		{
			pos = line.find(s1, pos);
			if (pos == string::npos)
				break;
			
