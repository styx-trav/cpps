# include <iostream>
# include <string>
# include <cstdlib>
# include <climits>
# include <cfloat>
# include <cmath>

//okay, fuck it :: i'm just making my own ::stoi(), dude --> checking everything, exception on issues
//==> no fancy shit, it's 1 minus sign max, and then all numbers
//and of course, an under/over check

int our_stoi(const std::string &s)
{
	const char *n = s.c_str();
	std::out_of_range her("out of range, baby !\n");
	int i = 0;
	if (n[i] == '-')
		i++;
	while (n[i] && std::isdigit(n[i]))
		i++;
	if (n[i])
		throw her;
	if (n[0] != '-')
	{
		if (s.length() > 10)
			throw her;
		if (s.compare("2147483647") > 0)
			throw her;
		return std::atoi(n);
	}
	if (s.length() > 11)
		throw her;
	if (s.compare("-2147483648") > 0)
		throw her;
	return std::atoi(n);
}
int main(int argc, char **argv)
{
	if (argc != 2)
		return 0;
	//let's test out this atoi thing, alright ?
	std::cout << "first a double : " << std::atof(argv[1]) << ", then \n";
	try
	{
		std::string s = argv[1];
		int n = our_stoi(s);
		std::cout << n << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what();
	}
}
