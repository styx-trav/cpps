#include "Fixed.hpp"

//constructors/destructors

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
	this->fixed_p = (int)roundf(number * (1 << this->f_b));
}

Fixed::Fixed(const Fixed &other)
{
	fixed_p = other.fixed_p;
	std::cout << "Fixed copy constructor called\n";
}

//operator overloads-non members

std::ostream&  operator<<(std::ostream &out, Fixed const &fix)
{
	out << fix.toFloat();
	return out;
}

//operator overloads-members

Fixed& Fixed::operator=(const Fixed &other)
{
	if (this != &other)
	{
		fixed_p = other.fixed_p;
		std::cout << "Fixed assignment operator called\n";
	}
	return *this;
}

	//pre-increments/decrements

Fixed& Fixed::operator--( void )
{
	fixed_p--;
	return *this;
}

Fixed& Fixed::operator++( void )
{
	fixed_p++;
	return *this;
}

	//post-increments/decrements

Fixed Fixed::operator--( int s )
{
	(void)s;
	Fixed neo(*this);
	fixed_p--;
	return neo;
}

Fixed Fixed::operator++( int s )
{
	(void)s;
	Fixed neo(*this);
	fixed_p++;
	return neo;
}

	//comparisons

bool Fixed::operator<(const Fixed &b) const
{
	return (this->getRawBits() < b.getRawBits());
}

bool Fixed::operator<=(const Fixed &b) const
{
	return (this->getRawBits() <= b.getRawBits());
}

bool Fixed::operator>(const Fixed &b) const
{
	return (this->getRawBits() > b.getRawBits());
}

bool Fixed::operator>=(const Fixed &b) const
{
	return (this->getRawBits() >= b.getRawBits());
}

bool Fixed::operator==(const Fixed &b) const
{
	return (this->getRawBits() == b.getRawBits());
}

bool Fixed::operator!=(const Fixed &b) const
{
	return (this->getRawBits() != b.getRawBits());
}

	//operations

Fixed Fixed::operator+(const Fixed &b) const
{
	Fixed neo;
	neo.setRawBits(this->getRawBits() + b.getRawBits());
	return neo;
}

Fixed Fixed::operator-(const Fixed &b) const
{
	Fixed neo;
	neo.setRawBits(this->getRawBits() - b.getRawBits());
	return neo;
}

Fixed Fixed::operator*(const Fixed &b) const
{
	Fixed neo;
	neo.setRawBits((this->getRawBits() * b.getRawBits()) / (1 << neo.f_b));
	return neo;
}

Fixed Fixed::operator/(const Fixed &b) const
{
	Fixed neo;
	neo.setRawBits((this->getRawBits() / b.getRawBits()) * (1 << neo.f_b));
	return neo;
}

//class-spec functions

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

//min-maxers

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	if (a < b)
		return a;
	return b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	if (a > b)
		return a;
	return b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a.getRawBits() < b.getRawBits())
		return a;
	return b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a.getRawBits() > b.getRawBits())
		return a;
	return b;
}
