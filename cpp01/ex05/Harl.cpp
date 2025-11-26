#include "Harl.hpp"

void	Harl::debug(void)
{
	std::cout << "[DEBUG]\nhey yeah, so there's an infinite loop if I run your program with specifically 4 arguments\n";
}

void	Harl::info(void)
{
	std::cout << "[INFO]\nfrom the valgrind read, looks like it's from the recursive called 'until_the_queen_is_dead' ? couldn't quite figure out what it does exactly, but maybe Tom has more info\n";
}

void	Harl::warning(void)
{
	std::cout << "[WARNING]\nhi guys, did you run this fix through anyone before pushing it ? i ran this twenty minutes ago now my computer's unresponsive\n";
}

void	Harl::error(void)
{
	std::cout << "[ERROR]alright, my computer is currently on fire, so i'd advise anyone to _not_ run this. also whoever pushed this i will be sending you a bill shortly\n";
}

void	Harl::complain(std::string level)
{
	std::string find[4] = {"DEBUG", "ERROR", "WARNING", "INFO"};
	void (Harl::*f[4])(void) = {&Harl::debug, &Harl::error, &Harl::warning, &Harl::info};
	for (int i = 0; i != 4; ++i)
	{
		if (find[i] == level)
		{
			(this->*f[i])();
			return ;
		}
	}
	std::cout << "Not a level\n";
}
