#include "HumanA.hpp"

HumanA::HumanA(std::string naming, Weapon &weaponing)
{
	std::cout << "creating a humanA\n";
	name = naming;
	Weapon *newWeapon = &weaponing;
	weapon = newWeapon;
}

HumanA::~HumanA()
{
	std::cout << "destroying humanA " << name << "\n";
}

void	HumanA::attack(void)
{
	std::cout << name << " attacks with their " << weapon->getType() << "\n";
}
