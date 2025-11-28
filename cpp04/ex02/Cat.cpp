#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
	std::cout << "Cat default constructor called\n";
	brain = new Brain();
}

Cat::~Cat()
{
	std::cout << "Cat destructor called\n";
	delete brain;
}

Cat::Cat(const Cat &other) : Animal(other)
{
	std::cout << "Cat copy constructor called\n";
	brain = new Brain(*(other.brain));
}

Cat& Cat::operator=(const Cat &other)
{
	if (this != &other)
	{
		type = other.type;
		*brain = *(other.brain);
		std::cout << "Cat assignment operator called\n";
	}
	return *this;
}

void Cat::makeSound()
{
	std::cout << type << " meows.\n";
}

void Cat::hasIdea(const std::string &newidea)
{
	std::cout << "cat has an idea !\n";
	brain->addIdea(newidea);
}

void Cat::readIdeas()
{
	brain->readIdeas();
}
