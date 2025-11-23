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

Fixed::Fixed(int const num)
{
	std::cout << "Fixed int constructor called\n";
	this->fixed_p = (int)((float)num * (1 << this->f_b));
}

Fixed::Fixed(float const number)
{
	std::cout << "Fixed float constructor called\n";
	this->fixed_p = (int)(number * (1 << this->f_b));
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

std::ostream& operator<<(std::ostream &out, const Fixed& fix)
{
	float res = fix.toFloat();
	out << res;
	return out;
}

int Fixed::getRawBits( void ) const
{
	return(this->fixed_p);
}

void Fixed::setRawBits( int const raw )
{
	this->fixed_p = raw;
}

int Fixed::toInt( void ) const
{
	int res = (int)((float)this->fixed_p / (1 << this->f_b));
	return res;
}

float Fixed::toFloat( void ) const
{
	float res = (float)this->fixed_p / (1 << this->f_b);
	return res;
}
