#include "Brain.hpp"

Brain::Brain() : index(0)
{
	std::cout << "Brain default constructor called\n";
}

Brain::~Brain()
{
	std::cout << "Brain destructor called\n";
}

Brain::Brain(const Brain &other)
{
	for (int i = 0; i != other.index; i++)
		ideas[i] = other.ideas[i];
	index = other.index;
	std::cout << "Brain copy constructor called\n";
}

Brain& Brain::operator=(const Brain &other)
{
	if (this != &other)
	{
		for (int i = 0; i != other.index; i++)
			ideas[i] = other.ideas[i];
		index = other.index;
		std::cout << "Brain assignment operator called\n";
	}
	return *this;
}

void	Brain::addIdea(const std::string &newidea)
{
	if (index == 100)
	{
		std::cout << "this brain is already full !\n";
		return ;
	}
	ideas[index] = newidea;
	index++;
}

void	Brain::readIdeas()
{
	for(int i = 0; i != index; i++)
		std::cout << i << ": " << ideas[i] << std::endl;
}
