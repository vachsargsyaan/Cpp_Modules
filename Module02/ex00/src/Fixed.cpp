#include "Fixed.hpp"

const int Fixed::bit = 8;

Fixed::Fixed():fixed(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called" << std::endl;
	this->fixed = other.getRawBits();
}

Fixed Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->fixed = other.fixed;
	return *this;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}
int Fixed::getRawBits(void) const
{
	std::cout <<  "getRawBits member function called" << std::endl;
	return this->fixed;
}

void Fixed::setRawBits(int const raw)
{
	this->fixed = raw;
}