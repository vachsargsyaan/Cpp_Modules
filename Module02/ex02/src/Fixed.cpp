#include "Fixed.hpp"

const int Fixed::bit = 8;

Fixed::Fixed():fixed(0)
{}

Fixed::Fixed(const int num)
{
    this->fixed = num * (1 << this->bit);
}

Fixed::Fixed(const float num)
{
    this->fixed = roundf(num * (1 << this->bit));
}

Fixed::Fixed(const Fixed &other)
{
    this->fixed = other.getRawBits();
}

Fixed::~Fixed()
{}

Fixed& Fixed::operator=(const Fixed &other)
{
    if (this == &other)
		return(*this);
    this->fixed = other.getRawBits();
    return *this;
}

int Fixed::getRawBits(void) const
{
    return this->fixed;
}

void Fixed::setRawBits( int const raw )
{
    this->fixed = raw;
}

float Fixed::toFloat(void) const
{
   float to_f = static_cast<float>(this->fixed);
   return (to_f / (1 << this->bit));	
}

int Fixed::toInt( void ) const
{
	int to_i = static_cast<int>(this->fixed);
	return (to_i / (1 << this->bit));
}

bool Fixed::operator>(const Fixed &other) const
{
    return this->fixed > other.fixed;
}

bool Fixed::operator>=(const Fixed &other) const
{
    return this->fixed >= other.fixed;
}

bool Fixed::operator<(const Fixed &other) const
{
    return this->fixed > other.fixed;
}

bool Fixed::operator<=(const Fixed &other) const
{
    return this->fixed >= other.fixed;
}

bool Fixed::operator==(const Fixed &other) const
{
    return this->fixed == other.fixed;
}

bool Fixed::operator!=(const Fixed &other) const
{
    return this->fixed != other.fixed;
}

Fixed Fixed::operator +(const Fixed &other) const
{
    Fixed temp;
	temp.fixed = this->fixed + other.fixed;
	return (temp);
}

Fixed Fixed::operator -(const Fixed &other) const
{
    Fixed temp;
	temp.fixed = this->fixed - other.fixed;
	return (temp);
}

Fixed Fixed::operator *(const Fixed &other) const
{
	Fixed temp(this->toFloat() * other.toFloat());
	return (temp);
}

Fixed Fixed::operator /(const Fixed &other) const
{
	Fixed temp(this->fixed / other.fixed);
	return (temp);
}

Fixed& Fixed::operator++()
{
    this->fixed++;
    return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed temp(*this);
	this->fixed++;
	return(temp);
}

Fixed& Fixed::operator--()
{
    this->fixed--;
    return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed temp(*this);
	this->fixed--;
	return(temp);
}

Fixed& Fixed::min(Fixed &a, Fixed &b)
{
    if (a < b)
		return (a);
    return (b);
}

const Fixed& Fixed::min(const Fixed &a, const Fixed &b)
{
	if(a.fixed < b.fixed)
		return(a);
	return (b);
}

Fixed& Fixed::max(Fixed &a, Fixed &b)
{
	if (a > b)
		return (a);
	return(b);
}

const Fixed& Fixed::max(const Fixed &a, const Fixed &b)
{
	if(a > b)
		return(a);
	return (b);
}

std::ostream& operator<<(std::ostream& os, const Fixed& obj)
{
    os << obj.toFloat();
    return os;
}