#include "Fixed.hpp"

Fixed::Fixed()
{
	fixed_p = 0;
	std::cout << "Fixed default constructor called\n";
}

Fixed::~Fixed()
{
	std::cout << "Fixed destructor called\n";
}

Fixed::Fixed(const Fixed &other)
{
	fixed_p = other.fixed_p;
	std::cout << "Fixed copy constructor called\n";
}

Fixed& Fixed::operator=(const Fixed &other)
{
	if (this != &other)
	{
		fixed_p = other.fixed_p;
		std::cout << "Fixed assignment operator called\n";
	}
	return *this;
}

int Fixed::getRawBits( void ) const
{
	return(this->fixed_p);
}

void Fixed::setRawBits( int const raw )
{
	this->fixed_p = raw;
}
