#include "Serializer.hpp"

Serializer::Serializer()
{
	std::cout << "Serializer default constructor called\n";
}

Serializer::~Serializer() {}

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
