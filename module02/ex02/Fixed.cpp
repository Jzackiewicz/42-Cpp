#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed(void)
{
	this->_value = 0;
	this->_fractionalBits = 8;
}

Fixed::Fixed(int value)
{
	this->_fractionalBits = 8;
	this->_value = value * (1 << this->_fractionalBits);
}

Fixed::Fixed(float value)
{
	this->_fractionalBits = 8;
	this->_value = static_cast<int>(roundf((value * (1 << this->_fractionalBits))));
}

Fixed::Fixed(const Fixed& obj)
{
	*this = obj;
}

Fixed::~Fixed(void)
{
	;
}

int	Fixed::getRawBits( void ) const
{
	return (this->_value);
}

void	Fixed::setRawBits( int const raw )
{
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

Fixed	&Fixed::operator=(const Fixed& obj)
{
	if (this != &obj)
	{
		this->_value = obj.getRawBits();
		this->_fractionalBits = obj._fractionalBits;
	}
	return (*this);
}

bool	Fixed::operator>(const Fixed &other)
{
	return (this->_value > other.getRawBits());
}

bool	Fixed::operator<(const Fixed &other)
{
	return (this->_value < other.getRawBits());
}

bool	Fixed::operator>=(const Fixed &other)
{
	return (this->_value >= other.getRawBits());
}

bool	Fixed::operator<=(const Fixed &other)
{
	return (this->_value <= other.getRawBits());
}

bool	Fixed::operator==(const Fixed &other)
{
	return (this->_value == other.getRawBits());
}

bool	Fixed::operator!=(const Fixed &other)
{
	return (this->_value != other.getRawBits());
}

Fixed	Fixed::operator+(const Fixed &other)
{
	Fixed newFixed;

	newFixed.setRawBits(this->_value + other._value);
	return (newFixed);
}

Fixed	Fixed::operator-(const Fixed &other)
{
	Fixed newFixed;

	newFixed.setRawBits(this->_value - other._value);
	return (newFixed);
}

Fixed	Fixed::operator*(const Fixed &other)
{
	Fixed	newFixed;
	
	int64_t mult = static_cast<int64_t>(this->_value) * other._value;
	int		result = static_cast<int>(mult >> this->_fractionalBits);
	newFixed.setRawBits(result);
	return (newFixed);
}

Fixed	Fixed::operator/(const Fixed &other)
{
	Fixed	newFixed;

	int64_t div = static_cast<int64_t>(this->_value) << this->_fractionalBits;
	int		result = static_cast<int>(div / other._value);
	newFixed.setRawBits(result);
	return (newFixed);
}

Fixed	&Fixed::operator++(void)
{
	this->_value++;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	tmp = *this;
	++*this;
	return (tmp);
}

Fixed	&Fixed::operator--(void)
{
	this->_value--;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	tmp = *this;
	--*this;
	return (tmp);
}

Fixed	&Fixed::min(Fixed &a, Fixed &b)
{
	return (b < a) ? b : a;
}

const Fixed	&Fixed::min(const Fixed &a, const Fixed &b)
{
	return (b._value < a._value) ? b : a;
}

Fixed	&Fixed::max(Fixed &a, Fixed &b)
{
	return (b > a) ? b : a;
}

const Fixed	&Fixed::max(const Fixed &a, const Fixed &b)
{
	return (b._value > a._value) ? b : a;
}

std::ostream&	operator<<(std::ostream& os, const Fixed& fixed)
{
	os << fixed.toFloat();
	return (os);
}