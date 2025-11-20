#include <iostream>
#include <fstream>
#include <cstring>
#include <string>

int main()
{
	std::ifstream streamHere("notes", std::ios::in);
	std::ofstream streamOut("notes.replace", std::ios::out);
	const std::string	s1 = "string";
	const std::string	s2 = "improved_string";
	std::string line;
	std::string tmp;
	size_t pos;

	if (!streamHere)
		return 0;
	//protections go here :: check input file access, output file existence, etc. (is there more ?)
	getline(streamHere, line);
	while (!streamHere.eof())
	{
		do
		{
			pos = line.find(s1, 0);
			if (pos == std::string::npos)
				streamOut << line;
			else
			{
				tmp = line.substr(0, pos);
				streamOut << tmp;
				streamOut << s2;
				tmp = line.substr(pos + s1.length(), line.length() - pos - s1.length());
				line = tmp;
			}
		} while (pos != std::string::npos);
		if (!streamHere.eof())
			streamOut << std::endl;
		getline(streamHere, line);
	}
        streamHere.close();
        streamOut.close();
}
