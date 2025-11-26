#ifndef ANIMAL_HPP
# define ANIMAL_HPP
# include <iostream>


class Animal
{
	private:
		std::string = _name;
	public:
		Animal();
		~Animal();
		Animal(std::string &name);
		Animal(const Animal &other);
		Animal &operator=(const Animal &other);
};

#endif