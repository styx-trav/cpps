#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain default constructor called\n";
}

Brain::~Brain()
{
	std::cout << "Brain destructor called\n";
}

Brain::Brain(const Brain &other)
{
	//do we copy here ?? surely theres a copy func in the string class
	for (int i = 0; i != 100; i++)
		ideas[i] = other.ideas[i];
	std::cout << "Brain copy constructor called\n";
}

Brain& Brain::operator=(const Brain &other)
{
	if (this != &other)
	{
		for (int i = 0; i != 100; i++)
			ideas[i] = other.ideas[i];
		std::cout << "Brain assignment operator called\n";
	}
	return *this;
}

