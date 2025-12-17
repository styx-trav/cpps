#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP
# include <iostream>
# include <stdint.h>
# include "Data.hpp"


class Serializer
{
	public:
		Serializer();
		virtual ~Serializer() = 0;
		Serializer(const Serializer &other);
		Serializer &operator=(const Serializer &other);
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};

#endif
