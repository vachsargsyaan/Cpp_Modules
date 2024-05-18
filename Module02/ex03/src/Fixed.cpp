#include "Fixed.hpp"

const int Fixed::bit = 8;

Fixed::Fixed() : fixed(0) {}

Fixed::Fixed(const int num)
{
    fixed = num << bit;
}

Fixed::Fixed(const float fnum)
{
    fixed = roundf(fnum * (1 << bit));
}

Fixed::Fixed(const Fixed &other)
{
    *this = other;
}

Fixed::~Fixed() {}

bool Fixed::operator >(const Fixed &other) const
{
    return this->fixed > other.fixed;
}

bool Fixed::operator >=(const Fixed &other) const
{
    return this->fixed >= other.fixed;
}

bool Fixed::operator <(const Fixed &other) const
{
    return this->fixed < other.fixed;
}

bool Fixed::operator <=(const Fixed &other) const {
    return this->fixed <= other.fixed;
}

bool Fixed::operator ==(const Fixed &other) const
{
    return this->fixed == other.fixed;
}

bool Fixed::operator !=(const Fixed &other) const {
    return this->fixed != other.fixed;
}

Fixed Fixed::operator +(const Fixed &other) const
{
    Fixed result;
    result.fixed = this->fixed + other.fixed;
    return result;
}

Fixed Fixed::operator -(const Fixed &other) const
{
    Fixed result;
    result.fixed = this->fixed - other.fixed;
    return result;
}

Fixed Fixed::operator *(const Fixed &other) const
{
    Fixed result;
    result.fixed = (this->fixed * other.fixed) >> bit;
    return result;
}

Fixed Fixed::operator /(const Fixed &other) const
{
    Fixed result;
    result.fixed = (this->fixed << bit) / other.fixed;
    return result;
}

Fixed& Fixed::operator ++()
{
    ++fixed;
    return *this;
}

Fixed Fixed::operator ++(int)
{
    Fixed temp(*this);
    ++fixed;
    return temp;
}

Fixed& Fixed::operator --()
{
    --fixed;
    return *this;
}

Fixed Fixed::operator --(int)
{
    Fixed temp(*this);
    --fixed;
    return temp;
}

Fixed& Fixed::min(Fixed &a, Fixed &b)
{
    return (a < b) ? a : b;
}

const Fixed& Fixed::min(const Fixed &a, const Fixed &b)
{
    return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed &a, Fixed &b)
{
    return (a > b) ? a : b;
}

const Fixed& Fixed::max(const Fixed &a, const Fixed &b)
{
    return (a > b) ? a : b;
}

int Fixed::getRawBits(void) const
{
    return fixed;
}

void Fixed::setRawBits(int const raw)
{
    fixed = raw;
}

float Fixed::toFloat(void) const
{
    return (float)fixed / (1 << bit);
}

int Fixed::toInt(void) const
{
    return fixed >> bit;
}

std::ostream& operator<<(std::ostream& os, const Fixed& obj)
{
    os << obj.toFloat();
    return os;
}
