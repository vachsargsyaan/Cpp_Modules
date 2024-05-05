#pragma once

class Fixed
{
	public:
		Fixed();
		Fixed(const int num);
		Fixed(const float num);
		Fixed(const Fixed &other);
		~Fixed();
	public:
		Fixed operator=(const Fixed &other);
		int getRawBits( void ) const;
		void setRawBits( int const raw );
		float	toFloat(void);
		int		toInt(void);
	private:
		int fixed;
		static const int bit;
};