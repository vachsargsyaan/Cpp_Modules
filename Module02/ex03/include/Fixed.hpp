#pragma once

#include <iostream>
#include <cmath>

class Fixed
{
	public:
		Fixed();
		Fixed(const int num);
		Fixed(const float fnum);
		Fixed(const Fixed &other);
		~Fixed();
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
	public:
		static Fixed& min(Fixed &a, Fixed &b);
	    static const Fixed& min(const Fixed &a, const Fixed &b);
	    static Fixed& max(Fixed &a, Fixed &b);
	    static const Fixed& max(const Fixed &a, const Fixed &b);
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
		float	toFloat(void) const;
		int		toInt(void) const;
	private:
		int fixed;
		const static int bit;
};

std::ostream& operator<<(std::ostream& os, const Fixed& obj);
