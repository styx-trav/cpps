#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
	{
		Animal a;
		std::cout << std::endl;
		Cat c;
		std::cout << std::endl;
		Dog d;
		std::cout << std::endl;
		
		std::cout << "a has type " << a.getType() << " and ";
		a.makeSound();
		std::cout << "c has type " << c.getType() << " and ";
		c.makeSound();
		std::cout << "d has type " << d.getType() << " and ";
		d.makeSound();
		std::cout << std::endl;
	}
	{
		std::cout << std::endl << std::endl << std::endl;
		
		WrongAnimal a;
		std::cout << std::endl;
		WrongCat c;
		std::cout << std::endl;
		
		std::cout << "a has type " << a.getType() << " and ";
		a.makeSound();
		std::cout << "c has type " << c.getType() << " but ";
		c.makeSound();
		std::cout << std::endl;
	}
}		
