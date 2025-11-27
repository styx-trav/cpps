#include "ClapTrap.hpp"

int main()
{
	ClapTrap a("Tim");
	a.attack("Bob");
	a.takeDamage(18);
	a.beRepaired(17);
	ClapTrap b("Bobby");
	b.beRepaired(17);
	b.takeDamage(18);
	b.attack("Bob");
	b.attack("Bob");
	b.attack("Bob");
	b.attack("Bob");
	b.attack("Bob");
	b.attack("Bob");
	b.attack("Bob");
	b.attack("Bob");
	b.attack("Bob");
	b.attack("Bob");
	b.attack("Bob");
}
