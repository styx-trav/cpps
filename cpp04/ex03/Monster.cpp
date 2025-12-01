#include "Monster.hpp"

Monster::Monster() : Character()
{
	std::cout << "Monster default constructor called\n";
	ep = 17;
	hp = 100;
}

Monster::~Monster()
{
	std::cout << "Monster destructor called\n";
}

Monster::Monster(std::string name) : Character(name)
{
	std::cout << "Monster constructor called\n";
	ep = 17;
	hp = 100;
}

Monster::Monster(std::string name, unsigned int at, unsigned int me, unsigned int de) : Character(name, at, me, de)
{
	std::cout << "Monster constructor called\n";
}

Monster::Monster(const Monster &other) : Character(other)
{
	std::cout << "Monster copy constructor called\n";
}

Monster& Monster::operator=(const Monster &other)
{
	if (this != &other)
	{
		_name = other._name;
		att = other.att;
	        med = other.med;
	        def = other.def;
	        ep = other.ep;
	        hp = other.hp;
		for(int i = 0; i != 4; i++)
		{
			if (inventory[i] != NULL)
				delete inventory[i];
			inventory[i] = NULL;
			if (other.inventory[i] != NULL)
				inventory[i] = (other.inventory[i])->clone();
		}
		std::cout << "Character assignment operator called\n";
	}
	return *this;
}
