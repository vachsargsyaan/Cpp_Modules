#pragma once

#include <iostream>
#include <cmath>
#include <fstream>

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
    public:
	    bool operator >(const Fixed &other) const;
	    bool operator >=(const Fixed &other) const;
	    bool operator <(const Fixed &other) const;
	    bool operator <=(const Fixed &other) const;
	    bool operator ==(const Fixed &other) const;
	    bool operator !=(const Fixed &other) const;
	    Fixed operator +(const Fixed &other) const;
	    Fixed operator -(const Fixed &other) const;
	    Fixed operator *(const Fixed &other) const;
	    Fixed operator /(const Fixed &other) const;
	    Fixed& operator ++();
	    Fixed operator ++(int);
	    Fixed& operator --();
	    Fixed operator --(int);
	    static Fixed& min(Fixed &a, Fixed &b);
	    static const Fixed& min(const Fixed &a, const Fixed &b);
	    static Fixed& max(Fixed &a, Fixed &b);
	    static const Fixed& max(const Fixed &a, const Fixed &b);
    private:
		int					fixed;
		static const int	bit;
};

std::ostream& operator<<(std::ostream& os, const Fixed& obj);