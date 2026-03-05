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
	void *item = reinterpret_cast<void *>(ptr);
	uintptr_t obj = reinterpret_cast<uintptr_t>(item);
	return obj;
}

Data* Serializer::deserialize(uintptr_t raw)
{
	void *item = reinterpret_cast<void *>(raw);
	Data *obj = reinterpret_cast<Data *>(item);
	return obj;
}
