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
		Fixed &operator=(const Fixed &other);
		~Fixed();
		
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
		float	toFloat(void) const;
		int		toInt(void) const;
	};
	
std::ostream&	operator<<(std::ostream& os, const Fixed& fixed);