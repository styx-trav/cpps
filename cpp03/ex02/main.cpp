#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	ClapTrap a("Tim");
	a.attack("Bob");
	a.takeDamage(18);
	a.beRepaired(17);
	ClapTrap b("Bobby");
	b.beRepaired(17);
	b.takeDamage(18);
	ScavTrap c("Timmy");
	c.attack("Bob");
	c.takeDamage(150);
	c.beRepaired(17);
	ScavTrap d("Robert Robertson");
	d.beRepaired(60);
	d.takeDamage(150);
	d.guardGate();
	FragTrap e("Bear_the_dog");
	e.attack("the bad guys");
	e.highFivesGuys();
}
