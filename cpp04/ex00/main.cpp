#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
	{
		Animal *a = new Animal();
		std::cout << std::endl;
		Animal *c = new Cat();
		std::cout << std::endl;
		Animal *d = new Dog();
		std::cout << std::endl;
		
		std::cout << "a has type " << a->getType() << " and ";
		a->makeSound();
		std::cout << "c has type " << c->getType() << " and ";
		c->makeSound();
		std::cout << "d has type " << d->getType() << " and ";
		d->makeSound();
		std::cout << std::endl;
		delete a;
		delete c;
		delete d;
	}
	{
		std::cout << std::endl << std::endl << std::endl;
		
		WrongAnimal *a = new WrongAnimal();
		std::cout << std::endl;
		WrongAnimal *c = new WrongCat();
		std::cout << std::endl;
		WrongCat *c1 = new WrongCat();
		std::cout << std::endl;
		
		std::cout << "a has type " << a->getType() << " and ";
		a->makeSound();
		std::cout << "c has type " << c->getType() << " but ";
		c->makeSound();
		std::cout << std::endl;
		std::cout << "however, c1 has type " << c1->getType() << " and ";
		c1->makeSound();
		std::cout << std::endl;
		delete a;
		delete c;
		delete c1;
	}
}		
