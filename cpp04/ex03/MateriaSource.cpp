#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	std::cout << "MateriaSource default constructor called\n";
	for (int i = 0; i != 4; i++)
		inventory[i] = NULL;
}

MateriaSource::~MateriaSource()
{
	for(int i = 0; i != 4; i++)
	{
		if (inventory[i] != NULL)
			delete inventory[i];
	}
	std::cout << "MateriaSource destructor called\n";
}

MateriaSource::MateriaSource(const MateriaSource &other)
{
	for(int i = 0; i != 4; i++)
	{
		if (other.inventory[i] != NULL)
			inventory[i] = (other.inventory[i])->clone();
		else
			inventory[i] = NULL;
	}
	std::cout << "MateriaSource copy constructor called\n";
}

MateriaSource& MateriaSource::operator=(const MateriaSource &other)
{
	if (this != &other)
	{
		for(int i = 0; i != 4; i++)
		{
			if (inventory[i] != NULL)
				delete inventory[i];
			inventory[i] = NULL;
			if (other.inventory[i] != NULL)
				inventory[i] = (other.inventory[i])->clone();
		}
		std::cout << "MateriaSource assignment operator called\n";
	}
	return *this;
}

void MateriaSource::learnMateria(AMateria* m)
{
	for(int i = 0; i != 4; i++)
	{
		if (inventory[i] == NULL)
		{
			inventory[i] = m;
			return ;
		}
	}
	std::cout << "this MateriaSource is already full !\n";
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for(int i = 0; i != 4; i++)
	{
		if (inventory[i] != NULL && type == (inventory[i])->getType())
		{
			return (inventory[i])->clone();
		}
	}
	std::cout << "No spell of that name in this source !\n";
	return NULL;
}
