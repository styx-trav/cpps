#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>
# include <fstream>
# include <cmath>

class Fixed
{
	private:
		int fixed_p;
		static const int f_b = 8;
	public:
		Fixed();
		~Fixed();
		Fixed(int const num);
		Fixed(float const number);
		Fixed(const Fixed &other);
		Fixed &operator=(const Fixed &other);
		Fixed &operator++();
		Fixed &operator--();
		Fixed operator++(int s);
		Fixed operator--(int s);
		bool operator<(const Fixed &b);
		bool operator<=(const Fixed &b);
		bool operator>(const Fixed &b);
		bool operator>=(const Fixed &b);
		bool operator==(const Fixed &b);
		bool operator!=(const Fixed &b);
		Fixed operator+(const Fixed &b);
		Fixed operator-(const Fixed &b);
		Fixed operator*(const Fixed &b);
		Fixed operator/(const Fixed &b);
		int getRawBits( void ) const;
		void setRawBits( int const raw );
		float toFloat( void ) const;
		int toInt ( void ) const;
};

std::ostream&  operator<<(std::ostream &out, Fixed const &fix);

#endif
