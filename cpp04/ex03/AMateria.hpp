#ifndef AMATERIA_HPP
# define AMATERIA_HPP
# include <iostream>


class AMateria
{
	protected:
		std::string type;
	public:
		AMateria();
		~AMateria();
		AMateria(std::string name);
		AMateria(const AMateria &other);
		AMateria &operator=(const AMateria &other);
		const std::string &getType();
		virtual AMateria* clone() = 0;
		virtual void use(ICharacter& target);
};

#endif
