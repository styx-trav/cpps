#ifndef IMATERIASOURCE_HPP
# define IMATERIASOURCE_HPP
# include <iostream>


class IMateriaSource
{
	private:
		std::string _name;
	public:
		IMateriaSource();
		~IMateriaSource();
		IMateriaSource(std::string &name);
		IMateriaSource(const IMateriaSource &other);
		IMateriaSource &operator=(const IMateriaSource &other);
};

#endif
