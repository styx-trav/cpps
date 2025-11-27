#ifndef ANIMAL_HPP
# define ANIMAL_HPP
# include <iostream>


class Animal
{
	protected:
		std::string type;
	public:
		Animal();
		~Animal();
		Animal(std::string name);
		Animal(const Animal &other);
		Animal &operator=(const Animal &other);
		void makeSound();
		const std::string &getType();
};

#endif
