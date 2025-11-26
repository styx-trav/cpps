#include "HumanA.hpp"

HumanA::HumanA(std::string naming, Weapon &weaponing) : weapon (weaponing)
{
	std::cout << "creating a humanA\n";
	name = naming;
}

HumanA::~HumanA()
{
	std::cout << "destroying humanA " << name << "\n";
}

void	HumanA::attack(void)
{
	std::cout << name << " attacks with their " << weapon.getType() << "\n";
}
