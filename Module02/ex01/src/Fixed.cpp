#include "Fixed.hpp"

const int Fixed::bit = 8;

Fixed::Fixed():fixed(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int num)
{
    std::cout<< "Int constructor called" << std::endl;
    this->fixed = num * (1 << bit);
}

Fixed::Fixed(const float num)
{
    std::cout << "Float constructor called" << std ::endl;
    this->fixed = roundf(num * (1 << this->bit));
}

Fixed::Fixed(const Fixed &other)
{
    std::cout << "Copy constructor called" << std::endl;
    this->fixed = other.getRawBits();
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed &other)
{
    std::cout << "Copy assignment operator called" << std::endl;
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

std::ostream& operator<<(std::ostream& os, const Fixed& obj)
{
    os << obj.toFloat();
    return os;
}