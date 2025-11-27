#include "Dog.cpp"
#include "Cat.cpp"

int main()
{
	Animal *tab = new Animal[6];
	for(int i = 0; i != 6; i++)
	{
		if (i < 3)
			tab[i] = Dog();
		else
			tab[i] = Cat();
	}
	delete[] tab;
}
