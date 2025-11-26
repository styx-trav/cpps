#ifndef DOG_HPP
# define DOG_HPP
# include <iostream>


class Dog
{
	private:
		std::string = _name;
	public:
		Dog();
		~Dog();
		Dog(std::string &name);
		Dog(const Dog &other);
		Dog &operator=(const Dog &other);
};

#endif