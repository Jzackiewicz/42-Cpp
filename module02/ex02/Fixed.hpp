#pragma once

#include <iostream>
#include <string>

class Fixed
{
	private:
		int	_value;
		int _fractionalBits;

	public:
		Fixed(void);
		Fixed(int value);
		Fixed(float value);
		Fixed(const Fixed& obj);
		~Fixed();

		Fixed	&operator=(const Fixed &other);
		bool	operator>(const Fixed &other);
		bool	operator<(const Fixed &other);
		bool	operator>=(const Fixed &other);
		bool	operator<=(const Fixed &other);
		bool	operator==(const Fixed &other);
		bool	operator!=(const Fixed &other);
		Fixed	operator+(const Fixed &other);
		Fixed	operator-(const Fixed &other);
		Fixed	operator*(const Fixed &other);
		Fixed	operator/(const Fixed &other);
		Fixed	&operator++(void);				// Preincrement
		Fixed	operator++(int);				// Postincrement
		Fixed	&operator--(void);				// Predecrement
		Fixed	operator--(int);				// Postdecrement
		
		static Fixed	&min(Fixed &a, Fixed &b);
		static const Fixed	&min(const Fixed &a, const Fixed &b);
		static Fixed	&max(Fixed &a, Fixed &b);
		static const Fixed	&max(const Fixed &a, const Fixed &b);
		
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
		float	toFloat(void) const;
		int		toInt(void) const;
	};
	
std::ostream	&operator<<(std::ostream& os, const Fixed& fixed);