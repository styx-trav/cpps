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
		friend std::ostream&  operator<<(std::ostream &out, const Fixed& fix);
		int getRawBits( void ) const;
		void setRawBits( int const raw );
		float toFloat( void ) const;
		int toInt ( void ) const;
};

#endif
