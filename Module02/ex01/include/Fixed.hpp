#pragma once

#include <iostream>
#include <cmath>

class Fixed
{
	public:
		Fixed();
		Fixed(const int num);
		Fixed(const float num);
		Fixed(const Fixed &other);
		~Fixed();
	public:
		Fixed&	operator=(const Fixed &other);
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
		float	toFloat(void) const;
		int		toInt(void) const;
	private:
		int					fixed;
		static const int	bit;
};

std::ostream& operator<<(std::ostream& os, const Fixed& obj);