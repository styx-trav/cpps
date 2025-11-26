#include "HumanB.hpp"

HumanB::HumanB(std::string naming)
{
	std::cout << "creating a humanB\n";
	name = naming;
	weapon = NULL;
}

HumanB::~HumanB()
{
	std::cout << "destroying humanB " << name << "\n";
}

void	HumanB::attack(void)
{
	std::cout << name << " attacks with their ";
	if (weapon != NULL)
		std::cout << weapon->getType() << "\n";
	else
		std::cout << "bare hands\n";
}

void	HumanB::setWeapon(Weapon &club)
{
	Weapon *newClub = &club;
	weapon = newClub;
}
