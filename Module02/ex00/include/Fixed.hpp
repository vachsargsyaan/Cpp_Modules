#pragma once

#include <iostream>
#include <string>

class Fixed
{
	public:
		Fixed();
		Fixed(const Fixed &other);
		~Fixed();
		Fixed operator=(const Fixed &other);
		int getRawBits( void ) const;
		void setRawBits( int const raw );
	private:
		int fixed;
		static const int bit;
};