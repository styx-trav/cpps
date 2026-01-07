#include <map>
#include <exception>
#include <iostream>
#include <sstream>
#include <string>
#include <cmath>
#include <fstream>

//okay, first setup :: no checks, just translation of the basic database
std::map<std::string, float> *db_setup(std::string filename)
{
	std::ifstream Input(filename.c_str(), std::ios::in);
	if (!Input)
		throw std::out_of_range("first database file could not be opened\n");
	std::string date;
	std::string value;
	std::map<std::string, float> *nex = new std::map<std::string, float>;
	getline(Input, date);
	while (!Input.eof())
	{
		getline(Input, date, ',');
		if (date.empty())
			break ;
		getline(Input, value);
		nex->insert(std::pair<std::string, float>(date, atof(value.c_str())));
	}
	Input.close();
	return nex;
}

bool isdate(int year, int month, int day)
{
	//baseline
	if (day > 31)
		return false;
	//bisextile years for february
	if (month == 2)
	{
		if (day > 29)
			return false;
		if (day == 29)
		{
			if ((year % 4) || ((year % 100) && !(year % 400)))
				return false;
			else
				return true;
		}
	}
	//30-day months
	if (month == 4 || month == 6 || month == 9 || month == 11)
	{
		if (day > 30)
			return false;
	}
	return true;
}

void check_date(std::string date)
{
	std::stringstream s(date);
	std::out_of_range ex(("bad input => " + date));
	if (s.eof())
		throw ex;
	getline(s, date, '-');
	int year = atoi(date.c_str());
	if (s.eof())
		throw ex;
	getline(s, date, '-');
	int month = atoi(date.c_str());
	if (month < 1 || month > 12)
		throw ex;
	if (s.eof())
		throw ex;
	getline(s, date);
	int day = atoi(date.c_str());
	if (day < 1 || !isdate(year, month, day) || !s.eof())
		throw ex;
}

float check_float(std::string value)
{
	float res = atof(value.c_str());
	if (res < 0)
		throw std::out_of_range("not a positive number.");
	if (res > 1000)
		throw std::out_of_range("too large a number.");
	return res;
}

float proxy_date(std::string date, std::map<std::string, float> *base)
{
	float res = 0;
	for (std::map<std::string, float>::iterator it = base->begin(); it != base->end(); it++)
	{
		if (date.compare(it->first) < 0)
			return res;
		res = it->second;
	}
	return res;
}

void rread(std::string l, std::map<std::string, float> *base)
{
	std::stringstream s(l);
	std::string date;
	std::string value;
	float res;
	if (s.eof())
		return ;
	getline(s, date, ' ');
	getline(s, value, ' ');
	getline(s, value);
	try
	{
		check_date(date);
		res = check_float(value);
		std::cout << date << " => " << res << " = ";
		if (base->count(date))
			res *= (*base)[date];
		else
			res *= proxy_date(date, base);
		std::cout << res << std::endl;
	}
	catch (std::exception &e) {std::cerr << "Error : " << e.what() << std::endl;}
}

int main(int ac, char **av)
{
	if (ac != 2)
		return 0;
	std::ifstream Input(av[1]);
	if (!Input)
	{
		std::cerr << "argument file could not be opened !\n";
		return 0;
	}
	try
	{
		std::map<std::string, float> *base = db_setup("data.csv");
		std::cout << "attempting a read on my map" << std::endl;
		std::string current;
		getline(Input, current);
		while (!Input.eof())
		{
			getline(Input, current);
			rread(current, base);
		}
		delete base;
	}
	catch (std::exception &e) {std::cerr << e.what();}
}
