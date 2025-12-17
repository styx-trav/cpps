#include "Serializer.hpp"

Serializer::Serializer()
{
	std::cout << "Serializer default constructor called\n";
}

Serializer::Serializer(const Serializer &other)
{
	(void)other;
	std::cout << "Serializer copy constructor called\n";
}

Serializer& Serializer::operator=(const Serializer &other)
{
	if (this != &other)
		std::cout << "Serializer assignment operator called\n";
	return *this;
}

uintptr_t Serializer::serialize(Data* ptr)
{
	void *item = (void *)ptr;
	uintptr_t obj = (uintptr_t)item;
	return obj;
}

Data* Serializer::deserialize(uintptr_t raw)
{
	void *item = (void *)raw;
	Data *obj = (Data *)item;
	return obj;
}
