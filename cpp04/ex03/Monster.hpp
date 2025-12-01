#ifndef MONSTER_HPP
# define MONSTER_HPP
# include "Character.hpp"


class Monster : public Character
{
	public:
		Monster();
		~Monster();
		Monster(std::string name);
		Monster(std::string name, unsigned int at, unsigned int me, unsigned int de);
		Monster(const Monster &other);
		Monster &operator=(const Monster &other);
};

#endif
