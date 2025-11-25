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
		bool operator<(const Fixed &b) const;
		bool operator<=(const Fixed &b) const;
		bool operator>(const Fixed &b) const;
		bool operator>=(const Fixed &b) const;
		bool operator==(const Fixed &b) const;
		bool operator!=(const Fixed &b) const;
		Fixed operator+(const Fixed &b) const;
		Fixed operator-(const Fixed &b) const;
		Fixed operator*(const Fixed &b) const;
		Fixed operator/(const Fixed &b) const;
		int getRawBits( void ) const;
		void setRawBits( int const raw );
		float toFloat( void ) const;
		int toInt ( void ) const;
		static Fixed &min(Fixed &a, Fixed &b);
		static Fixed &max(Fixed &a, Fixed &b);
		static const Fixed &min(const Fixed &a, const Fixed &b);
		static const Fixed &max(const Fixed &a, const Fixed &b);
};

std::ostream&  operator<<(std::ostream &out, Fixed const &fix);

#endif
