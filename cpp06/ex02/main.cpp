#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int main()
{
	std::cout << "First we'll generate an object\n";
	Base *s = generate();
	std::cout << "Then we identify it as a pointer ::\nThis object is a Base type : ";
	identify(s);
	std::cout << std::endl << "And then we identify it as a reference !\nThis object is a Base type : ";
	identify(*s);
	std::cout << std::endl;
	delete s;
}
