#include <iostream>
#include <fstream>
#include <cstring>
#include <string>

int main(int argc, char **argv)
{
	if (argc != 4)
		return 0;
	
	std::ifstream streamHere(argv[1], std::ios::in);
	if (!streamHere)
		return 0;
	
	std::string line = argv[1];
	line = line + ".replace";
	std::ofstream streamOut(line.c_str(), std::ios::out);
	if (!streamOut)
		return 0;
	
	const std::string	s1 = argv[2];
	const std::string	s2 = argv[3];
	std::string tmp;
	size_t pos;

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
