#include "Fixed.hpp"

int main()
{
	Fixed a;
	Fixed b(-10);
	Fixed c(123.87f);
	Fixed d(c);
	
	a = Fixed(955.666f);
	
	std::cout << "a : " << a.getRawBits() << std::endl;
	std::cout << "b : " << b.getRawBits() << std::endl;
	std::cout << "c : " << c.getRawBits() << std::endl;
	
	std::cout << "a is " << a << std::endl;
        std::cout << "b is " << b << std::endl;
        std::cout << "c is " << c << std::endl;
        std::cout << "d is " << d << std::endl;
        std::cout << "a is " << a.toInt() << " as integer" << std::endl;
        std::cout << "b is " << b.toInt() << " as integer" << std::endl;
        std::cout << "c is " << c.toInt() << " as integer" << std::endl;
        std::cout << "d is " << d.toInt() << " as integer" << std::endl;
        
        //checking comparisons
        
        std::cout << "a is bigger than b : " << (a > b) << std::endl;
        std::cout << "b is equal to d : " << (b == d) << std::endl;
        std::cout << "c is smaller or equal to d : " << (c <= d) << std::endl;
        std::cout << "d is smaller than c : " << (d < c) << std::endl;
        std::cout << "a is different from b : " << (a != b) << std::endl;
        
        //checking operations
        
        std::cout << "show me a + b : " << (a + b) << std::endl;
        std::cout << "show me a - c : " << (a - c) << std::endl;
        std::cout << "adding b to d" << std::endl;
        
        d = d + b;
        
        std::cout << "show me new d : " << d << std::endl;
        std::cout << "show me b² : " << (b * b) << std::endl;
        std::cout << "show me a / b : " << (a / b) << std::endl;
        
        //checking in/decrements
        
        std::cout << "see --a : " << --a << std::endl;
	std::cout << "see ++b : " << ++b << std::endl;
	std::cout << "see c++ : " << c++ << std::endl;
	std::cout << "see new c : " << c << std::endl;
	
	//checking min/max
	
	std::cout << "see min (a, b): " << Fixed::min(a, b) << std::endl;
	std::cout << "see max (c, d) : " << Fixed::max(c, d) << std::endl;
	
	std::cout << "see const min (a, b): " << Fixed::min((const Fixed)a, (const Fixed)b) << std::endl;
	std::cout << "see const max (c, d) : " << Fixed::max((const Fixed)c, (const Fixed)d) << std::endl;
	
	return 0;
}
