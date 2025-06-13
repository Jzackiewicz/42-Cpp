#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed(void)
{
	std::cout << "Default constructor called" << std::endl;
	this->_value = 0;
	this->_fractionalBits = 8;
}

Fixed::Fixed(int value)
{
	std::cout << "Int constructor called" << std::endl;
	this->_fractionalBits = 8;
	this->_value = value * (1 << this->_fractionalBits);
}

Fixed::Fixed(float value)
{
	std::cout << "Float constructor called" << std::endl;
	this->_fractionalBits = 8;
	this->_value = static_cast<int>(std::floor((value * (1 << this->_fractionalBits)) + 0.5));
}

Fixed::Fixed(const Fixed& obj)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = obj;
}

Fixed	&Fixed::operator=(const Fixed& obj)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &obj)
	{
		this->_value = obj.getRawBits();
		this->_fractionalBits = obj._fractionalBits;
	}
	return (*this);
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_value);
}

void	Fixed::setRawBits( int const raw )
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_value = raw;
}

float	Fixed::toFloat(void) const
{
	return (static_cast<float>(this->_value) / (1 << this->_fractionalBits));
}

int		Fixed::toInt(void) const
{
	return (this->_value >> this->_fractionalBits);
}

std::ostream&	operator<<(std::ostream& os, const Fixed& fixed)
{
	os << fixed.toFloat();
	return (os);
}