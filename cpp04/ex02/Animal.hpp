#ifndef ANIMAL_HPP
# define ANIMAL_HPP
# include <iostream>


class Animal
{
	protected:
		std::string type;
	public:
		Animal();
		virtual ~Animal() = 0;
		Animal(std::string name);
		Animal(const Animal &other);
		Animal &operator=(const Animal &other);
		virtual void makeSound();
		virtual void hasIdea(const std::string&) = 0;
		virtual void readIdeas() = 0;
		const std::string &getType();
};

#endif
