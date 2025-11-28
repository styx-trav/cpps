#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	{
		std::cout << "Test 1 ------------------------------------------" << std::endl << std::endl;
		Animal *tab[6];
		for(int i = 0; i != 6; i++)
		{
			if (i < 3)
				tab[i] = new Dog();
			else
				tab[i] = new Cat();
		}
		std::cout << std::endl;
		for(int i = 0; i != 6; i++)
		{
			tab[i]->makeSound();
			tab[i]->hasIdea("an idea !");
		}
		std::cout << std::endl;
		for(int i = 0; i != 6; i++)
			delete tab[i];
	}
	{
		std::cout << std::endl << std::endl << std::endl;
		std::cout << "Test 2 ------------------------------------------" << std::endl << std::endl;
		Cat a;
		a.hasIdea("i should push this glass off the counter.");
		a.hasIdea("you know what my human would love ? a dead mouse on their pillow ! i should go get that.");
		std::cout << std::endl;
		a.readIdeas();
		Cat b (a);
		Cat c;
		c = b;
		std::cout << std::endl << std::endl;
		b.readIdeas();
		c.readIdeas();
	}
	{
		std::cout << std::endl << std::endl << std::endl;
		std::cout << "Test 3 ------------------------------------------" << std::endl << std::endl;
		Dog a;
		a.hasIdea("can we go for a walk ?");
		a.hasIdea("oh look, a puddle ! bet my owner would love it if i splashed around in there.");
		a.hasIdea("no ! not the bath ! i'm sorry, i swear !");
		std::cout << std::endl;
		a.readIdeas();
		Dog b (a);
		Dog c;
		c = b;
		std::cout << std::endl << std::endl;
		b.readIdeas();
		c.readIdeas();
	}
}
