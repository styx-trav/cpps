#include "Data.hpp"
#include "Serializer.hpp"

int main()
{
	Data *ptr = new Data("Jan", 156);
	Data *notptr = new Data("Jared", 19);
	
	uintptr_t have = Serializer::serialize(ptr);
	uintptr_t nothave = Serializer::serialize(notptr);
	std::cout << "\nhere the serialized num of Jan: " << have << ", and of Jared: " << nothave << std::endl;
	
	ptr = Serializer::deserialize(have);
	notptr = Serializer::deserialize(nothave);
	std::cout << "and now the laundered pointers' names, 1: " << ptr->getName() << ", 2: " << notptr->getName();
	std::cout <<"\nand their ages, 1: " << ptr->age << ", 2: " << notptr->age << std::endl;
	std::cout << "pointer 1 says : ";
	ptr->read();
	std::cout << "\npointer 2 says : ";
	notptr->read();
	std::cout << std::endl;
	
	delete ptr;
	delete notptr;
	
	have = Serializer::serialize(NULL);
	std::cout << "\nhere the serialized num of NULL pointer : " << have << std::endl;
	
	ptr = Serializer::deserialize(have);
	std::cout << "and now the laundered pointer : is it NULL ? " << (ptr == NULL) << std::endl;
}
