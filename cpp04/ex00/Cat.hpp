#ifndef CAT_HPP
# define CAT_HPP
# include <iostream>


class Cat
{
	private:
		std::string = _name;
	public:
		Cat();
		~Cat();
		Cat(std::string &name);
		Cat(const Cat &other);
		Cat &operator=(const Cat &other);
};

#endif