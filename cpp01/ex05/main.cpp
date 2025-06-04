#include "Harl.hpp"

int main()
{
	Harl theHarl;

	std::cout << "show me debug, then info, then error then warning then something else\n";
	theHarl.complain("DEBUG");
	theHarl.complain("INFO");
	theHarl.complain("ERROR");
	theHarl.complain("WARNING");
	theHarl.complain("ew");
}
