#ifndef BRAIN_HPP
# define BRAIN_HPP
# include <iostream>


class Brain
{
	private:
		std::string ideas[100];
		int index;
	public:
		Brain();
		~Brain();
		Brain(const Brain &other);
		Brain &operator=(const Brain &other);
		void addIdea(const std::string &newidea);
		void readIdeas();
};

#endif
