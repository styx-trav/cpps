#include "Data.hpp"
#include "Serializer.hpp"

int main()
{
	Data *ptr = new Data("Jan");
	uintptr_t have = Serializer::serialize(ptr);
	std::cout << "here the serialized num : " << have << std::endl;
	ptr = Serializer::deserialize(have);
	std::cout << "and now the laundered pointer's name : " << ptr->getName() << std::endl;
	delete ptr;
}
