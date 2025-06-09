#include "Harl.hpp"

int main()
{
	Harl theHarl;

	std::cout << "show me debug :: \n";
	theHarl.complain("DEBUG");
	std::cout << "\nthen info :: \n";
	theHarl.complain("INFO");
	std::cout << "\nthen error :: \n";
	theHarl.complain("ERROR");
	std::cout << "\nthen warning :: \n";
	theHarl.complain("WARNING");
	std::cout << "\nand now something else :: \n";
	theHarl.complain("ew");
}
