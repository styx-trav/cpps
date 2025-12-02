#include "Character.hpp"

Character::Character() : ICharacter()
{
	std::cout << "Character default constructor called\n";
	ep = 4;
	hp = 24;
	_name = "name";
	att = 0;
	def = 0;
	med = 0;
	for (int i = 0; i != 4; i++)
		inventory[i] = NULL;
}

Character::~Character()
{
	for(int i = 0; i != 4; i++)
	{
		if (inventory[i] != NULL)
			delete inventory[i];
	}
	std::cout << "Character destructor called\n";
}

Character::Character(std::string name) : ICharacter()
{
	std::cout << "Character constructor called\n";
	_name = name;
	ep = 4;
	hp = 24;
	att = 0;
	def = 0;
	med = 0;
	for (int i = 0; i != 4; i++)
		inventory[i] = NULL;
}

Character::Character(std::string name, unsigned int at, unsigned int me, unsigned int de) : ICharacter()
{
	std::cout << "Character constructor called\n";
	_name = name;
	att = at;
	def = de;
	med = me;
	ep = 4;
	hp = 24;
	for (int i = 0; i != 4; i++)
		inventory[i] = NULL;
}

Character::Character(const Character &other) : ICharacter()
{
	_name = other._name;
	att = other.att;
	med = other.med;
	def = other.def;
	ep = other.ep;
	hp = other.hp;
	for(int i = 0; i != 4; i++)
	{
		if (other.inventory[i] != NULL)
			inventory[i] = (other.inventory[i])->clone();
		else
			inventory[i] = NULL;
	}
	std::cout << "Character copy constructor called\n";
}

Character& Character::operator=(const Character &other)
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

std::string const &Character::getName() const
{
	return this->_name;
}

void Character::equip(AMateria* m)
{
	for(int i = 0; i != 4; i++)
	{
		if (inventory[i] == NULL)
		{
			inventory[i] = m;
			return ;
		}
	}
	std::cout << _name << "'s inventory is already full !\n";
}

void Character::unequip(int idx)
{
	if (inventory[idx] == NULL)
		std::cout << "no materia to unequip at this slot\n";
	else
		std::cout << _name << " unequips their " << inventory[idx]->getType() << std::endl;
	inventory[idx] = NULL;
}

void Character::gift(int idx, ICharacter &target)
{
	if (inventory[idx] == NULL)
		return ;
	AMateria *tmp = inventory[idx];
	this->unequip(idx);
	std::cout << _name << " gifts their " << tmp->getType() << " to " << target.getName() << std::endl;
	target.equip(tmp);
}

void Character::use(int idx, ICharacter &target)
{
	if (!hp)
		return ;
	if (!ep || (ep == 1 && hp < 5))
	{
		std::cout << _name << " is fatigued, and cannot do anything.\n";
		return ;
	}
	if (inventory[idx] == NULL)
		std::cout << "no spell in this slot\n";
	else
	{
		this->ep--;
		if (hp < 5)
			this->ep--;
		std::cout << this->_name << " ";
		(inventory[idx])->use(target, att, def, med);
	}
}

void Character::takeDamage(unsigned int dam)
{
	if (!hp)
		return ;
	if (dam < def)
		dam = 0;
	else
		dam = dam - def;
	std::cout << _name << " takes " << dam << " points of damage.\n";
	if (def > 5)
		def -= 5;
	else
		def = 0;
	if (dam > hp)
		hp = 0;
	else
		hp = hp - dam;
	if (!hp)
		std::cout << _name << " is dead.\n";
	else if (hp < 5)
		std::cout << _name << "is severely injured (< 5hp). Any action will cost double the energy points.\n";
	else
		std::cout << _name << " now has " << hp << "hp." << std::endl;
}

void Character::beRepaired(unsigned int heal)
{
	if (!hp)
	{
		std::cout << _name << " cannot be helped. They are dead.\n";
		return ;
	}
	hp = hp + heal;
	std::cout << _name << " is healed for " << heal << ", and now has " << hp << "hp.\n";
}

void Character::beProtected(unsigned int protection)
{
	if (!hp)
		return ;
	def = def + protection;
	std::cout << _name << " gets a protection boost, bringing their defense to " << def << std::endl;
}
