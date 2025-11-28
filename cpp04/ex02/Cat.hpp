#ifndef CAT_HPP
# define CAT_HPP
# include "Animal.hpp"
# include "Brain.hpp"


class Cat : public Animal
{
	private:
		Brain *brain;
	public:
		Cat();
		~Cat();
		Cat(const Cat &other);
		Cat &operator=(const Cat &other);
		void makeSound() const;
		void hasIdea(const std::string&);
		void readIdeas() const;
};

#endif
