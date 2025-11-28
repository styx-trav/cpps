#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
	std::cout << "Dog default constructor called\n";
	brain = new Brain();
}

Dog::~Dog()
{
	std::cout << "Dog destructor called\n";
	delete brain;
}

Dog::Dog(const Dog &other) : Animal(other)
{
	std::cout << "Dog copy constructor called\n";
	brain = new Brain(*(other.brain));
}

Dog& Dog::operator=(const Dog &other)
{
	if (this != &other)
	{
		type = other.type;
		*brain = *(other.brain);
		std::cout << "Dog assignment operator called\n";
	}
	return *this;
}

void Dog::makeSound()
{
	std::cout << type << " barks.\n";
}

void Dog::hasIdea(const std::string &newidea)
{
	std::cout << "dog has an idea !\n";
	brain->addIdea(newidea);
}

void Dog::readIdeas()
{
	brain->readIdeas();
}
